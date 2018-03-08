#include<iostream>
#include<string>

using namespace std;

int main()
{
	string words;
	string last_word;
	if(cin>>last_word)
	while(cin>>words)
	{
		if(*words.begin()>90||*words.begin()<65)
		continue;
		if(words==last_word)
		{
		cout<<words<<endl;
		break;
		}
		else
		last_word=words;
	}
	if(!cin)
	cout<<"没相同的"<<endl;
 return 0;
	
}
