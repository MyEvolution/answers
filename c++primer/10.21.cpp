#include<iostream>
int main()
{
	int i;
	std::cin>>i;
	auto f = [=]()mutable->bool{
	while(--i!=0) ;
	return i==0;};
	std::cout<<f()<<std::endl;
	return 0;
 } 
