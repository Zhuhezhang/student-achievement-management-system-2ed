//计算机系学生信息派生类
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
	virtual void menu2();            //计算机系菜单 
	void input2();                   //计算机系输入
	void output2();                  //计算机系输出
	void add();                      //增加 
    void display();                  //显示 
    void find();                     //查询 
    void modify();                   //修改
	void del();                      //删除 
    void save();                     //保存信息到文件 
    void readfile(ifstream &in);     //从文件读入数据到结点 
	void copy1(Comstu *p1,Comstu *p2);//交换相邻结点的数据 
    void sort();                     //排序部分 
	void open();                     //打开文件 
	void close();                    //关闭文件 
	Comstu *next;

private:
	int computer_composition_principle_score;//计算机组成原理 
	int computer_archiecture_score;          //计算机体系结构 
	int assembly_language_score;             //汇编语言
	int all_average_score1;                  //全部课程平均成绩 
	int public_average_score1;               //公共课程平均成绩 
	ifstream in;
	ofstream out;
	Comstu *head;
	Comstu *end;
};
#endif
