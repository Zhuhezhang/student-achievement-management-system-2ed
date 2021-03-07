//Ӣ��ϵѧ����Ϣ�������ʵ�� 
#include "workengclass.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void Engstu::menu2()//Ӣ��ϵѧ���˵� 
{
	while(1)
	{
		open();
		system("cls");
		cout<<"\t\t**********Ӣ��ϵѧ���ɼ�����ϵͳ�˵�******\n";
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
	//��ʼ����ͷβ��� 
	head = new Engstu;
	head->next = new Engstu;
	end = head->next; 
	ifstream in("engstu.txt");
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
		end->next = new Engstu;
		end = end->next;
	}
} 
 
void Engstu::input2()//Ӣ��ϵѧ������ 
{
	input1();
	cout<<"�ۺ�Ӣ��ɼ���"<<endl;
    cin>>comprehensive_english_score;
    cout<<"����ɼ���"<<endl;
    cin>>speaking_score;
    cout<<"�����ɼ���"<<endl;
    cin>>hearing_score;
    all_average_score2=(math_score+english_score+sport_score+comprehensive_english_score+speaking_score+hearing_score)/6;
    public_average_score2=(math_score+english_score+sport_score)/3;
}
	
void Engstu::output2()
{
	output1();
	cout<<"�ۺ�Ӣ��ɼ���"<<comprehensive_english_score<<endl;
    cout<<"����ɼ���"<<speaking_score<<endl;
    cout<<"�����ɼ���"<<hearing_score<<endl;
    cout<<"ȫ���γ�ƽ���ɼ���"<<all_average_score2<<endl;
    cout<<"�����γ�ƽ���ɼ���"<<public_average_score2<<endl;
}

void Engstu::add()//������Ϣ
{
	char quit;
	while(1)
    {
		end->input2();
		end->next = new Engstu;
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
	
void Engstu::display()//��ʾ��Ϣ 
{
    if(head->next==end)
	{
	    cout<<"�յ�..."<<endl;
	}
	Engstu *pos;
	pos = head->next;
	for(pos;pos!=end;pos=pos->next)
 	{
		output2();
		cout<<endl;
	}	
}
	
void Engstu::find()//��ѯ��Ϣ 
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
	    Engstu *pos = head->next;
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
	
void Engstu::modify()//�޸���Ϣ 
{
    string name1;
	cout<<"����������Ҫ�޸ĵ�ѧ�����֣�";
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
	cout<<"�޸ĳɹ�!"<<endl;
}
	
void Engstu::del()//ɾ����Ϣ
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
	    cout<<"δ���ҵ���ѧ��...."<<endl;
	}
	cout<<"ɾ����Ϣ�ɹ�!"<<endl;
}
    
void Engstu::save()//������Ϣ���ļ� 
{
    out.open("engstu.txt");
    Engstu *pos = head->next;
    if(head->next== end)
	{
		cout<<"�յ�..."<<endl;
	}
    for(pos;pos!=end;pos=pos->next)
    {
        out<<'\t'<<pos->id<<'\t'<<pos->faculty<<'\t'<<pos->name<<'\t'<<pos->age<<'\t'<<pos->math_score<<'\t'<<pos->english_score<<'\t'<<pos->sport_score<<'\t'<<pos->comprehensive_english_score<<'\t'<<pos->speaking_score<<'\t'<<pos->hearing_score<<'\t'<<pos->all_average_score2<<'\t'<<pos->public_average_score2;
    }
    out.close();
    cout<<"����ɹ�"<<endl;
}
	
void Engstu::readfile(ifstream &in)//���ļ������� 
{
    in>>id>>faculty>>name>>age>>math_score>>english_score>>sport_score>>comprehensive_english_score>>speaking_score>>hearing_score>>all_average_score2>>public_average_score2;
}
	
void Engstu::copy2(Engstu *p1,Engstu *p2)//�������ڽ������� 
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
        p1->comprehensive_english_score = p2->comprehensive_english_score;
        p1->speaking_score = p2->speaking_score;
        p1->hearing_score = p2->hearing_score;
        p1->all_average_score2 = p2->all_average_score2;
        p1->public_average_score2 = p2->public_average_score2;
        //ֻ����Ϣ����,next���ܿ���������Ϣ��ʧ
    }	
}	
	
void Engstu::sort()//���� 
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
    Engstu *p1,*p2;
    p1=head->next;
    if(choice==1)//��ȫ���γ�ƽ���ɼ������� 
    {
	    for(p1;p1!=end;p1=p1->next)//ð������
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
    if(choice==2)//��ȫ���γ�ƽ���ɼ������� 
    {
	    p1=head->next;
	    for(p1;p1!=end;p1=p1->next)//ð������
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
    if(choice==3)//�������γ�ƽ���ɼ������� 
    {
	    for(p1;p1!=end;p1=p1->next)//ð������
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
    if(choice==4)//�������γ�ƽ���ɼ������� 
    {
	    p1=head->next;
	    for(p1;p1!=end;p1=p1->next)//ð������
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
    cout<<"����ɹ�!"<<endl;
}
