#include<iostream>

using namespace std;
class A
{
     int a ;
	friend ostream & operator <<(ostream &,const A&);
};
ostream &operator << (ostream &os,const A & a)
{
	os<<a.a<<endl;
}
template <typename T>
ostream &print(ostream &os,const T &s)
{
	os<<s<<endl;
	return os;
}
template <typename T,typename...Args>
ostream &print(ostream &os,const T & a,const Args&...args)
{
	os<<a<<endl;
 return print(os,args...);
}
int main()
{
	print(cout,"wocao",A());
}
