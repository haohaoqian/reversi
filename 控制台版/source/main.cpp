//main.cpp
#include"process.h"
#include"definition.h"
#include<cstdlib>
#include<thread>
using namespace std;
void do_setting()//分两步完成设置的载入
{
	in_case_nosettings();
	load_setting();
}
int main()
{
	system("color B0");//使用多线程同时完成动画展示和设置载入
	thread* thread1 = new thread(show);
	thread* thread2 = new thread(do_setting);
	thread1->join();
	delete thread1;
	thread2->join();
	delete thread2;
	mainmenu();
	return 0;
}