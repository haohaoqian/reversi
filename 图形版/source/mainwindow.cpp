#include "mainwindow.h"
#include "process.h"
#include "definition.h"
#include <QtWidgets>
#include <windows.h>
#include <fstream>
#include <cstring>
using namespace std;
QPushButton *pushButton1;
QPushButton *pushButton2;
QPushButton *pushButton3;
QPushButton *pushButton4;
QPushButton *pushButton5;
QLabel *label1;
QLabel *label2;
QLabel *label3;
QLabel *label4;
QLabel *label5;
QLabel *label6;
QPushButton *pushButton[8][8];
extern bool able;
extern black BLACK;
extern white WHITE;
extern int chess_board[8][8];
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("翻转棋");
    setFixedSize(1024,1024);
    setStyleSheet("border-image:url(:/picture/images/timg.jpg)");
    QFont font;
    font.setPointSize(50);
    label1=new QLabel(this);
    label1->setStyleSheet("border-image:url(:/picture/images/back.jpg)");
    label1->setGeometry(312,162,400,740);
    label1->setText("  翻转棋\n\n\n\n\n\n");
    label1->setFont(font);
    font.setPointSize(30);
    pushButton1=new QPushButton(this);
    pushButton1->setText("双人模式");
    pushButton1->setFont(font);
    pushButton1->setStyleSheet("border-image:url()");
    pushButton1->setGeometry(362,302,300,100);
    connect(pushButton1,SIGNAL(clicked(bool)),this,SLOT(mainmenu_1()));
    pushButton2=new QPushButton(this);
    pushButton2->setText("人机模式");
    pushButton2->setFont(font);
    pushButton2->setStyleSheet("border-image:url()");
    pushButton2->setGeometry(362,422,300,100);
    connect(pushButton2,SIGNAL(clicked(bool)),this,SLOT(mainmenu_2()));
    pushButton3=new QPushButton(this);
    pushButton3->setText("设置");
    pushButton3->setFont(font);
    pushButton3->setStyleSheet("border-image:url()");
    pushButton3->setGeometry(362,542,300,100);
    connect(pushButton3,SIGNAL(clicked(bool)),this,SLOT(mainmenu_3()));
    pushButton4=new QPushButton(this);
    pushButton4->setText("开发者信息");
    pushButton4->setFont(font);
    pushButton4->setStyleSheet("border-image:url()");
    pushButton4->setGeometry(362,662,300,100);
    connect(pushButton4,SIGNAL(clicked(bool)),this,SLOT(mainmenu_4()));
    pushButton5=new QPushButton(this);
    pushButton5->setText("退出游戏");
    pushButton5->setFont(font);
    pushButton5->setStyleSheet("border-image:url()");
    pushButton5->setGeometry(362,782,300,100);
    connect(pushButton5,SIGNAL(clicked(bool)),this,SLOT(mainmenu_5()));
}
MainWindow::~MainWindow()
{

}
void MainWindow::mainmenu_1()
{
    clear_window();
    QFont font;
    font.setPointSize(50);
    label1=new QLabel(this);
    label1->setStyleSheet("border-image:url(:/picture/images/back.jpg)");
    label1->setGeometry(312,302,400,420);
    label1->setText(" 双人模式\n\n\n");
    label1->setFont(font);
    font.setPointSize(30);
    pushButton1=new QPushButton(this);
    pushButton1->setText("开始游戏");
    pushButton1->setFont(font);
    pushButton1->setStyleSheet("border-image:url()");
    pushButton1->setGeometry(362,442,300,100);
    connect(pushButton1,SIGNAL(clicked(bool)),this,SLOT(doublemenu_1()));
    pushButton2=new QPushButton(this);
    pushButton2->setText("返回");
    pushButton2->setFont(font);
    pushButton2->setStyleSheet("border-image:url()");
    pushButton2->setGeometry(362,562,300,100);
    connect(pushButton2,SIGNAL(clicked(bool)),this,SLOT(doublemenu_2()));
    label1->show();
    pushButton1->show();
    pushButton2->show();
}
void MainWindow::mainmenu_2()
{
    clear_window();
    QFont font;
    font.setPointSize(50);
    label1=new QLabel(this);
    label1->setStyleSheet("border-image:url(:/picture/images/back.jpg)");
    label1->setGeometry(312,242,400,540);
    label1->setText(" 人机模式\n\n\n\n");
    label1->setFont(font);
    font.setPointSize(30);
    pushButton1=new QPushButton(this);
    pushButton1->setText("开始游戏");
    pushButton1->setFont(font);
    pushButton1->setStyleSheet("border-image:url()");
    pushButton1->setGeometry(362,402,300,100);
    connect(pushButton1,SIGNAL(clicked(bool)),this,SLOT(singlemenu_1()));
    pushButton2=new QPushButton(this);
    pushButton2->setText("查看历史");
    pushButton2->setFont(font);
    pushButton2->setStyleSheet("border-image:url()");
    pushButton2->setGeometry(362,522,300,100);
    connect(pushButton2,SIGNAL(clicked(bool)),this,SLOT(singlemenu_2()));
    pushButton3=new QPushButton(this);
    pushButton3->setText("返回");
    pushButton3->setFont(font);
    pushButton3->setStyleSheet("border-image:url()");
    pushButton3->setGeometry(362,642,300,100);
    connect(pushButton3,SIGNAL(clicked(bool)),this,SLOT(singlemenu_3()));
    label1->show();
    pushButton1->show();
    pushButton2->show();
    pushButton3->show();
}
void MainWindow::mainmenu_3()
{
    clear_window();
    QFont font;
    font.setPointSize(50);
    label1=new QLabel(this);
    label1->setStyleSheet("border-image:url(:/picture/images/back.jpg)");
    label1->setGeometry(312,242,400,540);
    label1->setText("   设置\n\n\n\n");
    label1->setFont(font);
    font.setPointSize(20);
    pushButton1=new QPushButton(this);
    pushButton1->setText("显示可落子位置");
    pushButton1->setFont(font);
    pushButton1->setStyleSheet("border-image:url()");
    pushButton1->setGeometry(362,382,300,100);
    connect(pushButton1,SIGNAL(clicked(bool)),this,SLOT(settingmenu_1()));
    pushButton2=new QPushButton(this);
    pushButton2->setText("不显示可落子位置");
    pushButton2->setFont(font);
    pushButton2->setStyleSheet("border-image:url()");
    pushButton2->setGeometry(362,502,300,100);
    connect(pushButton2,SIGNAL(clicked(bool)),this,SLOT(settingmenu_2()));
    pushButton3=new QPushButton(this);
    pushButton3->setText("返回");
    pushButton3->setFont(font);
    pushButton3->setStyleSheet("border-image:url()");
    pushButton3->setGeometry(362,622,300,100);
    connect(pushButton3,SIGNAL(clicked(bool)),this,SLOT(settingmenu_3()));
    label1->show();
    pushButton1->show();
    pushButton2->show();
    pushButton3->show();
}
void MainWindow::mainmenu_4()
{
    clear_window();
    QFont font;
    font.setPointSize(20);
    label1=new QLabel(this);
    label1->setGeometry(312,292,400,500);
    label1->setStyleSheet("border-image:url(:/picture/images/back.jpg)");
    label1->setText("      #开发者信息#\n\n        @ 郝千越\n  Tsinghua University\n   July,August  2019\n\n\n");
    label1->setFont(font);
    label1->show();
    font.setPointSize(30);
    pushButton5=new QPushButton(this);
    pushButton5->setText("返回");
    pushButton5->setFont(font);
    pushButton5->setStyleSheet("border-image:url()");
    pushButton5->setGeometry(362,670,300,100);
    pushButton5->show();
    connect(pushButton5,SIGNAL(clicked(bool)),this,SLOT(programmermenu()));
}
void MainWindow::mainmenu_5()
{
   clear_window();
   exit(0);
}
void MainWindow::doublemenu_1()
{
    delete label1;
    delete pushButton1;
    delete pushButton2;
    QFont font;
    font.setPointSize(30);
    label1=new QLabel(this);
    label1->setStyleSheet("border-image:url(:/picture/images/back.jpg)");
    label1->setGeometry(312,302,400,420);
    label1->setText("  希望哪方先手？\n\n\n\n\n");
    label1->setFont(font);
    font.setPointSize(20);
    pushButton1=new QPushButton(this);
    pushButton1->setText("黑棋");
    pushButton1->setFont(font);
    pushButton1->setStyleSheet("border-image:url()");
    pushButton1->setGeometry(362,442,300,100);
    connect(pushButton1,SIGNAL(clicked(bool)),this,SLOT(play_black_double()));
    pushButton2=new QPushButton(this);
    pushButton2->setText("白棋");
    pushButton2->setFont(font);
    pushButton2->setStyleSheet("border-image:url()");
    pushButton2->setGeometry(362,562,300,100);
    connect(pushButton2,SIGNAL(clicked(bool)),this,SLOT(play_white_double()));
    label1->show();
    pushButton1->show();
    pushButton2->show();
}
void MainWindow::doublemenu_2()
{
    delete label1;
    delete pushButton1;
    delete pushButton2;
    reset_window();
}
void MainWindow::singlemenu_1()
{
    delete label1;
    delete pushButton1;
    delete pushButton2;
    delete pushButton3;
    QFont font;
    font.setPointSize(30);
    label1=new QLabel(this);
    label1->setStyleSheet("border-image:url(:/picture/images/back.jpg)");
    label1->setGeometry(312,302,400,420);
    label1->setText("  希望哪方先手？\n\n\n\n\n");
    label1->setFont(font);
    font.setPointSize(20);
    pushButton1=new QPushButton(this);
    pushButton1->setText("黑棋（玩家）");
    pushButton1->setFont(font);
    pushButton1->setStyleSheet("border-image:url()");
    pushButton1->setGeometry(362,442,300,100);
    connect(pushButton1,SIGNAL(clicked(bool)),this,SLOT(play_black_single()));
    pushButton2=new QPushButton(this);
    pushButton2->setText("白棋（计算机）");
    pushButton2->setFont(font);
    pushButton2->setStyleSheet("border-image:url()");
    pushButton2->setGeometry(362,562,300,100);
    connect(pushButton2,SIGNAL(clicked(bool)),this,SLOT(play_white_single()));
    label1->show();
    pushButton1->show();
    pushButton2->show();
}
void MainWindow::singlemenu_2()
{
    delete label1;
    delete pushButton1;
    delete pushButton2;
    delete pushButton3;
    int computer, player, tie;
    history(computer,player,tie);
    QFont font;
    font.setPointSize(50);
    label1=new QLabel(this);
    label1->setStyleSheet("border-image:url(:/picture/images/back.jpg)");
    label1->setGeometry(312,162,400,700);
    label1->setText(" 历史记录\n\n\n\n\n\n");
    label1->setFont(font);
    font.setPointSize(20);
    label2=new QLabel(this);
    label2->setStyleSheet("border-image:url()");
    label2->setFont(font);
    label2->setGeometry(362,292,300,50);
    label2->setText("    共开局"+QString::number(computer+player+tie)+"次");
    label3=new QLabel(this);
    label3->setStyleSheet("border-image:url(:/picture/images/blackbright.jpg)");
    label3->setGeometry(392,342,70,70);
    label4=new QLabel(this);
    label4->setStyleSheet("border-image:url(:/picture/images/whitebright.jpg)");
    label4->setGeometry(562,342,70,70);
    label5=new QLabel(this);
    label5->setStyleSheet("border-image:url()");
    label5->setFont(font);
    label5->setGeometry(362,422,300,150);
    label5->setText("（玩家） （计算机)\n   "+QString::number(player)+"    :    "+QString::number(computer)+"\n     平局"+QString::number(tie)+"次");
    pushButton1=new QPushButton(this);
    pushButton1->setText("清空历史");
    pushButton1->setFont(font);
    pushButton1->setStyleSheet("border-image:url()");
    pushButton1->setGeometry(362,612,300,100);
    connect(pushButton1,SIGNAL(clicked(bool)),this,SLOT(singlemenu_2_1()));
    pushButton2=new QPushButton(this);
    pushButton2->setText("返回");
    pushButton2->setFont(font);
    pushButton2->setStyleSheet("border-image:url()");
    pushButton2->setGeometry(362,732,300,100);
    connect(pushButton2,SIGNAL(clicked(bool)),this,SLOT(singlemenu_2_2()));
    label1->show();
    label2->show();
    label3->show();
    label4->show();
    label5->show();
    pushButton1->show();
    pushButton2->show();
}
void MainWindow::singlemenu_3()
{
    delete label1;
    delete pushButton1;
    delete pushButton2;
    delete pushButton3;
    reset_window();
}
void MainWindow::settingmenu_1()
{
    ofstream op;
    op.open("setting", ios_base::binary | ios_base::trunc);
    able = true;
    op.write((char*)&able, 1);
    op.close();
    QMessageBox::information(NULL,"翻转棋-设置","已设置为显示落子位置",QMessageBox::Yes,QMessageBox::Yes);
    settingmenu_3();
}
void MainWindow::settingmenu_2()
{
    ofstream op;
    op.open("setting", ios_base::binary | ios_base::trunc);
    able = false;
    op.write((char*)&able, 1);
    op.close();
    QMessageBox::information(NULL,"翻转棋-设置","已设置为不显示落子位置",QMessageBox::Yes,QMessageBox::Yes);
    settingmenu_3();
}
void MainWindow::settingmenu_3()
{
    delete label1;
    delete pushButton1;
    delete pushButton2;
    delete pushButton3;
    reset_window();
}
void MainWindow::programmermenu()
{
    delete label1;
    delete pushButton5;
    reset_window();
}
void MainWindow::singlemenu_2_1()
{
    delete label1;
    delete label2;
    delete label3;
    delete label4;
    delete label5;
    delete pushButton1;
    delete pushButton2;
    QFont font;
    font.setPointSize(30);
    label1=new QLabel(this);
    label1->setStyleSheet("border-image:url(:/picture/images/back.jpg)");
    label1->setGeometry(312,302,400,420);
    label1->setText("  确认要清空吗？\n\n\n\n\n");
    label1->setFont(font);
    font.setPointSize(20);
    pushButton1=new QPushButton(this);
    pushButton1->setText("确认清空");
    pushButton1->setFont(font);
    pushButton1->setStyleSheet("border-image:url()");
    pushButton1->setGeometry(362,442,300,100);
    connect(pushButton1,SIGNAL(clicked(bool)),this,SLOT(singlemenu_2_1_1()));
    pushButton2=new QPushButton(this);
    pushButton2->setText("取消");
    pushButton2->setFont(font);
    pushButton2->setStyleSheet("border-image:url()");
    pushButton2->setGeometry(362,562,300,100);
    connect(pushButton2,SIGNAL(clicked(bool)),this,SLOT(singlemenu_2_1_2()));
    label1->show();
    pushButton1->show();
    pushButton2->show();
}
void MainWindow::singlemenu_2_2()
{
    delete label1;
    delete label2;
    delete label3;
    delete label4;
    delete label5;
    delete pushButton1;
    delete pushButton2;
    QFont font;
    font.setPointSize(50);
    label1=new QLabel(this);
    label1->setStyleSheet("border-image:url(:/picture/images/back.jpg)");
    label1->setGeometry(312,242,400,540);
    label1->setText(" 人机模式\n\n\n\n");
    label1->setFont(font);
    font.setPointSize(30);
    pushButton1=new QPushButton(this);
    pushButton1->setText("开始游戏");
    pushButton1->setFont(font);
    pushButton1->setStyleSheet("border-image:url()");
    pushButton1->setGeometry(362,402,300,100);
    connect(pushButton1,SIGNAL(clicked(bool)),this,SLOT(singlemenu_1()));
    pushButton2=new QPushButton(this);
    pushButton2->setText("查看历史");
    pushButton2->setFont(font);
    pushButton2->setStyleSheet("border-image:url()");
    pushButton2->setGeometry(362,522,300,100);
    connect(pushButton2,SIGNAL(clicked(bool)),this,SLOT(singlemenu_2()));
    pushButton3=new QPushButton(this);
    pushButton3->setText("返回");
    pushButton3->setFont(font);
    pushButton3->setStyleSheet("border-image:url()");
    pushButton3->setGeometry(362,642,300,100);
    connect(pushButton3,SIGNAL(clicked(bool)),this,SLOT(singlemenu_3()));
    label1->show();
    pushButton1->show();
    pushButton2->show();
    pushButton3->show();
}
void MainWindow::singlemenu_2_1_1()
{
    ofstream op;
    int t=0;
    op.open("history", ios_base::binary | ios_base::trunc);
    op.write((char*)&t, 4);
    op.write((char*)&t, 4);
    op.write((char*)&t, 4);
    op.close();
    singlemenu_2_1_2();
}
void MainWindow::singlemenu_2_1_2()
{
    delete label1;
    delete pushButton1;
    delete pushButton2;
    int computer, player, tie;
    history(computer,player,tie);
    QFont font;
    font.setPointSize(50);
    label1=new QLabel(this);
    label1->setStyleSheet("border-image:url(:/picture/images/back.jpg)");
    label1->setGeometry(312,162,400,700);
    label1->setText(" 历史记录\n\n\n\n\n\n");
    label1->setFont(font);
    font.setPointSize(20);
    label2=new QLabel(this);
    label2->setStyleSheet("border-image:url()");
    label2->setFont(font);
    label2->setGeometry(362,292,300,50);
    label2->setText("    共开局"+QString::number(computer+player+tie)+"次");
    label3=new QLabel(this);
    label3->setStyleSheet("border-image:url(:/picture/images/blackbright.jpg)");
    label3->setGeometry(392,342,70,70);
    label4=new QLabel(this);
    label4->setStyleSheet("border-image:url(:/picture/images/whitebright.jpg)");
    label4->setGeometry(562,342,70,70);
    label5=new QLabel(this);
    label5->setStyleSheet("border-image:url()");
    label5->setFont(font);
    label5->setGeometry(362,422,300,150);
    label5->setText("（玩家） （计算机)\n   "+QString::number(player)+"    :    "+QString::number(computer)+"\n     平局"+QString::number(tie)+"次");
    pushButton1=new QPushButton(this);
    pushButton1->setText("清空历史");
    pushButton1->setFont(font);
    pushButton1->setStyleSheet("border-image:url()");
    pushButton1->setGeometry(362,612,300,100);
    connect(pushButton1,SIGNAL(clicked(bool)),this,SLOT(singlemenu_2_1()));
    pushButton2=new QPushButton(this);
    pushButton2->setText("返回");
    pushButton2->setFont(font);
    pushButton2->setStyleSheet("border-image:url()");
    pushButton2->setGeometry(362,732,300,100);
    connect(pushButton2,SIGNAL(clicked(bool)),this,SLOT(singlemenu_2_2()));
    label1->show();
    label2->show();
    label3->show();
    label4->show();
    label5->show();
    pushButton1->show();
    pushButton2->show();
}
void MainWindow::prepare()
{
    delete pushButton1;
    delete pushButton2;
    delete label1;
    QFont font;
    font.setPointSize(30);
    setStyleSheet("border-image:url(:/picture/images/board.jpg)");
    setFixedSize(1323,992);
    QMessageBox::information(NULL,"翻转棋-进入游戏","载入游戏需要稍等片刻",QMessageBox::Yes,QMessageBox::Yes);
    pushButton1 =new QPushButton(this);
    pushButton1->setText("退出游戏");
    pushButton1->setFont(font);
    pushButton1->setGeometry(1050,810,220,100);
    pushButton1->setStyleSheet("border-image:url()");
    connect(pushButton1,SIGNAL(clicked(bool)),this,SLOT(escape()));
    pushButton1->show();
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            switch(chess_board[i][j])
            {
            case 1:case 2:break;
            case 0:
                pushButton[i][j]=new QPushButton(this);
                pushButton[i][j]->setStyleSheet("border-image:url(:/picture/images/deepback.jpg)");
                pushButton[i][j]->setGeometry(20+124*j,20+124*i,83,83);
                pushButton[i][j]->show();
                break;
            case 3:
                pushButton[i][j]=new QPushButton(this);
                pushButton[i][j]->setStyleSheet("border-image:url(:/picture/images/avli.jpg)");
                pushButton[i][j]->setGeometry(20+124*j,20+124*i,83,83);
                pushButton[i][j]->show();
            }
    connect(pushButton[0][0], SIGNAL(clicked(bool)), this, SLOT(click00()));
    connect(pushButton[0][1], SIGNAL(clicked(bool)), this, SLOT(click01()));
    connect(pushButton[0][2], SIGNAL(clicked(bool)), this, SLOT(click02()));
    connect(pushButton[0][3], SIGNAL(clicked(bool)), this, SLOT(click03()));
    connect(pushButton[0][4], SIGNAL(clicked(bool)), this, SLOT(click04()));
    connect(pushButton[0][5], SIGNAL(clicked(bool)), this, SLOT(click05()));
    connect(pushButton[0][6], SIGNAL(clicked(bool)), this, SLOT(click06()));
    connect(pushButton[0][7], SIGNAL(clicked(bool)), this, SLOT(click07()));
    connect(pushButton[1][0], SIGNAL(clicked(bool)), this, SLOT(click10()));
    connect(pushButton[1][1], SIGNAL(clicked(bool)), this, SLOT(click11()));
    connect(pushButton[1][2], SIGNAL(clicked(bool)), this, SLOT(click12()));
    connect(pushButton[1][3], SIGNAL(clicked(bool)), this, SLOT(click13()));
    connect(pushButton[1][4], SIGNAL(clicked(bool)), this, SLOT(click14()));
    connect(pushButton[1][5], SIGNAL(clicked(bool)), this, SLOT(click15()));
    connect(pushButton[1][6], SIGNAL(clicked(bool)), this, SLOT(click16()));
    connect(pushButton[1][7], SIGNAL(clicked(bool)), this, SLOT(click17()));
    connect(pushButton[2][0], SIGNAL(clicked(bool)), this, SLOT(click20()));
    connect(pushButton[2][1], SIGNAL(clicked(bool)), this, SLOT(click21()));
    connect(pushButton[2][2], SIGNAL(clicked(bool)), this, SLOT(click22()));
    connect(pushButton[2][3], SIGNAL(clicked(bool)), this, SLOT(click23()));
    connect(pushButton[2][4], SIGNAL(clicked(bool)), this, SLOT(click24()));
    connect(pushButton[2][5], SIGNAL(clicked(bool)), this, SLOT(click25()));
    connect(pushButton[2][6], SIGNAL(clicked(bool)), this, SLOT(click26()));
    connect(pushButton[2][7], SIGNAL(clicked(bool)), this, SLOT(click27()));
    connect(pushButton[3][0], SIGNAL(clicked(bool)), this, SLOT(click30()));
    connect(pushButton[3][1], SIGNAL(clicked(bool)), this, SLOT(click31()));
    connect(pushButton[3][2], SIGNAL(clicked(bool)), this, SLOT(click32()));
    connect(pushButton[3][5], SIGNAL(clicked(bool)), this, SLOT(click35()));
    connect(pushButton[3][6], SIGNAL(clicked(bool)), this, SLOT(click36()));
    connect(pushButton[3][7], SIGNAL(clicked(bool)), this, SLOT(click37()));
    connect(pushButton[4][0], SIGNAL(clicked(bool)), this, SLOT(click40()));
    connect(pushButton[4][1], SIGNAL(clicked(bool)), this, SLOT(click41()));
    connect(pushButton[4][2], SIGNAL(clicked(bool)), this, SLOT(click42()));
    connect(pushButton[4][5], SIGNAL(clicked(bool)), this, SLOT(click45()));
    connect(pushButton[4][6], SIGNAL(clicked(bool)), this, SLOT(click46()));
    connect(pushButton[4][7], SIGNAL(clicked(bool)), this, SLOT(click47()));
    connect(pushButton[5][0], SIGNAL(clicked(bool)), this, SLOT(click50()));
    connect(pushButton[5][1], SIGNAL(clicked(bool)), this, SLOT(click51()));
    connect(pushButton[5][2], SIGNAL(clicked(bool)), this, SLOT(click52()));
    connect(pushButton[5][3], SIGNAL(clicked(bool)), this, SLOT(click53()));
    connect(pushButton[5][4], SIGNAL(clicked(bool)), this, SLOT(click54()));
    connect(pushButton[5][5], SIGNAL(clicked(bool)), this, SLOT(click55()));
    connect(pushButton[5][6], SIGNAL(clicked(bool)), this, SLOT(click56()));
    connect(pushButton[5][7], SIGNAL(clicked(bool)), this, SLOT(click57()));
    connect(pushButton[6][0], SIGNAL(clicked(bool)), this, SLOT(click60()));
    connect(pushButton[6][1], SIGNAL(clicked(bool)), this, SLOT(click61()));
    connect(pushButton[6][2], SIGNAL(clicked(bool)), this, SLOT(click62()));
    connect(pushButton[6][3], SIGNAL(clicked(bool)), this, SLOT(click63()));
    connect(pushButton[6][4], SIGNAL(clicked(bool)), this, SLOT(click64()));
    connect(pushButton[6][5], SIGNAL(clicked(bool)), this, SLOT(click65()));
    connect(pushButton[6][6], SIGNAL(clicked(bool)), this, SLOT(click66()));
    connect(pushButton[6][7], SIGNAL(clicked(bool)), this, SLOT(click67()));
    connect(pushButton[7][0], SIGNAL(clicked(bool)), this, SLOT(click70()));
    connect(pushButton[7][1], SIGNAL(clicked(bool)), this, SLOT(click71()));
    connect(pushButton[7][2], SIGNAL(clicked(bool)), this, SLOT(click72()));
    connect(pushButton[7][3], SIGNAL(clicked(bool)), this, SLOT(click73()));
    connect(pushButton[7][4], SIGNAL(clicked(bool)), this, SLOT(click74()));
    connect(pushButton[7][5], SIGNAL(clicked(bool)), this, SLOT(click75()));
    connect(pushButton[7][6], SIGNAL(clicked(bool)), this, SLOT(click76()));
    connect(pushButton[7][7], SIGNAL(clicked(bool)), this, SLOT(click77()));
    label1=new QLabel(this);
    label1->setStyleSheet("border-image:url(:/picture/images/blackbright.jpg)");
    label1->setGeometry(1050,100,70,70);
    label1->show();
    label2=new QLabel(this);
    label2->setStyleSheet("border-image:url(:/picture/images/whitebright.jpg)");
    label2->setGeometry(1050,200,70,70);
    label2->show();
    label3=new QLabel(this);
    label3->setStyleSheet("border-image:url(:/picture/images/back.jpg)");
    label3->setText(QString::number(BLACK.Getmark()));
    label3->setFont(font);
    label3->setGeometry(1150,110,60,50);
    label3->show();
    label4=new QLabel(this);
    label4->setStyleSheet("border-image:url(:/picture/images/back.jpg)");
    label4->setText(QString::number(WHITE.Getmark()));
    label4->setFont(font);
    label4->setGeometry(1150,210,60,50);
    label4->show();
    label5=new QLabel(this);
    label5->setStyleSheet("border-image:url(:/picture/images/back.jpg)");
    label5->setFont(font);
    label5->setGeometry(1050,410,200,50);
    label5->show();
    font.setPointSize(20);
    label6=new QLabel(this);
    label6->setStyleSheet("border-image:url(:/picture/images/back.jpg)");
    label6->setFont(font);
    label6->setGeometry(1010,610,300,100);
    label6->show();
}
void MainWindow::play_black_double()
{
    BLACK.Setturn();
    prepare();
    player(false);
}
void MainWindow::play_white_double()
{
    WHITE.Setturn();
    prepare();
    player(false);
}
void MainWindow::play_black_single()
{
    BLACK.Setturn();
    prepare();
    player(true);
}
void MainWindow::play_white_single()
{
    WHITE.Setturn();
    prepare();
    player(true);
}
void MainWindow::clear_window()
{
    delete label1;
    delete pushButton1;
    delete pushButton2;
    delete pushButton3;
    delete pushButton4;
    delete pushButton5;
}
void MainWindow::reset_window()
{
    setFixedSize(1024,1024);
    setStyleSheet("border-image:url(:/picture/images/timg.jpg)");
    QFont font;
    font.setPointSize(50);
    label1=new QLabel(this);
    label1->setStyleSheet("border-image:url(:/picture/images/back.jpg)");
    label1->setGeometry(312,162,400,740);
    label1->setText("  翻转棋\n\n\n\n\n\n");
    label1->setFont(font);
    font.setPointSize(30);
    pushButton1=new QPushButton(this);
    pushButton1->setText("双人模式");
    pushButton1->setFont(font);
    pushButton1->setStyleSheet("border-image:url()");
    pushButton1->setGeometry(362,302,300,100);
    connect(pushButton1,SIGNAL(clicked(bool)),this,SLOT(mainmenu_1()));
    pushButton2=new QPushButton(this);
    pushButton2->setText("人机模式");
    pushButton2->setFont(font);
    pushButton2->setStyleSheet("border-image:url()");
    pushButton2->setGeometry(362,422,300,100);
    connect(pushButton2,SIGNAL(clicked(bool)),this,SLOT(mainmenu_2()));
    pushButton3=new QPushButton(this);
    pushButton3->setText("设置");
    pushButton3->setFont(font);
    pushButton3->setStyleSheet("border-image:url()");
    pushButton3->setGeometry(362,542,300,100);
    connect(pushButton3,SIGNAL(clicked(bool)),this,SLOT(mainmenu_3()));
    pushButton4=new QPushButton(this);
    pushButton4->setText("开发者信息");
    pushButton4->setFont(font);
    pushButton4->setStyleSheet("border-image:url()");
    pushButton4->setGeometry(362,662,300,100);
    connect(pushButton4,SIGNAL(clicked(bool)),this,SLOT(mainmenu_4()));
    pushButton5=new QPushButton(this);
    pushButton5->setText("退出游戏");
    pushButton5->setFont(font);
    pushButton5->setStyleSheet("border-image:url()");
    pushButton5->setGeometry(362,782,300,100);
    connect(pushButton5,SIGNAL(clicked(bool)),this,SLOT(mainmenu_5()));
    label1->show();
    pushButton1->show();
    pushButton2->show();
    pushButton3->show();
    pushButton4->show();
    pushButton5->show();
}
