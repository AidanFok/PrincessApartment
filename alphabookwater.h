#ifndef ALPHABOOKWATER_H
#define ALPHABOOKWATER_H

#include <QDialog>

namespace Ui {
class Alphabookwater;
}

class Alphabookwater : public QDialog
{
    Q_OBJECT

public:
    explicit Alphabookwater(QWidget *parent = 0);
    ~Alphabookwater();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Alphabookwater *ui;
};

#endif // ALPHABOOKWATER_H
