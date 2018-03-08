#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<forward_list>
#include<list>
using namespace std;

int main()
{
  vector<int> v{0,1,2,3,4,5,6,7,8,9};
  ostream_iterator<int> o(cout," ");
   forward_list<int> v1(v.rbegin(),v.rend());
  reverse(v1.begin(),v1.end());
  for(auto i=v.end()-1;i!=v.begin()-1;--i)
      o=*i;
      cout<<endl;
  copy(v.rbegin(),v.rend(),o);
  cout<<endl;
  auto i =find(v.rbegin(),v.rend(),0);
  cout<<i.base()-v.begin()-1<<endl;
  decltype(v.rbegin()) rb(v.begin()+7);
  auto re = rb+4;
  auto r = v.begin();
  cout<<r[5]<<endl;
  list<int> l(rb,re);
  copy(l.begin(),l.end(),o);
  return 0;
 } 
