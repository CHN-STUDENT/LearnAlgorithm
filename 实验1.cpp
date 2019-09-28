#include <iostream>
/************************************ 
* 题目：求两个数正整数 辗转相除法实现 
* 物联网1603 201616070320 郭治洪  
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
	{//check input two positive integers 检测输入的是两个正整数 
		static int num=0;
		if(num>0)
			cout<<"Error,please retry."<<endl; //Output retry tip 在失败输入给重试提示 
		cout<<endl<<"Input two positive integers:";
		cin>>a>>b;
		cout<<endl;
		num++;
	}while((a<=0)&&(b<=0));
	cout<<"The greatest common divisor is "<<euclidean(a,b)<<" ."<<endl;
} 
