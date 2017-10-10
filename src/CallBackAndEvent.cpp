#include "CallBackAndEvent.h"

#include <QEvent>
#include <QMouseEvent>

bool RightDoubleClicked::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonRelease ||
           event->type() == QEvent::MouseButtonDblClick){
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if(mouseEvent->button() == Qt::RightButton) {
            return true;
        }
    }
    return obj->eventFilter(obj, event);
}

//connect
void DeviceConnectCallBack::OnDeviceConnected(DeviceLayer::IDevice *pDevice, DeviceLayer::IContext *context)
{
    emit deviceConnectSuccess(pDevice, context);
}

void DeviceConnectCallBack::OnDeviceConnectFailed(DeviceLayer::IDevice *pDevice, DeviceLayer::DLResult result, DeviceLayer::IContext *context)
{
    emit deviceConnectFailed(pDevice, result, context);
}

void DeviceConnectCallBack::OnDeviceAccepted(DeviceLayer::IDevice *)
{
}

void DeviceConnectCallBack::OnDeviceDisconnected(DeviceLayer::IDevice *, DeviceLayer::IContext *)
{
}

void DeviceConnectCallBack::OnDeviceLoseConnection(DeviceLayer::IDevice *pDevice, DeviceLayer::DLResult result)
{
    emit deviceLoseConnect(pDevice, result);
}

// upgrade
void UpgradeDeviceCallback::OnUpgradeStarted(DeviceLayer::IDevice *device, DeviceLayer::IContext *pContext)
{
    emit started(device, pContext);
}

void UpgradeDeviceCallback::OnUpgradeStartFailed(DeviceLayer::IDevice *device, DeviceLayer::DLResult result, DeviceLayer::IContext *pContext)
{
    emit startFailed(device, result, pContext);
}

void UpgradeDeviceCallback::OnUpgradeNotifyProcessing(DeviceLayer::IDevice *device, const char *desc, DeviceLayer::IContext *pContext)
{
    emit notifyProcessing(device, desc, pContext);
}

void UpgradeDeviceCallback::OnUpgradeFaults(DeviceLayer::IDevice *device, DeviceLayer::IContext *pContext)
{
    emit faults(device, pContext);
}

void UpgradeDeviceCallback::OnUpgradeCompleted(DeviceLayer::IDevice *device, DeviceLayer::IContext *pContext)
{
    emit completed(device, pContext);
}

