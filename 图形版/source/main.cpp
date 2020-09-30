//main.cpp
#include "process.h"
#include "mainwindow.h"
#include <QApplication>
using namespace std;

void do_setting()//分两步完成设置的载入
{
    in_case_nosettings();
    load_setting();
}
int main(int argc, char *argv[])
{
    do_setting();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
