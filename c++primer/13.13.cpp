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
    vector<X> x5{x1,x2,x3,*x4};//这里是值传递的方式调用了构造函数？？ 
    cout<<"3个2,7个1";
    X x7[10]={x1,x2,x3}; 
    //查阅资料后明白了   {x1,x2,x3,*x4}实际上是初始化了一个类的对象，叫initializer_list；
	//然后vector 会调用initializer_list这个对象来构造 
	//因为该initializer_List对象是临时的  所以会销毁   对每个调用析构函数 
    cout<<x5.size()<<endl;
    delete x4;//4个4 
    return 0;
 }
