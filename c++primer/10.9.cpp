#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
bool isShorter(const string &s1,const string &s2)
{
	return s1.size()<s2.size();
}
void elimDups(vector<string> &v)
{
	sort(v.begin(),v.end());
	
	auto _end = unique(v.begin(),v.end());
	v.erase(_end,v.end());
		stable_sort(v.begin(),v.end(),isShorter);
}
bool IsLessthan5(const string &s)
{
	return s.size()<5;
 } 
int main()
{
	vector<string> v{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
	elimDups(v);
    auto i = partition(v.begin(),v.end(),IsLessthan5);
	while(i!=v.cend())
	cout<<*i++<<endl;
	return 0;
	
}
