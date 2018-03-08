#include<iostream>
#include<vector>

using namespace std;
void read_in(istream &is,vector<int> *);
void print_out(vector<int> *);
int main()
{
	vector<int> *v = new vector<int>;
	read_in(cin,v);
	print_out(v);
	delete v;
	return 0;
 }
 void read_in(istream &is,vector<int> *v)
 {
 	int a;
 	while(is>>a)
 	v->push_back(a);
 }
 void print_out(vector<int> *v)
 {
 	for(auto i:*v)
 	cout<<i<<" ";
 	cout<<endl;
 }
