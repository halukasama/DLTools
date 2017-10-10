#include "widget.h"
#include <QApplication>
#include <QTranslator>
#include <QDesktopWidget>
#include <DeviceLayer.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QPoint point = a.desktop()->availableGeometry().center();
    w.move(point.x() - (w.width() / 2), point.y() - (w.height() / 2));
    w.show();

    QTranslator* translator = new QTranslator(&a);
    if(translator->load(":/languages/res/qt_zh_CN"))
    {
        a.installTranslator(translator);
    }
    
    int ret = a.exec();
    DeviceLayer::DeviceLayerPtr devLayer(DeviceLayer::QueryDeviceLayer(), false);
    if(devLayer)
    {
        devLayer->FiniDeviceLayer();
    }
    return ret;
}
