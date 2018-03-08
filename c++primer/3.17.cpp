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
	for(auto &i:list)/*这两行for循环相对于前两行更简洁，但是可能并不是很好懂 
	   首先两个都是用for的范围循环   i是对list中字符串的引用  而c是对字符串i（此时i代表的就是所引用的字符串）的各个字符的引用
	    所以它的改变会改变字符串中的字符
		*/ 
	for(auto &c:i)   
	c=toupper(c);
	for(vector<string>::size_type i=0;i<list.size();i++)
	cout<<list[i]<<endl;
	return 0;
 } 
