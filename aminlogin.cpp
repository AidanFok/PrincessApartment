#include "aminlogin.h"
#include "ui_aminlogin.h"
#include "fstream"
#include "string"
using namespace std;
Aminlogin::Aminlogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Aminlogin)
{
    ui->setupUi(this);
    QPixmap pixmap("pic.png");//array[]输出至textbrowser
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
}

Aminlogin::~Aminlogin()
{
    delete ui;
}

void Aminlogin::on_pushButton_clicked()
{
    string yonghu1,yonghu2,mima1,mima2;
    yonghu1=ui->lineEdit->text().toStdString();//从lineedit读入账号密码
    mima1=ui->lineEdit_2->text().toStdString();
    ifstream fin1("aminlogininfo.txt");//从文件读入账号密码
    if(!fin1)
        {
        ui->label->setText("error");
        }
        fin1>>yonghu2>>mima2;
        fin1.close();
        if(yonghu1!=yonghu2||mima1!=mima2)
            {
                ui->label->setText("error");
                ui->lineEdit->clear();
                ui->lineEdit_2->clear();
            }
if(yonghu1==yonghu2&&mima1==mima2){
    Aminmainwindow.show();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    close();
}
}
