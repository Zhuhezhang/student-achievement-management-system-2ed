//学生信息基类
#ifndef WORKSTUCLASS_H_
#define WORKSTUCLASS_H_
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Student
{
public:
	void input1();      //输入1 
	void output1();     //输出1 
	virtual void menu2();//第二级菜单
	
	string id;
    string faculty;//系别 
	string name;
	int age;
	int math_score;
	int english_score;
	int sport_score;	
};
#endif
