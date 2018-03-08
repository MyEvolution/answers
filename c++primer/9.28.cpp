#include<iostream>
#include<string>
#include<forward_list>

using namespace std;

void InsertTwoStr(forward_list<string> &,const string & ,const string &);
//forward_list设为引用是必须的，或者设为指针，才能真正改变其值  const string设为引用为了提高性能 
int main()
{
	forward_list<string> fl(10,"what the fuck!"),fl1 = fl;
	forward_list<string>::iterator fli = fl.begin();
	  ++fli;
	*fli = "2333";
	InsertTwoStr(fl,"2333","66666");
	InsertTwoStr(fl1,"2333","66666");
		
	for(auto i:fl)
	cout<<i<<endl;
	cout<<"分割线——————————————"<<endl; 
	for(auto i:fl1)
	cout<<i<<endl;
	
	return 0;
}
void InsertTwoStr(forward_list<string> &fl,const string &s1,const string &s2)
{
	auto i = fl.cbegin(),j = fl.cbefore_begin();
	while(i != fl.cend())
	{
		if(*i==s1)
		  {
			fl.insert_after(i,s2);
		  	return;
			  }
		  	else
		  	  j = i++;
	}
	fl.insert_after(j,s2);
	
}


