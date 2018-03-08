#include<sstream>
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	string filename;
	cin>>filename;
	ifstream file(filename);
	vector<string> content;
	string line;
	while(getline(file,line))
	  content.push_back(line);
	for(auto i:content)
	{
	string word;
		istringstream iss(i);
		while(iss>>word)
	 cout<<word<<endl;
	}
	return 0;
}
