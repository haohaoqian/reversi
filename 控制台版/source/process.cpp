//process.cpp
#include"definition.h"
#include"chessboard.h"
#include"direction.h"
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<cstdlib>
#include<thread>
#include<graphics.h>
#pragma warning(disable:4715)
#undef max
using namespace std;
black BLACk;
white WHITe;
List P;
bool able = true;
void show()
{
	cout << "┌────────────────────────────────┐" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "│              ○●              │" << endl;
	cout << "│              ●○              │" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "└────────────────────────────────┘" << endl;
	Sleep(500);
	system("cls");
	cout << "┌────────────────────────────────┐" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "│              ○●○            │" << endl;
	cout << "│              ●○              │" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "└────────────────────────────────┘" << endl;
	Sleep(300);
	system("cls");
	cout << "┌────────────────────────────────┐" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "│              ○○○            │" << endl;
	cout << "│              ●○              │" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "└────────────────────────────────┘" << endl;
	Sleep(500);
	system("cls");
	cout << "┌────────────────────────────────┐" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "│              ○○○            │" << endl;
	cout << "│              ●○●            │" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "└────────────────────────────────┘" << endl;
	Sleep(300);
	system("cls");
	cout << "┌────────────────────────────────┐" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "│              ○○○            │" << endl;
	cout << "│              ●●●            │" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "└────────────────────────────────┘" << endl;
	Sleep(500);
	system("cls");
	cout << "┌────────────────────────────────┐" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "│              ○○○            │" << endl;
	cout << "│              ●●●            │" << endl;
	cout << "│              ○                │" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "└────────────────────────────────┘" << endl;
	Sleep(300);
	system("cls");
	cout << "┌────────────────────────────────┐" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "│              ○○○            │" << endl;
	cout << "│              ○○●            │" << endl;
	cout << "│              ○                │" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "└────────────────────────────────┘" << endl;
	Sleep(500);
	system("cls");
	cout << "┌────────────────────────────────┐" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "│              ○○○            │" << endl;
	cout << "│            ●○○●            │" << endl;
	cout << "│              ○                │" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "└────────────────────────────────┘" << endl;
	Sleep(300);
	system("cls");
	cout << "┌────────────────────────────────┐" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "│              ○○○            │" << endl;
	cout << "│            ●●●●            │" << endl;
	cout << "│              ○                │" << endl;
	cout << "│                                │" << endl;
	cout << "│                                │" << endl;
	cout << "└────────────────────────────────┘" << endl;
	Sleep(300);
}
void in_case_nosettings()//如果配置文件不存在，自动重新生成默认配置文件
{
	bool sign = false;
	ifstream ip;
	ofstream op;
	ip.open("history", ios_base::_Nocreate | ios_base::binary);
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
	ip.open("setting", ios_base::_Nocreate | ios_base::binary);
	if (!ip)
		sign = true;
	ip.close();
	if (sign)
	{
		bool a = true;
		op.open("setting", ios_base::trunc | ios_base::binary);
		op.write((char*)&a, 1);
		op.close();
	}
}
void programmer()
{
	char a;
	bool sign = false;
	while (true)
	{
		system("cls");
		cout << "┌────────────────────────────────────┐" << endl;
		cout << "│            #开发者信息#            │" << endl;
		cout << "│                                    │" << endl;
		cout << "│              @郝千越               │" << endl;
		cout << "│        July & August, 2019         │" << endl;
		cout << "│        Tsinghua University         │" << endl;
		cout << "│                                    │" << endl;
		cout << "│           [1]返回主菜单            │" << endl;
		cout << "│                                    │" << endl;
		cout << "└────────────────────────────────────┘" << endl;
		while (cin.peek() == '\n')
			getchar();
		a = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		switch (a)
		{
		case '1':sign = true; break;
		default:
			cout << "所选择功能不存在，请重新输入" << endl;
			Sleep(700); break;
		}
		if (sign == true)
			break;
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
void print_chess(int i)
{
	switch (i)
	{
	case 1:cout << " ●"; break;
	case 2:cout << " ○"; break;
	case 3:cout << " ×"; break;
	case 0:cout << "   "; break;
	}
}
void print_chessboard()//打印棋子与棋盘
{
	cout << "     1   2   3   4   5   6   7   8" << endl;
	cout << "  ┌───┬───┬───┬───┬───┬───┬───┬───┐" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << " " << i + 1;
		for (int j = 0; j < 8; j++)
		{
			cout << "│";
			print_chess(chess_board[i][j]);
		}
		cout << "│" << " " << i + 1 << endl;
		cout << "  ├───┼───┼───┼───┼───┼───┼───┼───┤" << endl;
	}
	cout << " 8";
	for (int j = 0; j < 8; j++)
	{
		cout << "│";
		print_chess(chess_board[7][j]);
	}
	cout << "│" << " 8" << endl;
	cout << "  └───┴───┴───┴───┴───┴───┴───┴───┘" << endl;
	cout << "     1   2   3   4   5   6   7   8" << endl;
}
template <typename T>
void print_chess(int i, T& p)
{
	switch (i)
	{
	case 1:p << "  ●"; break;
	case 2:p << "  ○"; break;
	case 3:p << " ×"; break;
	case 0:p << "    "; break;
	}
}
template <typename T>
void print_chessboard(T& p)//向文件中打印棋子与棋盘,与屏幕打印函数重载
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
void clear_makesure()
{
	char a;
	bool sign = false;
	while (true)
	{
		system("cls");
		cout << "┌───────────────────────────────┐" << endl;
		cout << "│       确定清空历史记录？      │" << endl;
		cout << "│                               │" << endl;
		cout << "│        [1]确认清空            │" << endl;
		cout << "│        [2]取消                │" << endl;
		cout << "│                               │" << endl;
		cout << "└───────────────────────────────┘" << endl;
		while (cin.peek() == '\n')
			getchar();
		a = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		ofstream op;
		int t = 0;
		switch (a)
		{
		case '1':
			op.open("history", ios_base::binary | ios_base::trunc);
			op.write((char*)&t, 4);
			op.write((char*)&t, 4);
			op.write((char*)&t, 4);
			op.close();
			sign = true; break;
		case '2':sign = true; break;
		default:
			cout << "所选择功能不存在，请重新输入" << endl;
			Sleep(700); break;
		}
		if (sign)
			break;
	}
}
void history()
{
	int computer, player, tie;
	ifstream ip;
	ip.open("history", ios_base::in | ios_base::binary);
	ip.read((char*)&computer, 4);
	ip.read((char*)&player, 4);
	ip.read((char*)&tie, 4);
	ip.close();
	char a;
	bool sign = false;
	while (true)
	{
		system("cls");
		cout << "        ——历史记录——       " << endl;
		cout << "           共开局";
		cout << player + computer + tie;
		cout << "次            " << endl;
		cout << "          玩家:计算机" << endl;
		cout << "           " << player << "      ";
		cout << computer << endl;
		cout << "            平局" << tie << "次" << endl;
		cout << "┌───────────────────────────────┐" << endl;
		cout << "│                               │" << endl;
		cout << "│      [1]返回                  │" << endl;
		cout << "│      [2]清空历史记录并返回    │" << endl;
		cout << "│                               │" << endl;
		cout << "└───────────────────────────────┘" << endl;
		while (cin.peek() == '\n')
			getchar();
		a = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		switch (a)
		{
		case '1':sign = true; break;
		case '2':clear_makesure(); sign = true; break;
		default:
			cout << "所选择功能不存在，请重新输入" << endl;
			Sleep(700); break;
		}
		if (sign)
			break;
	}
}
void input_position(int &x, int &y, int a)
{
	cout << "请输入落子位置  行数 列数" << endl;
	cout << "输入 0 0 退出棋局并返回" << endl;
	while (true)
	{
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		cin >> x;
		if (cin.fail() || x < 0 || x > 8)
		{
			x = -1;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), ' ');
			while (cin.peek() == ' ')
				getchar();
		}
		cin >> y;
		if (cin.fail() || y < 0 || y > 8)
		{
			y = -1;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		if (x == -1 || y == -1)
			cout << "请输入合法的坐标([1,1]-[8,8]之间)" << endl;
		else if (x == 0 && y == 0)
			break;
		else if (!judge_able(x - 1, y - 1, a))
		cout << "所选择位置不可落子，请重新输入" << endl;
		else break;
	}
}
void reset()//重置各变量
{
	for (int i = 0; i < 8; i++)
	{
		direction[i] = false;
		for (int j = 0; j < 8; j++)
			chess_board[i][j] = 0;
	}
	chess_board[3][3] = chess_board[4][4] = 1;
	chess_board[3][4] = chess_board[4][3] = 2;
	BLACk.Setmark(2);
	BLACk.Setable(true);
	BLACk.Setturn(false);
	BLACk.Set(-1, -1);
	WHITe.Setmark(2);
	WHITe.Setable(true);
	WHITe.Setturn(false);
	WHITe.Set(-1, -1);
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
void save()
{
	system("cls");
	cout << "┌────────────────────────────────┐" << endl;
	cout << "│         保存棋局中...          │" << endl;
	cout << "└────────────────────────────────┘" << endl;
	reset();
	ofstream op;
	op.open("record", ios_base::app);
	int x, y;
	bool turn = false;
	int turn1;
	int black, white;
	op << "起始" << endl;
	print_chessboard(op);
	op << "————————————————————————————" << endl;
	for (int t = 1;; t++)
	{
		if (P.read(x, y, turn, t));
		else break;
		op << "第" << t << "步" << endl;
		if (turn)
			turn1 = 2;
		else
			turn1 = 1;
		judge_able(x - 1, y - 1, turn1);
		chess_board[x - 1][y - 1] = turn1;
		reverse(x - 1, y - 1);
		count(black, white);
		BLACk.Setmark(black);
		WHITe.Setmark(white);
		print_chessboard(op);
		switch (turn1)
		{
		case 1:BLACk.Set(x, y); op << "黑棋落子(" << BLACk.GetX() << "," << BLACk.GetY() << ")" << endl; break;
		case 2:WHITe.Set(x, y); op << "白棋落子(" << WHITe.GetX() << "," << WHITe.GetY() << ")" << endl; break;
		}
		op << "黑棋● " << BLACk.Getmark() << ":白棋○ " << WHITe.Getmark() << endl;
		op << "————————————————————————————" << endl;
	}
	if (BLACk.Getmark() > WHITe.Getmark())
		op << "黑棋● 胜利" << "(" << BLACk.Getmark() << ":" << WHITe.Getmark() << ")" << endl;
	else if (BLACk.Getmark() < WHITe.Getmark())
		op << "白棋○ 胜利" << "(" << WHITe.Getmark() << ":" << BLACk.Getmark() << ")" << endl;
	else
		op << "平局" << "(" << BLACk.Getmark() << ":" << WHITe.Getmark() << ")" << endl;
	op << "————————————————————————————" << endl << endl << endl << endl;
	op.close();
	system("cls");
	cout << "┌────────────────────────────────┐" << endl;
	cout << "│        已保存至\"record\"        │" << endl;
	cout << "│                                │" << endl;
	cout << "│        输入任意字符返回        │" << endl;
	cout << "└────────────────────────────────┘" << endl;
	char a = getchar();
	while (cin.rdbuf()->in_avail())
		getchar();
	cin.clear();
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
bool I_am_AI(int &x, int &y)
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
		x = m + 1;
		y = n + 1;
	}
	else
	{
		max = 0; count = 0;
		while (m == -2)
		{
			for (int m1 = 0; m1 < 8; m1++)
				for (int n1 = 0; n1 < 8; n1++)
				{
					bool sign11 = false, sign12 = false, sign1 = false, sign2 = false;
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
								x = m + 1;
								y = n + 1;
								return true;
							}
							else
								if (BLACk.Getmark() < WHITe.Getmark())
								{
									for (int i = 0; i < 8; i++)
										for (int j = 0; j < 8; j++)
											chess_board[i][j] = saver[i][j];
									x = m + 1;
									y = n + 1;
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
													x = m + 1;
													y = n + 1;
													return true;
												}
												else
													if (BLACk.Getmark() < WHITe.Getmark())
													{
														for (int i = 0; i < 8; i++)
															for (int j = 0; j < 8; j++)
																chess_board[i][j] = saver[i][j];
														x = m + 1;
														y = n + 1;
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
		x = m + 1;
		y = n + 1;
	}
	return true;
}
void Free()
{
	thread* thread1 = new thread(reset);//多线程同时重置全局变量并释放动态内存
	thread* thread2 = new thread(free_memory);
	thread1->join();
	delete thread1;
	thread2->join();
	delete thread2;
}
bool player(bool m)
{
	int turn;
	int x, y;
	int black, white;
	bool sign = false, sign1 = false;
	while (true)
	{
		sign = sign1 = false;
		if (BLACk.Getturn())
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
		case 1:BLACk.Setable(sign); break;
		case 2:WHITe.Setable(sign); 
		}
		system("cls");
		print_chessboard();
		cout << "黑棋● " << BLACk.Getmark() << ":白棋○ " << WHITe.Getmark() << endl;
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
			case 1:BLACk.Setable(sign1); break;
			case 2:WHITe.Setable(sign1); 
			}
			if (sign1)
			{
				BLACk.Setturn();
				WHITe.Setturn();
				if (BLACk.Getturn())
					turn = 1;
				else
					turn = 2;
				switch (turn)
				{
				case 1:cout << "白棋○无处落子，黑棋●继续" << endl; break;
				case 2:cout << "黑棋●无处落子，白棋○继续" << endl; 
				}
				if (able)
				{
					sign = show_able(turn);
					system("cls");
					print_chessboard();
					cout << "黑棋● " << BLACk.Getmark() << ":白棋○ " << WHITe.Getmark() << endl;
					switch (turn)
					{
					case 1:cout << "白棋○无处落子，黑棋●继续" << endl; break;
					case 2:cout << "黑棋●无处落子，白棋○继续" << endl; 
					}
				}
			}
			//两方均无处落子游戏结束
			else
			{
				cout << "棋盘已无可落子处，游戏结束" << endl;
				break;
			}
		}
		switch (turn)
		{
		case 1:cout << "现在是黑棋●回合" << endl; input_position(x, y, 1); break;
		case 2:cout << "现在是白棋○回合" << endl; 
			if (m)
			{
				I_am_AI(x, y);
				judge_able(x - 1, y - 1, turn);
			}
			else
				input_position(x, y, 2);
		}
		while (x == 0 && y == 0)
		{
			char b;
			bool sign3 = false;
			while (true)
			{
				system("cls");
				cout << "┌───────────────────────────────┐" << endl;
				cout << "│          确定要退出吗？       │" << endl;
				cout << "│        当前棋局将会丢失！！   │" << endl;
				cout << "│                               │" << endl;
				cout << "│            [1]确定            │" << endl;
				cout << "│            [2]取消            │" << endl;
				cout << "│                               │" << endl;
				cout << "└───────────────────────────────┘" << endl;
				while (cin.peek() == '\n')
					getchar();
				b = getchar();
				while (cin.rdbuf()->in_avail())
					getchar();
				cin.clear();
				switch (b)
				{
				case '1':Free(); return true;
				case '2':	
					//重新显示棋盘
					system("cls");
					print_chessboard();
					cout << "黑棋● " << BLACk.Getmark() << ":白棋○ " << WHITe.Getmark() << endl;
					switch (turn)
					{
					case 1:cout << "现在是黑棋●回合" << endl; input_position(x, y, 1); break;
					case 2:cout << "现在是白棋○回合" << endl; input_position(x, y, 2); 
					}
					sign3 = true; break;
				default:
					cout << "所选择功能不存在，请重新输入" << endl;
					Sleep(700); break;
				}
				if (sign3)
					break;
			}
		}
		record* p = new record();
		switch (turn)
		{
		case 1:BLACk.Set(x, y); *p = BLACk; break;
		case 2:WHITe.Set(x, y); *p = WHITe; 
		}
		P.insert(p);
		chess_board[x - 1][y - 1] = turn;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (chess_board[i][j] == 3)
					chess_board[i][j] = 0;
		system("cls");
		print_chessboard();
		switch (turn)
		{
		case 1:BLACk.print(); break;
		case 2:WHITe.print();
		}
		Sleep(700);
		reverse(x - 1, y - 1);
		count(black, white);
		BLACk.Setmark(black);
		WHITe.Setmark(white);
		WHITe.Setturn();
		BLACk.Setturn();
	}
	system("cls");
	print_chessboard();
	char a;
	bool sign2 = false;
	int computer, player, tie;
	ifstream ip;
	ip.open("history", ios_base::in | ios_base::binary);
	ip.read((char*)&computer, 4);
	ip.read((char*)&player, 4);
	ip.read((char*)&tie, 4);
	ip.close();
	ofstream op;
	op.open("history", ios_base::trunc | ios_base::binary);
	while (true)
	{
		cout << "┌────────────────────────────────┐" << endl;
		cout << "│           本局结束!            │" << endl;
		cout << "│                                │" << endl;
		if (BLACk.Getmark() < 10)
			cout << "│           黑棋●:" << BLACk.Getmark() << "             │" << endl;
		else
			cout << "│           黑棋●:" << BLACk.Getmark() << "            │" << endl;
		if (WHITe.Getmark() < 10)
			cout << "│           白棋○:" << WHITe.Getmark() << "             │" << endl;
		else
			cout << "│           白棋○:" << WHITe.Getmark() << "            │" << endl;
		cout << "│                                │" << endl;
		cout << "│          ";
		if (BLACk.Getmark() > WHITe.Getmark())
		{
			cout << "黑棋● 胜利           │" << endl;
			if (m)
			{
				player++;
				op.write((char*)&computer, 4);
				op.write((char*)&player, 4);
				op.write((char*)&tie, 4);
			}
		}
		else if (BLACk.Getmark() < WHITe.Getmark())
		{
			cout << "白棋○ 胜利           │" << endl;
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
			cout << "    平局              │" << endl;
			if (m)
			{
				tie++;
				op.write((char*)&computer, 4);
				op.write((char*)&player, 4);
				op.write((char*)&tie, 4);
			}
		}
		if (!m)
		{
			op.write((char*)&computer, 4);
			op.write((char*)&player, 4);
			op.write((char*)&tie, 4);
		}
		op.close();
		cout << "│                                │" << endl;
		cout << "│        [1]返回                 │" << endl;
		cout << "│        [2]保存棋局并返回       │" << endl;
		cout << "│                                │" << endl;
		cout << "└────────────────────────────────┘" << endl;
		while (cin.peek() == '\n')
			getchar();
		a = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		switch (a)
		{
		case '1':sign2 = true; break;
		case '2':save();sign2 = true;break;
		default:
			cout << "所选择功能不存在，请重新输入" << endl;
			Sleep(700);
		}
		if (sign2)
		break;
	}
	Free();
}
void double_player_menu()
{
	char a;
	bool sign = false;
	while (true)
	{
		system("cls");
		cout << "┌───────────────────────────────┐" << endl;
		cout << "│        ——双人模式——       │" << endl;
		cout << "│          希望哪方先手？       │" << endl;
		cout << "│                               │" << endl;
		cout << "│          [1]黑棋              │" << endl;
		cout << "│          [2]白棋              │" << endl;
		cout << "│          [0]返回主菜单        │" << endl;
		cout << "│                               │" << endl;
		cout << "└───────────────────────────────┘" << endl;
		while (cin.peek() == '\n')
			getchar();
		a = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		switch (a)
		{
		case '1':BLACk.Setturn(); player(false); sign = true; break;
		case '2':WHITe.Setturn(); player(false); sign = true; break;
		case '0':sign = true; break;
		default:
			cout << "所选择功能不存在，请重新输入" << endl;
			Sleep(700); break;
		}
		if (sign)
			break;
	}
}
void single_player_menu2()
{
	char a;
	bool sign = false;
	while (true)
	{
		system("cls");
		cout << "┌───────────────────────────────┐" << endl;
		cout << "│        ——人机模式——       │" << endl;
		cout << "│          希望哪方先手？       │" << endl;
		cout << "│                               │" << endl;
		cout << "│          [1]玩家(黑棋)        │" << endl;
		cout << "│          [2]计算机(白棋)      │" << endl;
		cout << "│          [0]返回主菜单        │" << endl;
		cout << "│                               │" << endl;
		cout << "└───────────────────────────────┘" << endl;
		while (cin.peek() == '\n')
			getchar();
		a = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		switch (a)
		{
		case '1':BLACk.Setturn(); player(true); sign = true; break;
		case '2':WHITe.Setturn(); player(true); sign = true; break;
		case '0':sign = true; break;
		default:
			cout << "所选择功能不存在，请重新输入" << endl;
			Sleep(700); break;
		}
		if (sign)
			break;
	}
}
void single_player_menu()
{
	char a;
	bool sign = false;
	while (true)
	{
		system("cls");
		cout << "┌───────────────────────────────┐" << endl;
		cout << "│        ——人机模式——       │" << endl;
		cout << "│                               │" << endl;
		cout << "│          [1]开始游戏          │" << endl;
		cout << "│          [2]查看历史          │" << endl;
		cout << "│          [0]返回主菜单        │" << endl;
		cout << "│                               │" << endl;
		cout << "└───────────────────────────────┘" << endl;
		while (cin.peek() == '\n')
			getchar();
		a = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		switch (a)
		{
		case '1':single_player_menu2(); sign = true; break;
		case '2':history(); break;
		case '0':sign = true; break;
		default:
			cout << "所选择功能不存在，请重新输入" << endl;
			Sleep(700); break;
		}
		if (sign)
			break;
	}
}
void setting()
{
	char a;
	bool sign = false;
	while (true)
	{
		system("cls");
		cout << "┌────────────────────────────────┐" << endl;
		cout << "│              设置              │" << endl;
		cout << "│                                │" << endl;
		cout << "│        [1]显示可落子位置       │" << endl;
		cout << "│        [2]不显示可落子位置     │" << endl;
		cout << "│        [0]返回                 │" << endl;
		cout << "│                                │" << endl;
		cout << "└────────────────────────────────┘" << endl;
		while (cin.peek() == '\n')
			getchar();
		a = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		ofstream op;
		op.open("setting", ios_base::binary | ios_base::trunc);
		switch (a)
		{
		case '1':			
			able = true;
			op.write((char*)&able, 1);
			op.close();
			system("cls");
			cout << "┌────────────────────────────────┐" << endl;
			cout << "│           设置成功!            │" << endl;
			cout << "└────────────────────────────────┘" << endl;
			Sleep(500);
			sign = true; break;
		case '2':
			able = false;
			op.write((char*)&able, 1);
			op.close();
			system("cls");
			cout << "┌────────────────────────────────┐" << endl;
			cout << "│           设置成功!            │" << endl;
			cout << "└────────────────────────────────┘" << endl;
			Sleep(500);
			sign = true; break;
		case '0':sign = true; break;
		default:
			cout << "所选择功能不存在，请重新输入" << endl;
			Sleep(700); break;
		}
		if (sign)
			break;
	}
}
void load_setting()
{
	ifstream ip;
	ip.open("setting", ios_base::in | ios_base::binary);
	ip.read((char*)&able, 1);
	ip.close();
}
void mainmenu()
{
	char a;
	while (true)
	{
		system("cls");
		cout << "┌────────────────────────────────┐" << endl;
		cout << "│         趣    翻    棋         │" << endl;
		cout << "│            味    转            │" << endl;
		cout << "│                                │" << endl;
		cout << "│          [1]双人模式           │" << endl;
		cout << "│          [2]人机模式           │" << endl;
		cout << "│          [3]设置               │" << endl;
		cout << "│          [4]开发者信息         │" << endl;
		cout << "│          [0]退出游戏           │" << endl;
		cout << "│                                │" << endl;
		cout << "└────────────────────────────────┘" << endl;
		while (cin.peek() == '\n')
			getchar();
		a = getchar();
		while (cin.rdbuf()->in_avail())
			getchar();
		cin.clear();
		switch (a)
		{
		case '1':double_player_menu(); break;
		case '2':single_player_menu(); break;
		case '3':setting(); break;
		case '4':programmer(); break;
		case '0':exit(0); break;
		default:
			cout << "所选择功能不存在，请重新输入" << endl;
			Sleep(700); break;
		}
	}
}