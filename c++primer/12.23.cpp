#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
	const char *a="ancde";
	const char *b = "wocao";
	string s1(a);
	string s2(b);
 char * i = new  char [10];
	string * j = new string[2]{a,b};
	strcpy(i,a);
	strcpy(i+5,b);
	cout<<i<<j[0]<<j[1]<<endl;
	delete []i;
	delete []j;
	return 0;
}
