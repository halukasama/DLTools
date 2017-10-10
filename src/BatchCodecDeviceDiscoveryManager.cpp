#include "BatchCodecDeviceDiscoveryManager.h"

#include <DeviceLayerHelper.h>

BatchCodecDeviceDiscoveryManager::BatchCodecDeviceDiscoveryManager()
    :m_startedDiscovery(false)
{
    qRegisterMetaType<DeviceLayer::DevBaseInfo>("DeviceLayer::DevBaseInfo");
}

BatchCodecDeviceDiscoveryManager::~BatchCodecDeviceDiscoveryManager()
{
    if (m_deviceDiscoveryManager)
    {
        stopDiscoverDevices();
        m_deviceDiscoveryManager->SetCallback(NULL);
        m_deviceDiscoveryManager->ClearDiscoveryPorts();
        m_deviceDiscoveryManager.Reset();
    }
}

void* opendl(const char* path);

bool BatchCodecDeviceDiscoveryManager::startDiscoverDevices()
{
    initialize();

    DeviceLayer::DLResult ret;
    if (!m_startedDiscovery)
        ret = m_deviceDiscoveryManager->StartDiscovery();
    else
        ret = m_deviceDiscoveryManager->RefreshDiscovery();
    if (DLR_SUCCESS(ret) && !m_startedDiscovery)
        m_startedDiscovery = true;

    return m_startedDiscovery;
}

bool BatchCodecDeviceDiscoveryManager::stopDiscoverDevices()
{
    if (!m_deviceDiscoveryManager)
        return true;

    DeviceLayer::DLResult ret = m_deviceDiscoveryManager->StopDiscovery();
    if (DLR_SUCCESS(ret))
        m_startedDiscovery = false;
    else
        m_startedDiscovery = true;

    return true;
}

DeviceLayer::DeviceManagerPtr BatchCodecDeviceDiscoveryManager::getDeviceManagerPtr()
{
    if(!m_devManager) {
        m_devManager = DeviceLayer::DeviceManagerPtr(m_deviceLayer->CreateDeviceManager());
    }
    return m_devManager;
}

void BatchCodecDeviceDiscoveryManager::initialize()
{
    if(!m_deviceLayer)
    {
        m_deviceLayer = DeviceLayer::DeviceLayerPtr(DeviceLayer::QueryDeviceLayer(), false);
    }
    Q_ASSERT(m_deviceLayer);

    if(!m_deviceDiscoveryManager)
    {
        m_deviceDiscoveryManager = DeviceLayer::DeviceDiscoveryManagerPtr(m_deviceLayer->CreateDiscoveryManager(), false);
        m_deviceDiscoveryManager->SetCallback((IDeviceDiscoveryCallback*)this);
        m_deviceDiscoveryManager->AddDefaultDiscoveryPorts();
    }
    Q_ASSERT(m_deviceDiscoveryManager);
}

void BatchCodecDeviceDiscoveryManager::OnDeviceFound(const DeviceLayer::DevBaseInfo &devInfo, DeviceLayer::IDeviceDiscoveryManager *)
{
    emit foundDevices(devInfo);
}
