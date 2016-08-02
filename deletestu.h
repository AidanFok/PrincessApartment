#ifndef DELETESTU_H
#define DELETESTU_H

#include <QDialog>

namespace Ui {
class Deletestu;
}

class Deletestu : public QDialog
{
    Q_OBJECT

public:
    explicit Deletestu(QWidget *parent = 0);
    ~Deletestu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Deletestu *ui;
};

#endif // DELETESTU_H
