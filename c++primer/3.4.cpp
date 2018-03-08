#include<iostream>
#include<string>
using namespace std;
int main()
{
	string line1,line2;
	cin>>line1>>line2;
	if(line1.size()>line2.size())
	cout<<line1<<endl;
	else
	cout<<line2<<endl;
	if(line1>=line2)
	cout<<line1<<endl;
	else
	cout<<line2<<endl;
	cout<<line1+line2<<endl;
	cout<<line1+" "+line2<<endl;
	return 0;
}
