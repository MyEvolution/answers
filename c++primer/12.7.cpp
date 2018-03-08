#include<vector>
#include<iostream>
#include<memory>
#include"Sales_data.h" 

using namespace std;
void read_in(istream &is,shared_ptr<vector<int>> v)
{
	int a;
	while(is>>a)
	v->push_back(a);
}
void print_out(shared_ptr<vector<int>> v)
{
	for(auto i:*v)
	cout<<i<<" ";
	cout<<endl;
}
int main()
{
	shared_ptr<vector<int>> v = make_shared<vector<int>>();//用括号里的内容构造vector
	shared_ptr<int> m = make_shared<int>();
	cout<<*m<<endl;
	read_in(cin,v);
	print_out(v);
	return 0;
//当出了这个作用域   智能指针将自动释放内存	 
}
