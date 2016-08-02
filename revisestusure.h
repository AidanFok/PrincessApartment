#ifndef REVISESTUSURE_H
#define REVISESTUSURE_H

#include <QDialog>

namespace Ui {
class Revisestusure;
}

class Revisestusure : public QDialog
{
    Q_OBJECT

public:
    explicit Revisestusure(QWidget *parent = 0);
    ~Revisestusure();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Revisestusure *ui;
};

#endif // REVISESTUSURE_H
