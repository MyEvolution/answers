#include<iostream>
#include<string>
#include<windows.h> 
#include<sstream>
using namespace std;
istream &input_out(istream & is)
{
	string s;
	while(is>>s)
	cout<<s<<endl;//֮���Բ���ˢ��  ��Ϊ��cin���� 
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
