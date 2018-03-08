#include"real_text.h"
#include<iostream>

int main()
{
	string file;
	cin>>file;
	ifstream ifs(file);
	TextQuery Query(ifs);
     cout<<"enter word to look for ,or q to quit"<<endl;
     string s;
while(cin>>s&&s!="q")
	{
		print(cout,Query.query(s));
		cout<<"enter word to look for ,or q to quit"<<endl;
	 }
	 return 0;
}
