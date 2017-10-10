#ifndef BATCHCODECDEVICEDISCOVERYMANAGER_H
#define BATCHCODECDEVICEDISCOVERYMANAGER_H

#include <QObject>
#include <DeviceLayer.h>
#include <ObjectsPtr.h>

class BatchCodecDeviceDiscoveryManager : public QObject
                                        , protected DeviceLayer::IDeviceDiscoveryCallback
{
    Q_OBJECT
public:
    BatchCodecDeviceDiscoveryManager();
    ~BatchCodecDeviceDiscoveryManager();

    virtual bool startDiscoverDevices();
    virtual bool stopDiscoverDevices();

    DeviceLayer::DeviceDiscoveryManagerPtr getDeviceDiscoveryManagerPtr()
    {
        return m_deviceDiscoveryManager;
    }

    DeviceLayer::DeviceManagerPtr getDeviceManagerPtr();

protected:
    void initialize();
signals:
    void foundDevices(const DeviceLayer::DevBaseInfo &devInfo);
protected:
    virtual void OnDeviceFound(const DeviceLayer::DevBaseInfo &devInfo, DeviceLayer::IDeviceDiscoveryManager *pDiscoveryManager);
private:
    DeviceLayer::DeviceManagerPtr m_devManager;
    DeviceLayer::DeviceLayerPtr m_deviceLayer;
    DeviceLayer::DeviceDiscoveryManagerPtr m_deviceDiscoveryManager;
    bool m_startedDiscovery;
};

#endif // BATCHCODECDEVICEDISCOVERYMANAGER_H
