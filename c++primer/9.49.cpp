#include<iostream>
#include<string>

using namespace std;
string up("bdfhklt");
string down("gjpqy");
string not_here = up+down;
int main()
{
	string word;
	string word1;
	if(cin>>word)
	{
		int pos = 0;
		int last_pos = -1;
		int begin=0;
		int length_max = 0,length = 0;
		while((pos = word.find_first_of(not_here,pos))!=string::npos)//不是个好习惯  pos应该是size_type型的 
		{
			if((length = pos - last_pos - 1)>length_max)
			{
				length_max = length;
					begin = last_pos+1;
			}
			last_pos = pos;
			++pos;
		}
		if(last_pos!=word.size()&&(length = word.size()-last_pos-1)>length_max)
		  {
		  begin = last_pos+1;
		  length_max = length;
	      }
		if(length_max)
		{
			word1 = word.substr(begin,length_max);//从begin开始拷贝 
			cout<<word1<<endl;
		}
	}
	return 0;
}
/*
这个小程序却花了很长时间 
缺乏更多的练习

设计思路 ：找出不属于上述的，中间隔的便是我们要找的
用两个值储存长度和开始的位置   直到找到更长的字串

实现时候有几个细节没有注意：
1.因为pos储存的是不在范围内的，所以last_pos的初始值应该是-1,否则会忽略首个元素  
2.find_fist_of()参数有两个 ，又忘写第二个
3.最后退出循环pos是npos  所以我们检查最后时应该检查的是last_pos
4.string的初始化 拷贝  替换函数不够熟悉 
*/ 
 
