#include<iostream>
#include<list>
#include<vector>
#include<forward_list>

using namespace std;

int ia[]={0,1,1,2,3,5,8,13,21,55,89};

int main()
{
	vector<int> v(begin(ia),end(ia));
	list<int> l(begin(ia),end(ia));
	forward_list<int> fl(begin(ia),end(ia));
	cout<<distance(fl.begin(),fl.end())<<endl;
	for(auto i = v.cbegin();i!=v.cend();)
	   if(*i&1)
	       i=v.erase(i);//һ��Ҫ����i=  ��Ϊԭ�еĵ������Ѿ�ʧЧ
		 else  ++i;  
	for(auto i = l.cbegin();i!=l.cend();)
	   if(!(*i&1))
	       i=l.erase(i);//ͬ��
		else  ++i;   
		
	for(auto i = fl.before_begin(),j=fl.begin();j!=fl.end();)
	     if(*j&1)
	         j = fl.erase_after(i);
	         else
	            i = j++;
		   for(auto i:v)
		   cout<<i<<" ";
		   cout<<endl; 
		   		   
		   for(auto i:l)
		   cout<<i<<" ";
		   cout<<endl; 
		   
		   		   for(auto i:fl)
		   cout<<i<<" ";
		   cout<<endl; 
		   return 0;
		   
 } 
