#include "findstu.h"
#include "ui_findstu.h"
#include "structstudent.h"
#include "string"
#include "fstream"
using namespace std;
Findstu::Findstu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Findstu)
{
    ui->setupUi(this);
    QPixmap pixmap("pic.png");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
}

Findstu::~Findstu()
{
    delete ui;
}
void Findstu::on_pushButton_clicked()
{
    int a; int renshu=0;
    a=ui->spinBox->text().toInt();//选择按名字查找还是按学号查找
    if(a==1){//按名字
        int count1=0;
       string findbyname;
       findbyname=ui->lineEdit->text().toStdString();//面板读入名字
       student p;
       ifstream fin("studentinfo.txt");//从文件输入当前所有学生信息，统计人数
       while(!fin.eof())
           {
               fin>>p.name>>p.ID>>p.college>>p.phone>>p.mail>>p.stair>>p.room;
               renshu++;
           }
           renshu--;
           fin.close();
                  ifstream fin2("studentinfo.txt");
       for(int i=0;i<renshu;i++){//寻找该名字
       fin2>>p.name>>p.ID>>p.college>>p.phone>>p.mail>>p.stair>>p.room;
       if(p.name==findbyname){//如果找到，输出
           QString Qname= QString::fromStdString(p.name);
           QString QID= QString::fromStdString(p.ID);
           QString Qcollege= QString::fromStdString(p.college);
           QString Qphone= QString::fromStdString(p.phone);
           QString Qmail= QString::fromStdString(p.mail);
           QString Qstair= QString::fromStdString(p.stair);
           QString Qroom= QString::fromStdString(p.room);
           ui->textBrowser->clear();
           ui->textBrowser->setText("name:"+Qname+"\n"+"ID:"+QID+"\n"+"college:"+Qcollege+"\n"+"phone:"+Qphone+"\n"+"mail:"+Qmail+"\n"+"room:"+Qstair+"-"+Qroom);
           count1=1;break;
       }
       }
       fin2.close();
       if(count1==0)//找不到，输出“error”
           ui->textBrowser->setText("this student does not exist");
    }
    if(a==2){//按学号查找
        int count2=0;
       string findbyID;
       findbyID=ui->lineEdit->text().toStdString();
       student p;
       ifstream fin3("studentinfo.txt");//从文件输入当前所有学生信息，统计人数
       while(!fin3.eof())
           {
               fin3>>p.name>>p.ID>>p.college>>p.phone>>p.mail>>p.stair>>p.room;
               renshu++;
           }
           renshu--;
           fin3.close();

       ifstream fin4("studentinfo.txt");
       for(int i=0;i<renshu;i++){//寻找该学号
       fin4>>p.name>>p.ID>>p.college>>p.phone>>p.mail>>p.stair>>p.room;
       if(p.ID==findbyID){//找到就输出
           QString Qname= QString::fromStdString(p.name);
           QString QID= QString::fromStdString(p.ID);
           QString Qcollege= QString::fromStdString(p.college);
           QString Qphone= QString::fromStdString(p.phone);
           QString Qmail= QString::fromStdString(p.mail);
           QString Qstair= QString::fromStdString(p.stair);
           QString Qroom= QString::fromStdString(p.room);
           ui->textBrowser->clear();
           ui->textBrowser->setText("name:"+Qname+"\n"+"ID:"+QID+"\n"+"college:"+Qcollege+"\n"+"phone:"+Qphone+"\n"+"mail:"+Qmail+"\n"+"room:"+Qstair+"-"+Qroom);
           count2=1;break;
       }
       }
       fin4.close();
       if(count2==0)//找不到就输出“error”
           ui->textBrowser->setText("this student does not exist");
    }
}
