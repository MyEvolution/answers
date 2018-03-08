#include<iostream>
#include<string>
/*
预处理器
假如了#ifndef后  只有在该文件没有被定义的时候才会重新定义
这应当是一个习惯
所以类string中也加了预处理器
这样在头文件重复的情况下
编译器也不会发出错误或警告
因为只有第一个头文件未被忽略
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
