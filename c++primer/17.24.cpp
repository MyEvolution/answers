#include<regex>
#include<iostream>

using namespace std;

bool valid(const smatch &s);
int main()
{
	string pattern("(\\()?(\\d{3})(\\))?([-. ])*(\\d{3})([-. ])?(\\d{4})");
	regex r(pattern);
	string format("$2.$5.$7");
	smatch sm;
	
	string line;
	
	while(getline(cin,line))
	{
		if(regex_search(line,sm,r)&&valid(sm))
		{
		cout<<sm.prefix()<<
		regex_replace(sm.str(),r,format)<<endl;
	}
	}
 } 
 bool valid(const smatch &s)
 {
 	if(s.operator[](1).matched)
 	{
 		return s[3].matched&&(s[4].matched == 0||s[4].str() == " ");
	 }else
	   return !s[3].matched&&s[4].str() == s[6].str();
 }
