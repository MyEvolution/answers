#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> data;
	int m;
	for(decltype(data.size()) i=0;i<10;i++)
	{
	cin>>m;
	data.push_back(m);
	}
	for(auto i=data.begin();i!=data.end();i++)
	 {
	  *i*=2;
	  cout<<*i<<" ";
	}
	cout<<endl;
	return 0; 
}
