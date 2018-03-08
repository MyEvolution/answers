#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int array[]={0,1,2,3,4,5,6,7,8,9,10};
	vector<int> vect(begin(array),end(array));
	int array1[11];
	
	for(auto i:vect)
	cout<<i<<" ";
	cout<<endl;
	int *p=array1;
	auto q=vect.begin();
    for(;q!=vect.end();p++,q++)
    {
    *p=*q;
    cout<<*p<<" ";
  }
  cout<<endl;
	return 0;
}
