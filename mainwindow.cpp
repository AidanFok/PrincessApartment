#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSound"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*QPixmap m;
    m.load("image.jpg");
    qreal width = m.width(); //获得以前图片的宽和高
      qreal height = m.height();
      m = m.scaled(width,height,Qt::KeepAspectRatio);
      ui->label->setPixmap(m);*/

      QPixmap pixmap("pic.png");//设置背景图片

      QPalette palette;

      palette.setBrush(backgroundRole(), QBrush(pixmap));

      setPalette(palette);
       //QSound::play("邓紫棋 - 查克靠近.wav");
       QSound *gem=new QSound("邓紫棋 - 查克靠近.wav");
       gem->play();
       //sound->stop();
       gem->setLoops(QSound::Infinite);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()//三个按钮三个窗口
{
    alphain.show();
}

void MainWindow::on_pushButton_2_clicked()
{
    aminin.show();
}

void MainWindow::on_pushButton_3_clicked()
{
    studentin.show();
}
