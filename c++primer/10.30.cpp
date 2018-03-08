#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>
using namespace std;

int main()
{
	istream_iterator<int> i(cin),eof;
	ostream_iterator<int> o(cout," ");
	vector<int> v(i,eof);
	sort(v.begin(),v.end());
	unique_copy(v.begin(),v.end(),o);
	return 0;
}
