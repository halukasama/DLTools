#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>
#include <ObjectsPtr.h>
#include <DeviceLayer.h>
#include <DeviceLayerDef.h>

class QLabel;

enum ContextDo{
    DO_GET_CONFIG,
    DO_SET_CONFIG
};

class Context : public DeviceLayer::IContext {
public :
    Context(ContextDo contextDo);
    ~Context();

public:
    ContextDo getContextDo();

private:
    ContextDo m_contextDo;
};


class ConfigCallBack :public QObject, public DeviceLayer::IConfigCallback {
    Q_OBJECT
protected:
    virtual void OnConfigureComplete(DeviceLayer::IDevice* pDevice, const DeviceLayer::ConfigParams& params, DeviceLayer::IContext* pContext);
    virtual void OnConfigurePending(DeviceLayer::IDevice* pDevice, DeviceLayer::IContext* pContext);
signals:
    void configInfo(DeviceLayer::IDevice *pDevice, QStringList paramsList);
    void setConfigInfoResult(DeviceLayer::IDevice *pDevice, bool error);
};


class QAbstractButton;
namespace Ui {
class ConfigDialog;
}

class ConfigDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ConfigDialog(DeviceLayer::DeviceManagerPtr, DeviceLayer::DevicePtr, QWidget *parent = 0);
    ~ConfigDialog();

public:
    void setParams(QStringList paramsList);
    DeviceLayer::ConfigParams getConfigParams();

private slots:
    void accept();

private slots:
    void lineEditChangedSlot();
    void showDeviceInfo(DeviceLayer::IDevice *pDevice, QStringList paramsList);
    void setDeviceInfo(DeviceLayer::IDevice *pDevice, bool error);

signals:
    void setDeviceResult(DeviceLayer::IDevice *pDevice, bool error);

private:
    DeviceLayer::DeviceManagerPtr m_devManager;
    DeviceLayer::DevicePtr m_pDevice;
    ConfigCallBack m_configCallBack;
    QLabel *m_pLabel;
    bool m_bChanged;

private:
    Ui::ConfigDialog *ui;
};

#endif // CONFIGDIALOG_H
