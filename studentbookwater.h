#ifndef STUDENTBOOKWATER_H
#define STUDENTBOOKWATER_H

#include <QDialog>

namespace Ui {
class Studentbookwater;
}

class Studentbookwater : public QDialog
{
    Q_OBJECT

public:
    explicit Studentbookwater(QWidget *parent = 0);
    ~Studentbookwater();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Studentbookwater *ui;
};

#endif // STUDENTBOOKWATER_H
