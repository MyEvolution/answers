#include<iostream>
#include<vector>
using namespace std; 
struct X
{
	X(){cout<<"X()"<<endl;};//1
	X(const X& x){cout<<"X(const X &x)"<<endl;};//2
	X &operator = (const X &x){ cout<<"operator(const X &x)"<<endl;};//3
	~X(){cout<<"~X()"<<endl;}//4 
 };
 void F(X){
 	
 };
 void G(X&)
 {
 	
 };
 int main()
 {
 	X x1,x2(x1);//1,2
 	X x3 = x1;//2
    x3 = x2;//3
    F(x1);G(x1);//2 4
    X* x4 = new X(x1);//2
    X x6{x1}; 
    vector<X> x5{x1,x2,x3,*x4};//������ֵ���ݵķ�ʽ�����˹��캯������ 
    cout<<"3��2,7��1";
    X x7[10]={x1,x2,x3}; 
    //�������Ϻ�������   {x1,x2,x3,*x4}ʵ�����ǳ�ʼ����һ����Ķ��󣬽�initializer_list��
	//Ȼ��vector �����initializer_list������������� 
	//��Ϊ��initializer_List��������ʱ��  ���Ի�����   ��ÿ�������������� 
    cout<<x5.size()<<endl;
    delete x4;//4��4 
    return 0;
 }
