#include<iostream>
#include<map>
#include<set>
#include<string>
#include<iterator>
#include<algorithm>

using namespace std;

int main()
{
	map<string,size_t> mss;
	set<string> ignore{"the","a",""};
	set<char> ignore2{',' ,'.',';','"','!','?',' ','\n','\b'};
	char c;
	while(cin.get(c))
	{
		string s = "";
		auto i = back_inserter(s);
		while(ignore2.find(c)==ignore2.end())
       	   {
		  i = tolower(c);
          cin.get(c);
           }
          
		  if(ignore.find(s)==ignore.end())
		  ++mss[s];
	}
	/*
	while(cin>>s)
	if(ignore.find(s)==ignore.end())
	  ++mss[s];
	  */
	for(auto i:mss)
	   cout<<i.first<<":"<<i.second<<endl;
	   return 0;
 }
 /*
 ��������������
 cinֱ������ʱ�޷�����ո�ͻ��з�\n
 ��������ʹ��cin.get(c)�����ܻ��з�
 */ 
