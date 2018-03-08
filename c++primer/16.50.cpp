#include<iostream>

using namespace std;

template <typename T> void f(T){
	cout<<"①"<<endl;
}
template <typename T> void f(const T*)
{
	cout<<"②"<<endl;
}
template <typename T> void g(T)
{
	cout<<"③"<<endl; 
}
template <typename T> void g(T*)
{
	cout<<"④"<<endl;
}
template<typename T,typename...Args> void foo(const T&,const Args&...rest)
{
	cout<<sizeof...(Args)<<endl;
	cout<<sizeof...(rest)<<endl;
}
int main()
{
	int i = 42,*p = &i;
	const int ci = 0,*p2 = &ci;
	
	f(i);//只能调用1
	f(p);//调用1，2都是可行，1精确匹配
	f(ci);//1；
	f(p2);//1,2都精确匹配，2更特例
	g(i);//3
	g(p);//3,4都行，4特例化
	g(ci);//3
	g(p2);//3,4都行 ，4特里化
	int j = 0;double d = 3.14;string s = "how now brown cow";
	foo(i,s,42,d);
	foo(s,42,"hi");
	foo(d,s);
	foo("hi");
	foo(i,i,i,i,i,i);
	return 0; 
}
