//数学系学生信息派生类的实现 
#include "workmatclass.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void Matstu::menu2()
{
	while(1)
	{
		open();
		system("cls");
		cout<<"\t\t**********数学系学生成绩管理系统菜单******\n";
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
void Matstu::close()
{
	save();
    Matstu *pos = head->next;
	Matstu *temp;
	while(pos!=end)
	{
		temp = pos;
		pos = pos->next;
		delete temp;
	}
	delete head,end;
}

void Matstu::open()
{
	//初始化，头尾结点 
	head = new Matstu;
	head->next = new Matstu;
	end = head->next; 
	ifstream in("matstu.txt");
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
		end->next = new Matstu;
		end = end->next;
	}
} 
	
void Matstu::input2()
{
	input1();
	cout<<"实变函数成绩："<<endl;
    cin>>real_function_score;
    cout<<"泛函分析成绩："<<endl;
    cin>>functional_analysis_score;
    cout<<"微分几何成绩："<<endl;
    cin>>differential_geometry_score;
    all_average_score3=(math_score+english_score+sport_score+real_function_score+functional_analysis_score+differential_geometry_score)/6;
    public_average_score3=(math_score+english_score+sport_score)/3;
}
	
void Matstu::output2()
{
	output1();
	cout<<"实变函数成绩："<<real_function_score<<endl;
    cout<<"泛函分析成绩："<<functional_analysis_score<<endl;
    cout<<"微分几何成绩："<<differential_geometry_score<<endl;
    cout<<"全部课程平均成绩："<<all_average_score3<<endl;
    cout<<"公共课程平均成绩："<<public_average_score3<<endl;
}

void Matstu::add()
{
	char quit;
	while(1)
    {
		end->input2();
		end->next = new Matstu;
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

void Matstu::display()//显示信息 
{
    if(head->next==end)
	{
	    cout<<"空的..."<<endl;
	}
	Matstu *pos;
	pos = head->next;
	for(pos;pos!=end;pos=pos->next)
 	{
		output2();
		cout<<endl;
	}	
}

void Matstu::find()//查询信息 
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
	    Matstu *pos = head->next;
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

void Matstu::modify()//修改信息 
{
    string name1;
	cout<<"请输入您想要修改的学生名字：";
	cin>>name1;
	Matstu *pos = head->next;
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
	
void Matstu::del()//删除结点 
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
	Matstu *p1 = head->next;
	Matstu *p2 = head;
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
    
void Matstu::save()
{
    out.open("matstu.txt");
    Matstu *pos = head->next;
    if(head->next== end)
	{
		cout<<"空的..."<<endl;
	}
    for(pos;pos!=end;pos=pos->next)
    {
        out<<'\t'<<pos->id<<'\t'<<pos->faculty<<'\t'<<pos->name<<'\t'<<pos->age<<'\t'<<pos->math_score<<'\t'<<pos->english_score<<'\t'<<pos->sport_score<<'\t'<<pos->real_function_score<<'\t'<<pos->functional_analysis_score<<'\t'<<pos->differential_geometry_score<<'\t'<<pos->all_average_score3<<'\t'<<pos->public_average_score3;
    }
    out.close();
    cout<<"保存成功"<<endl;
}
	
void Matstu::readfile(ifstream &in)
{
    in>>id>>faculty>>name>>age>>math_score>>english_score>>sport_score>>real_function_score>>functional_analysis_score>>differential_geometry_score>>all_average_score3>>public_average_score3;
}
	
void Matstu::copy3(Matstu *p1,Matstu *p2)//交换相邻结点的数据 
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
        p1->real_function_score = p2->real_function_score;
        p1->functional_analysis_score = p2->functional_analysis_score;
        p1->differential_geometry_score = p2->differential_geometry_score;
        p1->all_average_score3 = p2->all_average_score3;
        p1->public_average_score3 = p2->public_average_score3;
        //只是信息拷贝,next不能拷贝否则信息丢失
    }
}		
	
void Matstu::sort()//排序 
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
    Matstu *p1,*p2;
    p1=head->next;
    if(choice==1)//按全部课程平均成绩降序排 
    {
	    for(p1;p1!=end;p1=p1->next)//冒泡排序
	    {
		    for(p2=p1->next;p2!=end;p2=p2->next)
		    {
			    if(p2->all_average_score3 > p1->all_average_score3)
			    {
				   Matstu *ptemp = new Matstu;
                   copy3(ptemp, p1);
                   copy3(p1, p2);
                   copy3(p2, ptemp);
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
			    if(p2->all_average_score3 < p1->all_average_score3)
			    {
				    Matstu *ptemp = new Matstu;
                    copy3(ptemp, p1);
                    copy3(p1, p2);
                    copy3(p2, ptemp);
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
			    if(p2->public_average_score3 > p1->public_average_score3)
			    {
				  Matstu *ptemp = new Matstu;
                  copy3(ptemp, p1);
                  copy3(p1, p2);
                  copy3(p2, ptemp);
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
			    if(p2->public_average_score3 < p1->public_average_score3)
			    {
				    Matstu *ptemp = new Matstu;
                    copy3(ptemp, p1);
                    copy3(p1, p2);
                    copy3(p2, ptemp);
		        }	
		    }
      	}
    }
    cout<<"排序成功!"<<endl;	
} 
