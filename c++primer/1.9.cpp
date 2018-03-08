#include<iostream>
int main()
{
	int i=50;
	int sum=0;
	while(i<=100)
	sum+=i++;
	std::cout<<"the sum is "<<sum<<std::endl;
	return 0;
 } 
