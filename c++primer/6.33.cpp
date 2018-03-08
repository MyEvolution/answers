#include<iostream>
#include<vector>
	int i=10;
using namespace std;
void printve(const vector<int> &,vector<int>::size_type );
int main()
{
	vector<int> v{0,1,2,3,5,6,9};

	printve(v,v.size());
	return 0;
}
void printve(const vector<int> &v,vector<int>::size_type si)
{
	static decltype(si) i = si;
	if(si>1)
	printve(v,si-1);
	cout<<v[si-1]<<((i==si)?'\n':' ');
}
