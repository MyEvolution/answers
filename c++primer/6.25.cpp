#include<iostream>
using namespace std;
int main(int argc,char **argv)
{
	string s;
	while(--argc)
	  s+=*++argv;
	  cout<<s<<endl;
	  return 0;
 } 
