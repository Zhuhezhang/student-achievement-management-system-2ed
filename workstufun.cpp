//学生信息基类的实现 
#include "workstuclass.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void Student::input1()//输入1
{
    cout<<"学号："<<endl;
    cin>>id;
    cout<<"系别："<<endl;
    cin>>faculty;
    cout<<"姓名："<<endl;
    cin>>name;
    cout<<"年龄："<<endl;
    cin>>age;
    cout<<"高数成绩："<<endl;
    cin>>math_score;
    cout<<"英语成绩："<<endl;
    cin>>english_score;
    cout<<"体育成绩："<<endl;
    cin>>sport_score;
}

void Student::output1()//输出1 
{
	cout<<"学号："<<id<<endl;
    cout<<"系别："<<faculty<<endl;
    cout<<"姓名："<<name<<endl;
    cout<<"年龄："<<age<<endl;
    cout<<"高数成绩："<<math_score<<endl;
    cout<<"英语成绩："<<english_score<<endl;
    cout<<"体育成绩："<<sport_score<<endl;
}
