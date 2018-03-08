#include"Sales_data.h"

istream &read(istream &is,Sales_data &item)
{
	double price=0;
	is>>item.ISBN>>item.TheNum>>price;
	 item.TheSumMoney=price*item.TheNum;
	 return is;
 } 
ostream &print(ostream &os,const Sales_data &item)
{
	os<<item.ISBN<<" "<<item.TheNum<<" "<<item.TheSumMoney<<" "<<item.avg_price();
	return os;
}
Sales_data add(const Sales_data &lhs,const Sales_data &rhs)
{
	Sales_data sum=lhs;
	return sum.combine(rhs);
}
Sales_data & Sales_data::combine(const Sales_data &rhs)
{
	TheNum+=rhs.TheNum;
	TheSumMoney+=rhs.TheSumMoney;
	return *this;
}
