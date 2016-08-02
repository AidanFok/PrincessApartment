#ifndef SUMMARYSTU_H
#define SUMMARYSTU_H

#include <QDialog>

namespace Ui {
class Summarystu;
}

class Summarystu : public QDialog
{
    Q_OBJECT

public:
    explicit Summarystu(QWidget *parent = 0);
    ~Summarystu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Summarystu *ui;
};

#endif // SUMMARYSTU_H
