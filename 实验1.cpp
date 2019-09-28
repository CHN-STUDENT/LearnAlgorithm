#include <iostream>
/************************************ 
* ��Ŀ���������������� շת�����ʵ�� 
* ������1603 201616070320 ���κ�  
************************************/ 
using namespace std;

unsigned int euclidean(unsigned int a,unsigned int b)
{
	unsigned int t;
	if(a<b)
	{//swap a,b
		t=a;
		a=b;
		b=t;
	}
	while(b!=0)
	{
		t=b;
		b=a%b;
		a=t;
	}
	return a;
} 

int main(void)
{
	unsigned int a,b;
	do
	{//check input two positive integers �������������������� 
		static int num=0;
		if(num>0)
			cout<<"Error,please retry."<<endl; //Output retry tip ��ʧ�������������ʾ 
		cout<<endl<<"Input two positive integers:";
		cin>>a>>b;
		cout<<endl;
		num++;
	}while((a<=0)&&(b<=0));
	cout<<"The greatest common divisor is "<<euclidean(a,b)<<" ."<<endl;
} 
