//英语系学生信息派生类
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
	virtual void menu2();            //英语系学生菜单
	void input2();                   //英语系学生输入 
	void output2();                  //输出 
	void add();                      //增加信息
    void display();                  //显示信息 
    void find();                     //查询信息 
    void modify();                   //修改信息 
    void del();                      //删除信息
    void save();                     //保存信息到文件 
    void readfile(ifstream &in);     //从文件输入结点 
	void copy2(Engstu *p1,Engstu *p2);//交换相邻结点的数据 
    void sort();                     //排序 
    void open();                     //打开文件 
    void close();                    //关闭文件 
    Engstu *next;
    
private:
	ifstream in;
	ofstream out;
	Engstu *head;
	Engstu *end;	
	int comprehensive_english_score;//综合英语
	int speaking_score;             //口语
	int hearing_score;              //听力
	int all_average_score2;         //全部课程平均成绩 
	int public_average_score2;      //公共课程平均成绩 
};
#endif
