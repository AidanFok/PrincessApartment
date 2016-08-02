#include "alphasendnotice.h"
#include "ui_alphasendnotice.h"
#include "string"
#include "structstudent.h"
#include "fstream"
#include "iostream"
 #include <QDebug>
using namespace std;
Alphasendnotice::Alphasendnotice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Alphasendnotice)
{
    ui->setupUi(this);
    QPixmap pixmap("pic.png");//array[]输出至textbrowser
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
}

Alphasendnotice::~Alphasendnotice()
{
    delete ui;
}

void Alphasendnotice::on_pushButton_clicked()
{
    QString Qp=ui->textEdit->toPlainText();//从textedit读入至Qp
    string p=Qp.toStdString();//QString格式转换成string格式
    /*cout<<p;*/
    ofstream fout1("notice.txt");//清空notice文件
    if(fout1)
        fout1.eof();
    fout1.close();
    ofstream fout("notice.txt");//内容写入notice文件
    if(fout){
        fout<<p<<endl;
    }
    fout.close();
    ui->label->setText("success");
    ui->textEdit->clear();
}
