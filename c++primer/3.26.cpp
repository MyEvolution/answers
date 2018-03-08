#include<iostream>
#include<vector>
using namespace std;
/*这个算法是用迭代器进行二分查找*/ 
int main()
{
	vector<int> data;
	cout<<"请输入有序整数列:"<<endl;
	bool found=false;
	int a,look_for;
	decltype (data.size()) position; 
	while(cin>>a)
	data.push_back(a);
     cin.clear();
     cin>>look_for;
	auto begin=data.begin(),end=data.end()-1,mid=begin+(end-begin)/2;//牢记end是尾数的后一位 
	while(begin<=end)
	{
		if(*mid>look_for)
		end=mid-1;
		else if(*mid<look_for)
		begin=mid+1;
		else 
	    {
	    	found=true;
	    	position=mid-data.begin()+1;
	    	break;
		}
		mid=begin+(end-begin)/2;
	}
	found?cout<<"we found the number in position "<<position<<endl:cout<<"we could not find it"<<endl;
	return 0;
}
