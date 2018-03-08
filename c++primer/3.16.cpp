#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10,42);
	vector<int> v4{10};
	vector<int> v5{10,42};
	vector<string> v6{10};
	vector<string> v7{10,"hi"};
	
	for(decltype(v1.size()) i = 0||cout<<"v1's size:"<<v1.size()<<endl;i  <v1.size() ; i++)//之所以用||,因为i=0这个表达式的值是0，必须用||后面才可以执行 
	  	cout<<v1[i]<<" ";                        //同时知道（int i = 0)这个整体，也就是定义并初始化 不是一个表达式 没有布尔值？？因为括起来时候不能用来判定是否是true或者false 
	  	cout<<endl;
	  		for(decltype(v3.size()) i = 0||cout<<"v2's size:"<<v2.size()<<endl; i  <v2.size() ; i++)
	  	cout<<v2[i]<<" ";
	  	 	cout<<endl;
		for(decltype(v3.size()) i = 0||cout<<"v3's size:"<<v3.size()<<endl; i  <v3.size() ; i++)
	  	cout<<v3[i]<<" ";
	  	 	cout<<endl;
	for(decltype(v4.size()) i = 0||cout<<"v4's size:"<<v4.size()<<endl; i  <v4.size() ; i++)
	  	cout<<v4[i]<<" ";
	  	 	cout<<endl;
	for(decltype(v5.size()) i = 0||cout<<"v5's size:"<<v5.size()<<endl; i  <v5.size() ; i++)
	  	cout<<v5[i]<<" ";
	  	 	cout<<endl;
	for(decltype(v6.size()) i = 0||cout<<"v6's size:"<<v6.size()<<endl; i  <v6.size() ; i++)
	  	cout<<v6[i]<<" ";
	  	 	cout<<endl;
	for(decltype(v7.size()) i = 0||cout<<"v7's size:"<<v7.size()<<endl; i  <v7.size() ; i++)
	  	cout<<v7[i]<<"";
	  	 	cout<<endl;
	  	return 0;
	  
}
