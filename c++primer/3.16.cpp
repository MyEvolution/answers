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
	
	for(decltype(v1.size()) i = 0||cout<<"v1's size:"<<v1.size()<<endl;i  <v1.size() ; i++)//֮������||,��Ϊi=0������ʽ��ֵ��0��������||����ſ���ִ�� 
	  	cout<<v1[i]<<" ";                        //ͬʱ֪����int i = 0)������壬Ҳ���Ƕ��岢��ʼ�� ����һ�����ʽ û�в���ֵ������Ϊ������ʱ���������ж��Ƿ���true����false 
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
