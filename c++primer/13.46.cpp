#include<utility>
#include<iostream>

using namespace std;

int main()
{
	int && i = 5;
	int p = 10;
	int && j =move(10);
	cout<<i<<endl;
	cout<<++i<<endl;
	p = 100;
	j = 101;
	cout<<++j<<endl;
	cout<<p<<endl;
	return 0;
 } 
