#include<iostream>
#include<iterator>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;

int main()
{
	string filename;
	cin>>filename;
	ifstream ifs(filename);
	istream_iterator<string> i(ifs),eof;
	ostream_iterator<string> o(cout,"\n");
	vector<string> v(i,eof);
	copy(v.cbegin(),v.cend(),o);
	return 0;
}
