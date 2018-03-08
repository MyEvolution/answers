#include<iostream>
int main()
{
	int i=0,&r=i;//r是绑定到i上的引用
	auto a=r;//a是int型
	const int ci = i,&cr = ci;//ci是常量（可以通过改变i改变其值吗？）cr是常量引用
	auto b = ci;//ci是顶层const  所以被忽略  b是整型
	auto c = cr;// cr是ci的引用  c=int； 
	auto d = &i;//d是int 指针
	auto e = &ci;//&ci是底层const  e是指向常量的整型指针
	const auto f = ci;//f是整型常量const int
	auto &g = ci;//auto定义引用时，给初始值绑定引用  初始值的顶层const的性质不在存在 所以g为常量引用
	//auto &h = 42;//错误 h为非常量引用  不能绑定字面值
	const auto &j = 42;//j为常量引用
	auto k = ci,&l = i;//k整型，l为整型引用
	auto &m = ci, *p = &ci;//m常量引用  p为指向整型常量的指针
	//auto &n=i,*p2=&ci;//错误  n为非常量引用  p2是指向整型常量的指针 二者类型一致
	a=42;b=42;c=42;*d=42;//*e=42;g=42;
	std::cout<<a<<b<<c<<*d<<std::endl; 
	std::cout<<ci<<std::endl;
	i=10;
	std::cout<<ci<<std::endl;
	std::cout<<"所以初始值为变量的常量，其值不会随变量改变而改变"<<std::endl;
	const auto &n = i;//n是常量引用
	auto &o = i;//o是什么？ 
	o = 40;
	std::cout<<n<<std::endl;
	std::cout<<"当一个变量被常量引用绑定  无法通过常量引用改变该变量 \n并且如果用该常量引用作为auto类型引用的右侧 ，得到的是一个常量引用"<<std::endl;
	return 0; 
 } 
