#include "studentbookwater.h"
#include "ui_studentbookwater.h"
#include "string"
#include "structstudent.h"
#include "fstream"
 #include <QDebug>
using namespace std;
Studentbookwater::Studentbookwater(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Studentbookwater)
{
    ui->setupUi(this);
    QPixmap pixmap("pic.png");//设置背景图片
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
}

Studentbookwater::~Studentbookwater()
{
    delete ui;
}

void Studentbookwater::on_pushButton_clicked()
{
    int a,b,c;
    a=ui->spinBox->text().toInt();//写入订水房间和订水量
    b=ui->lineEdit->text().toInt();
    c=ui->lineEdit_2->text().toInt();
    if(b>=1&&b<=6&&c>=1&&c<=100){
        int bookwater[7][101];
            ifstream fin("bookwater.txt");//从文件写入订水信息
               if(fin){for(int i=1;i<=6;i++){
                 for(int j=1;j<=100;j++)
                 fin>>bookwater[i][j];
                }}
                fin.close();
                bookwater[b][c]=a;
                /*qDebug()<<a;*/
                ofstream fout("bookwater.txt");//订水信息写入到文件
                   if(fout){for(int i=1;i<=6;i++){
                     for(int j=1;j<=100;j++)
                     fout<<bookwater[i][j]<<endl;
                    }}
                    fout.close();
                    ui->label_4->setText("suceess");

    }
    else{
        ui->label_4->setText("error");//房间号超出范围，输出“error”
    }
}
