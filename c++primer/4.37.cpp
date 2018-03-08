#include<iostream>
using namespace std;
int main()
{
	string p[]={"haha","wocao"};
	const string *ps=p;
	void *i=static_cast<void *>(const_cast<string *>(ps));
	return 0;
}
