#include<forward_list>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	forward_list<int> fl({1,2,3,4,5,6,7,8,9});
	forward_list<int> fl2({10,11,12,13,14});
	fl.splice_after(fl.begin(),fl2,fl2.begin(),fl2.end());
	for_each(fl.begin(),fl.end(),[](int i){
		cout<<i<<" ";
	});
	return 0;
}
