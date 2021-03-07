//英语系学生信息派生类的实现 
#include "workengclass.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void Engstu::menu2()//英语系学生菜单 
{
	while(1)
	{
		open();
		system("cls");
		cout<<"\t\t**********英语系学生成绩管理系统菜单******\n";
        cout<<"\t\t*                                        *\n";
        cout<<"\t\t*              1.录入学生成绩            *\n";
        cout<<"\t\t*                                        *\n";
        cout<<"\t\t*              2.删除学生成绩            *\n";
        cout<<"\t\t*                                        *\n";
        cout<<"\t\t*              3.修改学生成绩            *\n";
        cout<<"\t\t*                                        *\n";
        cout<<"\t\t*              4.显示学生成绩            *\n";
        cout<<"\t\t*                                        *\n";
        cout<<"\t\t*              5.查询学生成绩            *\n";
        cout<<"\t\t*                                        *\n";
        cout<<"\t\t*              6.排序学生成绩            *\n";
        cout<<"\t\t*                                        *\n";
        cout<<"\t\t*              0.退出                    *\n";
        cout<<"\t\t*                                        *\n";
        cout<<"\t\t******************************************\n";
        cout<<"\t\t请输入指令(0-6): ";
            
        int choice(0);
        cin>>choice;
        switch(choice)
		{
			case 1: add();    break;//添加 
			case 2: del();    break;//删除 
			case 3: modify(); break;//修改 
			case 4: display();break;//显示 
			case 5: find();   break;//查询 
			case 6: sort();   break;//排序
			case 0: return;   break;
			default :cout<<"\n无效指令!\n\n\n";
		}
		close();
	}
}

void Engstu::close()
{
	save();
    Engstu *pos = head->next;
	Engstu *temp;
	while(pos!=end)
	{
		temp = pos;
		pos = pos->next;
		delete temp;
	}
	delete head,end;
}

void Engstu::open()
{
	//初始化，头尾结点 
	head = new Engstu;
	head->next = new Engstu;
	end = head->next; 
	ifstream in("engstu.txt");
	char ch = in.get();
	if(in.eof())
	{
		cout<<"文件为空！"<<endl;
	}
	//若文件非空
	while(!in.eof())
	{
		end->readfile(in);
		if(end->name[0] == '\0')
		break;//不加这一句的话程序会把文件最后结束的标记也都出来		
		end->next = new Engstu;
		end = end->next;
	}
} 
 
void Engstu::input2()//英语系学生输入 
{
	input1();
	cout<<"综合英语成绩："<<endl;
    cin>>comprehensive_english_score;
    cout<<"口语成绩："<<endl;
    cin>>speaking_score;
    cout<<"听力成绩："<<endl;
    cin>>hearing_score;
    all_average_score2=(math_score+english_score+sport_score+comprehensive_english_score+speaking_score+hearing_score)/6;
    public_average_score2=(math_score+english_score+sport_score)/3;
}
	
void Engstu::output2()
{
	output1();
	cout<<"综合英语成绩："<<comprehensive_english_score<<endl;
    cout<<"口语成绩："<<speaking_score<<endl;
    cout<<"听力成绩："<<hearing_score<<endl;
    cout<<"全部课程平均成绩："<<all_average_score2<<endl;
    cout<<"公共课程平均成绩："<<public_average_score2<<endl;
}

void Engstu::add()//增加信息
{
	char quit;
	while(1)
    {
		end->input2();
		end->next = new Engstu;
		end = end->next;
		cout<<"是否继续?(Y/N)"<<endl;
		cin>>quit;
		switch(quit)
		{
			case'Y':
			case'y':break;
		  	case'n':
			case'N':return;break;
			default:cout<<"错误输入,是否继续输入?(Y/N)";
				    cin>>quit;
		}
	}
	    cout<<"增加信息成功!"<<endl;
	    system("pause");
}
	
void Engstu::display()//显示信息 
{
    if(head->next==end)
	{
	    cout<<"空的..."<<endl;
	}
	Engstu *pos;
	pos = head->next;
	for(pos;pos!=end;pos=pos->next)
 	{
		output2();
		cout<<endl;
	}	
}
	
void Engstu::find()//查询信息 
{
    while(1)
	{
	    string name1;
	    string id1;
	    cout<<"    1、按学号查询\n";
	    cout<<"    2、按姓名查询\n";
	    cout<<"\n请输入指令：";
	    int choice;
        cin>>choice;
 	    while(choice !=1 && choice != 2)
	    {
		    cout<<"错误指令！\n";
		    system("pause");
		    cout<<"请重新输入指令：";
		    cin>>choice;
            continue;//重新执行条件判断
	    }
        system("cls");
	    Engstu *pos = head->next;
	    int flag(0);//判断是否找到信息 
	    if(choice==1)
     	{
		    cout<<"请输入要查询的学号：";
		    cin>>id1;
	        for(pos;pos!=end;pos=pos->next)
	        {
		        if(pos->id==id1)
		        {
			        flag = 1; 
			        output2();
		        }
	        }
        }
	    if(choice==2)
	    {
		    cout<<"请输入要查询的姓名：";
		    cin>>name1;
	        for(pos;pos!=end;pos=pos->next)
	        {
		        if(pos->name==name1)
		        {
			        flag = 1;
			        output2();
		        }
	        }
        }
        if(!flag)
        {
    	    cout<<"未能找到该学生信息...\n";
	    }
	    char c;
	    cout<<"\n是否继续查询(Y/N)：";
        cin>>c;
        system("cls");
        if(c == 'N' || c == 'n')
        break;
    }	
}
	
void Engstu::modify()//修改信息 
{
    string name1;
	cout<<"请输入您想要修改的学生名字：";
	cin>>name1;
	Engstu *pos = head->next;
	for(pos;pos!=end;pos=pos->next)
	{
		if(name1==pos->name)
		{
			pos->input2();
			break;
	    }	
	}
	cout<<"修改成功!"<<endl;
}
	
void Engstu::del()//删除信息
{
    int del_flag = 0;
	string name1;
	if(head->next == end)	
	{
	    cout<<"空的..."<<endl;
		return ;
	}
	cout<<"请输入您想要删除的学生名字：";
	cin>>name1;
	Engstu *p1 = head->next;
	Engstu *p2 = head;
	for(p1;p1!=end;p1->next)
	{
		if(p1->name==name1)
		{
			del_flag = 1;
			p2->next = p1->next;
			delete p1;
		    break;		
		}
		else
		{
		    p2=p2->next;
			p1=p1->next;
		}
	}	
	if(del_flag == 0)
	{
	    cout<<"未能找到该学生...."<<endl;
	}
	cout<<"删除信息成功!"<<endl;
}
    
void Engstu::save()//保存信息到文件 
{
    out.open("engstu.txt");
    Engstu *pos = head->next;
    if(head->next== end)
	{
		cout<<"空的..."<<endl;
	}
    for(pos;pos!=end;pos=pos->next)
    {
        out<<'\t'<<pos->id<<'\t'<<pos->faculty<<'\t'<<pos->name<<'\t'<<pos->age<<'\t'<<pos->math_score<<'\t'<<pos->english_score<<'\t'<<pos->sport_score<<'\t'<<pos->comprehensive_english_score<<'\t'<<pos->speaking_score<<'\t'<<pos->hearing_score<<'\t'<<pos->all_average_score2<<'\t'<<pos->public_average_score2;
    }
    out.close();
    cout<<"保存成功"<<endl;
}
	
void Engstu::readfile(ifstream &in)//从文件输入结点 
{
    in>>id>>faculty>>name>>age>>math_score>>english_score>>sport_score>>comprehensive_english_score>>speaking_score>>hearing_score>>all_average_score2>>public_average_score2;
}
	
void Engstu::copy2(Engstu *p1,Engstu *p2)//交换相邻结点的数据 
{
	if (p2 == nullptr)
    {
        cout <<"拷贝目标为空！"<<endl;
    }
    else
    {	
        p1->name=p2->name;
        p1->id=p2->id;
        p1->faculty=p2->faculty;
        p1->age = p2->age;
        p1->math_score = p2->math_score;
        p1->english_score = p2->english_score;
        p1->sport_score = p2->sport_score;
        p1->comprehensive_english_score = p2->comprehensive_english_score;
        p1->speaking_score = p2->speaking_score;
        p1->hearing_score = p2->hearing_score;
        p1->all_average_score2 = p2->all_average_score2;
        p1->public_average_score2 = p2->public_average_score2;
        //只是信息拷贝,next不能拷贝否则信息丢失
    }	
}	
	
void Engstu::sort()//排序 
{
    cout<<"\t\t************************排序**********************\n";
	cout<<"\t\t*                                                *\n";
    cout<<"\t\t*            1.按全部课程平均成绩降序排          *\n";
    cout<<"\t\t*                                                *\n";
    cout<<"\t\t*            2.按全部课程平均成绩升序排          *\n";
    cout<<"\t\t*                                                *\n";
    cout<<"\t\t*            3.按公共课程平均成绩降序排          *\n";
    cout<<"\t\t*                                                *\n";
    cout<<"\t\t*            4.按公共课程平均成绩升序排          *\n";
    cout<<"\t\t*                                                *\n";
    cout<<"\t\t**************************************************\n";
    cout<<"\t\t请输入指令(1-4): ";
	int choice(0);
	cin>>choice;
    while(choice < 1 || choice > 4)
    {
        cout<<"错误指令！\n\n";
        system("pause");//这将要求“按任意键....”关闭窗口
        continue;       //重新执行条件判断
    }
    Engstu *p1,*p2;
    p1=head->next;
    if(choice==1)//按全部课程平均成绩降序排 
    {
	    for(p1;p1!=end;p1=p1->next)//冒泡排序
	    {
		    for(p2=p1->next;p2!=end;p2=p2->next)
		    {
			    if(p2->all_average_score2 > p1->all_average_score2)
			    {
				    Engstu *ptemp = new Engstu;
                    copy2(ptemp, p1);
                    copy2(p1, p2);
                    copy2(p2, ptemp);
		        }	
		    }
      	}
    }
    if(choice==2)//按全部课程平均成绩升序拍 
    {
	    p1=head->next;
	    for(p1;p1!=end;p1=p1->next)//冒泡排序
	    {
		    for(p2=p1->next;p2!=end;p2=p2->next)
		    {
			    if(p2->all_average_score2 < p1->all_average_score2)
			    {
				    Engstu *ptemp = new Engstu;
                    copy2(ptemp, p1);
                    copy2(p1, p2);
                    copy2(p2, ptemp);
		        }	
		    }
      	}
    }
    if(choice==3)//按公共课程平均成绩降序排 
    {
	    for(p1;p1!=end;p1=p1->next)//冒泡排序
	    {
		    for(p2=p1->next;p2!=end;p2=p2->next)
		    {
			    if(p2->public_average_score2 > p1->public_average_score2)
			    {
				    Engstu *ptemp = new Engstu;
                    copy2(ptemp, p1);
                    copy2(p1, p2);
                    copy2(p2, ptemp);
		        }	
		    }
      	}
    }
    if(choice==4)//按公共课程平均成绩升序排 
    {
	    p1=head->next;
	    for(p1;p1!=end;p1=p1->next)//冒泡排序
	    {
		    for(p2=p1->next;p2!=end;p2=p2->next)
		    {
			    if(p2->public_average_score2 < p1->public_average_score2)
			    {
				    Engstu *ptemp = new Engstu;
                    copy2(ptemp, p1);
                    copy2(p1, p2);
                    copy2(p2, ptemp);
		        }	
		    }
      	}
    }
    cout<<"排序成功!"<<endl;
}
