#ifndef CHANGEALPHA_H
#define CHANGEALPHA_H

#include <QDialog>

namespace Ui {
class Changealpha;
}

class Changealpha : public QDialog
{
    Q_OBJECT

public:
    explicit Changealpha(QWidget *parent = 0);
    ~Changealpha();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    
private:
    Ui::Changealpha *ui;
};

#endif // CHANGEALPHA_H
