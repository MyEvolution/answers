#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

template <typename T> size_t occur_times(const T&i,const vector<T> & v )
{
   size_t times = 0;
   for(auto j:v)
   if(j == i)
      ++times;
      return times;
}
template <> size_t occur_times(const char * const &i,const vector<const char *> & v)
{
	size_t times = 0;
	for(auto j : v)
	if(!strcmp(j,i))
	++times;
	return times;
}
int main()
{
	vector<int> v1 = {1,2,5,63,2,2,2,6,9,3,2,1,4,2};
	vector<double> v2 = {1.0,5.6,9.6,8.1,1.0,1.0,1.0};
	vector<string> v3 = {"fuck","haha","english","fuck"};
	vector<const char *> v4 = {"fuck","haha","english","fuck"};
	const char *i = "fuck";
	cout<<occur_times(2,v1)<<endl;
	cout<<occur_times(1.0,v2)<<endl;
	cout<<occur_times<string>("fuck",v3)<<endl;
	cout<<occur_times(i,v4)<<endl;
}
