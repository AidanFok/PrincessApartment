#ifndef ALPHASERVICE_H
#define ALPHASERVICE_H

#include <QDialog>
#include "alphabookwater.h"
#include "alphanotice.h"
#include "alphasendnotice.h"
namespace Ui {
class Alphaservice;
}

class Alphaservice : public QDialog
{
    Q_OBJECT

public:
    explicit Alphaservice(QWidget *parent = 0);
    ~Alphaservice();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Alphaservice *ui;
    Alphabookwater alphawater;
    Alphanotice alphanotices;
    Alphasendnotice alphasendnotices;
};

#endif // ALPHASERVICE_H
