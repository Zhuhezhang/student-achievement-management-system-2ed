//���ѧУ���Ǽ̳м�����ࡢӢ�������ѧ��
#ifndef WORKSCHCLASS_H_
#define WORKSCHCLASS_H_
#include "workcomclass.h"
#include "workengclass.h"
#include "workmatclass.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class School : virtual public Comstu,virtual public Engstu,virtual public Matstu
{              //����࣬��ֹ�̳ж�������������
public:
	void menu1();//�ս�ȥ�����˵� 
};
#endif
