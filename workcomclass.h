//�����ϵѧ����Ϣ������
#ifndef WORKCOMCLASS_H_
#define WORKCOMCLASS_H_
#include "workstuclass.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Comstu : public Student
{
public:
	virtual void menu2();            //�����ϵ�˵� 
	void input2();                   //�����ϵ����
	void output2();                  //�����ϵ���
	void add();                      //���� 
    void display();                  //��ʾ 
    void find();                     //��ѯ 
    void modify();                   //�޸�
	void del();                      //ɾ�� 
    void save();                     //������Ϣ���ļ� 
    void readfile(ifstream &in);     //���ļ��������ݵ���� 
	void copy1(Comstu *p1,Comstu *p2);//�������ڽ������� 
    void sort();                     //���򲿷� 
	void open();                     //���ļ� 
	void close();                    //�ر��ļ� 
	Comstu *next;

private:
	int computer_composition_principle_score;//��������ԭ�� 
	int computer_archiecture_score;          //�������ϵ�ṹ 
	int assembly_language_score;             //�������
	int all_average_score1;                  //ȫ���γ�ƽ���ɼ� 
	int public_average_score1;               //�����γ�ƽ���ɼ� 
	ifstream in;
	ofstream out;
	Comstu *head;
	Comstu *end;
};
#endif
