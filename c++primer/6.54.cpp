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
	decltype(add)* i = add; //auto p���һ��������ʱ�� auto�������� ָ������ָ�� ��decltype��ͬ ���ߵõ���ֻ�Ǻ�������
	decltype (i)m = sub; //����õ��Ĳ�֪�����û���ָ��
	int (&p) (int ,int ) = add;//���úͺ���ָ����һ����Ч�� 
	//auto���ں�����������ʱֻ��˵����Ҫʹ��β�÷������͵ķ�ʽ 
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
 	  	cerr<<"��������Ϊ0��"<<endl;
 	  	return -1;
	   }
 }
