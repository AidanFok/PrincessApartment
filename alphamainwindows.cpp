#include "alphamainwindows.h"
#include "ui_alphamainwindows.h"
#include "fstream"
using namespace std;
Alphamainwindows::Alphamainwindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Alphamainwindows)
{
    ui->setupUi(this);
    QPixmap pixmap("pic.png");//设置背景图片
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
}

Alphamainwindows::~Alphamainwindows()
{
    delete ui;
}

void Alphamainwindows::on_pushButton_clicked()
{
    int a;
    a=ui->spinBox->text().toInt();//从spinbox读入选项
    switch (a) {//选择界面
    case 1:
        establishstudent.show();
        break;
    case 2:
        findstudent.show();
        break;
    case 3:
        summarystudent.show();
        break;
    case 4:
        revisestudent.show();
        break;
    case 5:
        deletestudent.show();
        break;
    case 6:
        alphaser.show();
        break;
    default:
        ui->label_7->setText("error");
        break;
    }
}
