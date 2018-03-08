#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	map<string,vector<pair<string,string>>> _first_name;
	string first_name;
	string child_name;
	string birth;
	while(cin>>first_name)
	{
		while(cin>>child_name>>birth)
		  _first_name[first_name].push_back({child_name,birth});
		  cin.clear();
	}
	for(auto i:_first_name)
	{
		cout<<"children whose first name is "<<"\""<<i.first<<"\":";
		for_each(i.second.cbegin(),i.second.cend(),[](const pair<string,string> &s){cout<<s.first<<" "<<s.second<<endl;});
		cout<<endl;
	}
	return 0;
	
}
