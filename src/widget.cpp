#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMenu>
#include <arpa/inet.h>

#include <DeviceLayerHelper.h>
#include <DeviceLayer.h>

#include <ConfigTargets.h>
#include <DeviceLayerResult.h>
#include <QTreeWidgetItem>
#include <QMessageBox>
#include <QLabel>
#include <QPixmap>
#include <QBitmap>
#include <QMouseEvent>
#include <QFileDialog>

#include "ConfigDialog.h"
#include "CallBackAndEvent.h"
#include "AbuoutDialog.h"

Q_DECLARE_METATYPE(DeviceLayer::DevicePtr)
Q_DECLARE_METATYPE(DeviceLayer::UpgradePtr)

enum DEVICE_LIST_COLUMN_INDEX {
    COLUMN_INDEX_IP,
    COLUMN_INDEX_MODEL,
    COLUMN_INDEX_MASK,
    COLUMN_INDEX_MODELID,
    COLUMN_INDEX_CONNECT,
    COLUMN_INDEX_UPGRADE
};

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_findButtonState(false)
{
    ui->setupUi(this);
    initDialog();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initDialog()
{
    this->setWindowIcon(QIcon(":/Icon/res/icon/DeviceToolbox.ico"));

    RightDoubleClicked *right = new RightDoubleClicked;
    ui->treeWidget->viewport()->installEventFilter(right);

    m_okIcon = QPixmap(":/Icon/res/icon/2.png");
//    QBitmap okMask = m_okIcon.createMaskFromColor(QColor(252,252,252), Qt::MaskInColor);
//    m_okIcon.setMask(okMask);
    m_cancleIcon = QPixmap(":/Icon/res/icon/1.png");
//    QBitmap cancleMask = m_okIcon.createMaskFromColor(QColor(252,252,252), Qt::MaskInColor);
//    m_cancleIcon.setMask(cancleMask);
    m_upgradMenu = new QMenu(ui->upgrade);
    ui->upgrade->setMenu(m_upgradMenu);
    ui->upgrade->setPopupMode(QToolButton::MenuButtonPopup);

    connect(m_upgradMenu, SIGNAL(triggered(QAction*)),
            this, SLOT(upgradeActionFile(QAction*)));

    //控制按钮
    connect(ui->findAndStopButton, SIGNAL(clicked()), SLOT(findAndStopButtonSlot()));
    connect(ui->refreshButton, SIGNAL(clicked()), SLOT(refreshButtonSlot()));
    connect(ui->clearButton, SIGNAL(clicked()), SLOT(clearAllDeviceSlot()));
    connect(ui->connectButton, SIGNAL(clicked()), SLOT(connectButtonSlot()));
    connect(ui->configButton, SIGNAL(clicked()), SLOT(setDeviceButtonSlot()));
    connect(ui->restartButton, SIGNAL(clicked()), SLOT(restartButtonSlot()));
    connect(ui->upgrade, SIGNAL(clicked()), SLOT(upgradeButtonSolt()));
    connect(ui->aboutButton, SIGNAL(clicked()), SLOT(aboutButtonSolt()));
    connect(ui->treeWidget, &QTreeWidget::itemDoubleClicked,
            this, &Widget::itemDoubleClicked);

    connect(ui->treeWidget, SIGNAL(itemSelectionChanged()),
            this, SLOT(selectChanged()));

    //DeviceManageBack
    connect(&m_discoveryManger, &BatchCodecDeviceDiscoveryManager::foundDevices,
                            this, &Widget::addDevicesInfo, Qt::QueuedConnection);

    //ConnectBack
    connect(&m_deviceConnectBack, &DeviceConnectCallBack::deviceConnectSuccess,
            this, &Widget::deviceConnectSuccess, Qt::BlockingQueuedConnection);
    connect(&m_deviceConnectBack, &DeviceConnectCallBack::deviceConnectFailed,
            this, &Widget::deviceConnectFailed, Qt::BlockingQueuedConnection);
    connect(&m_deviceConnectBack, &DeviceConnectCallBack::deviceLoseConnect,
            this, &Widget::deviceLoseConnect, Qt::BlockingQueuedConnection);

    //UpgradeBack
    connect(&m_deviceUpgradBack, &UpgradeDeviceCallback::started,
            this, &Widget::started, Qt::BlockingQueuedConnection);
    connect(&m_deviceUpgradBack, &UpgradeDeviceCallback::startFailed,
            this, &Widget::startFailed, Qt::BlockingQueuedConnection);
    connect(&m_deviceUpgradBack, &UpgradeDeviceCallback::notifyProcessing,
            this, &Widget::notifyProcessing, Qt::BlockingQueuedConnection);
    connect(&m_deviceUpgradBack, &UpgradeDeviceCallback::faults,
            this, &Widget::faults, Qt::BlockingQueuedConnection);
    connect(&m_deviceUpgradBack, &UpgradeDeviceCallback::completed,
            this, &Widget::completed, Qt::BlockingQueuedConnection);

    ui->treeWidget->setColumnWidth(0, 160);
    ui->treeWidget->setColumnWidth(1, 100);
    ui->treeWidget->setColumnWidth(2, 130);
    ui->treeWidget->setColumnWidth(3, 100);
    ui->treeWidget->setColumnWidth(4, 80);
}

void Widget::closeEvent(QCloseEvent *event)
{
    clearAllDeviceSlot();
    QWidget::closeEvent(event);
}

void Widget::upgradeDevice(QList<QTreeWidgetItem *> items, const QString &fileName)
{
    foreach (QTreeWidgetItem *item, items) {
        if(m_upgradBtnsState.contains(item)) {
            continue;
        }

        qDebug() << fileName;

        DeviceLayer::DevicePtr device = item->data(COLUMN_INDEX_MODELID, Qt::UserRole).value<DeviceLayer::DevicePtr>();
        DeviceLayer::UpgradePtr upgrade(device->GetUpgrade());
        upgrade->ResetUpgrade(false);
        if(!upgrade) {
            qDebug() << "Upgrade is Null";
            continue;
        }

        DeviceLayer::UpgradeParams configure;
        QString name = "FilePath";
        configure.SetProp(name.toStdString().data(), fileName.toStdString().data());

        if (!DLR_SUCCESS(upgrade->ConfigureUpgrade(configure))) {
            item->setText(COLUMN_INDEX_UPGRADE, tr("升级参数错误"));
            continue;
        }

        if (!DLR_SUCCESS(upgrade->StartUpgrade(NULL))) {
            item->setText(COLUMN_INDEX_UPGRADE, tr("启动升级失败"));
            continue;
        }
        item->setText(COLUMN_INDEX_UPGRADE, tr("启动升级"));
        m_upgradBtnsState.append(item);
    }
    selectChanged();
}

void Widget::connectDevice(QList<QTreeWidgetItem *> items)
{
    foreach(QTreeWidgetItem *item, items) {
        if (!item->data(COLUMN_INDEX_CONNECT, Qt::UserRole).toBool() && !m_upgradBtnsState.contains(item)) {
            DeviceLayer::DevicePtr device = item->data(COLUMN_INDEX_MODELID, Qt::UserRole).value<DeviceLayer::DevicePtr>();
            if(!device) {
                QMessageBox::warning(this, tr("创建失败"), tr("设备对象创建失败(可能是不支持的设备型号)"));
            }
            else {
                DeviceLayer::DLResult result = device->Connect(NULL);
                if(result != DeviceLayer::DLR_S_OK) {
                    qDebug() << "Connect slot is error, error value " << result;
                    continue;
                }
                item->setText(COLUMN_INDEX_CONNECT, tr("连接中"));
            }
        }
    }
    changedButtonState(items);
}

void Widget::connectDevice(QTreeWidgetItem *item)
{
    if (!item->data(COLUMN_INDEX_CONNECT, Qt::UserRole).toBool() && !m_upgradBtnsState.contains(item)) {
        DeviceLayer::DevicePtr device = item->data(COLUMN_INDEX_MODELID, Qt::UserRole).value<DeviceLayer::DevicePtr>();
        if(!device) {
            QMessageBox::warning(this, tr("创建失败"), tr("设备对象创建失败(可能是不支持的设备型号)"));
        }
        else {
            DeviceLayer::DLResult result = device->Connect(NULL);
            if(result != DeviceLayer::DLR_S_OK) {
                qDebug() << "Connect slot is error, error value " << result;
                return;
            }
            item->setText(COLUMN_INDEX_CONNECT, tr("连接中"));
        }
    }
    selectChanged();
}

void Widget::findAndStopButtonSlot()
{
    ui->findAndStopButton->setEnabled(false);
    ui->findAndStopButton->repaint();
    ui->findAndStopButton->update();

    if(!m_findButtonState) {
        ui->findAndStopButton->setText(tr("停止搜索"));
        m_discoveryManger.startDiscoverDevices();        
        ui->refreshButton->setEnabled(true);
        m_findButtonState = true;
    }
    else {
        ui->findAndStopButton->setText(tr("搜索设备"));
        m_discoveryManger.stopDiscoverDevices();
        m_findButtonState = false;
        ui->refreshButton->setEnabled(false);
    }
    ui->findAndStopButton->setEnabled(true);

    static bool first = true;
    if(first) {
        first = false;
        m_discoveryManger.getDeviceManagerPtr()->SetCallback(&m_deviceConnectBack);
        m_discoveryManger.getDeviceManagerPtr()->SetCallback(&m_deviceUpgradBack);
    }
}

void Widget::refreshButtonSlot()
{
    if (m_discoveryManger.getDeviceDiscoveryManagerPtr())
        m_discoveryManger.getDeviceDiscoveryManagerPtr()->RefreshDiscovery();
}

void Widget::clearAllDeviceSlot()
{
    while (ui->treeWidget->topLevelItemCount() > 0) {
        QTreeWidgetItem *item = ui->treeWidget->takeTopLevelItem(0);
        DeviceLayer::DevicePtr device = item->data(COLUMN_INDEX_MODELID, Qt::UserRole).value<DeviceLayer::DevicePtr>();
        m_discoveryManger.getDeviceManagerPtr()->RemoveDevice(device->GetDeviceId());
        delete item;
        item = NULL;
    }
    ui->connectButton->setEnabled(false);
    ui->configButton->setEnabled(false);
    ui->restartButton->setEnabled(false);
}

void Widget::connectButtonSlot()
{
    QList<QTreeWidgetItem *> items = ui->treeWidget->selectedItems();
    connectDevice(items);
}

void Widget::setDeviceButtonSlot()
{
    QTreeWidgetItem *item = ui->treeWidget->currentItem();
    if (m_upgradBtnsState.contains(item)) {
        return;
    }

    DeviceLayer::DevicePtr device = item->data(COLUMN_INDEX_MODELID, Qt::UserRole).value<DeviceLayer::DevicePtr>();
    ConfigDialog config(m_discoveryManger.getDeviceManagerPtr(), device, this);
    connect(&config, &ConfigDialog::setDeviceResult,
            this, &Widget::showSetResult , Qt::UniqueConnection);
    config.exec();
}

void Widget::restartButtonSlot()
{
    QList<QTreeWidgetItem *> list = ui->treeWidget->selectedItems();
    foreach(QTreeWidgetItem *item, list) {
        if (!item->data(COLUMN_INDEX_CONNECT, Qt::UserRole).toBool() && !m_upgradBtnsState.contains(item)) {
            continue;
        }

        DeviceLayer::DevicePtr device = item->data(COLUMN_INDEX_MODELID, Qt::UserRole).value<DeviceLayer::DevicePtr>();
        DeviceLayer::ConfigPtr config(device->GetConfig(), false);
        if(!config) {
            qDebug() << "Restart the config is Null";
            continue;
        }

        DeviceLayer::ConfigParams configParams;
        bool isOK = configParams.AddInvokeAction(DLCT_RESTART);
        if(isOK) {
            DeviceLayer::DLResult result = config->Configure(configParams, NULL);
            if(result == DeviceLayer::DLR_S_OK) {
                item->setText(COLUMN_INDEX_CONNECT, tr("未连接"));
                item->setIcon(0, m_cancleIcon);
                item->setData(COLUMN_INDEX_CONNECT, Qt::UserRole, false);
                if(item == ui->treeWidget->currentItem()) {
                }
            }
            else {
                qDebug() << "Restart the configuer result value is " << result;
            }
        }
        else {
            qDebug() << "Restart the add invoke action is error";
        }
    }
    changedButtonState(list);
}

void Widget::upgradeButtonSolt()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, tr("打开"), "/root", tr("升级文件(*)"));
    if(fileName.isEmpty()) {
        return;
    }
    m_upgradMenu->addAction(fileName);

    upgradeDevice(ui->treeWidget->selectedItems(), fileName);
}

void Widget::aboutButtonSolt()
{
    AbuoutDialog aboutDialog(this);
    aboutDialog.exec();
}

void Widget::upgradeActionFile(QAction *action)
{
    upgradeDevice(ui->treeWidget->selectedItems(), action->text());
}

void Widget::selectChanged()
{
    changedButtonState(ui->treeWidget->selectedItems());
}

void Widget::changedButtonState(QList<QTreeWidgetItem *> items)
{

    if (m_upgradBtnsState.count() != 0) {
        ui->clearButton->setEnabled(false);
    }
    else {
        ui->clearButton->setEnabled(true);
    }

    if(items.count() == 0) {
        ui->connectButton->setEnabled(false);
        ui->configButton->setEnabled(false);
        ui->restartButton->setEnabled(false);
        ui->upgrade->setEnabled(false);
    }
    else if(items.count() == 1) {

        if(m_upgradBtnsState.contains(items.value(0))) {
            ui->configButton->setEnabled(false);
            ui->configButton->setEnabled(false);
            ui->restartButton->setEnabled(false);
            ui->upgrade->setEnabled(false);
        }
        else {
            if (items.value(0)->data(COLUMN_INDEX_CONNECT, Qt::UserRole).toBool()) {
                ui->connectButton->setEnabled(false);
                ui->configButton->setEnabled(true);
                ui->restartButton->setEnabled(true);
            }
            else {
                ui->connectButton->setEnabled(true);
                ui->configButton->setEnabled(false);
                ui->restartButton->setEnabled(false);
            }

            DeviceLayer::UpgradePtr upgrad = items.value(0)->data(COLUMN_INDEX_UPGRADE, Qt::UserRole).value<DeviceLayer::UpgradePtr>();
            if(!upgrad) {
                ui->upgrade->setEnabled(false);
            }
            else {
                ui->upgrade->setEnabled(true);
            }
        }
    }
    else {
        int  connectButtonState = 0;
        bool theConnect = false;
        bool theReboot = false;
        foreach (QTreeWidgetItem *item, items) {
            if(m_upgradBtnsState.contains(item)) {
                continue;
            }

            if (!item->data(COLUMN_INDEX_CONNECT, Qt::UserRole).toBool() && !theConnect) {
                theConnect = true;
                connectButtonState |= 1;
            }
            if (item->data(COLUMN_INDEX_CONNECT, Qt::UserRole).toBool() && !theReboot) {
                theReboot = true;
                connectButtonState |= 2;
            }

            DeviceLayer::UpgradePtr upgrad = item->data(COLUMN_INDEX_UPGRADE, Qt::UserRole).value<DeviceLayer::UpgradePtr>();
            if(upgrad) {
                connectButtonState |= 4;
            }
            if(connectButtonState == 7) {
                break;
            }
        }
        ui->connectButton->setEnabled((connectButtonState & 1) == 1);
        ui->configButton->setEnabled(false);
        ui->restartButton->setEnabled((connectButtonState & 2) == 2);
        ui->upgrade->setEnabled((connectButtonState & 4) == 4);
    }
}

void Widget::itemDoubleClicked(QTreeWidgetItem *item, int )
{
    ui->treeWidget->setCurrentItem(item);

    if(m_upgradBtnsState.contains(item)) {
        return;
    }

    if(!item->data(COLUMN_INDEX_CONNECT, Qt::UserRole).toBool()) {
        connectDevice(item);
    }
    else if(item->data(COLUMN_INDEX_CONNECT, Qt::UserRole).toBool()) {
        setDeviceButtonSlot();
    }
}

void Widget::addDevicesInfo(const DeviceLayer::DevBaseInfo &devInfo)
{
    ulong deviceIP = devInfo.GetDeviceIp();
    if (deviceIP > 0) {
        deviceIP = htonl(deviceIP);
    }
    QString strIP = QString(tr("%1")).arg(::inet_ntoa((in_addr&)deviceIP));

    DeviceLayer::DeviceModelPtr pModel(devInfo.GetDeviceModel(), false);
    QString strModelID = pModel->GetModelId().ToString();

    const char* temp = devInfo.GetProp("MAC");
    QString strMac = temp ? temp : "";

    temp = devInfo.GetProp("SN");
    QString strDeviceID = temp ? temp : "";

    QTreeWidgetItem *rootItem = ui->treeWidget->invisibleRootItem();

    for(int i = 0; i < rootItem->childCount(); ++i) {
        QTreeWidgetItem *item = rootItem->child(i);
        DeviceLayer::DevicePtr ptr = item->data(COLUMN_INDEX_MODELID, Qt::UserRole).value<DeviceLayer::DevicePtr>();
        const DeviceLayer::DevBaseInfo *info = ptr->GetBaseInfo();

        ulong newDeviceIP = info->GetDeviceIp();
        if (newDeviceIP > 0) {
            newDeviceIP = htonl(newDeviceIP);
        }
        QString newIP = QString(tr("%1")).arg(::inet_ntoa((in_addr&)newDeviceIP));

        DeviceLayer::DeviceModelPtr newModel(devInfo.GetDeviceModel(), false);
        QString newModelID = newModel->GetModelId().ToString();

        const char* newTemp = info->GetProp("MAC");
        QString newMac = newTemp ? newTemp : "";

        newTemp = info->GetProp("SN");
        QString newDeviceID = newTemp ? newTemp : "";

        if(strModelID == newModelID) {
            bool sameID = false;
            bool sameMac = false;
            if(!strDeviceID.isEmpty() && !newDeviceID.isEmpty() && strDeviceID == newDeviceID) {
                sameID = true;
            }
            if(newMac == strMac) {
                sameMac = true;
            }

            if(sameID || sameMac) {
                if(strIP != newIP) {
                    item->setText(0, strIP);
                    m_discoveryManger.getDeviceManagerPtr()->RemoveDevice(item->data(COLUMN_INDEX_MODELID, Qt::UserRole).value<DeviceLayer::DevicePtr>()->GetDeviceId());
                    DeviceLayer::DevicePtr device(m_discoveryManger.getDeviceManagerPtr()->AddDevice(devInfo), false);
                    if(device) {                        
                        QVariant deviceVariant;
                        deviceVariant.setValue<DeviceLayer::DevicePtr>(device);
                        item->setData(COLUMN_INDEX_MODELID, Qt::UserRole, deviceVariant);

                        DeviceLayer::UpgradePtr upgrade(device->GetUpgrade());
                        QVariant upgradeVariant;
                        upgradeVariant.setValue<DeviceLayer::UpgradePtr>(upgrade);
                        item->setData(COLUMN_INDEX_UPGRADE, Qt::UserRole, upgradeVariant);
                    }
                }
                return;
            }
        }
    }

    QStringList deviceInfos;
    deviceInfos << strIP;
    deviceInfos << strModelID;
    deviceInfos << strMac;
    deviceInfos << strDeviceID;
    deviceInfos << tr("未连接");

    QTreeWidgetItem *devItem = new QTreeWidgetItem(ui->treeWidget, deviceInfos);
    DeviceLayer::DevicePtr device(m_discoveryManger.getDeviceManagerPtr()->AddDevice(devInfo), false);

    if(device) {
        QVariant deviceVariant;
        deviceVariant.setValue<DeviceLayer::DevicePtr>(device);
        devItem->setData(COLUMN_INDEX_MODELID, Qt::UserRole, deviceVariant);

        DeviceLayer::UpgradePtr upgrade(device->GetUpgrade());
        QVariant upgradeVariant;
        upgradeVariant.setValue<DeviceLayer::UpgradePtr>(upgrade);
        devItem->setData(COLUMN_INDEX_UPGRADE, Qt::UserRole, upgradeVariant);

        devItem->setData(COLUMN_INDEX_CONNECT, Qt::UserRole, false);

        devItem->setIcon(0, m_cancleIcon);
    }
    else {
        delete devItem;
    }
}

void Widget::showSetResult(DeviceLayer::IDevice *, bool error)
{
    if(error) {
        QMessageBox::warning(this, tr("配置信息"), tr("配置信息失败,请重新配置!   "));
    }
    else {
        QMessageBox::StandardButton button =
                QMessageBox::warning(this, tr("配置信息"), tr("配置信息成功,重启后方生效,是否重启?"),
                                     QMessageBox::Ok | QMessageBox::Cancel);
        if(button == QMessageBox::Ok) {
            restartButtonSlot();
        }
        selectChanged();
    }
}

void Widget::deviceConnectSuccess(DeviceLayer::IDevice *pDevice, DeviceLayer::IContext *)
{
    QTreeWidgetItem *rootItem = ui->treeWidget->invisibleRootItem();

    for(int i = 0; i < rootItem->childCount(); ++i) {

        QTreeWidgetItem *item = rootItem->child(i);        
        DeviceLayer::DevicePtr device = item->data(COLUMN_INDEX_MODELID, Qt::UserRole).value<DeviceLayer::DevicePtr>();
        DeviceLayer::UpgradePtr upgrade = item->data(COLUMN_INDEX_UPGRADE, Qt::UserRole).value<DeviceLayer::UpgradePtr>();

        if(!upgrade) {
            DeviceLayer::UpgradePtr upgrade(device->GetUpgrade());
            QVariant upgradeVariant;
            upgradeVariant.setValue<DeviceLayer::UpgradePtr>(upgrade);
            item->setData(COLUMN_INDEX_UPGRADE, Qt::UserRole, upgradeVariant);
        }

        if(device == pDevice) {
            item->setIcon(0, m_okIcon);
            item->setText(COLUMN_INDEX_CONNECT, tr("已连接"));
            item->setData(COLUMN_INDEX_CONNECT, Qt::UserRole, true);
            break;
        }
    }
    selectChanged();
}

void Widget::deviceConnectFailed(DeviceLayer::IDevice *pDevice, DeviceLayer::DLResult , DeviceLayer::IContext *)
{
    QTreeWidgetItem *rootItem = ui->treeWidget->invisibleRootItem();

    for(int i = 0; i < rootItem->childCount(); ++i) {
        QTreeWidgetItem *item = rootItem->child(i);
        DeviceLayer::DevicePtr device = item->data(COLUMN_INDEX_MODELID, Qt::UserRole).value<DeviceLayer::DevicePtr>();

        if(device == pDevice) {
            ui->connectButton->setEnabled(true);
            item->setIcon(0, m_cancleIcon);
            item->setText(COLUMN_INDEX_CONNECT, tr("连接失败"));
            break;
        }
    }
    selectChanged();
}

void Widget::deviceLoseConnect(DeviceLayer::IDevice *pDevice, DeviceLayer::DLResult )
{
    QTreeWidgetItem *rootItem = ui->treeWidget->invisibleRootItem();

    for(int i = 0; i < rootItem->childCount(); ++i) {
        QTreeWidgetItem *item = rootItem->child(i);
        DeviceLayer::DevicePtr device = item->data(COLUMN_INDEX_MODELID, Qt::UserRole).value<DeviceLayer::DevicePtr>();
        QVariant variant;
        DeviceLayer::UpgradePtr upgrade(device->GetUpgrade());
        variant.setValue<DeviceLayer::UpgradePtr>(upgrade);
        item->setData(COLUMN_INDEX_UPGRADE, Qt::UserRole, variant);

        if(device == pDevice) {
            item->setIcon(0, m_cancleIcon);
            item->setText(COLUMN_INDEX_CONNECT, tr("连接断开"));
            item->setData(COLUMN_INDEX_CONNECT, Qt::UserRole, false);
            break;
        }
    }
    selectChanged();
}

void Widget::started(DeviceLayer::IDevice *device, DeviceLayer::IContext *)
{
    // 启动成后，才会由后边的回调
    QTreeWidgetItem *rootItem = ui->treeWidget->invisibleRootItem();

    for(int i = 0; i < rootItem->childCount(); ++i) {
        QTreeWidgetItem *item = rootItem->child(i); 
        DeviceLayer::DevicePtr itemDevice = item->data(COLUMN_INDEX_MODELID, Qt::UserRole).value<DeviceLayer::DevicePtr>();
        if(itemDevice == device) {
            item->setText(COLUMN_INDEX_UPGRADE, tr("开始升级"));
            break;
        }
    }
}

void Widget::startFailed(DeviceLayer::IDevice *device, DeviceLayer::DLResult , DeviceLayer::IContext *)
{
    //启动失败， 没有其余任何的事件， 恢复按钮状态
    QTreeWidgetItem *rootItem = ui->treeWidget->invisibleRootItem();
    for(int i = 0; i < rootItem->childCount(); ++i) {
        QTreeWidgetItem *item = rootItem->child(i);
        DeviceLayer::DevicePtr itemDevice = item->data(COLUMN_INDEX_MODELID, Qt::UserRole).value<DeviceLayer::DevicePtr>();
        if(itemDevice == device) {
            item->setText(COLUMN_INDEX_UPGRADE, tr("启动升级失败"));
            m_upgradBtnsState.removeOne(item);
            break;
        }
    }
    selectChanged();
}

void Widget::notifyProcessing(DeviceLayer::IDevice *device, const char *desc, DeviceLayer::IContext *)
{    
    QTreeWidgetItem *rootItem = ui->treeWidget->invisibleRootItem();
    QString text(desc);
    for(int i = 0; i < rootItem->childCount(); ++i) {
        QTreeWidgetItem *item = rootItem->child(i);
        DeviceLayer::DevicePtr itemDevice = item->data(COLUMN_INDEX_MODELID, Qt::UserRole).value<DeviceLayer::DevicePtr>();
        if(itemDevice == device) {
            item->setText(COLUMN_INDEX_UPGRADE, text);
            break;
        }
    }
}

void Widget::faults(DeviceLayer::IDevice *device, DeviceLayer::IContext *)
{
    // 恢复之前状态
    QTreeWidgetItem *rootItem = ui->treeWidget->invisibleRootItem();
    for(int i = 0; i < rootItem->childCount(); ++i) {
        QTreeWidgetItem *item = rootItem->child(i);
        DeviceLayer::DevicePtr itemDevice = item->data(COLUMN_INDEX_MODELID, Qt::UserRole).value<DeviceLayer::DevicePtr>();
        if(itemDevice == device) {
            item->setText(COLUMN_INDEX_UPGRADE, tr("升级失败"));
            m_upgradBtnsState.removeOne(item);
            break;
        }
    }
    selectChanged();
}

void Widget::completed(DeviceLayer::IDevice *device, DeviceLayer::IContext *)
{
    QTreeWidgetItem *rootItem = ui->treeWidget->invisibleRootItem();
    for(int i = 0; i < rootItem->childCount(); ++i) {
        QTreeWidgetItem *item = rootItem->child(i);
        DeviceLayer::DevicePtr itemDevice = item->data(COLUMN_INDEX_MODELID, Qt::UserRole).value<DeviceLayer::DevicePtr>();
        if(itemDevice == device) {
            item->setText(COLUMN_INDEX_UPGRADE, tr("升级成功"));
            m_upgradBtnsState.removeOne(item);
            break;
        }
    }
    selectChanged();
}
