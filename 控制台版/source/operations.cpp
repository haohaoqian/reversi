//operations.cpp
#include"definition.h"
#include<iostream>
using namespace std;
node::node(int a, int b) :X(a), Y(b)
{}
node::~node()
{}
int node::GetX()
{
	return X;
}
int node::GetY()
{
	return Y;
}
void node::Set(int a, int b)
{
	X = a;
	Y = b;
}
void node::print()
{
	cout << "(" << X << "," << Y << ")";
}
black::black() :turn(false), able(true), mark(2), node(-1, -1)
{}
black::~black()
{}
bool black::Getturn()
{
	return turn;
}
bool black::Getable()
{
	return able;
}
int black::Getmark()
{
	return mark;
}
void black::Setturn()
{
	turn = !turn;
}
void black::Setturn(bool a)
{
	turn = a;
}
void black::Setable(bool a)
{
	able = a;
}
void black::Setmark(int a)
{
	mark = a;
}
void black::print()
{
	cout << "黑棋落子";
	node::print();
}
white::white() :turn(false), able(true), mark(2), node(-1, -1)
{}
white::~white()
{}
bool white::Getturn()
{
	return turn;
}
bool white::Getable()
{
	return able;
}
int white::Getmark()
{
	return mark;
}
void white::Setturn()
{
	turn = !turn;
}
void white::Setturn(bool a)
{
	turn = a;
}
void white::Setable(bool a)
{
	able = a;
}
void white::Setmark(int a)
{
	mark = a;
}
void white::print()
{
	cout << "白棋落子";
	node::print();
}
List::List() :head(NULL), current(NULL)
{}
List::~List()
{}
record* List::Gethead()
{
	return head;
}
void List::insert(record* p)
{
	if (head == NULL)
		head = p;
	else
	{
		current = head;
		while (current->next != NULL)
			current = current->next;
		current->next = p;
	}
}
void List::Delete()//删除末尾节点
{
	current = head;
	if (head == NULL);
	else if (current->next == NULL)//处理仅剩一个节点的特殊情况
	{
		delete head;
		head = NULL;
	}
	else
	{
		while (current->next->next != NULL)
			current = current->next;
		delete current->next;
		current->next = NULL;
	}
}
bool List::read(int& a, int& b, bool& c, int t)
{
	current = head;
	for (int i = 1; i < t; i++)
	{
		current = current->next;
		if (current == NULL)
			return false;
	}
	a = current->GetX();
	b = current->GetY();
	c = current->Getturn();
	return true;
}
record::record() :node(-1, -1), turn(false)
{}
record::~record()
{}
bool record::Getturn()
{
	return turn;
}
void record::operator=(black a)
{
	turn = false;
	node::Set(a.GetX(), a.GetY());
}
void record::operator=(white a)
{
	turn = true;
	node::Set(a.GetX(), a.GetY());
}