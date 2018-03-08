#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a1 = "wjsajdskdjakljdaksldjadlksadsadsadasd;as";
	cout<<sizeof(a1)<<endl;
	int a=1,b=1;
	/*cout<<(bool)(a+b)<<endl; 
	if((a==b)&(a+b))
	cout<<"并且"<<endl; 
	else
	cout<<"按位与"<<endl; */
	if((a-b)&&(b+=1)) ;
	else
	cout<<a<<" "<<b<<endl;
	if((a-b)&(bool)(b+=1)) ;
	else
	cout<<a<<" "<<b<<endl;
	return 0;
}
/*
在看java书籍的时候写着
&可以当作逻辑运算符与来处理 不过是不短路与
也就是两边的布尔值都会算出来再进行与运算
于是我想到c++中是否也有这样的功能
事实证明c++没有 &在c++中只有按位于的功能 
如果两边是布尔值则转换为0，1进行按位于 这实际上和逻辑与是一样的
但是不同的是逻辑与会将非零的值全部转换为true；
如1&&8按逻辑与是ture  但是按照按位与的话是0

同时java中布尔值无法和整数互换
因此&才可以进行逻辑与运算 因为如果两侧不一致会报错
同时&&两侧若不是布尔值也会报错
这意味着在java中无法写
if(a+b)这样的语句了 中间需要的是布尔值 
*/ 
