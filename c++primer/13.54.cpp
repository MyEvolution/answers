#include"StrVec.h"
using std::endl;
void f(int a)
{
	cout<<"��ֵ"<<endl;
}
void f(const int &a)
{
	cout<<"����"<<endl; 
}
int main()
{
	StrVec s1 = {"wocao","haha"};
	StrVec s ,s2;
       s2 = s1;
       s = std::move(s1);
	return 0;
}
