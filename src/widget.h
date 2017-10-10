#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <DeviceLayer.h>
#include <DeviceLayerDef.h>
#include "BatchCodecDeviceDiscoveryManager.h"
#include <QMap>
#include "CallBackAndEvent.h"
class QTreeWidgetItem;
class QLabel;
class QMenu;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    void initDialog();

protected:
    void closeEvent(QCloseEvent * event);

private:
    void upgradeDevice(QList<QTreeWidgetItem *> items, const QString &fileName);
    void connectDevice(QList<QTreeWidgetItem *> items);
    void connectDevice(QTreeWidgetItem * item);
    
private slots:
    void findAndStopButtonSlot();
    void refreshButtonSlot();
    void clearAllDeviceSlot();
    void connectButtonSlot();
    void setDeviceButtonSlot();
    void restartButtonSlot();
    void upgradeButtonSolt();
    void aboutButtonSolt();
    void upgradeActionFile(QAction *);

    void selectChanged();
    void changedButtonState(QList<QTreeWidgetItem *> items);
    void itemDoubleClicked(QTreeWidgetItem *item, int);

    // find device and connect device back
    void addDevicesInfo(const DeviceLayer::DevBaseInfo &info);
    void showSetResult(DeviceLayer::IDevice *, bool error);
    void deviceConnectSuccess(DeviceLayer::IDevice* pDevice, DeviceLayer::IContext*);
    void deviceConnectFailed(DeviceLayer::IDevice* pDevice, DeviceLayer::DLResult, DeviceLayer::IContext*);
    void deviceLoseConnect(DeviceLayer::IDevice* pDevice, DeviceLayer::DLResult);

    // upgrade
    void started(DeviceLayer::IDevice* device, DeviceLayer::IContext*);
    void startFailed(DeviceLayer::IDevice* device, DeviceLayer::DLResult, DeviceLayer::IContext*);
    void notifyProcessing(DeviceLayer::IDevice* device, const char* desc, DeviceLayer::IContext*);
    void faults(DeviceLayer::IDevice* device, DeviceLayer::IContext*);
    void completed(DeviceLayer::IDevice* device, DeviceLayer::IContext*);

private:
    Ui::Widget *ui;

private:
    BatchCodecDeviceDiscoveryManager m_discoveryManger;
    DeviceConnectCallBack m_deviceConnectBack;
    UpgradeDeviceCallback m_deviceUpgradBack;
    QPixmap m_okIcon;
    QPixmap m_cancleIcon;

    QList <QTreeWidgetItem *> m_upgradBtnsState;
    QMenu *m_upgradMenu;
    bool m_findButtonState;
};

#endif // WIDGET_H
