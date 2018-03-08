#include<iostream>
#include<unordered_map>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;
void word_transform(istream &,const unordered_map<string,string> &);
unordered_map<string,string> map_build(istream &);
const string &transform(const string &s,const unordered_map<string,string> &);

int main()
{
	string file1,file2;
	cin>>file1>>file2;
	ifstream f1(file1),f2(file2);
	string word;
	  
	word_transform(f1, map_build(f2));

	return 0;
}
void word_transform(istream &line,const unordered_map<string,string> &rule)
{
	string word_line,word;
	while(getline(line,word_line))
	{
		bool first_word = true;
		istringstream iss(word_line);
		while(iss>>word)
		  {
		  	cout<<(first_word?"":" ")<<transform(word,rule);
		  	first_word = false;
		  }
		  cout<<endl;
	}
}
const string &transform(const string &line,const unordered_map<string,string> &rule)
{
	auto i = rule.find(line);
	if(i!=rule.end())
	   return i->second;
	   else return line;
}
unordered_map<string,string> map_build(istream &rule)
{
	unordered_map<string,string> the_rule;
	string key,mapped;
	while(rule>>key,getline(rule,mapped))
	{
		if(mapped.size()>1)
		the_rule.insert({key,mapped.substr(1)});
		else
		throw runtime_error("no rule for "+key);
	}
	return the_rule;
}
/*
当引用是const时，我们可以引用一个临时对象（右值）
*/ 
