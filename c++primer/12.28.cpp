#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<fstream>
#include<sstream> 

using namespace std;

int main()
{
	vector<string> line;
	map<string,size_t> word_num;
	map<string,set<size_t>> word_line;
	
	string filename;
	cin>>filename;
	ifstream ifs(filename);
	string _line,word;
	size_t line_num = 0;
	while(getline(ifs,_line))
	{
		++line_num;
		line.push_back(_line);
		istringstream iss(_line);
		while(iss>>word)
		{
			++word_num[word];
			word_line[word].insert(line_num);
		}	
	}
	
	do
	{
		string look_for;
		cout<<"输入查找的单词"<<endl;
		if(!(cin>>look_for)||look_for == "q")
		break;
		cout<<look_for<<" occurs "<<word_num[look_for]<<" times "<<endl;
		auto  i = word_line.find(look_for);
		if(i!=word_line.end())
		for(auto j:i->second)
		  cout<<"line ("<<j<<"):"<<line[j-1]<<endl;
	}while(true);
	return 0;
}
