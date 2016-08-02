#ifndef STUDENTLOGIN_H
#define STUDENTLOGIN_H

#include <QDialog>
#include "studentmainwindows.h"
namespace Ui {
class Studentlogin;
}

class Studentlogin : public QDialog
{
    Q_OBJECT

public:

    explicit Studentlogin(QWidget *parent = 0);
    ~Studentlogin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Studentlogin *ui;
    Studentmainwindows Studentmainwindow;
};

#endif // STUDENTLOGIN_H
