//ѧУ��ѧ����Ϣ�������ʵ��
#include "workschclass.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void School::menu1()//�ս�ȥ�����˵� 
{
	while(1)
	{
		system("cls");
		cout<<"\t\t********�ɼ�����ϵͳ�˵�******\n";
        cout<<"\t\t*                            *\n";
        cout<<"\t\t*    1.�����ϵѧ���ɼ�����  *\n";
        cout<<"\t\t*                            *\n";
        cout<<"\t\t*    2.Ӣ��ϵѧ���ɼ�����    *\n";
        cout<<"\t\t*                            *\n";
        cout<<"\t\t*    3.��ѧϵѧ���ɼ�����    *\n";
        cout<<"\t\t*                            *\n";
        cout<<"\t\t*    0.�˳�                  *\n";
        cout<<"\t\t*                            *\n";
        cout<<"\t\t******************************\n";
        cout<<"\t\t������ָ��(0-3): ";
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
            cout<<"����ָ�\n\n";
            system("pause");//�⽫Ҫ�󡰰������....���رմ���
            continue;       //����ִ�������ж�
        }
        switch(choice_menu1)
		{
			case 1: p1->menu2();    break;
			case 2: p2->menu2();    break;
			case 3: p3->menu2();    break;
			case 0: return;         break;
			default :cout<<"\n��Чָ��!\n\n\n";
		}
	}	
}
