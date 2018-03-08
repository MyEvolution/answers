#include<iostream>
#include<vector>
using std::cin;using std::cout;
using std::endl;
using std::vector;
int main()
{
	vector<int> data;
	int a;
	while(cin>>a)
	  data.push_back(a);
	for(auto i=data.begin();(i+1)!=data.end();i++)
	  cout<<*i+*(i+1)<<" ";
	  cout<<endl;
	  for(auto i=data.begin();i!=(data.begin()+data.size()/2);i++)
	  cout<<*i+*(data.end()-(i-data.begin())-1)<<" ";
	  cout<<endl;
	  return 0;
 } 
