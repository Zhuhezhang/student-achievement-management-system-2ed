//Ӣ��ϵѧ����Ϣ������
#ifndef WORKENGCLASS_H_
#define WORKENGCLASS_H_
#include "workstuclass.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Engstu : public Student
{
public:
	virtual void menu2();            //Ӣ��ϵѧ���˵�
	void input2();                   //Ӣ��ϵѧ������ 
	void output2();                  //��� 
	void add();                      //������Ϣ
    void display();                  //��ʾ��Ϣ 
    void find();                     //��ѯ��Ϣ 
    void modify();                   //�޸���Ϣ 
    void del();                      //ɾ����Ϣ
    void save();                     //������Ϣ���ļ� 
    void readfile(ifstream &in);     //���ļ������� 
	void copy2(Engstu *p1,Engstu *p2);//�������ڽ������� 
    void sort();                     //���� 
    void open();                     //���ļ� 
    void close();                    //�ر��ļ� 
    Engstu *next;
    
private:
	ifstream in;
	ofstream out;
	Engstu *head;
	Engstu *end;	
	int comprehensive_english_score;//�ۺ�Ӣ��
	int speaking_score;             //����
	int hearing_score;              //����
	int all_average_score2;         //ȫ���γ�ƽ���ɼ� 
	int public_average_score2;      //�����γ�ƽ���ɼ� 
};
#endif
