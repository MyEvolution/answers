#include<iostream>
using namespace std;
int main()
{
	size_t a,b,c,d,e,f,g;
	a=sizeof(bool);
	b=sizeof(char);
	c=sizeof(short);
	d=sizeof(int);
	e=sizeof(long);
	f=sizeof(long long);
	g=sizeof(float);
	auto h=sizeof(double);
	cout<<a<<" "<<b<<" "
	<<c<<" "<<d<<" "<<e<<" "
	<<f<<" "<<g<<" "<<h<<endl;
	char x[10]="123456789",*p=x;
	int a1=0xffff;
	unsigned char b1=a1;
	cout<<a1<<" "<<(int)b1<<endl;
	cout<<sizeof(x)/sizeof(*x)<<" "<<sizeof(p)/sizeof(*p)<<endl;
	return 0;
}
