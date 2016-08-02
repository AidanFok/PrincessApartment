#include "studentservice.h"
#include "ui_studentservice.h"

Studentservice::Studentservice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Studentservice)
{
    ui->setupUi(this);
    QPixmap pixmap("pic.png");//设置背景图片
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
}

Studentservice::~Studentservice()
{
    delete ui;
}

void Studentservice::on_pushButton_clicked()
{
    int a;
    a=ui->spinBox->text().toInt();
    switch (a) {//选择面板
    case 1:
        studentbookwaters.show();
        break;
    case 2:
        alphanotices.show();
        break;
    default:
        break;
    }
}
