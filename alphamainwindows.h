#ifndef ALPHAMAINWINDOWS_H
#define ALPHAMAINWINDOWS_H

#include <QDialog>
#include "establishstu.h"
#include "findstu.h"
#include "summarystu.h"
#include "revisestu.h"
#include "deletestu.h"
#include "alphaservice.h"
namespace Ui {
class Alphamainwindows;
}

class Alphamainwindows : public QDialog
{
    Q_OBJECT

public:
    explicit Alphamainwindows(QWidget *parent = 0);
    ~Alphamainwindows();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Alphamainwindows *ui;
    Establishstu establishstudent;
    Findstu findstudent;
    Summarystu summarystudent;
    Revisestu revisestudent;
    Deletestu deletestudent;
    Alphaservice alphaser;

};

#endif // ALPHAMAINWINDOWS_H
