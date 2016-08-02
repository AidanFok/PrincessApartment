#include "establishstu.h"
#include "ui_establishstu.h"
#include "string"
#include "vector"
#include "fstream"
using namespace std;
Establishstu::Establishstu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Establishstu)
{
    ui->setupUi(this);
    QPixmap pixmap("pic.png");//设置背景图片
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
    ui->label_8->setText("enter student information");
}

Establishstu::~Establishstu()
{
    delete ui;
}


void Establishstu::on_pushButton_clicked()
{    string name,ID,college,phone,mail,stair,room;
    int allroom[7][101];
    ifstream fin("roominfo.txt");//从文件写入房间信息
       if(fin){for(int i=1;i<=6;i++){
         for(int j=1;j<=100;j++)
         fin>>allroom[i][j];  
        }}
        fin.close();
    int a,b;
    a=ui->spinBox->text().toInt();//从面板读入房间号
    b=ui->spinBox_2->text().toInt();
    if(allroom[a][b]>=4){//如果该房间住满4个人，输出“满员”
        ui->label_8->setText("this room is full!");
    }
    else{
        name=ui->lineEdit->text().toStdString();//输入学生信息
        ID=ui->lineEdit_2->text().toStdString();
        college=ui->lineEdit_3->text().toStdString();
        phone=ui->lineEdit_4->text().toStdString();
        mail=ui->lineEdit_5->text().toStdString();
        stair=ui->spinBox->text().toStdString();
        room=ui->spinBox_2->text().toStdString();
        if(name==""||ID==""||college==""||phone==""||mail==""||stair==""||room=="")ui->label_8->setText("there are empty informations");
        else{
        allroom[a][b]++;//该房间人数+1
        ofstream fout("roominfo.txt");//房间信息写入到文件
            if(fout){
                for(int i=1;i<=6;i++)
                for(int j=1;j<=100;j++)
                fout<<allroom[i][j]<<endl;
            }
            fout.close();

            ofstream outfile("studentinfo.txt",ios::app);//以追加方式写入到学生信息中
            if(outfile){
                outfile<<name<<endl<<ID<<endl<<college<<endl<<phone<<endl<<mail<<endl<<stair<<endl<<room<<endl;
                }
            outfile.close();
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        ui->label_8->setText("ok,next one");}

    }

}

void Establishstu::on_pushButton_2_clicked()
{      ui->label_8->setText("enter student information");
    close();

}
