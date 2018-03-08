#include"real_StrBlob.h"
#include<iostream>
using namespace std;
int main()
{
	
	StrBlob sb = {"abc","wocao","23333"};
	for(auto i = sb.cbegin();i!=sb.cend();++i)
	cout<<*i<<endl;
	auto i = sb.cbegin();
//	*i = "wocao";constStrBlobptrµü´úÆ÷£¬Ö»¶Á 
	return 0;
}
