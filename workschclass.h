//这个学校类是继承计算机类、英语类和数学类
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
{              //虚基类，防止继承多个基类过来出错
public:
	void menu1();//刚进去的主菜单 
};
#endif
