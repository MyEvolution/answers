#include<iostream>
#include<string>
#include<deque>
#include<list>

using namespace std;

int main()
{
	string word;
	//deque<string> dq;
	list<string> dq;
	while(cin>>word)
	 dq.push_back(word);
	 
	 for(list<string>::iterator i = dq.begin();i!=dq.end();++i)//这里之所以不能用rbegin  是因为二者并不是同一类型的
	           //reverse_iterator 
	    cout<<*i<<endl;
	    return 0;
}
