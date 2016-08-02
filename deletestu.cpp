#include "deletestu.h"
#include "ui_deletestu.h"
#include "structstudent.h"
#include "string"
#include "fstream"
#include "sstream"
using namespace std;
Deletestu::Deletestu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Deletestu)
{
    ui->setupUi(this);
    QPixmap pixmap("pic.png");//设置背景图片
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
}

Deletestu::~Deletestu()
{
    delete ui;
}

void Deletestu::on_pushButton_clicked()
{
    int a;
    a=ui->spinBox->text().toInt();//选择通过名字还是学号删除
    if(a==1){
        string deletebyname;
        deletebyname=ui->lineEdit->text().toStdString();//输入待删除名字
        student array[2400];int ren=0;
                   int count1=0;
                   int allroom[7][101];
                       ifstream fin("roominfo.txt");//读入房间信息
                          if(fin){for(int i=1;i<=6;i++){
                            for(int j=1;j<=100;j++)
                            fin>>allroom[i][j];
                           }}
                           fin.close();
                       ifstream fin1("studentinfo.txt");//统计人数并将学生信息吸入array[]
                           while(!fin1.eof())
                           {
                               fin1>>array[ren].name>>array[ren].ID>>array[ren].college>>array[ren].phone>>array[ren].mail>>array[ren].stair>>array[ren].room;
                               ren++;
                           }
                           ren--;
                           fin1.close();

                     for(int i=0;i<ren;i++){//查找该学生名字
                     if(array[i].name==deletebyname){//如果找到
                         stringstream sa;sa<<array[i].stair;
                         stringstream sb;sb<<array[i].room;
                         int a,b;
                         sa>>a;sb>>b;
                         allroom[a][b]--;//该房间人数-1
                         ofstream fout("roominfo.txt");//房间信息写入文件
                             if(fout){
                                 for(int i=1;i<=6;i++)
                                 for(int j=1;j<=100;j++)
                                 fout<<allroom[i][j]<<endl;
                             }
                             fout.close();

                         ofstream fout1("studentinfo.txt");//清空学生信息文件
                         fout1.eof();
                         fout1.close();
                         ofstream fout2("studentinfo.txt",ios::app);//追加形式打开文件
                         if(fout2){
                         for(int s=0;s<ren;s++){//除了该生，其他学生重新写入学生信息文档
                          if(s!=i){
                         fout2<<array[s].name<<endl;
                         fout2<<array[s].ID<<endl;
                         fout2<<array[s].college<<endl;
                         fout2<<array[s].phone<<endl;
                         fout2<<array[s].mail<<endl;
                         fout2<<array[s].stair<<endl;
                         fout2<<array[s].room<<endl;}
                                      }
                         }
                         fout2.close();
                         count1=1;ui->label->setText("success");break;
                     }
                     }
                     if(count1==0){//没找到该学生
                          ui->label->setText("this student does not exist"); }
    }
    if(a==2){
        string deletebyID;
        deletebyID=ui->lineEdit->text().toStdString();//输入待删除学号
        student array[100];int ren=0;
                   int count2=0;      int allroom[7][101];
                   ifstream fin("roominfo.txt");//读入房间信息
                      if(fin){for(int i=1;i<=6;i++){
                        for(int j=1;j<=100;j++)
                        fin>>allroom[i][j];
                       }}
                       fin.close();
                       ifstream fin2("studentinfo.txt");//统计人数并将学生信息吸入array[]
                           while(!fin2.eof())
                           {
                               fin2>>array[ren].name>>array[ren].ID>>array[ren].college>>array[ren].phone>>array[ren].mail>>array[ren].stair>>array[ren].room;
                               ren++;
                           }
                           ren--;
                           fin2.close();

                     for(int i=0;i<ren;i++){//查找该学生学号
                     if(array[i].ID==deletebyID){//如果找到

                         stringstream sa;sa<<array[i].stair;
                         stringstream sb;sb<<array[i].room;
                         int a,b;
                         sa>>a;sb>>b;
                         allroom[a][b]--;//该房间人数-1
                         ofstream fout("roominfo.txt");//房间信息写入文件
                             if(fout){
                                 for(int i=1;i<=6;i++)
                                 for(int j=1;j<=100;j++)
                                 fout<<allroom[i][j]<<endl;
                             }
                             fout.close();

                         ofstream fout3("studentinfo.txt");//清空学生信息文件
                         fout3.eof();
                         fout3.close();
                         ofstream fout4("studentinfo.txt",ios::app);//追加形式打开文件
                         if(fout4){
                         for(int s=0;s<ren;s++){//除了该生，其他学生重新写入学生信息文档
                          if(s!=i){
                         fout4<<array[s].name<<endl;
                         fout4<<array[s].ID<<endl;
                         fout4<<array[s].college<<endl;
                         fout4<<array[s].phone<<endl;
                         fout4<<array[s].mail<<endl;
                         fout4<<array[s].stair<<endl;
                         fout4<<array[s].room<<endl;}
                                      }
                         }
                         fout4.close();
                         count2=1;ui->label->setText("success");break;
                     }}
                     if(count2==0){//没找到该学生
                          ui->label->setText("this student does not exist"); }
    }
}
