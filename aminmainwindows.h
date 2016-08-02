#ifndef AMINMAINWINDOWS_H
#define AMINMAINWINDOWS_H

#include <QDialog>
#include "changealpha.h"
namespace Ui {
class Aminmainwindows;
}

class Aminmainwindows : public QDialog
{
    Q_OBJECT

public:
    explicit Aminmainwindows(QWidget *parent = 0);
    ~Aminmainwindows();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Aminmainwindows *ui;
    Changealpha changealp;
};

#endif // AMINMAINWINDOWS_H
