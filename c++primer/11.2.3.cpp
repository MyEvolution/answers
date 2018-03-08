#include<string>
#include<iostream>
#include<utility>
#include<vector>
#include<map>
#include<iterator>

using namespace std;

int main()
{
	//pair<string,int> p;
	vector<pair<string,int>> v;
	string s;
	int i;
	while(cin>>s,cin>>i)
	//v.push_back(pair<string,int>(s,i));
	v.push_back({s,i});
	for(auto i:v)
	cout<<i.first<<" "<<i.second<<endl;
	map<string ,int> m;
	auto p = inserter(m,m.end());
	p={"string",5};
	p =pair<string,int>("haha",6);
	return 0;
 } 
