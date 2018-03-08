#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include"Sales_item.h"
#include<fstream>
#include<functional>

using namespace std;
using namespace placeholders;
inline bool compareIsbn1(const Sales_item & s1,const Sales_item & s2)
{
	return s1.isbn()<s2.isbn();
}
int main()
{
	string filename;
	cin>>filename;
	ifstream ifs(filename);
	istream_iterator<Sales_item> i(ifs),eof;
	ostream_iterator<Sales_item> o(cout,"\n");
	vector<Sales_item> v(i,eof);
	stable_sort(v.begin(),v.end(),compareIsbn1);
	auto begin = v.cbegin();
	      while(begin!=v.cend())
	      {	  
	auto count1 = count_if(begin,v.cend(),bind(compareIsbn,*begin,_1));

	auto sum = accumulate(begin+1,begin+count1,*begin);
	   o=sum;//Êä³öºÍ 
	   begin+=count1;
           }
	return 0;
}
