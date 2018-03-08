#include<iostream>
#include<string>
#include<windows.h> 
#include<sstream>
using namespace std;
istream &input_out(istream & is)
{
	string s;
	while(is>>s)
	cout<<s<<endl;//之所以不断刷新  因为和cin关联 
	is.clear();
	return is;
}
int main()
{
	string line;
  if(getline(cin,line))
    {
    	istringstream s(line);
       input_out(s);	
	}
	return 0;
 } 
