#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int i;
	vector<int> num;
	while(cin>>i)
	 num.push_back(i);
	 for(auto &data:num)
	   if(data&1)
	   data*=2;
	for(auto data=num.begin();data!=num.end();data++)
	cout<<*data<<" ";
	return 0;
	   
 } 
