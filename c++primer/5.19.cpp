#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1,s2;
	do
	{
		cout<<"please input two strings"<<endl;
		if(cin>>s1>>s2)
		if(s1.size()>s2.size())
		cout<<s2<<endl;
		else 
		  cout<<s1<<endl;
	}while(cin);
	return 0;
 } 
