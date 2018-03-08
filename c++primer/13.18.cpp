#include"Employee.h"
int main()
{
	Employee e1("Jordan");
	Employee e2(e1);
	e1.get_info(cout);
	e2.get_info(cout);
	e2 = string("Mike");//编译器只自动执行一次隐式转换 
	e2.get_info(cout);
	return 0;
}
/*
是需要定义的
首先拷贝构造函数和拷贝赋值运算符就需要自己定义
编译器合成的拷贝，赋值会使用相同的雇员证号
而析构函数用合成的即可
*/
 
