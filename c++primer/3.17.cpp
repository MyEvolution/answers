#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	vector<string> list;
	string word;
	while(cin>>word)
	list.push_back(word);
	//for(vector<string>::size_type i=0;i<list.size();i++)
	//for(auto &c:list[i])
	for(auto &i:list)/*������forѭ�������ǰ���и���࣬���ǿ��ܲ����Ǻܺö� 
	   ��������������for�ķ�Χѭ��   i�Ƕ�list���ַ���������  ��c�Ƕ��ַ���i����ʱi����ľ��������õ��ַ������ĸ����ַ�������
	    �������ĸı��ı��ַ����е��ַ�
		*/ 
	for(auto &c:i)   
	c=toupper(c);
	for(vector<string>::size_type i=0;i<list.size();i++)
	cout<<list[i]<<endl;
	return 0;
 } 
