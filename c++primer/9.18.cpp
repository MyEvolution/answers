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
	 
	 for(list<string>::iterator i = dq.begin();i!=dq.end();++i)//����֮���Բ�����rbegin  ����Ϊ���߲�����ͬһ���͵�
	           //reverse_iterator 
	    cout<<*i<<endl;
	    return 0;
}
