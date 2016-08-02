#ifndef STUDENTMAINWINDOWS_H
#define STUDENTMAINWINDOWS_H

#include <QDialog>
#include "findstu.h"
#include "summarystu.h"
#include "studentservice.h"
namespace Ui {
class Studentmainwindows;
}

class Studentmainwindows : public QDialog
{
    Q_OBJECT

public:
    explicit Studentmainwindows(QWidget *parent = 0);
    ~Studentmainwindows();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Studentmainwindows *ui;
    Findstu findstudent;
    Summarystu summarystudent;
    Studentservice studentservices;
};

#endif // STUDENTMAINWINDOWS_H
