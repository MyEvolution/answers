#include<iostream>

using namespace std;

int main()
{
	int i;
	cin>>i;
	auto f=[](int a,int b){
		return a+b;
	};
	auto f1=[i](int b)
	{
		return i+b;
	};
	cout<<f(5,6)<<endl;
	cout<<f1(6)<<endl;
	return 0;
}
