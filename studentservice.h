#ifndef STUDENTSERVICE_H
#define STUDENTSERVICE_H

#include <QDialog>
#include "studentbookwater.h"
#include "alphanotice.h"
namespace Ui {
class Studentservice;
}

class Studentservice : public QDialog
{
    Q_OBJECT

public:
    explicit Studentservice(QWidget *parent = 0);
    ~Studentservice();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Studentservice *ui;
    Alphanotice alphanotices;
    Studentbookwater studentbookwaters;
};

#endif // STUDENTSERVICE_H
