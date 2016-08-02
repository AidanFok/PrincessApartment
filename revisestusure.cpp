#include "revisestusure.h"
#include "ui_revisestusure.h"
#include "string"
#include "structstudent.h"
#include "fstream"
 #include <QDebug>
using namespace std;
extern string revisebyname;
extern string revisebyID;
extern int flagforrevise;
Revisestusure::Revisestusure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Revisestusure)
{
    ui->setupUi(this);
    QPixmap pixmap("pic.png");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
    ui->label_8->setText("Push 'show' to Show More Information First");

}

Revisestusure::~Revisestusure()
{
    delete ui;
}

void Revisestusure::on_pushButton_clicked()
{
    if(flagforrevise==1){
    student array[2400];int ren=0;
               int count1=0;
                   ifstream fin("studentinfo.txt");
                       while(!fin.eof())//输入学生信息
                       {
                           fin>>array[ren].name>>array[ren].ID>>array[ren].college>>array[ren].phone>>array[ren].mail>>array[ren].stair>>array[ren].room;
                           ren++;
                       }
                       ren--;

                 for(int i=0;i<ren;i++){
                 if(array[i].name==revisebyname){
                     if(ui->lineEdit->text().toStdString()==""||ui->lineEdit_2->text().toStdString()==""||ui->lineEdit_3->text().toStdString()==""||ui->lineEdit_4->text().toStdString()==""||ui->lineEdit_5->text().toStdString()==""||ui->spinBox->text().toStdString()==""||ui->spinBox_2->text().toStdString()==""){count1=2;break;}
                     else{
                     array[i].name=ui->lineEdit->text().toStdString();
                     array[i].ID=ui->lineEdit_2->text().toStdString();
                     array[i].college=ui->lineEdit_3->text().toStdString();
                     array[i].phone=ui->lineEdit_4->text().toStdString();
                     array[i].mail=ui->lineEdit_5->text().toStdString();
                     array[i].stair=ui->spinBox->text().toStdString();
                     array[i].room=ui->spinBox_2->text().toStdString();
                     count1=1;break;}
                 }
                 }

                 if(count1==0){
                 ui->label_8->setText("this student does not exist");}
                 if(count1==1){
               ofstream outfile("studentinfo.txt");
               if(outfile){
                for(int j=0;j<ren;j++){
                   outfile<<array[j].name<<endl;
                   outfile<<array[j].ID<<endl;
                   outfile<<array[j].college<<endl;
                   outfile<<array[j].phone<<endl;
                   outfile<<array[j].mail<<endl;
                   outfile<<array[j].stair<<endl;
                   outfile<<array[j].room<<endl;
                }
               }
               outfile.close();
               ui->label_8->setText("success!");}
                 if(count1==2){ ui->label_8->setText("there are empty informations");}

               }
    if(flagforrevise==2){
        student array[100];int ren=0;
                   int count2=0;
                       ifstream fin("studentinfo.txt");
                           while(!fin.eof())//输入学生信息
                           {
                               fin>>array[ren].name>>array[ren].ID>>array[ren].college>>array[ren].phone>>array[ren].mail>>array[ren].stair>>array[ren].room;
                               ren++;
                           }
                           ren--;

                     for(int i=0;i<ren;i++){
                     if(array[i].ID==revisebyID){
                                              if(ui->lineEdit->text().toStdString()==""||ui->lineEdit_2->text().toStdString()==""||ui->lineEdit_3->text().toStdString()==""||ui->lineEdit_4->text().toStdString()==""||ui->lineEdit_5->text().toStdString()==""||ui->spinBox->text().toStdString()==""||ui->spinBox_2->text().toStdString()==""){count2=2;break;}
                                              else{
                         array[i].name=ui->lineEdit->text().toStdString();
                         array[i].ID=ui->lineEdit_2->text().toStdString();
                         array[i].college=ui->lineEdit_3->text().toStdString();
                         array[i].phone=ui->lineEdit_4->text().toStdString();
                         array[i].mail=ui->lineEdit_5->text().toStdString();
                         array[i].stair=ui->spinBox->text().toStdString();
                         array[i].room=ui->spinBox_2->text().toStdString();
                         count2=1;break;}
                     }
                   }
                     if(count2==0){
                          ui->label_8->setText("this student does not exist");}
                     if(count2==1){
                   ofstream outfile("studentinfo.txt");
                   if(outfile){
                    for(int j=0;j<ren;j++){
                       outfile<<array[j].name<<endl;
                       outfile<<array[j].ID<<endl;
                       outfile<<array[j].college<<endl;
                       outfile<<array[j].phone<<endl;
                       outfile<<array[j].mail<<endl;
                       outfile<<array[j].stair<<endl;
                       outfile<<array[j].room<<endl;
                    }
                   }
                   outfile.close();
                   ui->label_8->setText("success!");}
                       if(count2==2){ ui->label_8->setText("there are empty informations");}

    }
}

void Revisestusure::on_pushButton_2_clicked()
{
    if(flagforrevise==1){//按名字修改
    student array[2400];int ren=0;
               int count1=0;
                   ifstream fin("studentinfo.txt");//输入学生信息，统计人数
                       while(!fin.eof())
                       {
                           fin>>array[ren].name>>array[ren].ID>>array[ren].college>>array[ren].phone>>array[ren].mail>>array[ren].stair>>array[ren].room;
                           ren++;
                       }
                       ren--;
                       fin.close();

                 for(int i=0;i<ren;i++){
                 if(array[i].name==revisebyname){//如果找到该名字，输出
                     ui->label->setText(QString::fromStdString(array[i].name));
                     ui->label_2->setText(QString::fromStdString(array[i].ID));
                     ui->label_3->setText(QString::fromStdString(array[i].college));
                     ui->label_4->setText(QString::fromStdString(array[i].phone));
                     ui->label_5->setText(QString::fromStdString(array[i].mail));
                     ui->label_6->setText(QString::fromStdString(array[i].stair));
                     ui->label_7->setText(QString::fromStdString(array[i].room));
                     count1=1;break;
                 }
                 }
                 if(count1==0){//找不到该名字
                     ui->label_8->setText("this student does not exist"); }
                 else{
                      ui->label_8->setText("refresh student info on the right");
                 }
               }
    if(flagforrevise==2){//按学号修改
        student array[100];int ren=0;
                   int count2=0;
                       ifstream fin1("studentinfo.txt");//输入学生信息，统计人数
                           while(!fin1.eof())
                           {
                               fin1>>array[ren].name>>array[ren].ID>>array[ren].college>>array[ren].phone>>array[ren].mail>>array[ren].stair>>array[ren].room;
                               ren++;
                           }
                           ren--;
                           fin1.close();

                     for(int i=0;i<ren;i++){
                     if(array[i].ID==revisebyID){//如果找到该学号，输出
                         ui->label->setText(QString::fromStdString(array[i].name));
                         ui->label_2->setText(QString::fromStdString(array[i].ID));
                         ui->label_3->setText(QString::fromStdString(array[i].college));
                         ui->label_4->setText(QString::fromStdString(array[i].phone));
                         ui->label_5->setText(QString::fromStdString(array[i].mail));
                         ui->label_6->setText(QString::fromStdString(array[i].stair));
                         ui->label_7->setText(QString::fromStdString(array[i].room));
                         count2=1;break;
                     }
                   } if(count2==0){//找不到该学号
                         ui->label_8->setText("this student does not exist");
                    }
                     else{
                          ui->label_8->setText("refresh student info on the right");
                     }

    }
}
