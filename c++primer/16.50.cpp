#include<iostream>

using namespace std;

template <typename T> void f(T){
	cout<<"��"<<endl;
}
template <typename T> void f(const T*)
{
	cout<<"��"<<endl;
}
template <typename T> void g(T)
{
	cout<<"��"<<endl; 
}
template <typename T> void g(T*)
{
	cout<<"��"<<endl;
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
	
	f(i);//ֻ�ܵ���1
	f(p);//����1��2���ǿ��У�1��ȷƥ��
	f(ci);//1��
	f(p2);//1,2����ȷƥ�䣬2������
	g(i);//3
	g(p);//3,4���У�4������
	g(ci);//3
	g(p2);//3,4���� ��4���ﻯ
	int j = 0;double d = 3.14;string s = "how now brown cow";
	foo(i,s,42,d);
	foo(s,42,"hi");
	foo(d,s);
	foo("hi");
	foo(i,i,i,i,i,i);
	return 0; 
}
