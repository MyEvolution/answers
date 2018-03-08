#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include<sstream>
using namespace std;

void word_transform(ifstream &rule,ifstream &the_article);
const string &transform(const string &s,map<string,string> &);
map<string,string> &map_build(ifstream &rule);
int main()
{
	string file1,file2;
	cin>>file1>>file2;
	ifstream f1(file1),f2(file2);
	word_transform(f1,f2);
	return 0;
}

void word_transform(ifstream &rule,ifstream &the_article)
{
	map<string,string> _rule = map_build(rule);
	string line;
	while(getline(the_article,line))
	{
		string word;
		istringstream iss(line);
		bool first_word = true;
		while(iss>>word)
		{
		cout<<(first_word?"":" ")<<transform(word,_rule);
		first_word = false;
	   }
	   cout<<endl;
	}
}
map<string,string> &map_build(ifstream &rule)
{
	string key,mapped;
	map<string,string> key_mapped;
	while(rule>>key,getline(rule,mapped))
	{
		if(mapped.size()>1)
		key_mapped[key]=mapped.substr(1);
		else throw runtime_error("no rules for"+key);
	}
	return key_mapped;
	
}
const string &transform(const string &s,map<string,string> &_rule)
{
	map<string,string>::iterator i;
	if((i = _rule.find(s))!=_rule.end())
	   return i->second;
	   else return s;
}
