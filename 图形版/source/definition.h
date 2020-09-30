#ifndef DEFINITION
#define DEFINITION
#pragma once
class abstract
{
    virtual void print() = 0;
};
class node :virtual public abstract
{
public:
    node(int a, int b);
    ~node();
    int GetX();
    int GetY();
    void Set(int a, int b);
    virtual void print();
protected:
    int X;
    int Y;
};
class record;
class black :public node, virtual public abstract
{
public:
    black();
    ~black();
    bool Getturn();
    bool Getable();
    int Getmark();
    void Setturn();
    void Setturn(bool a);//Setturn重载，提供两种设置方式
    void Setable(bool a);
    void Setmark(int a);
    virtual void print();
private:
    bool turn;//记录是否到本方回合
    bool able;//记录本方有无可落子处
    int mark;//记录本方目前棋子数
};
class white :public node, virtual public abstract
{
public:
    white();
    ~white();
    bool Getturn();
    bool Getable();
    int Getmark();
    void Setturn();
    void Setturn(bool a);//Setturn重载，提供两种设置方式
    void Setable(bool a);
    void Setmark(int a);
    virtual void print();
private:
    bool turn;//记录是否到本方回合
    bool able;//记录本方有无可落子处
    int mark;//记录本方目前棋子数
};
class List
{
public:
    List();
    ~List();
    record* Gethead();
    void insert(record* p);
    void Delete();
    bool read(int& a, int& b, bool& c, int t);
private:
    record* head, *current;
};
class record :public node
{
public:
    record();
    ~record();
    bool Getturn();
    void operator=(black a);
    void operator=(white a);//重载等号，将棋局记录在record中
    friend class List;
private:
    bool turn;//记录落子方是黑还是白
    record* next;//同类对象指针，用链表储存每一步信息
};

#endif // DEFINITION

