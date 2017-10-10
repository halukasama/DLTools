#ifndef ABUOUTDIALOG_H
#define ABUOUTDIALOG_H

#include <QDialog>

namespace Ui {
class AbuoutDialog;
}

class AbuoutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AbuoutDialog(QWidget *parent = 0);
    ~AbuoutDialog();

private:
    Ui::AbuoutDialog *ui;
};

#endif // ABUOUTDIALOG_H
