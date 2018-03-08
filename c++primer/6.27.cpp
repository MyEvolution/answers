#include<iostream>
#include<initializer_list>
#include<vector>
using namespace std;
int sum(initializer_list<int> );
//int sum(vector<int> );
int main()
{
	cout<<sum({1,2,3,4,5,6});
	return 0;
 }
int sum(initializer_list<int> l)
{
	int sum=0;
	for(auto &i:l)
	 sum+=i;
	 return sum;
}
