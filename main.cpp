#include "mainwindow.h"
#include <QApplication>
#include "fstream"
#include "string"
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /*ofstream fout("bookwater.txt");
    if(fout){
        for(int i=0;i<600;i++)
        fout<<0<<endl;
    }
    fout.close();
    ofstream fout2("roominfo.txt");
    if(fout2){
        for(int i=0;i<600;i++)
        fout2<<0<<endl;
    }
    fout2.close();
    ofstream fout3("studentinfo.txt");
    fout3.eof();
    fout3.close();*/

    return a.exec();
}
int flagforrevise;
string revisebyname;
string revisebyID;
