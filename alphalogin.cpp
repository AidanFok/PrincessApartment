#include "alphalogin.h"
#include "ui_alphalogin.h"
#include "fstream"
#include "string"
using namespace std;
Alphalogin::Alphalogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Alphalogin)
{
    ui->setupUi(this);
    QPixmap pixmap("pic.png");//设置背景图片
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
}

Alphalogin::~Alphalogin()
{
    delete ui;
}

void Alphalogin::on_pushButton_clicked()
{
    string yonghu1,yonghu2,mima1,mima2;
    yonghu1=ui->lineEdit->text().toStdString();//从lineedit读入账号密码并转换成string格式
    mima1=ui->lineEdit_2->text().toStdString();
    /*char *yonghu1;
    char *mima1;
    char yonghu2[20];
    char mima2[20];
    QByteArray ba = ui->lineEdit->text().toLatin1();
    QByteArray bb = ui->lineEdit_2->text().toLatin1();
    yonghu1 =ba.data();
    mima1 = bb.data();*/
    ifstream fin1("alphalogininfo.txt");//从文件读入账号密码信息
    if(!fin1)
        {
        ui->label->setText("error");
        }
        fin1>>yonghu2>>mima2;
        fin1.close();
        if(yonghu1!=yonghu2||mima1!=mima2)//不匹配则输出error
            {
                ui->label->setText("error");
                ui->lineEdit->clear();
                ui->lineEdit_2->clear();
            }
if(yonghu1==yonghu2&&mima1==mima2){//匹配则login
alphamainwindow.show();
ui->lineEdit->clear();
ui->lineEdit_2->clear();
close();
}
}
