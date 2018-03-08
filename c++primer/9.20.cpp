#include<list>
#include<deque>
#include<iostream>

using namespace std;

int main()
{
	list<int> l;
	deque<int> dq1,dq2;
	int num;
	while(cin>>num)
	  l.push_back(num);
   for(auto i = l.cbegin();i!=l.cend();++i)
      if(*i&1)
      dq1.push_front(*i);
      else
      dq2.push_front(*i);
    for(auto i = dq1.cbegin();i!=dq1.cend();++i)
       cout<<*i<<ends;
    for(auto i = dq2.cbegin();i!=dq2.cend();++i)
        cout<<*i<<ends;
      return 0;
      
}
