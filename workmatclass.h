//��ѧϵѧ����Ϣ������
#ifndef WORKMATCLASS_H_
#define WORKMATCLASS_H_
#include "workstuclass.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Matstu : public Student
{
public:
	virtual void menu2();            //�˵�2 
	void input2();                   //����2 
	void output2();                  //���2 
	void add();                      //���� 
    void display();                  //��ʾ��Ϣ 
    void find();                     //��ѯ��Ϣ 
    void modify();                   //�޸���Ϣ 
    void del();                      //ɾ����� 
    void save();                     //���� 
    void readfile(ifstream &in);     //���ļ��������ݵ����
	void copy3(Matstu *p1,Matstu *p2);//�������ڽ������� 
    void sort();                     //����
	void open();                     //���ļ� 
	void close();                    //�ر��ļ� 
	Matstu *next;
	
private:	
	ifstream in;
	ofstream out;
	Matstu *head;
	Matstu *end;
	int real_function_score;        //ʵ�亯�� 
	int functional_analysis_score;  //�������� 
	int differential_geometry_score;//΢�ּ���
	int all_average_score3;         //ȫ���γ�ƽ���ɼ� 
	int public_average_score3;      //�����γ�ƽ���ɼ� 
};
#endif
