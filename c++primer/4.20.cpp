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
 ��q�����Ժ��ڽ�����
 ++*q
 ��q�����ú��1
 */ 
