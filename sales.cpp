#include <iostream> 
#include <string> 

//������1603 ���κ� 201616070320
//����ϵͳ ʹ������C++��C����
//��ӭָ������ 

using namespace std;

typedef struct 
{//��Ʒ��Ϣ�ṹ�� 
	unsigned int id; //��ƷID 
	string name; //��Ʒ���� 
	double price; //��Ʒ���� 
	double commodity_price; //����Ʒ�ĵ��� 
	unsigned int quantity; //��Ʒ�������� 
}Commodity;

typedef struct
{//������Ϣ�ṹ�� 
	Commodity commodities[7];  //����ÿ����Ʒ�ṹ�� 
	double all_price; //�ܼ� 
	unsigned int all_quantity; //������ 
}Sale;

void SetCommodity(Sale &s)
{
	s.all_price=0.0;
	s.all_quantity=0;
	s.commodities[1].id=1;
	s.commodities[1].name="�����";
	s.commodities[1].price=3.0;
	s.commodities[1].commodity_price=0.0; 
	s.commodities[1].quantity=0; 
	s.commodities[2].id=2;
	s.commodities[2].name="ѩ��";
	s.commodities[2].price=3.0;
	s.commodities[2].commodity_price=0.0; 
	s.commodities[2].quantity=0; 
	s.commodities[3].id=3;
	s.commodities[3].name="����";
	s.commodities[3].price=3.0;
	s.commodities[3].commodity_price=0.0; 
	s.commodities[3].quantity=0; 
	s.commodities[4].id=4;
	s.commodities[4].name="������";
	s.commodities[4].price=4.0;
	s.commodities[4].commodity_price=0.0; 
	s.commodities[4].quantity=0; 
	s.commodities[5].id=5;
	s.commodities[5].name="�̲�";
	s.commodities[5].price=3.0;
	s.commodities[5].commodity_price=0.0; 
	s.commodities[5].quantity=0; 
	s.commodities[6].id=6;
	s.commodities[6].name="��Ȫˮ";
	s.commodities[6].price=2.0;
	s.commodities[6].commodity_price=0.0; 
	s.commodities[6].quantity=0; 
} 

void PrintCommodity()
{
	cout<<"������Ҫ����Ĳ�Ʒ:"<<endl;
	cout<<"1.����� 3Ԫ"<<endl;
	cout<<"2.ѩ�� 3Ԫ"<<endl;
	cout<<"3.���� 3Ԫ"<<endl;
	cout<<"4.������ 4Ԫ"<<endl;
	cout<<"5.�̲� 3Ԫ"<<endl; 
	cout<<"6.��Ȫˮ 2Ԫ"<<endl; 
	cout<<"----------------------------"<<endl; 
}

void ToAskWhatYouNeedBuy(Sale &s)
{
	int sel;
	int i=0;
	while(1)
	{
		string select;
		if(i!=0)
			cout<<"ѡ����������ԣ�"<<endl; 
		if(i>=5)
		{
			cout<<"�벻Ҫ�����ظ������룡"<<endl; 
			exit(-1);
		}
		cout<<"����������ѡ�񣺣�ȡ��������c��"; 
		cin>>select;
		cout<<endl;
		cin.sync();//ˢ�����뻺�� 
		if(select.length()==1&&(select.at(0)=='C'||select.at(0)=='c'))
			break;
		sel=(int)strtol(select.c_str(),NULL,10);
		if(sel>0&&sel<7)
		{
			int q;
			cout<<"----------------------------"<<endl; 
			int j=0;
			while(1)
			{
				string quantity;
				if(j!=0)
					cout<<"������������ԣ�"<<endl; 
				if(j>=5)
				{
					cout<<"�벻Ҫ�����ظ������룡"<<endl; 
					exit(-1);
				}
				cout<<"����ѡ��"<<s.commodities[sel].id<<" "<<s.commodities[sel].name<<" ����������Ҫ����������ȡ��������c��"; 
				cin>>quantity;
				cout<<endl;
				cin.sync(); 
				if(quantity.length()==1&&(quantity.at(0)=='C'||quantity.at(0)=='c'))
					break;
				q=(int)strtol(quantity.c_str(),NULL,10);
				if(q>0)
				{
					if(s.commodities[sel].quantity+q>999)
						cout<<"�������������Χ�����ι�����Ч��"<<endl; 
					else
					{
						s.commodities[sel].quantity+=q; //�������� 
						s.commodities[sel].commodity_price+=(q*s.commodities[sel].price); //���µ��� 
						s.all_price+=(q*s.commodities[sel].price); //�����ܼ� 
						s.all_quantity+=q; //���������� 
					}
					break;
				} 
				j++;
			}
			j=0;
			break;
		}
		i++;
	}
	i=0;
}

void ToAskBuy(Sale &s) 
{
	int i=0;
	while(1)
	{
		if(i!=0)
		{
			if(i>=10)
			{
				cout<<"�Բ���ϵͳÿ�ν��ܽ���10�ʶ�����"<<endl; 
				exit (0); 
			} 
			string select;
			int j=0;
			while(1)
			{
				if(j!=0)
					cout<<"������������ԣ�"<<endl; 
				if(j>=5)
				{
					cout<<"�벻Ҫ�����ظ������룡"<<endl; 
					exit(-1);
				}
				cout<<"----------------------------"<<endl; 
				cout<<"���������Ƿ�Ҫ����<Y/N>";
				cin>>select;
				cout<<endl;
				cin.sync();
				if(select.length()==1&&(select.at(0)=='n'||select.at(0)=='N'||select.at(0)=='Y'||select.at(0)=='y'))
					break;//ѡ��Y/N������Ч�˳��������ѭ�� 
				j++; 
			}
			j=0;
			if(select.length()==1&&(select.at(0)=='n'||select.at(0)=='N'))
				break;//ѡ��N���Ӽ�������ֱ���˳������ѭ�� 
		}
		ToAskWhatYouNeedBuy(s);
		i++;
	}
	i=0;
}

void PrintWhatBuy(Sale s)
{
	if(s.all_price!=0&&s.all_quantity!=0)
	{
		cout<<"----------------------------"<<endl;
		cout<<"���������Ĺ�����Ϣ��"<<endl;
		cout<<"�ܼۣ�"<<s.all_price<<" Ԫ����������"<<s.all_quantity<<endl;
		cout<<"----------------------------"<<endl;
		for(int i=1;i<=6;i++)
		{
			if(s.commodities[i].quantity!=0)
			{
				cout<<s.commodities[i].name<<" "<<s.commodities[i].price<<" Ԫ * "<<s.commodities[i].quantity \
				    <<" = "<<s.commodities[i].commodity_price<<" Ԫ"<<endl;;
			}
		}
	}
} 
 
int main(void)
{
	cout<<"��������ϵͳ"<<endl;
	cout<<"----------------------------"<<endl; 
	Sale s; 
	SetCommodity(s);
	PrintCommodity();
	ToAskBuy(s);
	PrintWhatBuy(s);
	system("pause");
	return 0;
}
