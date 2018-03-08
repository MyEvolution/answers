#include"Sales_data.h"
int main()
{
	std::string null_isbn("9-999-99999-9");//这是构造函数进行的初始化 
	//而不是将const char*隐式转化后在对null_isbn进行的直接初始化 
	//下面可以证明 
	std::string n(null_isbn);//直接初始化 
	Sales_data item1(null_isbn); //构造函数进行的初始化 
	Sales_data item2("9-999-99999-9");//编译器只能自动执行一次隐式转换 
	Sales_data item3(item2); 
	//而如果 上一条语句是隐式转换后的 直接初始化，那么这里应该会执行两次隐式转换 
	//1.const char*转换成string  2.string转换成Sales_data
	//而事实上上述做法是不允许的
	//所以当一个类的对象以构造函数形式初始化的时候 ，执行的是调用构造函数进行的初始化
	//这正是构造函数的意义 
	std::cout<<null_isbn<<n<<item3.isbn();
	//std::string a = item1;//隐式初始化是单向的 
	Sales_data item4 = n;
	Sales_data item5 = {"9-999-99999-9",25,15.99}; 
	std::cout<<item5.isbn()<<std::endl;
	
	return 0;
 } 
