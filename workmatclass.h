//数学系学生信息派生类
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
	virtual void menu2();            //菜单2 
	void input2();                   //输入2 
	void output2();                  //输出2 
	void add();                      //增加 
    void display();                  //显示信息 
    void find();                     //查询信息 
    void modify();                   //修改信息 
    void del();                      //删除结点 
    void save();                     //保存 
    void readfile(ifstream &in);     //从文件读入数据到结点
	void copy3(Matstu *p1,Matstu *p2);//交换相邻结点的数据 
    void sort();                     //排序
	void open();                     //打开文件 
	void close();                    //关闭文件 
	Matstu *next;
	
private:	
	ifstream in;
	ofstream out;
	Matstu *head;
	Matstu *end;
	int real_function_score;        //实变函数 
	int functional_analysis_score;  //泛函分析 
	int differential_geometry_score;//微分几何
	int all_average_score3;         //全部课程平均成绩 
	int public_average_score3;      //公共课程平均成绩 
};
#endif
