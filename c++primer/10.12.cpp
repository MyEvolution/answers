#include<iostream>
#include<vector>
#include<fstream>
#include"Sales_data.h"
#include<algorithm>


bool compareIsbn(const Sales_data &s1,const Sales_data &s2)
{
	return s1.isbn()<s1.isbn();
}

using namespace std;

int main()
{
	vector<Sales_data> v;
	Sales_data Sd;
	string file;
	cin>>file;
	ifstream ifs(file);
	while(read(ifs,Sd))
	 v.push_back(Sd);
	 sort(v.begin(),v.end(),[](const Sales_data &s1,const Sales_data &s2)->bool{//Œ≤÷√∑µªÿ 
	 	return s1.isbn()<s2.isbn();
	 });
	 for(auto i:v)
	 print(cout,i);
	 return 0;
}
