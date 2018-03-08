#include<iostream>
int main()
{
	int current;
	int getnum;
	int cout;
	std::cin>>current;
	cout=1;
	while(std::cin>>getnum)
		if(getnum==current)
		cout++;
		else
		{
			std::cout<<current<<" occurs "<<cout<<" times "<<std::endl;
			current=getnum;
			cout=1;
		}
	std::cout<<current<<" occurs "<<cout<<" times "<<std::endl;
	return 0;
}
