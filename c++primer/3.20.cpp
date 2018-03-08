#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> array;
    for(int i;cin>>i;)
	array.push_back(i);
	for(decltype(array.size()) i = 0;i<array.size()-1;i++)
         cout<<array[i]+array[i+1]<<" ";
         cout<<endl;
	for(decltype(array.size()) i = 0;i<array.size()/2;i++)
         cout<<array[i]+array[array.size()-1-i]<<" ";
         if(array.size()&1)
         cout<<array[array.size()/2];
         cout<<endl;    
	
	return 0;
 } 
