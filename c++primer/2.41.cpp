#include<iostream>
#include<string>
/*
Ԥ������
������#ifndef��  ֻ���ڸ��ļ�û�б������ʱ��Ż����¶���
��Ӧ����һ��ϰ��
������string��Ҳ����Ԥ������
������ͷ�ļ��ظ��������
������Ҳ���ᷢ������򾯸�
��Ϊֻ�е�һ��ͷ�ļ�δ������
*/ 
#include"Sales_data.h"
int main()
{
	Sales_data data1,data2;
	double price;
	std::cin>>data1.ISBN>>data1.TheNum>>price;
	data1.TheSumMoney=data1.TheNum*price;
	
	std::cin>>data2.ISBN>>data2.TheNum>>price;
	data2.TheSumMoney=data2.TheNum*price;
	if(data1.ISBN==data2.ISBN)
	{
		std::cout<<data1.ISBN<<" "<<data1.TheNum+data2.TheNum<<" "<<data1.TheSumMoney+data2.TheSumMoney
		<<" ";
		if(data1.TheNum+data2.TheNum)
		std::cout<<(data1.TheSumMoney+data2.TheSumMoney)/(data1.TheNum+data2.TheNum)
		<<std::endl;
		else
		std::cout<<"no sales"<<std::endl; 
		return 0;
	}else
	{
		std::cerr<<"the ISBN is not the same!"<<std::endl;
		return -1;
	}
 } 
