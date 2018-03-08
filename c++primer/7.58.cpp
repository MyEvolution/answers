#include<vector>
#include<iostream>
using std::vector;
class Example
{
	public:
		static constexpr double rate = 6.5;//6.5也可以？不是必须是整型常量吗 
		static constexpr int vecSize = 10;//const并且初始值是常量表达式也行  但是既然是常量表达式就应该使用constexpr 
		 static vector<double> vec;//这是非字面值  所以不能类内初始化
		 //你妈的防不胜防！ 
}; 
constexpr double Example::rate;
vector<double>Example::vec(10);
int m;
const int i = 10;
//const 后面跟常量表达式的话  和constexpr是一样的效果  但是constexpr更快，
//并且能在编译时期检验后面到底是不是常量表达式 
int array[i];
int main()
{
	
	std::cout<<Example::rate<<std::endl<<Example::vec.size()<<std::endl;
	return 0;
}
