#ifndef ALPHANOTICE_H
#define ALPHANOTICE_H

#include <QDialog>

namespace Ui {
class Alphanotice;
}

class Alphanotice : public QDialog
{
    Q_OBJECT

public:
    explicit Alphanotice(QWidget *parent = 0);
    ~Alphanotice();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Alphanotice *ui;
};

#endif // ALPHANOTICE_H
