#include "studentlogin.h"
#include "ui_studentlogin.h"
#include "structstudent.h"
#include "string"
#include "fstream"
using namespace std;
Studentlogin::Studentlogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Studentlogin)
{
    ui->setupUi(this);
    QPixmap pixmap("pic.png");//设置背景图片
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
}

Studentlogin::~Studentlogin()
{
    delete ui;
}

void Studentlogin::on_pushButton_clicked()
{    string loginbyID,loginbyname;
    int count1=0;int renshu=0;
   loginbyID=ui->lineEdit->text().toStdString();//从面板输入学生名字学号
   loginbyname=ui->lineEdit_2->text().toStdString();
   student p;
   ifstream fin("studentinfo.txt");//统计人数
   while(!fin.eof())
       {
           fin>>p.name>>p.ID>>p.college>>p.phone>>p.mail>>p.stair>>p.room;
           renshu++;
       }
       renshu--;
       fin.close();

              ifstream fin2("studentinfo.txt");//从文件输入当前所有学生信息
   for(int i=0;i<renshu;i++){
   fin2>>p.name>>p.ID>>p.college>>p.phone>>p.mail>>p.stair>>p.room;
   if(p.ID==loginbyID&&p.name==loginbyname){//找到匹配则login
       Studentmainwindow.show();
       ui->lineEdit->clear();
       ui->lineEdit_2->clear();
       count1=1;close();break;
   }
   }
   fin2.close();
   if(count1==0){//找不到输出“error”
       ui->label->setText("error");
       ui->lineEdit->clear();
       ui->lineEdit_2->clear();
   }
}
