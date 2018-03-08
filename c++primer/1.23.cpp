#include<iostream>
#include"Sales_item.h"
#include<fstream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	ifstream ifs(s);
	Sales_item item;
	Sales_item Current;
	
	if(ifs>>item)
{
	Current=item;
	while(ifs>>item)
	{
		if(item.isbn()==Current.isbn())
		Current+=item;
		else
		{
			std::cout<<Current<<std::endl;
		   Current=item;
		}
	}
	std::cout<<Current<<std::endl;
}
else
   std::cerr<<"No Data?£¡"<<std::endl; 
	return 0;
 } 
