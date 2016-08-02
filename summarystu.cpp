#include "summarystu.h"
#include "ui_summarystu.h"
#include "structstudent.h"
#include "string"
#include "fstream"
using namespace std;
Summarystu::Summarystu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Summarystu)
{
    ui->setupUi(this);
    QPixmap pixmap("pic.png");//设置背景图片
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
}

Summarystu::~Summarystu()
{
    delete ui;
}

void Summarystu::on_pushButton_clicked()
{   ui->textBrowser->clear();
    student array[100];int ren=0;
    ifstream fin1("studentinfo.txt");//输入学生信息，统计人数
        while(!fin1.eof())
        {
            fin1>>array[ren].name>>array[ren].ID>>array[ren].college>>array[ren].phone>>array[ren].mail>>array[ren].stair>>array[ren].room;
            ren++;
        }
        ren--;
        fin1.close();
        int allroom[7][101];
        ifstream fin("roominfo.txt");//输入房间信息
           if(fin){for(int i=1;i<=6;i++){
             for(int j=1;j<=100;j++)
             fin>>allroom[i][j];
            }}
            fin.close();
            int count[6];//统计非空房数
            for(int i=0;i<6;i++)count[i]=0;
            for(int i=1;i<=6;i++){
                for(int j=1;j<=100;j++){
                    if(allroom[i][j]!=0)count[i-1]++;
                }
            }
            QString Qren=QString::number(ren);
            QString Qstair1=QString::number(count[0]);
            QString Qstair2=QString::number(count[1]);
            QString Qstair3=QString::number(count[2]);
            QString Qstair4=QString::number(count[3]);
            QString Qstair5=QString::number(count[4]);
            QString Qstair6=QString::number(count[5]);
            ui->textBrowser->append("there are "+Qren+"student and the count of using room in each stair is"+Qstair1+","+Qstair2+","+Qstair3+","+Qstair4+","+Qstair5+","+Qstair6+".\n");
            ui->textBrowser->append("Details:");//输出信息
            for(int i=0;i<ren;i++){
            QString Qi=QString::number(i+1);
            QString Qname= QString::fromStdString(array[i].name);
            QString QID= QString::fromStdString(array[i].ID);
            QString Qcollege= QString::fromStdString(array[i].college);
            QString Qphone= QString::fromStdString(array[i].phone);
            QString Qmail= QString::fromStdString(array[i].mail);
            QString Qstair= QString::fromStdString(array[i].stair);
            QString Qroom= QString::fromStdString(array[i].room);
            ui->textBrowser->append(Qi+":name:"+Qname+"  ID:"+QID+"  college:"+Qcollege+"  phone:"+Qphone+"  mail:"+Qmail+"  room:"+Qstair+"-"+Qroom+".\n");
            }

}
