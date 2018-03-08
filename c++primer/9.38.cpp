#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> v;
    vector<int>::size_type a,b;
    	v.resize(1198);
	while((a=v.capacity())>=(b=v.size())&&a<10000)
	  {
	  
	  	cout<<a<<endl;
	  v.insert(v.end(),a-b+200,200);
	  
       }
       return 0;
}
