#ifndef SALES_DATA2_H
#include<iostream>
#include<string>

class Sales_data2
{
	private:
	std::string bookNo;
    unsigned unit_sold = 0;
    double revenue=0.0;
    public:
    Sales_data2(std::string s,unsigned num,double price):bookNo(s),
	unit_sold(num),revenue(price*unit_sold)//如果类中的revenue在unit_sold前定义就不好使了 
	{std::cout<<"0"<<std::endl;};
	Sales_data2():Sales_data2("",0,0.0){
		std::cout<<"1"<<std::endl;
	}
	Sales_data2(std::string s):Sales_data2(s,0,0.0){
		std::cout<<"2"<<std::endl;
	}
	Sales_data2(std::istream &is):Sales_data2()
	{
		is>>bookNo>>unit_sold>>revenue;
		std::cout<<"3"<<std::endl;
	}
};
#endif

Sales_data2 A,B("11111"),C("1",1,10),D(std::cin);//0 1 0 2  0 0 1 3
