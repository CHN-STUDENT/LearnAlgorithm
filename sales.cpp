#include <iostream> 
#include <string> 

//物联网1603 郭治洪 201616070320
//售卖系统 使用略渣C++和C构建
//欢迎指出不足 

using namespace std;

typedef struct 
{//商品信息结构体 
	unsigned int id; //商品ID 
	string name; //商品名称 
	double price; //商品定价 
	double commodity_price; //该商品的单价 
	unsigned int quantity; //商品购买数量 
}Commodity;

typedef struct
{//售卖信息结构体 
	Commodity commodities[7];  //包括每个商品结构体 
	double all_price; //总价 
	unsigned int all_quantity; //总数量 
}Sale;

void SetCommodity(Sale &s)
{
	s.all_price=0.0;
	s.all_quantity=0;
	s.commodities[1].id=1;
	s.commodities[1].name="冰红茶";
	s.commodities[1].price=3.0;
	s.commodities[1].commodity_price=0.0; 
	s.commodities[1].quantity=0; 
	s.commodities[2].id=2;
	s.commodities[2].name="雪碧";
	s.commodities[2].price=3.0;
	s.commodities[2].commodity_price=0.0; 
	s.commodities[2].quantity=0; 
	s.commodities[3].id=3;
	s.commodities[3].name="可乐";
	s.commodities[3].price=3.0;
	s.commodities[3].commodity_price=0.0; 
	s.commodities[3].quantity=0; 
	s.commodities[4].id=4;
	s.commodities[4].name="果粒橙";
	s.commodities[4].price=4.0;
	s.commodities[4].commodity_price=0.0; 
	s.commodities[4].quantity=0; 
	s.commodities[5].id=5;
	s.commodities[5].name="绿茶";
	s.commodities[5].price=3.0;
	s.commodities[5].commodity_price=0.0; 
	s.commodities[5].quantity=0; 
	s.commodities[6].id=6;
	s.commodities[6].name="矿泉水";
	s.commodities[6].price=2.0;
	s.commodities[6].commodity_price=0.0; 
	s.commodities[6].quantity=0; 
} 

void PrintCommodity()
{
	cout<<"请输入要购买的产品:"<<endl;
	cout<<"1.冰红茶 3元"<<endl;
	cout<<"2.雪碧 3元"<<endl;
	cout<<"3.可乐 3元"<<endl;
	cout<<"4.果粒橙 4元"<<endl;
	cout<<"5.绿茶 3元"<<endl; 
	cout<<"6.矿泉水 2元"<<endl; 
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
			cout<<"选择错误，请重试！"<<endl; 
		if(i>=5)
		{
			cout<<"请不要恶意重复的输入！"<<endl; 
			exit(-1);
		}
		cout<<"请输入您的选择：（取消请输入c）"; 
		cin>>select;
		cout<<endl;
		cin.sync();//刷新输入缓冲 
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
					cout<<"输入错误，请重试！"<<endl; 
				if(j>=5)
				{
					cout<<"请不要恶意重复的输入！"<<endl; 
					exit(-1);
				}
				cout<<"您的选择："<<s.commodities[sel].id<<" "<<s.commodities[sel].name<<" ，请输入需要的数量：（取消请输入c）"; 
				cin>>quantity;
				cout<<endl;
				cin.sync(); 
				if(quantity.length()==1&&(quantity.at(0)=='C'||quantity.at(0)=='c'))
					break;
				q=(int)strtol(quantity.c_str(),NULL,10);
				if(q>0)
				{
					if(s.commodities[sel].quantity+q>999)
						cout<<"超出允许最大购买范围，本次购买无效！"<<endl; 
					else
					{
						s.commodities[sel].quantity+=q; //更新数量 
						s.commodities[sel].commodity_price+=(q*s.commodities[sel].price); //更新单价 
						s.all_price+=(q*s.commodities[sel].price); //更新总价 
						s.all_quantity+=q; //更新总数量 
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
				cout<<"对不起，系统每次仅能接受10笔订单！"<<endl; 
				exit (0); 
			} 
			string select;
			int j=0;
			while(1)
			{
				if(j!=0)
					cout<<"输入错误，请重试！"<<endl; 
				if(j>=5)
				{
					cout<<"请不要恶意重复的输入！"<<endl; 
					exit(-1);
				}
				cout<<"----------------------------"<<endl; 
				cout<<"请输入您是否还要购买：<Y/N>";
				cin>>select;
				cout<<endl;
				cin.sync();
				if(select.length()==1&&(select.at(0)=='n'||select.at(0)=='N'||select.at(0)=='Y'||select.at(0)=='y'))
					break;//选择Y/N输入有效退出这个输入循环 
				j++; 
			}
			j=0;
			if(select.length()==1&&(select.at(0)=='n'||select.at(0)=='N'))
				break;//选择N不接继续购买直接退出掉这个循环 
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
		cout<<"以下是您的购买信息："<<endl;
		cout<<"总价："<<s.all_price<<" 元，总数量："<<s.all_quantity<<endl;
		cout<<"----------------------------"<<endl;
		for(int i=1;i<=6;i++)
		{
			if(s.commodities[i].quantity!=0)
			{
				cout<<s.commodities[i].name<<" "<<s.commodities[i].price<<" 元 * "<<s.commodities[i].quantity \
				    <<" = "<<s.commodities[i].commodity_price<<" 元"<<endl;;
			}
		}
	}
} 
 
int main(void)
{
	cout<<"饮料售卖系统"<<endl;
	cout<<"----------------------------"<<endl; 
	Sale s; 
	SetCommodity(s);
	PrintCommodity();
	ToAskBuy(s);
	PrintWhatBuy(s);
	system("pause");
	return 0;
}
