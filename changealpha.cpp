#include "changealpha.h"
#include "ui_changealpha.h"
#include "fstream"
#include "string"
using namespace std;
Changealpha::Changealpha(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Changealpha)
{
    ui->setupUi(this);
    QPixmap pixmap("pic.png");//设置背景图片
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
}

Changealpha::~Changealpha()
{
    delete ui;
}

void Changealpha::on_pushButton_clicked()
{
    string yonghu3,mima3;
    yonghu3=ui->lineEdit_3->text().toStdString();//从界面读入新的楼长账号密码
    mima3=ui->lineEdit_4->text().toStdString();
    ofstream fout1("alphalogininfo.txt");//清空楼长账号密码文档
    fout1.eof();
    fout1.close();
    ofstream fout2("alphalogininfo.txt");//写入楼长账号密码
    fout2<<yonghu3<<endl;
    fout2<<mima3<<endl;
    fout2.close();
    ui->label->setText("success");

}



void Changealpha::on_pushButton_2_clicked()
{
    string yonghu1,mima1;
            ifstream fin1("alphalogininfo.txt");//读入楼长账号密码并显示
            if(fin1)
            {fin1>>yonghu1>>mima1;}
                fin1.close();
                ui->label_6->setText(QString::fromStdString(yonghu1));
                ui->label_7->setText(QString::fromStdString(mima1));
}
