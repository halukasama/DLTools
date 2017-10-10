#ifndef CALLBACKANDEVENT_H
#define CALLBACKANDEVENT_H
#include <QObject>
#include <DeviceLayer.h>
#include <DeviceLayerDef.h>
#include "BatchCodecDeviceDiscoveryManager.h"

class RightDoubleClicked : public QObject
{
    Q_OBJECT
protected:
    bool eventFilter(QObject *obj, QEvent *event);
};



class DeviceConnectCallBack :public QObject, public DeviceLayer::IDeviceConnectionCallback {
    Q_OBJECT
public:
    virtual void OnDeviceConnected(DeviceLayer::IDevice* pDevice, DeviceLayer::IContext*context);
    virtual void OnDeviceConnectFailed(DeviceLayer::IDevice*, DeviceLayer::DLResult result, DeviceLayer::IContext*);
    virtual void OnDeviceAccepted(DeviceLayer::IDevice* );
    virtual void OnDeviceDisconnected(DeviceLayer::IDevice*, DeviceLayer::IContext* );
    virtual void OnDeviceLoseConnection(DeviceLayer::IDevice* , DeviceLayer::DLResult );

signals:
    void deviceConnectSuccess(DeviceLayer::IDevice* , DeviceLayer::IContext*);
    void deviceConnectFailed(DeviceLayer::IDevice*, DeviceLayer::DLResult, DeviceLayer::IContext*);
    void deviceLoseConnect(DeviceLayer::IDevice* , DeviceLayer::DLResult);
};


class UpgradeDeviceCallback : public QObject, public DeviceLayer::IUpgradeCallback
{
    Q_OBJECT
public:
    virtual void OnUpgradeStarted(DeviceLayer::IDevice* device, DeviceLayer::IContext* pContext); //cheng
    virtual void OnUpgradeStartFailed(DeviceLayer::IDevice* device, DeviceLayer::DLResult result, DeviceLayer::IContext* pContext); //shi
    virtual void OnUpgradeNotifyProcessing(DeviceLayer::IDevice* device, const char* desc, DeviceLayer::IContext* pContext);
    virtual void OnUpgradeFaults(DeviceLayer::IDevice* device, DeviceLayer::IContext* pContext);
    virtual void OnUpgradeCompleted(DeviceLayer::IDevice* device, DeviceLayer::IContext* pContext);

signals:
    void started(DeviceLayer::IDevice* device, DeviceLayer::IContext* pContext);
    void startFailed(DeviceLayer::IDevice* device, DeviceLayer::DLResult result, DeviceLayer::IContext* pContext);
    void notifyProcessing(DeviceLayer::IDevice* device, const char* desc, DeviceLayer::IContext* pContext);
    void faults(DeviceLayer::IDevice* device, DeviceLayer::IContext* pContext);
    void completed(DeviceLayer::IDevice* device, DeviceLayer::IContext* pContext);
};


#endif // CALLBACKANDEVENT_H
