#include<iostream>
#include"Sales_item.h"

int main()
{
	Sales_item a;
	Sales_item sum;
	std::cin>>a;
	sum=a;
	
	while(std::cin>>a)
     sum+=a;
	
	std::cout<<sum<<std::endl;
	return 0;
}
