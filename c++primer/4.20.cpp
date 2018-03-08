#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	vector<string> str_list={"haha","what the Fuck","give me that money!"};
	decltype(str_list.begin()) item=str_list.begin();
	cout<<item->empty()<<endl;
	const char *a=item->c_str();
	char *q;
	  strcpy(q,a);
	cout<<*++q<<endl;
	cout<<*item<<endl;
	return 0;
 } 
 /*
 *++q
 是q后移以后在解引用
 ++*q
 是q解引用后加1
 */ 
