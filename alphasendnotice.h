#ifndef ALPHASENDNOTICE_H
#define ALPHASENDNOTICE_H

#include <QDialog>

namespace Ui {
class Alphasendnotice;
}

class Alphasendnotice : public QDialog
{
    Q_OBJECT

public:
    explicit Alphasendnotice(QWidget *parent = 0);
    ~Alphasendnotice();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Alphasendnotice *ui;
};

#endif // ALPHASENDNOTICE_H
