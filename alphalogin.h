#ifndef ALPHALOGIN_H
#define ALPHALOGIN_H

#include <QDialog>
#include "alphamainwindows.h"

namespace Ui {
class Alphalogin;
}

class Alphalogin : public QDialog
{
    Q_OBJECT

public:
    explicit Alphalogin(QWidget *parent = 0);
    ~Alphalogin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Alphalogin *ui;
    Alphamainwindows alphamainwindow;
};

#endif // ALPHALOGIN_H
