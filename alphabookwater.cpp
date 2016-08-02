#include "alphabookwater.h"
#include "ui_alphabookwater.h"
#include "string"
#include "structstudent.h"
#include "fstream"
 #include <QDebug>
using namespace std;
Alphabookwater::Alphabookwater(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Alphabookwater)//构造函数
{
    ui->setupUi(this);
    QPixmap pixmap("pic.png");//设置背景图片
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
}

Alphabookwater::~Alphabookwater()//析构函数
{
    delete ui;
}

void Alphabookwater::on_pushButton_clicked()//按下按钮时执行函数
{
    ui->textBrowser->clear();//清空textbrowser
    int bookwater[7][101];
        ifstream fin("bookwater.txt");//读入文件中各寝室订水信息至二维数组
           if(fin){for(int i=1;i<=6;i++){
             for(int j=1;j<=100;j++)
             fin>>bookwater[i][j];
            }}
            fin.close();
            int flag=0;
            for(int i=1;i<=6;i++){//显示需要订水的寝室
           for(int j=1;j<=100;j++){
               if(bookwater[i][j]!=0){
                   QString Qi=QString::number(i);
                   QString Qj=QString::number(j);
                   QString Qwater=QString::number(bookwater[i][j]);
                   ui->textBrowser->append("room "+Qi+"-"+Qj+" need "+Qwater+" water");//append函数输出不会清空原来的内容
                   flag=1;
               }
           }
}
            if(flag==0) ui->textBrowser->append("no room need water");//没有寝室需要订水
}

void Alphabookwater::on_pushButton_2_clicked()
{
 ui->textBrowser->clear();
 ofstream fout("bookwater.txt");//清空订水信息，写入文件
     if(fout){
         for(int i=0;i<600;i++)
         fout<<0<<endl;
     }
     fout.close();
     ui->textBrowser->setText("success");
}
