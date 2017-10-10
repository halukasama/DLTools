#include "ConfigDialog.h"
#include "ui_ConfigDialog.h"

#include <arpa/inet.h>
#include <QDebug>
#include <ConfigTargets.h>
#include <QCloseEvent>
#include <QAbstractButton>
#include <QPushButton>
#include <QLabel>

Context::Context(ContextDo contextDo)
{
    m_contextDo = contextDo;
}

Context::~Context()
{
}

ContextDo Context::getContextDo()
{
    return m_contextDo;
}

void ConfigCallBack::OnConfigureComplete(DeviceLayer::IDevice *pDevice, const DeviceLayer::ConfigParams &params, DeviceLayer::IContext *pContext)
{
    Context *context = static_cast<Context *>(pContext);
    if(!context) {
        return;
    }

    if(context->getContextDo() == DO_GET_CONFIG) {
        QStringList paramsList;
        paramsList << params.GetGetAction(DLCT_NET_IPADDRESS).GetValue().ToString();
        paramsList << params.GetGetAction(DLCT_NET_SUBNETMASK).GetValue().ToString();
        paramsList << params.GetGetAction(DLCT_NET_GATEWAY).GetValue().ToString();
        emit configInfo(pDevice, paramsList);
    }
    else if(context->getContextDo() == DO_SET_CONFIG) {
        if(params.GetSetAction(DLCT_NET_IPADDRESS).GetResult() != DeviceLayer::DLR_S_OK ||
           params.GetSetAction(DLCT_NET_SUBNETMASK).GetResult() != DeviceLayer::DLR_S_OK ||
           params.GetSetAction(DLCT_NET_GATEWAY).GetResult() != DeviceLayer::DLR_S_OK) {
            emit setConfigInfoResult(pDevice, true);
        }
        else {
            emit setConfigInfoResult(pDevice, false);
        }
    }
}

void ConfigCallBack::OnConfigurePending(DeviceLayer::IDevice* pDevice, DeviceLayer::IContext* pContext)
{
}



ConfigDialog::ConfigDialog(DeviceLayer::DeviceManagerPtr manager, DeviceLayer::DevicePtr device,QWidget *parent)
    : QDialog(parent)
    , m_devManager(manager)
    , m_pDevice(device)
    , m_bChanged(false)
    , ui(new Ui::ConfigDialog)
{
    ui->setupUi(this);

    m_pLabel = new QLabel(tr("正在获取数组,请等待......."), this);
    m_pLabel->resize(180, m_pLabel->size().height());
    m_pLabel->move(10, 155);
    m_pLabel->show();

    m_devManager->SetCallback(&m_configCallBack);
    connect(&m_configCallBack, &ConfigCallBack::configInfo,
            this, &ConfigDialog::showDeviceInfo, Qt::BlockingQueuedConnection);
    connect(&m_configCallBack, &ConfigCallBack::setConfigInfoResult,
            this, &ConfigDialog::setDeviceInfo, Qt::BlockingQueuedConnection);

    DeviceLayer::ConfigPtr config(m_pDevice->GetConfig(), false);
    if(!config) {
        qDebug() << "Restart the config is Null";
        return;
    }

    DeviceLayer::ConfigParams configParams;
    configParams.AddGetAction(DLCT_NET_IPADDRESS);
    configParams.AddGetAction(DLCT_NET_SUBNETMASK);
    configParams.AddGetAction(DLCT_NET_GATEWAY);
    DeviceLayer::DLResult result = config->Configure(configParams, new Context(DO_GET_CONFIG));
    if(result != DeviceLayer::DLR_S_OK) {
        qDebug() << "Get Device Info is Error";
        return;
    }
}


ConfigDialog::~ConfigDialog()
{
    m_devManager->SetCallback((DeviceLayer::IConfigCallback*)NULL);
    delete ui;
}

void ConfigDialog::setParams(QStringList paramsList)
{
    ui->ipLineEdit->setText(paramsList.value(0));
    ui->subnetLineEdit->setText(paramsList.value(1));
    ui->gatewayLineEdit->setText(paramsList.value(2));

    ui->ipLineEdit->setEnabled(true);
    ui->subnetLineEdit->setEnabled(true);
    ui->gatewayLineEdit->setEnabled(true);

    connect(ui->ipLineEdit, SIGNAL(textChanged(QString)), SLOT(lineEditChangedSlot()));
    connect(ui->subnetLineEdit, SIGNAL(textChanged(QString)), SLOT(lineEditChangedSlot()));
    connect(ui->gatewayLineEdit, SIGNAL(textChanged(QString)), SLOT(lineEditChangedSlot()));
}

DeviceLayer::ConfigParams ConfigDialog::getConfigParams()
{
    DeviceLayer::ConfigParams configParams;
    if(m_bChanged) {
        DeviceLayer::ConfigValue valueIP(ui->ipLineEdit->text().toUtf8().constData());
        configParams.AddSetAction(valueIP, DLCT_NET_IPADDRESS);

        DeviceLayer::ConfigValue valueSub(ui->subnetLineEdit->text().toUtf8().constData());
        configParams.AddSetAction(valueSub, DLCT_NET_SUBNETMASK);

        DeviceLayer::ConfigValue valueGate(ui->gatewayLineEdit->text().toUtf8().constData());
        configParams.AddSetAction(valueGate, DLCT_NET_GATEWAY);

        configParams.AddInvokeAction(DLCT_SAVECONFIG);
    }
    return configParams;
}

void ConfigDialog::accept()
{
    DeviceLayer::ConfigPtr config(m_pDevice->GetConfig(), false);
    if(!config) {
        qDebug() << "The get config is null for accept";
        close();
        return;
    }

    DeviceLayer::ConfigParams configParams = getConfigParams();
    if( configParams.GetActionCount() == 0) {
        qDebug() << "Get params is Null, not hava changed";
        close();
        return;
    }

    DeviceLayer::DLResult result = config->Configure(configParams, new Context(DO_SET_CONFIG));
    if(result != DeviceLayer::DLR_S_OK) {
        qDebug() << "Set Device Info is Error, the value is " << result;
        close();
    }
    this->setEnabled(false);
}

void ConfigDialog::lineEditChangedSlot()
{
    m_bChanged = true;
}

void ConfigDialog::showDeviceInfo(DeviceLayer::IDevice *pDevice, QStringList paramsList)
{
    if(m_pDevice == pDevice && !paramsList.value(0).isEmpty()) {
        setParams(paramsList);
        m_bChanged = false;
        m_pLabel->hide();
    }
    else if (m_pDevice == pDevice){
        m_pLabel->setText(tr("获取设备配置信息失败!"));
    }
}

void ConfigDialog::setDeviceInfo(DeviceLayer::IDevice *pDevice, bool error)
{
    if(m_pDevice == pDevice) {
        emit setDeviceResult(pDevice, error);
        close();
    }
}
