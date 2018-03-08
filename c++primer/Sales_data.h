#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<string>
#include<iostream>

using std::istream;
using std::ostream;
using std::string;
//template <typename T> struct std::hash;
struct Sales_data
{
	friend struct std::hash<Sales_data>;
   friend istream &read(istream &is,Sales_data &item);
   friend ostream &print(ostream &os,const Sales_data &item);
   friend Sales_data add(const Sales_data &lhs,const Sales_data &rhs);
   friend istream &operator >> (istream &is,Sales_data & sd);
   friend ostream &operator << (ostream &os,const Sales_data &sd);
	public:
	Sales_data()=default;
	Sales_data(const std::string &s):ISBN(s){}
	Sales_data(const std::string &s,int num,double price):ISBN(s),TheNum(num),TheSumMoney(num*price){}
	Sales_data(istream is)
	{
		double price;
		is>>this->ISBN>>this->TheNum>>price;
		this->TheSumMoney=price*this->TheNum;
	}
	Sales_data &  operator =(const string & s);
	Sales_data &  operator =(const Sales_data & s);
	Sales_data& operator += (const Sales_data &s)
	{
	       TheNum+= s.TheNum;
	       TheSumMoney += s.TheSumMoney;
	       return *this;
	}
    friend bool operator == (const Sales_data &,const Sales_data &);
	private:
	std::string ISBN;//书的编码 
	int TheNum=0;//卖出去的数量
	double TheSumMoney=0.0;//价格 
	public:	
	std::string isbn()const{return ISBN;};
	Sales_data &combine(const Sales_data &rhs);
	inline double avg_price()const{return (TheNum!=0)?TheSumMoney/TheNum:-1;}
};
namespace std
{
	template <> struct hash<Sales_data>
	{
		typedef size_t result_type ;
		typedef Sales_data argument_type ;
		size_t operator ()(const Sales_data & a)const
		{
			return hash<string>()(a.ISBN)^hash<int>()(a.TheNum)
			^hash<double>()(a.TheSumMoney);
		}
	};
}
istream &operator >> (istream &is,Sales_data & sd)
{
	double price;
	is>>sd.ISBN>>sd.TheNum>>price;
	if(is)//这个检查的是输入最后一个的状态，也就是输入3个后再输入结束符，那么price输入正确，is也是有效的，在下次读取时候会出错*/ 
	sd.TheSumMoney = price * sd.TheNum;//必须检查可能会输入错误的情况
	/*仔细想一下 ，如果我们用while(cin>>Sd)
	而我们未定义输入出错的情况
	那么sd.ISBN以及其他成员会出现未定义的情况*/ 
	else
	  sd = Sales_data();
	return is;
}
ostream &operator << (ostream &os,const Sales_data &sd)
{
	os<<sd.ISBN<<" "<<sd.TheNum<<" "<<sd.TheSumMoney<<" "<<sd.TheSumMoney/sd.TheNum;
	return os;
}
istream &read(istream &is,Sales_data &item);
ostream &print(ostream &os,const Sales_data &item);
//正如两个变量相加返回一个右值一样，这里返回类型非引用 
Sales_data add(const Sales_data &lhs,const Sales_data &rhs);
bool compareIsbn(const Sales_data &s1,const Sales_data &s2)
{
	return s1.isbn()<s2.isbn();
}
/*Sales_data::Sales_data(istream is)
{
	read(is,*this);
}*/
Sales_data operator + (const Sales_data &s1,const Sales_data &s2)
{
	Sales_data s3(s1);
	s3+=s2;
	return s1;
}
Sales_data & Sales_data::operator =(const Sales_data &s1)
{
	ISBN = s1.ISBN;
	TheNum = s1.TheNum;
	TheSumMoney = s1.TheSumMoney;
	return *this;
 }
 Sales_data & Sales_data :: operator =(const string & s)
 {
 	ISBN = s;
 	TheNum = 0,TheSumMoney = 0;
 	return *this;
 }
 bool operator ==(const Sales_data &s1,const Sales_data &s2)
 {
 	return s1.ISBN == s2.ISBN&& s1.TheNum == s2.TheNum && s1.TheSumMoney == s2.TheSumMoney;
 }
#endif
