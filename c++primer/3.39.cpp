#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	string item1="what the FuCK!!";
	string item2="What The FuCK!!";
	char item3[]="what the FuCK!!"; 
	char item4[]="What The FuCK!!";
	item1>item2?cout<<item1<<endl:cout<<item2<<endl;
	strcmp(item3,item4)>0?cout<<item3<<endl:cout<<item4<<endl;
	return 0;
}
