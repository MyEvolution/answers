#include<iostream>
#include<set>
#include"Sales_data.h" 
#include<map>
#include<list>
#include<fstream>
#include<sstream>
#include<iterator>

using namespace std;

int main()
{
	multiset<Sales_data,bool(*)(const Sales_data&,const Sales_data&)> a(compareIsbn);
	a.insert(Sales_data("999-999-999"));
	map<string,list<size_t>> word_line;
	string filename;
	cin>>filename;
	string line,word;
	ifstream ifs(filename);
	size_t n = 1;
	while(getline(ifs,line))
	{
		
		istringstream iss(line);
		while(iss>>word)
		word_line[word].push_back(n);
	    ++n;
	}
	ostream_iterator<size_t> o(cout," ");
	for(auto i:word_line)
	{
		cout<<i.first<<" occurs times"<<":";
		for(auto j:i.second)
		 o = j;
		cout<<endl;
	}
	
	return 0;
 } 
