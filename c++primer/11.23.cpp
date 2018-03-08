#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

int main()
{
	multimap<string,string> family;
	map<vector<string>,int> test;
	vector<string> v= {"wocao","haha","fuck"};
	test[v] = 10;
	test[{"wocao","haha","fuck"}]=20;
	for(auto i:test)
	  for(auto j:i.first)
	     cout<<j<<" ";
	     cout<<test[v]<<endl;
	string first_name;
	string last_name;
	while(cin>>first_name>>last_name)
	{
	    family.insert({first_name,last_name});	
	}
	for(auto i:family)
	cout<<i.first<<" "<<i.second<<endl;
	return 0;
}
