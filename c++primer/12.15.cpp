#include<iostream>
#include<memory>

using namespace std;
struct destination;
struct connection;//没有良好的析构函数 所以内存可能未被释放 ，比如用malloc申请的内存 
connection connect(destination *);
void disconnect(connection );
void end_connect(connection *p)
{
	disconnect(*p);
}
void f(destination &d)
{
	connection c = connect(&d);
	shared_ptr<connection> p(&c,[](connection *p){	disconnect(*p);	});
	//执行代码 即使中间退出也会正常释放
	disconnect(c); 
}
/*
我想原理是这样的
c的结构中有时候会申请了内存 但是没有良好的析构函数
因为c没有类的概念 ，也就没有析构函数
当一个类创立时，会申请内存 而一般会带有释放内存的函数
在使用完对象后应该将其释放
但是如果程序发生异常中断  内存将无法访问并释放，因为没有指针指向它
这时候智能指针就十分有效
我们为c的类的对象建立一个智能指针  即使中断 依然可以通过智能指针将其释放
但是因为c类中的内存不是通过new申请，没有delete函数
所以我们必须自己定义一个函数来代替delete
这个可以通过借用c的结构中的释放内存的函数来实现
当智能指针不在指向他的时候，便会对该指针调用delete函数  同时也就是对该对象调用了释放内存的函数
再释放掉指针，所以整个程序便圆满了
*/ 
