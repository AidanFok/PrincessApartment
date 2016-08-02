#include "aminmainwindows.h"
#include "ui_aminmainwindows.h"

Aminmainwindows::Aminmainwindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Aminmainwindows)
{
    ui->setupUi(this);
    QPixmap pixmap("pic.png");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);

}

Aminmainwindows::~Aminmainwindows()
{
    delete ui;
}

void Aminmainwindows::on_pushButton_clicked()
{
    changealp.show();
        close();
}
