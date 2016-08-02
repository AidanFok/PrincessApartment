#include "revisestu.h"
#include "ui_revisestu.h"
#include "string"
using namespace std;
Revisestu::Revisestu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Revisestu)
{
    ui->setupUi(this);
    QPixmap pixmap("pic.png");//设置背景图片
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
}

Revisestu::~Revisestu()
{
    delete ui;
}
extern string revisebyname;
extern string revisebyID;
extern int flagforrevise;
void Revisestu::on_pushButton_clicked()
{

    flagforrevise=ui->spinBox->text().toInt();//选择按名字修改还是按学号修改
    if(flagforrevise==1){
        revisebyname=ui->lineEdit->text().toStdString();
        revisesure.show();
        close();
    }
    if(flagforrevise==2){
        revisebyID=ui->lineEdit->text().toStdString();
        revisesure.show();
        close();
    }
}
