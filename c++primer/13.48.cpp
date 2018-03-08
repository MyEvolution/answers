#include"str.h"
#include<vector>
//#include"StrVec.h"

using namespace std;

int main()
{
vector<str> v;
	v.resize(10,"abc");
	cout<<v.size()<<endl; 
	str s = "233334";
	 cout<<".........."<<endl;
	v.push_back(s);
	cout<<v.size()<<endl; 
	cout<<".........."<<endl;
	v.push_back("2333");
	cout<<".........."<<endl;
	v.push_back(std::move(s));
		cout<<".........."<<endl;
	v.push_back(std::move(s));
			cout<<".........."<<endl;
	v.push_back(std::move(s));
	  return 0;
}
/*
我想我找到了为什么会输出很多拷贝构造的原因

仔细考虑一下vector是如何增长的

刚开始vector的容量是0；
增加一个后是1，
在增加要重新分配内存  是 2
再增加  4 所以会执行两次之前的拷贝
和刚刚的输出是相符合的
但是我编写的StrVec都是靠移动过去的，而这个vector扩充容量竟然靠拷贝？
不可思议  unbelievable 

所以我决定再做个测试
请看文件text4.cpp 
事实证明  还真是如此啊！！
 
*/ 
