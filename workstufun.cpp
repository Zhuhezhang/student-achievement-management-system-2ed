//ѧ����Ϣ�����ʵ�� 
#include "workstuclass.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void Student::input1()//����1
{
    cout<<"ѧ�ţ�"<<endl;
    cin>>id;
    cout<<"ϵ��"<<endl;
    cin>>faculty;
    cout<<"������"<<endl;
    cin>>name;
    cout<<"���䣺"<<endl;
    cin>>age;
    cout<<"�����ɼ���"<<endl;
    cin>>math_score;
    cout<<"Ӣ��ɼ���"<<endl;
    cin>>english_score;
    cout<<"�����ɼ���"<<endl;
    cin>>sport_score;
}

void Student::output1()//���1 
{
	cout<<"ѧ�ţ�"<<id<<endl;
    cout<<"ϵ��"<<faculty<<endl;
    cout<<"������"<<name<<endl;
    cout<<"���䣺"<<age<<endl;
    cout<<"�����ɼ���"<<math_score<<endl;
    cout<<"Ӣ��ɼ���"<<english_score<<endl;
    cout<<"�����ɼ���"<<sport_score<<endl;
}
