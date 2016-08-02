#ifndef ESTABLISHSTU_H
#define ESTABLISHSTU_H

#include <QDialog>
namespace Ui {
class Establishstu;
}

class Establishstu : public QDialog
{
    Q_OBJECT

public:
    explicit Establishstu(QWidget *parent = 0);
    ~Establishstu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Establishstu *ui;
};

#endif // ESTABLISHSTU_H
