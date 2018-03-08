#include<iostream>
#include<fstream>
#include<iterator>

using namespace std;

int main()
{
	string f1,f2,f3;
	cin>>f1>>f2>>f3;
	ifstream ifs(f1);
	ofstream of1(f2),of2(f3); 
	istream_iterator<int> ii(ifs),eof;
	ostream_iterator<int> oi1(of1," "),oi2(of2,"\n");
	while(ii!=eof)
	  if(*ii&1)
	    *oi1++=*ii++;//只读流的迭代器需要自增 
	    else
	       *oi2++=*ii++;
	       return 0;
}
