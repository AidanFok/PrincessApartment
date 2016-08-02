#include "alphanotice.h"
#include "ui_alphanotice.h"
#include "string"
#include "structstudent.h"
#include "fstream"
 #include <QDebug>
using namespace std;
Alphanotice::Alphanotice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Alphanotice)
{
    ui->setupUi(this);
    QPixmap pixmap("pic.png");//设置背景图片
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
}

Alphanotice::~Alphanotice()
{
    delete ui;
}

void Alphanotice::on_pushButton_clicked()
{   int count=0;string array[1000];
    ui->textBrowser->clear();
ifstream fin("notice.txt");//从文件读入信息至array[]
    if(fin){
        while(!fin.eof()){
              fin>>array[count];
            count++;}
  }count--;
    fin.close();
    for(int i=0;i<count;i++){//array[]输出至textbrowser
          ui->textBrowser->append(QString::fromStdString(array[i]));
    }


}
