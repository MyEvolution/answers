#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<functional>

using namespace std;
using namespace placeholders;

void biggies(vector<string> &v,vector<string>::size_type sz);
int main()
{
	vector<string> v{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
	biggies(v,4);
	return 0; 
}
bool check_size(const string &s,vector<string>::size_type sz)
{
	return s.size()>=sz;
}
bool isShorter(const string &s1,const string &s2)
{
	return s1.size()<s2.size();
}
void biggies(vector<string> &v,vector<string>::size_type sz)
{
	sort(v.begin(),v.end());
	auto i = unique(v.begin(),v.end());
	v.erase(i,v.end());
	stable_sort(v.begin(),v.end(),bind(isShorter,_1,_2));
	auto count = count_if(v.begin(),v.end(),bind(check_size,_1,sz));
	cout<<count<<endl;
	for_each(v.cend()-count,v.cend(),[](const string &s){cout<<s<<" ";});
	cout<<endl;
}
