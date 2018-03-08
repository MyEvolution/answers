#include<iostream>
int _abc; 
int _; 
int main()
{
	int month=9,day=7;
	int a=0;int b=07;//前面有0是8进制，命名标识符时候，第一个必须是下划线或者字母 第一个若是下划线后面不能跟大写字母
	                   //定义在函数体之外的标识符首个不能用下划线 
	                   _=10;
	std::cout<<month<<day<<a<<b<<_<<std::endl;
	return 0;
}
