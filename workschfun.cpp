//学校类学生信息派生类的实现
#include "workschclass.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void School::menu1()//刚进去的主菜单 
{
	while(1)
	{
		system("cls");
		cout<<"\t\t********成绩管理系统菜单******\n";
        cout<<"\t\t*                            *\n";
        cout<<"\t\t*    1.计算机系学生成绩管理  *\n";
        cout<<"\t\t*                            *\n";
        cout<<"\t\t*    2.英语系学生成绩管理    *\n";
        cout<<"\t\t*                            *\n";
        cout<<"\t\t*    3.数学系学生成绩管理    *\n";
        cout<<"\t\t*                            *\n";
        cout<<"\t\t*    0.退出                  *\n";
        cout<<"\t\t*                            *\n";
        cout<<"\t\t******************************\n";
        cout<<"\t\t请输入指令(0-3): ";
        int choice_menu1(0);
        cin>>choice_menu1;
        Comstu c1;
        Engstu e1;
        Matstu m1;
        Student *p1=&c1;
        Student *p2=&e1;
        Student *p3=&m1;
        while(choice_menu1 < 0 || choice_menu1 > 3)
        {
            cout<<"错误指令！\n\n";
            system("pause");//这将要求“按任意键....”关闭窗口
            continue;       //重新执行条件判断
        }
        switch(choice_menu1)
		{
			case 1: p1->menu2();    break;
			case 2: p2->menu2();    break;
			case 3: p3->menu2();    break;
			case 0: return;         break;
			default :cout<<"\n无效指令!\n\n\n";
		}
	}	
}
