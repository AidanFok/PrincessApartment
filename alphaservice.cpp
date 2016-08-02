#include "alphaservice.h"
#include "ui_alphaservice.h"

Alphaservice::Alphaservice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Alphaservice)
{
    ui->setupUi(this);
    QPixmap pixmap("pic.png");//array[]输出至textbrowser
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
}

Alphaservice::~Alphaservice()
{
    delete ui;
}

void Alphaservice::on_pushButton_2_clicked()
{
    int a;
    a=ui->spinBox->text().toInt();
    switch (a) {//选择
    case 1:
        alphawater.show();
        break;
    case 2:
        alphanotices.show();
        break;
    case 3:
        alphasendnotices.show();
        break;
    default:
        break;
    }
}
