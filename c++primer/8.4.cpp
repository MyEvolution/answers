#include<vector>
#include<string>
#include<fstream>
#include<iostream>
using namespace std;

int main()
{
	string filename;
	string s;
	vector<string> file_content;
	if(cin>>filename)
	{
	   ifstream file(filename);
	   while(file>>s)
	   file_content.push_back(s);
	   file.close();	
	}
	
	for(auto &i:file_content)
	cout<<i<<endl;
	return 0;
}
