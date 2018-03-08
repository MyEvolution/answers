#include<iostream>
#include"real_StrBlob.h"
using namespace std;
int main()
{
	const StrBlob SB;
	StrBlob sb(SB);
	string line;
	while(getline(cin,line))
	  SB.push_back(line);
	  for(auto i = SB.begin();!i.is_equal(SB.end());i.incr())
	    i.deref() = "haha";
	  for(auto i = SB.begin();!i.is_equal(SB.end());i.incr())
	  cout<<i.deref()<<endl;
	     return 0;
 } 
