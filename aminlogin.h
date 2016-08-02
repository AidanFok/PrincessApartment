#ifndef AMINLOGIN_H
#define AMINLOGIN_H

#include <QDialog>
#include "aminmainwindows.h"
namespace Ui {
class Aminlogin;
}

class Aminlogin : public QDialog
{
    Q_OBJECT

public:
    explicit Aminlogin(QWidget *parent = 0);
    ~Aminlogin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Aminlogin *ui;
    Aminmainwindows Aminmainwindow;
};

#endif // AMINLOGIN_H
