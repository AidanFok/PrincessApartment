#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "alphalogin.h"
#include "aminlogin.h"
#include "studentlogin.h"
namespace Ui {//在Ui命名空间里定义Mainwindows类
class MainWindow;
}

class MainWindow : public QMainWindow//Mainwindows类继承QMainwindows类
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();//button执行函数是Mainwindows的私有变量

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;//指向ui界面的指针
    Alphalogin alphain;//Alphalogin类的成员alphain是Mainwindows的私有变量
    Aminlogin aminin;
    Studentlogin studentin;
};

#endif // MAINWINDOW_H
