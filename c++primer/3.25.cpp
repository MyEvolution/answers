#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> data(11,0);
	int grade;
	while(cin>>grade)
		(*(data.begin()+grade/10))++;
	for(auto i=data.begin();i!=data.end();i++)
	 cout<<*i<<" ";
	 cout<<endl;
	 return 0;
}
