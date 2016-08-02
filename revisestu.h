#ifndef REVISESTU_H
#define REVISESTU_H

#include <QDialog>
#include "revisestusure.h"
namespace Ui {
class Revisestu;
}

class Revisestu : public QDialog
{
    Q_OBJECT

public:
    explicit Revisestu(QWidget *parent = 0);
    ~Revisestu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Revisestu *ui;
    Revisestusure revisesure;
};

#endif // REVISESTU_H
