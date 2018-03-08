#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
#include<list>

using namespace std;

int main()
{
	
	list<string> v1;
	vector<int> v2{1,2,3,4,5,6,7,8,9};
	vector<int> v3,v5;
	list<int> v4;
	vector<string> v{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
	sort(v.begin(),v.end());
	unique_copy(v.begin(),v.end(),back_inserter(v1));
	for_each(v1.begin(),v1.end(),[](const string &s){cout<<s<<endl;});
	copy(v2.begin(),v2.end(),back_inserter(v3));
	copy(v2.begin(),v2.end(),front_inserter(v4));
		copy(v2.begin(),v2.end(),inserter(v5,v5.begin()));
		for_each(v3.begin(),v3.end(),[](int i){
			cout<<i<<" ";
		});
		cout<<endl;
        for_each(v4.begin(),v4.end(),[](int i){
			cout<<i<<" ";
		});
		cout<<endl;
		for_each(v5.begin(),v5.end(),[](int i){
			cout<<i<<" ";
		});
		cout<<endl;
	return 0;
}
