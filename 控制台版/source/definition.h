//definition.h
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
	void Setturn(bool a);//Setturn���أ��ṩ�������÷�ʽ
	void Setable(bool a);
	void Setmark(int a);
	virtual void print();
private:
	bool turn;//��¼�Ƿ񵽱����غ�
	bool able;//��¼�������޿����Ӵ�
	int mark;//��¼����Ŀǰ������
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
	void Setturn(bool a);//Setturn���أ��ṩ�������÷�ʽ
	void Setable(bool a);
	void Setmark(int a);
	virtual void print();
private:
	bool turn;//��¼�Ƿ񵽱����غ�
	bool able;//��¼�������޿����Ӵ�
	int mark;//��¼����Ŀǰ������
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
	void operator=(white a);//���صȺţ�����ּ�¼��record��
	friend class List;
private:
	bool turn;//��¼���ӷ��Ǻڻ��ǰ�
	record* next;//ͬ�����ָ�룬��������ÿһ����Ϣ
};
