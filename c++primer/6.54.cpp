#include<iostream>
#include<vector>
#include<typeinfo>

using namespace std;
int func(int a,int b);


//vector<int (*) (int a,int b)> _func;
vector<decltype(func)*>_func;


int add(int a,int b);
int sub(int a,int b);
int mul(int a,int b);
int div1(int a,int b);
int main()
{
	decltype(add)* i = add; //auto p后跟一个函数的时候 auto的类型是 指向函数的指针 与decltype不同 后者得到的只是函数而已
	decltype (i)m = sub; //这里得到的不知是引用还是指针
	int (&p) (int ,int ) = add;//引用和函数指针有一样的效果 
	//auto放在函数返回类型时只能说明是要使用尾置返回类型的方式 
  _func.push_back(p);
  _func.push_back(m);
  _func.push_back(mul);	
  _func.push_back(div1);
  int a,b;
  cin>>a>>b;
  for(auto i:_func)
     cout<<i(a,b)<<" ";
     return 0;
 }
 int add(int a,int b)
 {
 	return a+b;
 }
 int sub(int a,int b)
 {
 	return a-b;
 }
 int mul(int a,int b)
 {
 	return a*b;
 }
 int div1(int a,int b)
 {
 	if(b!=0)
 	return a/b;
 	else
 	  {
 	  	cerr<<"除数不能为0！"<<endl;
 	  	return -1;
	   }
 }
