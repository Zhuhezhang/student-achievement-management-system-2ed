//ѧ����Ϣ����
#ifndef WORKSTUCLASS_H_
#define WORKSTUCLASS_H_
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Student
{
public:
	void input1();      //����1 
	void output1();     //���1 
	virtual void menu2();//�ڶ����˵�
	
	string id;
    string faculty;//ϵ�� 
	string name;
	int age;
	int math_score;
	int english_score;
	int sport_score;	
};
#endif
