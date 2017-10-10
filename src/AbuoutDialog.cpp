#include "AbuoutDialog.h"
#include "ui_AbuoutDialog.h"

#include <QFileInfo>
#include <QDateTime>

#define CURRENT_VERISION    "1.0.0.10"

AbuoutDialog::AbuoutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AbuoutDialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("关于 设备工具箱"));
    connect(ui->btnOk, SIGNAL(clicked()), this, SLOT(accept()));

    QSize sz = size();
    setMinimumSize(sz);
    setMaximumSize(sz);

    QFileInfo fi(QCoreApplication::applicationFilePath());
    ui->labelVersion->setText(tr("软件版本: %1\n修改时间: %2")
                              .arg(CURRENT_VERISION, fi.lastModified().toString("yyyy-MM-dd hh:mm:ss")));
}

AbuoutDialog::~AbuoutDialog()
{
    delete ui;
}
