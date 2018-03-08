#include<iostream>
#include<utility>

using namespace std;

template <typename T1,typename T2,typename T3>
void func(T1 a,T2 &&b, T3 &&c)
{
	a(std::forward<T3>(c),std::forward<T2>(b)); 
} 
//这里有一个问题 ，比如t1是个函数类型，我们希望用它来处理b和c
//如果t1需要的是引用，但是b，c传进来的确是拷贝 ，我们无法真正影响到需要改变的值
//有个办法是将T2,T3换为右值引用类型的，T2&&,T3&&会保持原来的左值或者右值属性。
//上述办法对于处理左值引用是足够了，但是如果需要一个右值就出问题了，即使我们传入右值
//T2 b是一个右值引用  但是它依然是个左值，无法用来实例化右值引用。用std::move的话 
//又无法保证原来是左值时候的情况 
//这时候我们可以使用forward函数，它必须指定类型，并且返回他原来的属性，
// 具体实现就是返回Type &&   然后进行引用叠加来实现。
//Type虽然需要显示指定，但是其实也是根据最先传入参数决定，传入右值，则他是非引用，传入左值
//他是引用， 叠加上&&，就会得到原本的类型了。 
void print(int a,int b)
{
	cout<<a<<" "<<b<<endl;
}
int main()
{
	const int a = 10,b= 11;
	func(print,a,b);
}
