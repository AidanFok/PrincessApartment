#ifndef FINDSTU_H
#define FINDSTU_H

#include <QDialog>

namespace Ui {
class Findstu;
}

class Findstu : public QDialog
{
    Q_OBJECT

public:
    explicit Findstu(QWidget *parent = 0);
    ~Findstu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Findstu *ui;
};

#endif // FINDSTU_H
