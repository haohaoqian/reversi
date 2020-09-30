//process.cpp
#include"definition.h"
#include"chessboard.h"
#include"direction.h"
#include"mainwindow.h"
#include<iostream>
#include<QtWidgets>
#include<fstream>
#include<Windows.h>
#undef max
using namespace std;
black BLACK;
white WHITE;
List P;
extern QPushButton *pushButton1;
extern QPushButton *pushButton2;
extern QPushButton *pushButton3;
extern QPushButton *pushButton4;
extern QPushButton *pushButton5;
extern QLabel *label1;
extern QLabel *label2;
extern QLabel *label3;
extern QLabel *label4;
extern QLabel *label5;
extern QLabel *label6;
QLabel *label7;
QLabel *label[8][8]={NULL};
extern QPushButton *pushButton[8][8];
bool able = true;
int xp=0,yp=0;
int chess_board_[8][8]={0};
int chess_board__[8][8]={0};
int TURN;
bool M;
void in_case_nosettings()//如果配置文件不存在，自动重新生成默认配置文件
{
    bool sign = false;
    ifstream ip;
    ofstream op;
    ip.open("history",ios_base::binary);
    if (!ip)
        sign = true;
    ip.close();
    if (sign)
    {
        int a = 0;
        op.open("history", ios_base::trunc | ios_base::binary);
        op.write((char*)&a, 4);
        op.write((char*)&a, 4);
        op.write((char*)&a, 4);
        op.close();
    }
    ip.open("setting",ios_base::binary);
    if (!ip)
        sign = true;
    ip.close();
    if (sign)
    {
        bool a = false;
        op.open("setting", ios_base::trunc | ios_base::binary);
        op.write((char*)&a, 1);
        op.close();
    }
}
void count(int &a, int &b)
{
    a = b = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            switch (chess_board[i][j])
            {
            case 1:a++; break;
            case 2:b++; break;
            }
}
void print_chess(int i, ofstream& p)
{
    switch (i)
    {
    case 1:p << "  ●"; break;
    case 2:p << "  ○"; break;
    case 3:p << " ×"; break;
    case 0:p << "    "; break;
    }
}
bool judge_able(int x, int y, int a)//判断棋盘上某一位置能否落子
//分为8个方向逐一判断，有一个方向可以翻转即可落子
{
    if (!(chess_board[x][y] == 0 || chess_board[x][y] == 3))
        return false;
    bool sign = false;
    bool sign1 = false, sign2 = false;
    for (int i = x + 1; i < 8; i++)
    {
        if (chess_board[i][y] == a)
        {
            sign2 = true;
            break;
        }
        else if (chess_board[i][y] == 0 || chess_board[i][y] == 3)
            break;
        else
            sign1 = true;
    }
    direction[0] = sign1 && sign2;
    sign1 = false, sign2 = false;
    for (int i = x - 1; i >= 0; i--)
    {
        if (chess_board[i][y] == a)
        {
            sign2 = true;
            break;
        }
        else if (chess_board[i][y] == 0 || chess_board[i][y] == 3)
            break;
        else
            sign1 = true;
    }
    direction[1] = sign1 && sign2;
    sign1 = false, sign2 = false;
    for (int i = y + 1; i < 8; i++)
    {
        if (chess_board[x][i] == a)
        {
            sign2 = true;
            break;
        }
        else if (chess_board[x][i] == 0 || chess_board[x][i] == 3)
            break;
        else
            sign1 = true;
    }
    direction[2] = sign1 && sign2;
    sign1 = false, sign2 = false;
    for (int i = y - 1; i >= 0; i--)
    {
        if (chess_board[x][i] == a)
        {
            sign2 = true;
            break;
        }
        else if (chess_board[x][i] == 0 || chess_board[x][i] == 3)
            break;
        else
            sign1 = true;
    }
    direction[3] = sign1 && sign2;
    sign1 = false, sign2 = false;
    for (int i = 1;; i++)
    {
        if (x + i >= 8 || y + i >= 8)
            break;
        else if (chess_board[x + i][y + i] == a)
        {
            sign2 = true;
            break;
        }
        else if (chess_board[x + i][y + i] == 0 || chess_board[x + i][y + i] == 3)
            break;
        else
            sign1 = true;
    }
    direction[4] = sign1 && sign2;
    sign1 = false, sign2 = false;
    for (int i = 1;; i++)
    {
        if (x + i >= 8 || y - i < 0)
            break;
        else if (chess_board[x + i][y - i] == a)
        {
            sign2 = true;
            break;
        }
        else if (chess_board[x + i][y - i] == 0 || chess_board[x + i][y - i] == 3)
            break;
        else
            sign1 = true;
    }
    direction[5] = sign1 && sign2;
    sign1 = false, sign2 = false;
    for (int i = 1;; i++)
    {
        if (x - i < 0 || y + i >= 8)
            break;
        else if (chess_board[x - i][y + i] == a)
        {
            sign2 = true;
            break;
        }
        else if (chess_board[x - i][y + i] == 0 || chess_board[x - i][y + i] == 3)
            break;
        else
            sign1 = true;
    }
    direction[6] = sign1 && sign2;
    sign1 = false, sign2 = false;
    for (int i = 1;; i++)
    {
        if (x - i < 0 || y - i < 0)
            break;
        else if (chess_board[x - i][y - i] == a)
        {
            sign2 = true;
            break;
        }
        else if (chess_board[x - i][y - i] == 0 || chess_board[x - i][y - i] == 3)
            break;
        else
            sign1 = true;
    }
    direction[7] = sign1 && sign2;
    sign = direction[0] || direction[1] || direction[2] || direction[3] || direction[4] || direction[5] || direction[6] || direction[7];
    return sign;
}
void show_position(int a,int b,int c)
{
    switch(c)
    {
    case 1:label6->setText(" 黑棋落子（"+QString::number(a+1)+","+QString::number(b+1)+"）");break;
    case 2:label6->setText(" 白棋落子（"+QString::number(a+1)+","+QString::number(b+1)+"）");
    }
}
void MainWindow::click00()
{
  if (judge_able(0, 0, TURN))
   {
     xp = 0; yp = 0;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click01()
{
  if (judge_able(0, 1, TURN))
   {
     xp = 0; yp = 1;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click02()
{
  if (judge_able(0, 2, TURN))
   {
     xp = 0; yp = 2;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click03()
{
  if (judge_able(0, 3, TURN))
   {
     xp = 0; yp = 3;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click04()
{
  if (judge_able(0, 4, TURN))
   {
     xp = 0; yp = 4;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click05()
{
  if (judge_able(0, 5, TURN))
   {
     xp = 0; yp = 5;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click06()
{
  if (judge_able(0, 6, TURN))
   {
     xp = 0; yp = 6;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click07()
{
  if (judge_able(0, 7, TURN))
   {
     xp = 0; yp = 7;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click10()
{
  if (judge_able(1, 0, TURN))
   {
     xp = 1; yp = 0;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click11()
{
  if (judge_able(1, 1, TURN))
   {
     xp = 1; yp = 1;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click12()
{
  if (judge_able(1, 2, TURN))
   {
     xp = 1; yp = 2;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click13()
{
  if (judge_able(1, 3, TURN))
   {
     xp = 1; yp = 3;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click14()
{
  if (judge_able(1, 4, TURN))
   {
     xp = 1; yp = 4;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click15()
{
  if (judge_able(1, 5, TURN))
   {
     xp = 1; yp = 5;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click16()
{
  if (judge_able(1, 6, TURN))
   {
     xp = 1; yp = 6;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click17()
{
  if (judge_able(1, 7, TURN))
   {
     xp = 1; yp = 7;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click20()
{
  if (judge_able(2, 0, TURN))
   {
     xp = 2; yp = 0;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click21()
{
  if (judge_able(2, 1, TURN))
   {
     xp = 2; yp = 1;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click22()
{
  if (judge_able(2, 2, TURN))
   {
     xp = 2; yp = 2;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click23()
{
  if (judge_able(2, 3, TURN))
   {
     xp = 2; yp = 3;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click24()
{
  if (judge_able(2, 4, TURN))
   {
     xp = 2; yp = 4;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click25()
{
  if (judge_able(2, 5, TURN))
   {
     xp = 2; yp = 5;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click26()
{
  if (judge_able(2, 6, TURN))
   {
     xp = 2; yp = 6;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click27()
{
  if (judge_able(2, 7, TURN))
   {
     xp = 2; yp = 7;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click30()
{
  if (judge_able(3, 0, TURN))
   {
     xp = 3; yp = 0;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click31()
{
  if (judge_able(3, 1, TURN))
   {
     xp = 3; yp = 1;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click32()
{
  if (judge_able(3, 2, TURN))
   {
     xp = 3; yp = 2;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click35()
{
  if (judge_able(3, 5, TURN))
   {
     xp = 3; yp = 5;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click36()
{
  if (judge_able(3, 6, TURN))
   {
     xp = 3; yp = 6;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click37()
{
  if (judge_able(3, 7, TURN))
   {
     xp = 3; yp = 7;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click40()
{
  if (judge_able(4, 0, TURN))
   {
     xp = 4; yp = 0;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click41()
{
  if (judge_able(4, 1, TURN))
   {
     xp = 4; yp = 1;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click42()
{
  if (judge_able(4, 2, TURN))
   {
     xp = 4; yp = 2;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click45()
{
  if (judge_able(4, 5, TURN))
   {
     xp = 4; yp = 5;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click46()
{
  if (judge_able(4, 6, TURN))
   {
     xp = 4; yp = 6;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click47()
{
  if (judge_able(4, 7, TURN))
   {
     xp = 4; yp = 7;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click50()
{
  if (judge_able(5, 0, TURN))
   {
     xp = 5; yp = 0;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click51()
{
  if (judge_able(5, 1, TURN))
   {
     xp = 5; yp = 1;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click52()
{
  if (judge_able(5, 2, TURN))
   {
     xp = 5; yp = 2;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click53()
{
  if (judge_able(5, 3, TURN))
   {
     xp = 5; yp = 3;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click54()
{
  if (judge_able(5, 4, TURN))
   {
     xp = 5; yp = 4;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click55()
{
  if (judge_able(5, 5, TURN))
   {
     xp = 5; yp = 5;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click56()
{
  if (judge_able(5, 6, TURN))
   {
     xp = 5; yp = 6;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click57()
{
  if (judge_able(5, 7, TURN))
   {
     xp = 5; yp = 7;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click60()
{
  if (judge_able(6, 0, TURN))
   {
     xp = 6; yp = 0;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click61()
{
  if (judge_able(6, 1, TURN))
   {
     xp = 6; yp = 1;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click62()
{
  if (judge_able(6, 2, TURN))
   {
     xp = 6; yp = 2;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click63()
{
  if (judge_able(6, 3, TURN))
   {
     xp = 6; yp = 3;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click64()
{
  if (judge_able(6, 4, TURN))
   {
     xp = 6; yp = 4;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click65()
{
  if (judge_able(6, 5, TURN))
   {
     xp = 6; yp = 5;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click66()
{
  if (judge_able(6, 6, TURN))
   {
     xp = 6; yp = 6;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click67()
{
  if (judge_able(6, 7, TURN))
   {
     xp = 6; yp = 7;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click70()
{
  if (judge_able(7, 0, TURN))
   {
     xp = 7; yp = 0;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click71()
{
  if (judge_able(7, 1, TURN))
   {
     xp = 7; yp = 1;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click72()
{
  if (judge_able(7, 2, TURN))
   {
     xp = 7; yp = 2;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click73()
{
  if (judge_able(7, 3, TURN))
   {
     xp = 7; yp = 3;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click74()
{
  if (judge_able(7, 4, TURN))
   {
     xp = 7; yp = 4;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click75()
{
  if (judge_able(7, 5, TURN))
   {
     xp = 7; yp = 5;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click76()
{
  if (judge_able(7, 6, TURN))
   {
     xp = 7; yp = 6;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::click77()
{
  if (judge_able(7, 7, TURN))
   {
     xp = 7; yp = 7;
     show_position(xp, yp, TURN);
     player_(M);
   }
   else
      label6->setText("所选位置不可落子!!");
}
void MainWindow::print_chessboard(ofstream& p)//向文件中打印棋子与棋盘,与屏幕打印函数重载
{
    p << "          1       2       3       4       5       6       7       8" << endl;
    p << "     ┌───┬───┬───┬───┬───┬───┬───┬───┐" << endl;
    for (int i = 0; i < 7; i++)
    {
        p << i + 1;
        for (int j = 0; j < 8; j++)
        {
            p << "   │";
            print_chess(chess_board[i][j], p);
        }
        p << "   │" << " " << i + 1 << endl;
        p << "     ├───┼───┼───┼───┼───┼───┼───┼───┤" << endl;
    }
    p << "8";
    for (int j = 0; j < 8; j++)
    {
        p << "   │";
        print_chess(chess_board[7][j], p);
    }
    p << "   │" << " 8" << endl;
    p << "     └───┴───┴───┴───┴───┴───┴───┴───┘" << endl;
    p << "          1       2       3       4       5       6       7       8" << endl;
}
void MainWindow::print_chessboard()
{
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if(chess_board[i][j]!=chess_board_[i][j])
            {
                if(label[i][j]!=NULL)
                    delete label[i][j];
                switch(chess_board[i][j])
                {
                case 0:case 3:break;
                case 1:
                    label[i][j]=new QLabel(this);
                    label[i][j]->setStyleSheet("border-image:url(:/picture/images/blackdeep.jpg)");
                    label[i][j]->setGeometry(20+124*j,20+124*i,83,83);
                    label[i][j]->show();
                    break;
                case 2:
                    label[i][j]=new QLabel(this);
                    label[i][j]->setStyleSheet("border-image:url(:/picture/images/whitedeep.jpg)");
                    label[i][j]->setGeometry(20+124*j,20+124*i,83,83);
                    label[i][j]->show();
                    break;
                }
                chess_board_[i][j]=chess_board[i][j];
            }
}
void MainWindow::clear_chessboard()
{
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        {
            if(label[i][j]!=NULL)
            {
                delete label[i][j];
                label[i][j]=NULL;
            }
            if(pushButton[i][j]!=NULL)
            {
                delete pushButton[i][j];
                pushButton[i][j]=NULL;
            }
        }
}
void load_setting()
{
    ifstream ip;
    ip.open("setting", ios_base::in | ios_base::binary);
    ip.read((char*)&able, 1);
    ip.close();
}

void reverse(int x, int y)//落子后翻转棋子
{
    if (direction[0])
    {
        for (int i = x + 1;; i++)
        {
            if (chess_board[i][y] == chess_board[x][y])
                break;
            else
                chess_board[i][y] = chess_board[x][y];
        }
    }
    if (direction[1])
    {
        for (int i = x - 1;; i--)
        {
            if (chess_board[i][y] == chess_board[x][y])
                break;
            else
                chess_board[i][y] = chess_board[x][y];
        }
    }
    if (direction[2])
    {
        for (int i = y + 1;; i++)
        {
            if (chess_board[x][i] == chess_board[x][y])
                break;
            else
                chess_board[x][i] = chess_board[x][y];
        }
    }
    if (direction[3])
    {
        for (int i = y - 1;; i--)
        {
            if (chess_board[x][i] == chess_board[x][y])
                break;
            else
                chess_board[x][i] = chess_board[x][y];
        }
    }
    if (direction[4])
    {
        for (int i = 1;; i++)
        {
            if (chess_board[x + i][y + i] == chess_board[x][y])
                break;
            else
                chess_board[x + i][y + i] = chess_board[x][y];
        }
    }
    if (direction[5])
    {
        for (int i = 1;; i++)
        {
            if (chess_board[x + i][y - i] == chess_board[x][y])
                break;
            else
                chess_board[x + i][y - i] = chess_board[x][y];
        }
    }
    if (direction[6])
    {
        for (int i = 1;; i++)
        {
            if (chess_board[x - i][y + i] == chess_board[x][y])
                break;
            else
                chess_board[x - i][y + i] = chess_board[x][y];
        }
    }
    if (direction[7])
    {
        for (int i = 1;; i++)
        {
            if (chess_board[x - i][y - i] == chess_board[x][y])
                break;
            else
                chess_board[x - i][y - i] = chess_board[x][y];
        }
    }
}
bool show_able(int a)//将可落子位置的信息加入数组
{
    bool sign = false;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (judge_able(i, j, a))
            {
                chess_board[i][j] = 3;
                sign = true;
            }
    return sign;
}
void history(int &computer, int &player, int &tie)
{
    ifstream ip;
    ip.open("history", ios_base::in | ios_base::binary);
    ip.read((char*)&computer, 4);
    ip.read((char*)&player, 4);
    ip.read((char*)&tie, 4);
    ip.close();
}
void MainWindow::input_position()
{
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if(chess_board__[i][j]!=chess_board[i][j])
            {
                switch(chess_board[i][j])
                {
                case 1:case 2:
                    if(pushButton[i][j]!=NULL)
                    {
                        delete pushButton[i][j];
                        pushButton[i][j]=NULL;
                    }
                    break;
                case 3:
                    pushButton[i][j]->setStyleSheet("border-image:url(:/picture/images/avli.jpg)");
                    break;
                case 0:
                    pushButton[i][j]->setStyleSheet("border-image:url(:/picture/images/deepback.jpg)");
                }
                chess_board__[i][j]=chess_board[i][j];
            }
}
void reset()//重置各变量
{
    for (int i = 0; i < 8; i++)
    {
        direction[i] = false;
        for (int j = 0; j < 8; j++)
        {
            chess_board[i][j] = 0;
            chess_board_[i][j] = 0;
            chess_board__[i][j] = 0;
        }
    }
    chess_board[3][3] = chess_board[4][4] = 1;
    chess_board[3][4] = chess_board[4][3] = 2;
    BLACK.Setmark(2);
    BLACK.Setable(true);
    BLACK.Setturn(false);
    BLACK.Set(-1, -1);
    WHITE.Setmark(2);
    WHITE.Setable(true);
    WHITE.Setturn(false);
    WHITE.Set(-1, -1);
}
void free_memory()
{
    while (true)
    {
        P.Delete();
        if (P.Gethead() == NULL)
            break;
    }
}
void Free()
{
    reset();
    free_memory();
}
void MainWindow::save()
{
    reset();
    ofstream op;
    op.open("record", ios_base::app);
    int xp, yp;
    bool turn = false;
    int turn1;
    int black, white;
    op << "起始" << endl;
    print_chessboard(op);
    op << "————————————————————————————" << endl;
    for (int t = 1;; t++)
    {
        if (P.read(xp, yp, turn, t));
        else break;
        op << "第" << t << "步" << endl;
        if (turn)
            turn1 = 2;
        else
            turn1 = 1;
        judge_able(xp - 1, yp - 1, turn1);
        chess_board[xp- 1][yp - 1] = turn1;
        reverse(xp - 1, yp - 1);
        count(black, white);
        BLACK.Setmark(black);
        WHITE.Setmark(white);
        print_chessboard(op);
        switch (turn1)
        {
        case 1:BLACK.Set(xp, yp); op << "黑棋落子(" << BLACK.GetX() << "," << BLACK.GetY() << ")" << endl; break;
        case 2:WHITE.Set(xp, yp); op << "白棋落子(" << WHITE.GetX() << "," << WHITE.GetY() << ")" << endl; break;
        }
        op << "黑棋● " << BLACK.Getmark() << ":白棋○ " << WHITE.Getmark() << endl;
        op << "————————————————————————————" << endl;
    }
    if (BLACK.Getmark() > WHITE.Getmark())
        op << "黑棋● 胜利" << "(" << BLACK.Getmark() << ":" << WHITE.Getmark() << ")" << endl;
    else if (BLACK.Getmark() < WHITE.Getmark())
        op << "白棋○ 胜利" << "(" << WHITE.Getmark() << ":" << BLACK.Getmark() << ")" << endl;
    else
        op << "平局" << "(" << BLACK.Getmark() << ":" << WHITE.Getmark() << ")" << endl;
    op << "————————————————————————————" << endl << endl << endl << endl;
    op.close();
    QMessageBox::information(NULL,"翻转棋-保存棋局","棋局已保存至“record”文件",QMessageBox::Yes,QMessageBox::Yes);
    delete label6;
    delete pushButton2;
    delete pushButton3;
    Free();
    reset_window();
}
void MainWindow::nosave()
{
    delete label6;
    delete pushButton2;
    delete pushButton3;
    Free();
    reset_window();
}
bool human_being()
{
    int m, n;
    if (judge_able(0, 0, 1))
    {
        m = 0;
        n = 0;
    }
    else if (judge_able(0, 7, 1))
    {
        m = 0;
        n = 7;
    }
    else if (judge_able(7, 0, 1))
    {
        m = 7;
        n = 0;
    }
    else if (judge_able(7, 7, 1))
    {
        m = 7;
        n = 7;
    }
    else
    {
        int saver[8][8];
        int count, max = 0;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                saver[i][j] = chess_board[i][j];
        for (int m1 = 0; m1 < 8; m1++)
            if (judge_able(0, m1, 1))
            {
                count = 0;
                chess_board[0][m1] = 1;
                reverse(0, m1);
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                        if (chess_board[i][j] == 2)
                            count++;
                if (count > max)
                {
                    max = count;
                    m = 0;
                    n = m1;
                }
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                        chess_board[i][j] = saver[i][j];
            }
        for (int m1 = 0; m1 < 8; m1++)
            if (judge_able(7, m1, 1))
            {
                count = 0;
                chess_board[7][m1] = 1;
                reverse(7, m1);
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                        if (chess_board[i][j] == 2)
                            count++;
                if (count > max)
                {
                    max = count;
                    m = 7;
                    n = m1;
                }
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                        chess_board[i][j] = saver[i][j];
            }
        for (int m1 = 0; m1 < 8; m1++)
            if (judge_able(m1, 0, 1))
            {
                count = 0;
                chess_board[m1][0] = 1;
                reverse(m1, 0);
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                        if (chess_board[i][j] == 2)
                            count++;
                if (count > max)
                {
                    max = count;
                    m = m1;
                    n = 0;
                }
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                        chess_board[i][j] = saver[i][j];
            }
        for (int m1 = 0; m1 < 8; m1++)
            if (judge_able(m1, 7, 1))
            {
                count = 0;
                chess_board[m1][7] = 1;
                reverse(m1, 7);
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                        if (chess_board[i][j] == 2)
                            count++;
                if (count > max)
                {
                    max = count;
                    m = m1;
                    n = 7;
                }
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                        chess_board[i][j] = saver[i][j];
            }
        if (max == 0)
        {
            for (int m1 = 1; m1 < 7; m1++)
                for (int n1 = 1; n1 < 7; n1++)
                    if (judge_able(m1, n1, 1))
                    {
                        count = 0;
                        chess_board[m1][n1] = 1;
                        reverse(m1, n1);
                        for (int i = 0; i < 8; i++)
                            for (int j = 0; j < 8; j++)
                                if (chess_board[i][j] == 2)
                                    count++;
                        if (count > max)
                        {
                            max = count;
                            m = m1;
                            n = n1;
                        }
                        for (int i = 0; i < 8; i++)
                            for (int j = 0; j < 8; j++)
                                chess_board[i][j] = saver[i][j];
                    }
        }
        if (max == 0)
            return false;
    }
    judge_able(m, n, 1);
    chess_board[m][n] = 1;
    reverse(m, n);
    return true;
}
bool I_am_AI(int &xp, int &yp)
{
    int saver[8][8];
    int m = -2, n = -2;
    int max = 0, count = 0;
    int pp = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (chess_board[i][j] == 3)
                chess_board[i][j] = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            saver[i][j] = chess_board[i][j];
    if (judge_able(0, 0, 2) || judge_able(0, 7, 2) || judge_able(7, 0, 2) || judge_able(7, 7, 2))
    {
        if (judge_able(0, 0, 2))
        {
            chess_board[0][0] = 2;
            reverse(0, 0);
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                    if (chess_board[i][j] == 2)
                        count++;
            if (count > max)
            {
                max = count;
                m = 0;
                n = 0;
            }
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                    chess_board[i][j] = saver[i][j];
        }
        count = 0;
        if (judge_able(0, 7, 2))
        {
            chess_board[0][7] = 2;
            reverse(0, 7);
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                    if (chess_board[i][j] == 2)
                        count++;
            if (count > max)
            {
                max = count;
                m = 0;
                n = 7;
            }
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                    chess_board[i][j] = saver[i][j];
        }
        count = 0;
        if (judge_able(7, 0, 2))
        {
            chess_board[7][0] = 2;
            reverse(7, 0);
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                    if (chess_board[i][j] == 2)
                        count++;
            if (count > max)
            {
                max = count;
                m = 7;
                n = 0;
            }
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                    chess_board[i][j] = saver[i][j];
        }
        count = 0;
        if (judge_able(7, 7, 2))
        {
            chess_board[7][7] = 2;
            reverse(7, 7);
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                    if (chess_board[i][j] == 2)
                        count++;
            if (count > max)
            {
                max = count;
                m = 7;
                n = 7;
            }
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                    chess_board[i][j] = saver[i][j];
        }
        xp = m;
        yp = n;
    }
    else
    {
        max = 0; count = 0;
        while (m == -2)
        {
            for (int m1 = 0; m1 < 8; m1++)
                for (int n1 = 0; n1 < 8; n1++)
                {
                    bool sign11 = false, sign12 = false;
                    if (judge_able(m1, n1, 2))
                    {
                        chess_board[m1][n1] = 2;
                        reverse(m1, n1);
                        switch (pp)
                        {
                        case 0:
                            if (judge_able(0, 0, 1) || judge_able(0, 7, 1) || judge_able(7, 0, 1) || judge_able(7, 7, 1))
                            {
                                for (int i = 0; i < 8; i++)
                                    for (int j = 0; j < 8; j++)
                                        chess_board[i][j] = saver[i][j];
                                continue;
                            }
                            for (int k = 1; k < 7; k++)
                                if (judge_able(0, k, 1) || judge_able(k, 0, 1) || judge_able(7, k, 1) || judge_able(k, 7, 1))
                                {
                                    for (int i = 0; i < 8; i++)
                                        for (int j = 0; j < 8; j++)
                                            chess_board[i][j] = saver[i][j];
                                    continue;
                                }
                            break;
                        case 1:
                            if (judge_able(0, 0, 1) || judge_able(0, 7, 1) || judge_able(7, 0, 1) || judge_able(7, 7, 1))
                            {
                                for (int i = 0; i < 8; i++)
                                    for (int j = 0; j < 8; j++)
                                        chess_board[i][j] = saver[i][j];
                                continue;
                            }
                            break;
                        default:;
                        }
                        sign11 = human_being();
                        for (int i = 0; i < 8; i++)
                        {
                            for (int j = 0; j < 8; j++)
                                if (judge_able(i, j, 2))
                                {
                                    sign12 = true;
                                    break;
                                }
                            if (sign12)
                                break;
                        }
                        if (!sign11)
                        {
                            m = m1;
                            n = n1;
                            if (sign12)
                            {
                                for (int i = 0; i < 8; i++)
                                    for (int j = 0; j < 8; j++)
                                        chess_board[i][j] = saver[i][j];
                                xp = m;
                                yp = n;
                                return true;
                            }
                            else
                                if (BLACK.Getmark() < WHITE.Getmark())
                                {
                                    for (int i = 0; i < 8; i++)
                                        for (int j = 0; j < 8; j++)
                                            chess_board[i][j] = saver[i][j];
                                    xp = m;
                                    yp = n;
                                    return true;
                                }
                        }
                        else
                        {
                            if (sign12)
                            {
                                int saver1[8][8];
                                for (int i = 0; i < 8; i++)
                                    for (int j = 0; j < 8; j++)
                                        saver1[i][j] = chess_board[i][j];
                                for (int m2 = 0; m2 < 8; m2++)
                                    for (int n2 = 0; n2 < 8; n2++)
                                    {
                                        bool sign21 = false, sign22 = false;
                                        if (judge_able(m2, n2, 2))
                                        {
                                            chess_board[m2][n2] = 2;
                                            reverse(m2, n2);
                                            sign21 = human_being();
                                            for (int i = 0; i < 8; i++)
                                            {
                                                for (int j = 0; j < 8; j++)
                                                    if (judge_able(i, j, 2))
                                                    {
                                                        sign22 = true;
                                                        break;
                                                    }
                                                if (sign22)
                                                    break;
                                            }
                                            if (!sign21)
                                            {
                                                m = m1;
                                                n = n1;
                                                if (sign22)
                                                {
                                                    for (int i = 0; i < 8; i++)
                                                        for (int j = 0; j < 8; j++)
                                                            chess_board[i][j] = saver[i][j];
                                                    xp = m;
                                                    yp = n;
                                                    return true;
                                                }
                                                else
                                                    if (BLACK.Getmark() < WHITE.Getmark())
                                                    {
                                                        for (int i = 0; i < 8; i++)
                                                            for (int j = 0; j < 8; j++)
                                                                chess_board[i][j] = saver[i][j];
                                                        xp = m;
                                                        yp = n;
                                                        return true;
                                                    }
                                            }
                                            else
                                            {
                                                if (sign22)
                                                {
                                                    for (int i = 0; i < 8; i++)
                                                        for (int j = 0; j < 8; j++)
                                                            if (chess_board[i][j] == 2)
                                                                count++;
                                                    if (count > max)
                                                    {
                                                        max = count;
                                                        m = m1;
                                                        n = n1;
                                                    }
                                                }
                                                else
                                                {
                                                    m = m1;
                                                    n = n1;
                                                }
                                                for (int i = 0; i < 8; i++)
                                                    for (int j = 0; j < 8; j++)
                                                        chess_board[i][j] = saver1[i][j];
                                            }
                                        }
                                    }
                            }
                            else
                            {
                                m = m1;
                                n = n1;
                            }
                            for (int i = 0; i < 8; i++)
                                for (int j = 0; j < 8; j++)
                                    chess_board[i][j] = saver[i][j];
                        }
                    }
                }
            if (m == -2 && n == -2)
                pp++;
        }
        xp = m;
        yp = n;
    }
    return true;
}
void MainWindow::escape()
{
    QFont font;
    font.setPointSize(30);
    label7=new QLabel(this);
    label7->setStyleSheet("border-image:url(:/picture/images/back.jpg)");
    label7->setGeometry(312,302,400,420);
    label7->setText("  确认要退出吗？\n\n\n\n\n");
    label7->setFont(font);
    font.setPointSize(20);
    pushButton2=new QPushButton(this);
    pushButton2->setText("取消");
    pushButton2->setFont(font);
    pushButton2->setStyleSheet("border-image:url()");
    pushButton2->setGeometry(362,442,300,100);
    connect(pushButton2,SIGNAL(clicked(bool)),this,SLOT(escape_1()));
    pushButton3=new QPushButton(this);
    pushButton3->setText("退出");
    pushButton3->setFont(font);
    pushButton3->setStyleSheet("border-image:url()");
    pushButton3->setGeometry(362,562,300,100);
    connect(pushButton3,SIGNAL(clicked(bool)),this,SLOT(escape_2()));
    label7->show();
    pushButton2->show();
    pushButton3->show();
}
void MainWindow::escape_1()
{
    delete pushButton2;
    delete pushButton3;
    delete label7;
}
void MainWindow::escape_2()
{
    clear_chessboard();
    delete pushButton1;
    delete pushButton2;
    delete pushButton3;
    delete label1;
    delete label2;
    delete label3;
    delete label4;
    delete label5;
    delete label6;
    delete label7;
    reset();
    reset_window();
}
void MainWindow::player_(bool m)
{
    int turn;
    int black,white;
    if (BLACK.Getturn())
        turn = 1;
    else
        turn = 2;
    record* p = new record();
    switch (turn)
    {
    case 1:BLACK.Set(xp+1, yp+1); *p = BLACK; break;
    case 2:WHITE.Set(xp+1, yp+1); *p = WHITE;
    }
    P.insert(p);
    chess_board[xp][yp] = turn;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (chess_board[i][j] == 3)
                chess_board[i][j] = 0;
    reverse(xp, yp);
    count(black, white);
    BLACK.Setmark(black);
    WHITE.Setmark(white);
    WHITE.Setturn();
    BLACK.Setturn();
    player(m);
}
void MainWindow::save_choice()
{
    if (BLACK.Getmark() > WHITE.Getmark())
        QMessageBox::information(NULL,"游戏结束","黑棋胜利！",QMessageBox::Yes,QMessageBox::Yes);
    else if (BLACK.Getmark() < WHITE.Getmark())
        QMessageBox::information(NULL,"游戏结束","白棋胜利！",QMessageBox::Yes,QMessageBox::Yes);
    else
        QMessageBox::information(NULL,"游戏结束","平局",QMessageBox::Yes,QMessageBox::Yes);
    clear_chessboard();
    delete pushButton1;
    delete label1;
    delete label2;
    delete label3;
    delete label4;
    delete label5;
    delete label6;
    QFont font;
    font.setPointSize(30);
    label6=new QLabel(this);
    label6->setStyleSheet("border-image:url(:/picture/images/back.jpg)");
    label6->setGeometry(312,302,400,420);
    label6->setText("  要保存棋局吗？\n\n\n\n\n");
    label6->setFont(font);
    font.setPointSize(20);
    pushButton2=new QPushButton(this);
    pushButton2->setText("保存");
    pushButton2->setFont(font);
    pushButton2->setStyleSheet("border-image:url()");
    pushButton2->setGeometry(362,442,300,100);
    connect(pushButton2,SIGNAL(clicked(bool)),this,SLOT(save()));
    pushButton3=new QPushButton(this);
    pushButton3->setText("不保存");
    pushButton3->setFont(font);
    pushButton3->setStyleSheet("border-image:url()");
    pushButton3->setGeometry(362,562,300,100);
    connect(pushButton3,SIGNAL(clicked(bool)),this,SLOT(nosave()));
    label6->show();
    pushButton2->show();
    pushButton3->show();
}
void MainWindow::player_end(bool m)
{
    int computer, player, tie;
    ifstream ip;
    ip.open("history", ios_base::in | ios_base::binary);
    ip.read((char*)&computer, 4);
    ip.read((char*)&player, 4);
    ip.read((char*)&tie, 4);
    ip.close();
    ofstream op;
    op.open("history", ios_base::trunc | ios_base::binary);
    if (BLACK.Getmark() > WHITE.Getmark())
    {
        if (m)
        {
            player++;
            op.write((char*)&computer, 4);
            op.write((char*)&player, 4);
            op.write((char*)&tie, 4);
        }
    }
    else
    {
        if (BLACK.Getmark() < WHITE.Getmark())
        {
            if (m)
            {
                computer++;
                op.write((char*)&computer, 4);
                op.write((char*)&player, 4);
                op.write((char*)&tie, 4);
            }
        }
        else
        {
            if (m)
            {
                tie++;
                op.write((char*)&computer, 4);
                op.write((char*)&player, 4);
                op.write((char*)&tie, 4);
            }
        }
    }
    if (!m)
    {
        op.write((char*)&computer, 4);
        op.write((char*)&player, 4);
        op.write((char*)&tie, 4);
    }
    op.close();
    save_choice();
}
void MainWindow::player(bool m)
{
    int turn;
    bool sign = false, sign1 = false,sign2 = false;
    sign = sign1 = sign2 = false;
    if (BLACK.Getturn())
        turn = 1;
    else
        turn = 2;
    if (able)
        sign = show_able(turn);
    else
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
                if (judge_able(i, j, turn))
                {
                    sign = true;
                    break;
                }
            if (sign)
                break;
        }
    switch (turn)
    {
    case 1:BLACK.Setable(sign); break;
    case 2:WHITE.Setable(sign);
    }
    print_chessboard();
    label3->setText(QString::number(BLACK.Getmark()));
    label4->setText(QString::number(WHITE.Getmark()));
    //一方无处落子时，对方继续落子
    if (!sign)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
                if (judge_able(i, j, 3 - turn))
                {
                    sign1 = true;
                    break;
                }
            if (sign1)
                break;
        }
        switch (3 - turn)
        {
        case 1:BLACK.Setable(sign1); break;
        case 2:WHITE.Setable(sign1);
        }
        if (sign1)
        {
            BLACK.Setturn();
            WHITE.Setturn();
            if (BLACK.Getturn())
                turn = 1;
            else
                turn = 2;
            switch (turn)
            {
            case 1:label6->setText("白棋无处落子\n 黑棋继续"); break;
            case 2:label6->setText("黑棋无处落子\n 白棋继续");
            }
            if (able)
            {
                sign = show_able(turn);
                print_chessboard();
            }
        }
        //两方均无处落子游戏结束
        else
        {
            label6->setText("棋盘已无可落子处\n   游戏结束");
            sign2=true;
        }
    }
    if(sign2)
        player_end(m);
    else
    {
        TURN=turn;
        M=m;
        switch (turn)
        {
        case 1:
            label5->setText("黑棋回合");
            input_position(); break;
        case 2:
            label5->setText("白棋回合");
            if (m)
            {
                I_am_AI(xp, yp);
                show_position(xp,yp,2);
                judge_able(xp, yp, turn);
                player_(m);
            }
            else
               input_position();
        }
    }
}
