#include<functional>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
using namespace placeholders;

int main()
{
	vector<string> vs{"pooh","pooh","pooh","string"};
	vector<int> vi{15,56895,10265,5635,45,9635,11235,55,10235};
	
	cout<<count_if(vi.begin(),vi.end(),bind(greater<int>(),_1,1024))<<endl;
	transform(vi.begin(),vi.end(),vi.begin(),bind(multiplies<int>(),_1,2));
	for_each(vi.begin(),vi.end(),[](int i){cout<<i<<" ";});
	cout<<endl;
	auto i = find_if(vs.begin(),vs.end(),bind(not_equal_to<string>(),_1,"pooh"));
	cout<<*i<<endl;
	if(find_if(vi.begin(),vi.end(),bind(modulus<int>(),_1,5))==vi.end())
	   cout<<"都能被5整除"<<endl;
	return 0;
}

