#include "studentmainwindows.h"
#include "ui_studentmainwindows.h"

Studentmainwindows::Studentmainwindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Studentmainwindows)
{
    ui->setupUi(this);
    QPixmap pixmap("pic.png");//设置背景图片
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
}

Studentmainwindows::~Studentmainwindows()
{
    delete ui;
}

void Studentmainwindows::on_pushButton_clicked()
{
    int a;
    a=ui->spinBox->text().toInt();//选择面板
    switch (a){
    case 1:
        findstudent.show();
        break;
    case 2:
        summarystudent.show();
        break;
    case 3:
        studentservices.show();
        break;
    default:
        ui->label->setText("error");
        break;
    }
}
