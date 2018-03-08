#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<string> intv({"123.1","465.3","7569.566"});
	string s = "1ba";
	string::size_type b;
	cout<<stod(s,&b)<<endl;
	cout<<b<<endl;
	int sum = 0;
	double sum1=0.0;
	for(auto i:intv)
	{
	sum+=stoi(i);
	sum1+=stod(i);
     }
	cout<<sum1<<endl;
	return 0;
 } 
