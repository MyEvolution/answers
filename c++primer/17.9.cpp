#include<iostream>
#include<bitset>

using namespace std;

int main()
{
	bitset<64> b1(32);
	bitset<32> b2(1010101);
	string a;
	cin>>a;
	bitset<8> b3(a);
	cout<<b1<<"\n"<<b2<<"\n"<<b3;
 } 
