#include<iostream>
#include<vector>
using namespace std;
/*����㷨���õ��������ж��ֲ���*/ 
int main()
{
	vector<int> data;
	cout<<"����������������:"<<endl;
	bool found=false;
	int a,look_for;
	decltype (data.size()) position; 
	while(cin>>a)
	data.push_back(a);
     cin.clear();
     cin>>look_for;
	auto begin=data.begin(),end=data.end()-1,mid=begin+(end-begin)/2;//�μ�end��β���ĺ�һλ 
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
