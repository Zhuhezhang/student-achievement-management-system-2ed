//��ѧϵѧ����Ϣ�������ʵ�� 
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
		cout<<"\t\t**********��ѧϵѧ���ɼ�����ϵͳ�˵�******\n";
        cout<<"\t\t*                                        *\n";
        cout<<"\t\t*              1.¼��ѧ���ɼ�            *\n";
        cout<<"\t\t*                                        *\n";
        cout<<"\t\t*              2.ɾ��ѧ���ɼ�            *\n";
        cout<<"\t\t*                                        *\n";
        cout<<"\t\t*              3.�޸�ѧ���ɼ�            *\n";
        cout<<"\t\t*                                        *\n";
        cout<<"\t\t*              4.��ʾѧ���ɼ�            *\n";
        cout<<"\t\t*                                        *\n";
        cout<<"\t\t*              5.��ѯѧ���ɼ�            *\n";
        cout<<"\t\t*                                        *\n";
        cout<<"\t\t*              6.����ѧ���ɼ�            *\n";
        cout<<"\t\t*                                        *\n";
        cout<<"\t\t*              0.�˳�                    *\n";
        cout<<"\t\t*                                        *\n";
        cout<<"\t\t******************************************\n";
        cout<<"\t\t������ָ��(0-6): ";
            
        int choice(0);
        cin>>choice; 
        switch(choice)
		{
			case 1: add();    break;//��� 
			case 2: del();    break;//ɾ�� 
			case 3: modify(); break;//�޸� 
			case 4: display();break;//��ʾ 
			case 5: find();   break;//��ѯ 
			case 6: sort();   break;//����
			case 0: return;   break;
			default :cout<<"\n��Чָ��!\n\n\n";
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
	//��ʼ����ͷβ��� 
	head = new Matstu;
	head->next = new Matstu;
	end = head->next; 
	ifstream in("matstu.txt");
	char ch = in.get();
	if(in.eof())
	{
		cout<<"�ļ�Ϊ�գ�"<<endl;
	}
	//���ļ��ǿ�
	while(!in.eof())
	{
		end->readfile(in);
		if(end->name[0] == '\0')
		break;//������һ��Ļ��������ļ��������ı��Ҳ������		
		end->next = new Matstu;
		end = end->next;
	}
} 
	
void Matstu::input2()
{
	input1();
	cout<<"ʵ�亯���ɼ���"<<endl;
    cin>>real_function_score;
    cout<<"���������ɼ���"<<endl;
    cin>>functional_analysis_score;
    cout<<"΢�ּ��γɼ���"<<endl;
    cin>>differential_geometry_score;
    all_average_score3=(math_score+english_score+sport_score+real_function_score+functional_analysis_score+differential_geometry_score)/6;
    public_average_score3=(math_score+english_score+sport_score)/3;
}
	
void Matstu::output2()
{
	output1();
	cout<<"ʵ�亯���ɼ���"<<real_function_score<<endl;
    cout<<"���������ɼ���"<<functional_analysis_score<<endl;
    cout<<"΢�ּ��γɼ���"<<differential_geometry_score<<endl;
    cout<<"ȫ���γ�ƽ���ɼ���"<<all_average_score3<<endl;
    cout<<"�����γ�ƽ���ɼ���"<<public_average_score3<<endl;
}

void Matstu::add()
{
	char quit;
	while(1)
    {
		end->input2();
		end->next = new Matstu;
		end = end->next;
		cout<<"�Ƿ����?(Y/N)"<<endl;
		cin>>quit;
		switch(quit)
		{
			case'Y':
			case'y':break;
		  	case'n':
			case'N':return;break;
			default:cout<<"��������,�Ƿ��������?(Y/N)";
				    cin>>quit;
		}
	}
	cout<<"������Ϣ�ɹ�!"<<endl;
	system("pause");
}

void Matstu::display()//��ʾ��Ϣ 
{
    if(head->next==end)
	{
	    cout<<"�յ�..."<<endl;
	}
	Matstu *pos;
	pos = head->next;
	for(pos;pos!=end;pos=pos->next)
 	{
		output2();
		cout<<endl;
	}	
}

void Matstu::find()//��ѯ��Ϣ 
{
    while(1)
	{
	    string name1;
	    string id1;
	    cout<<"    1����ѧ�Ų�ѯ\n";
	    cout<<"    2����������ѯ\n";
	    cout<<"\n������ָ�";
	    int choice;
        cin>>choice;
 	    while(choice !=1 && choice != 2)
	    {
		    cout<<"����ָ�\n";
		    system("pause");
		    cout<<"����������ָ�";
		    cin>>choice;
            continue;//����ִ�������ж�
	    }
        system("cls");
	    Matstu *pos = head->next;
	    int flag(0);//�ж��Ƿ��ҵ���Ϣ 
	    if(choice==1)
     	{
		    cout<<"������Ҫ��ѯ��ѧ�ţ�";
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
		    cout<<"������Ҫ��ѯ��������";
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
    	    cout<<"δ���ҵ���ѧ����Ϣ...\n";
	    }
	    char c;
	    cout<<"\n�Ƿ������ѯ(Y/N)��";
        cin>>c;
        system("cls");
        if(c == 'N' || c == 'n')
        break;
    }	
}

void Matstu::modify()//�޸���Ϣ 
{
    string name1;
	cout<<"����������Ҫ�޸ĵ�ѧ�����֣�";
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
	cout<<"�޸ĳɹ�!"<<endl;
}
	
void Matstu::del()//ɾ����� 
{
    int del_flag = 0;
	string name1;
	if(head->next == end)	
	{
	    cout<<"�յ�..."<<endl;
		return ;
	}
	cout<<"����������Ҫɾ����ѧ�����֣�";
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
	    cout<<"δ���ҵ���ѧ��...."<<endl;
	}
	cout<<"ɾ����Ϣ�ɹ�!"<<endl;
}
    
void Matstu::save()
{
    out.open("matstu.txt");
    Matstu *pos = head->next;
    if(head->next== end)
	{
		cout<<"�յ�..."<<endl;
	}
    for(pos;pos!=end;pos=pos->next)
    {
        out<<'\t'<<pos->id<<'\t'<<pos->faculty<<'\t'<<pos->name<<'\t'<<pos->age<<'\t'<<pos->math_score<<'\t'<<pos->english_score<<'\t'<<pos->sport_score<<'\t'<<pos->real_function_score<<'\t'<<pos->functional_analysis_score<<'\t'<<pos->differential_geometry_score<<'\t'<<pos->all_average_score3<<'\t'<<pos->public_average_score3;
    }
    out.close();
    cout<<"����ɹ�"<<endl;
}
	
void Matstu::readfile(ifstream &in)
{
    in>>id>>faculty>>name>>age>>math_score>>english_score>>sport_score>>real_function_score>>functional_analysis_score>>differential_geometry_score>>all_average_score3>>public_average_score3;
}
	
void Matstu::copy3(Matstu *p1,Matstu *p2)//�������ڽ������� 
{
	if (p2 == nullptr)
    {
        cout <<"����Ŀ��Ϊ�գ�"<<endl;
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
        //ֻ����Ϣ����,next���ܿ���������Ϣ��ʧ
    }
}		
	
void Matstu::sort()//���� 
{
    cout<<"\t\t************************����**********************\n";
	cout<<"\t\t*                                                *\n";
    cout<<"\t\t*            1.��ȫ���γ�ƽ���ɼ�������          *\n";
    cout<<"\t\t*                                                *\n";
    cout<<"\t\t*            2.��ȫ���γ�ƽ���ɼ�������          *\n";
    cout<<"\t\t*                                                *\n";
    cout<<"\t\t*            3.�������γ�ƽ���ɼ�������          *\n";
    cout<<"\t\t*                                                *\n";
    cout<<"\t\t*            4.�������γ�ƽ���ɼ�������          *\n";
    cout<<"\t\t*                                                *\n";
    cout<<"\t\t**************************************************\n";
    cout<<"\t\t������ָ��(1-4): ";
	int choice(0);
	cin>>choice;
	while(choice < 1 || choice > 4)
    {
        cout<<"����ָ�\n\n";
        system("pause");//�⽫Ҫ�󡰰������....���رմ���
        continue;       //����ִ�������ж�
    }
    Matstu *p1,*p2;
    p1=head->next;
    if(choice==1)//��ȫ���γ�ƽ���ɼ������� 
    {
	    for(p1;p1!=end;p1=p1->next)//ð������
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
    if(choice==2)//��ȫ���γ�ƽ���ɼ������� 
    {
	    p1=head->next;
	    for(p1;p1!=end;p1=p1->next)//ð������
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
    if(choice==3)//�������γ�ƽ���ɼ������� 
    {
	    for(p1;p1!=end;p1=p1->next)//ð������
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
    if(choice==4)//�������γ�ƽ���ɼ������� 
    {
	    p1=head->next;
	    for(p1;p1!=end;p1=p1->next)//ð������
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
    cout<<"����ɹ�!"<<endl;	
} 
