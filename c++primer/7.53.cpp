#ifndef DEBUG_H
#define DEBUG_H
#include<string>
#include<iostream>
class Debug
{
	public:
		
		constexpr Debug(bool b = true ):hw(b),io(b),other(b){
		}//已经提供默认构造 
		constexpr Debug(bool h,bool i,bool o):hw(h),io(i),other(o){
		}
		Debug(bool h,bool i):hw(h),io(i){
		}
	    const/*expr*/ bool any(){
	    	return hw||io||other;
		}//这里如果是const修饰  则无法调用m.any()？ 
		void set_io(bool b){
			io = b;
		}
		void set_hw(bool h)
		{
			hw = h;
		}
		void set_other(bool o)
		{
			other = o;
		}
	private:
		bool io;
		bool hw;
		bool other;
	
};
class de//这也是字面值类型 
{
	int a;
	//Debug d=Debug(1,0); 加了这一句后 因为用的不是constexpr构造 所以该类不是字面值常量类 
};
#endif
//constexpr int i = 20;
constexpr int  abc(Debug)//de需要的是字面值常量类 
{
	return 100;
}
constexpr int abcd(int i)
{
	return 100;
 } 
  Debug n(1,1);
  constexpr Debug m(1);
   int b[abc(m)]; 
 int a[abc(n)];
 int i;
int c[abcd(i)]; 
int main()
{
   const int & a = i;
   constexpr Debug m(1);//如果调用默认初始化将无法通过编译
    // 因为constexpr构造函数才能构造出constexpr对象
    Debug n(1,1);
	
	abc(n); 
	if(m.any())
	//	[Error] passing 'const Debug' as 'this' argument of 'const bool Debug::any()' discards qualifiers [-fpermissive]
	 //因为是常量对象   而any未声明是const类型的函数  所以编译器认为this指针可能会改变常量对象的值 无法通过编译
	 //和const无关 实际上去叼const也是一样的
	 //而constexpr声明的函数是隐式constde  所以可以通过编译 
	 //实际上想想   constexpr函数因为其限定  根本无法做出除了return的可执行操作  也因此一定不会改变什么值，
	 //所以是隐式const的函数 
	std::cerr<<"print appropriate error messages"<<std::endl;
	//if(prod.any())
	//std::cerr<<"print an error message"<<std::endl;
	return 0;
 } 
/*
constexpr代表在编译阶段编译器就可以检查出来其是否是常量表达式
他只能在定义字面值时用到
如果是初始值是一个常量表达式则可以通过编译
被定义的变量是一个常量 

同时用constexpr修饰的函数意思是在编译阶段就可以得知其返回值是不是常量表达式
当然这并不意味着constexpr不能返回非常量表达式 
而实际上constexpr在修饰字面值时  和const修饰的常量表达式是一直的效果（即需要constexpr的地方它也可以上比如定义一个数组的维度
即必要时编译器也会检查const修饰的是否是常量表达式） 
 区别是const后面可以跟非常量表达式
constexpr后面不可以  如果确定是常量表达式 最好用constexpr修饰 速度更快
当修饰函数时  constexpr可以在编译时期检测返回值是不是常量表达式  但是非常量表达式也不会报错
区别就是用const修饰的话 编译器会认为它返回的一定不是常量表达式
（即编译器不会检查const修饰的是否返回一个常量表达式，而直接认定它不是） 
如定义数组维度时  如果返回的是常量表达式 你可以用constexpr来定义
但是你无法用const修饰的函数来定义 
constexpr修饰的函数只有一条可执行语句就是return 并且返回类型以及形参一定是字面值类型



也许可以这样理解
什么是字面值常量类？
1.聚合类并且所有的数据成员类型都是字面值
2.符合下面情况：
 类至少含有1个constexpr构造函数
 类中有别的类的成员  该成员初始化是用constexpr构造函数构造的
 类内初始化初始值一定是常量表达式
 数据成员都是字面值
 
 上面两条符合一条就算是字面值常量类 
 第一条很容易理解 ，它只有一种情况
 列表初始化或者默认构造，即每个成员都被默认初始化 
 第二天却有两种情况，你可以把它当作 如果是用constexpr构造函数构造的
是个常量表达式 
 而用其他构造函数构造出来的 不是
 即只有constexpr构造函数能构造出constexpr对象，相对应constexpr int i=10,后面跟的是个常量表达式 
 如本程序的56行  你无法在该定义前加上constexpr修饰 因为不是用constexpr函数构造的 
 当然   这个类是字面值常量类，是字面值类型，他的对象可以作为constexpr函数的参数
 但是如果不是用constexpr构造函数构造出来的   返回的值不能在编译器确定是个常量表达式
 如51-53行 
 这正和内置类型的字面值  如int 之类的是一致的 
 如54行
 当参数不是常量表达式  其返回值也不是常量表达式 
*/ 
