//�����ϵѧ����Ϣ�������ʵ�� 
#include "workcomclass.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void Comstu::menu2()//�����ϵ�˵� 
{
	while(1)
	{
		open();
		system("cls");
		cout<<"\t\t********�����ϵѧ���ɼ�����ϵͳ�˵�******\n";
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

void Comstu::close()
{
	save();
    Comstu *pos = head->next;
	Comstu *temp;
	while(pos!=end)
	{
		temp = pos;
		pos = pos->next;
		delete temp;
	}
	delete head,end;
}

void Comstu::open()
{
	//��ʼ����ͷβ��� 
	head = new Comstu;
	head->next = new Comstu;
	end = head->next; 
	ifstream in("comstu.txt");
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
		end->next = new Comstu;
		end = end->next;
	}
} 
 
void Comstu::input2()//�����ϵ����
{
	input1();
	cout<<"��������ԭ��ɼ���"<<endl;
    cin>>computer_composition_principle_score;
    cout<<"�������ϵ�ɼ���"<<endl;
    cin>>computer_archiecture_score;
    cout<<"������Գɼ���"<<endl;
    cin>>assembly_language_score;
    all_average_score1=(math_score+english_score+sport_score+computer_composition_principle_score+computer_archiecture_score+assembly_language_score)/6;
    public_average_score1=(math_score+english_score+sport_score)/3;
}

void Comstu::output2()//�����ϵ���
{
	output1();
	cout<<"��������ԭ��ɼ���"<<computer_composition_principle_score<<endl;
    cout<<"�������ϵ�ɼ���"<<computer_archiecture_score<<endl;
    cout<<"������Գɼ���"<<assembly_language_score<<endl;
    cout<<"ȫ���γ�ƽ���ɼ���"<<all_average_score1<<endl;
    cout<<"�����γ�ƽ���ɼ���"<<public_average_score1<<endl;
}

void Comstu::add()//���� 
{
	char quit;
	while(1)
    {
		end->input2();
		end->next = new Comstu;
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
	
void Comstu::display()//��ʾ 
{
    if(head->next==end)
	{
	    cout<<"�յ�..."<<endl;
	}
	Comstu *pos;
	pos = head->next;
	for(pos;pos!=end;pos=pos->next)
 	{
		pos->output2();
		cout<<endl;
	}	
} 
	
void Comstu::find()//��ѯ 
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
	    Comstu *pos = head->next;
	    int flag(0);//�ж��Ƿ��ҵ���Ϣ 
	    if(choice==1)
     	{
		    cout<<"������Ҫ��ѯ��ѧ�ţ�";
		    cin>>id;
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
	
void Comstu::modify()//�޸� 
{
    string name1;
	cout<<"����������Ҫ�޸ĵ�ѧ�����֣�";
	cin>>name1;
	Comstu *pos = head->next;
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
	
void Comstu::del()//ɾ����� 
{
    int del_flag = 0;
	string name1;
	if(head->next == end)	
	{
	    cout<<"�յ�..."<<endl;
		return;
	}
	cout<<"����������Ҫɾ����ѧ�����֣�";
	cin>>name1;
	Comstu *p1 = head->next;
	Comstu *p2 = head;
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
    
void Comstu::save()//������Ϣ���ļ� 
{
    out.open("comstu.txt");
    Comstu *pos = head->next;
    if(head->next== end)
	{
		cout<<"�յ�..."<<endl;
	}
    for(pos;pos!=end;pos=pos->next)
    {
        out<<'\t'<<pos->id<<'\t'<<pos->faculty<<'\t'<<pos->name<<'\t'<<pos->age<<'\t'<<pos->math_score<<'\t'<<pos->english_score<<'\t'<<pos->sport_score<<'\t'<<pos->computer_composition_principle_score<<'\t'<<pos->computer_archiecture_score<<'\t'<<pos->assembly_language_score<<'\t'<<pos->all_average_score1<<'\t'<<pos->public_average_score1;
    }
    out.close();
    cout<<"����ɹ�"<<endl;
}
	
void Comstu::readfile(ifstream &in)//���ļ��������ݵ���� 
{
    in>>id>>faculty>>name>>age>>math_score>>english_score>>sport_score>>computer_composition_principle_score>>computer_archiecture_score>>assembly_language_score>>all_average_score1>>public_average_score1;
}
	
void Comstu::copy1(Comstu *p1,Comstu *p2)//�������ڽ������� 
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
        p1->computer_composition_principle_score = p2->computer_composition_principle_score;
        p1->computer_archiecture_score = p2->computer_archiecture_score;
        p1->assembly_language_score = p2->assembly_language_score;
        p1->all_average_score1 = p2->all_average_score1;
        p1->public_average_score1 = p2->public_average_score1;
        //ֻ����Ϣ����,next���ܿ���������Ϣ��ʧ
   }
}
	
void Comstu::sort()//���򲿷� 
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
    Comstu *p1,*p2;
    p1=head->next;
    if(choice==1)//��ȫ���γ�ƽ���ɼ������� 
    {
	    for(p1;p1!=end;p1=p1->next)//ð������
	    {
		    for(p2=p1->next;p2!=end;p2=p2->next)
		    {
			    if(p2->all_average_score1 > p1->all_average_score1)
			    {
				    Comstu *ptemp = new Comstu;
                    copy1(ptemp, p1);
                    copy1(p1, p2);
                    copy1(p2, ptemp);
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
			    if(p2->all_average_score1 < p1->all_average_score1)
			    {
				    Comstu *ptemp = new Comstu;
                    copy1(ptemp, p1);
                    copy1(p1, p2);
                    copy1(p2, ptemp);
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
			    if(p2->public_average_score1 > p1->public_average_score1)
			    {
				    Comstu *ptemp = new Comstu;
                    copy1(ptemp, p1);
                    copy1(p1, p2);
                    copy1(p2, ptemp);
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
			    if(p2->public_average_score1 < p1->public_average_score1)
			    {
				    Comstu *ptemp = new Comstu;
                    copy1(ptemp, p1);
                    copy1(p1, p2);
                    copy1(p2, ptemp);
		        }	
		    }
      	}
    }
    cout<<"����ɹ�!"<<endl;
}
