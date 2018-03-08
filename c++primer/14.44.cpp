#include<functional>
#include<map>
#include<iostream>

using namespace std;

using namespace placeholders;
int multiplie(int a,int b)
{
	return a*b;
}
int dvd(int a,int b)
{
	return a/b;
}
void f(unsigned int){
cout<<"wocao"<<endl;}

struct E
{
	E(double d):e(d){}
	E(int d):e(d){}
	int e;
};
void f(const E&)
{
}

struct LongDouble
{
	LongDouble(double = 0.0){}
	operator double(){return 0.0;}
	//operator float(){return 0.0f;}
};
int main()
{
	int (*divides)(int a,int b) = dvd;
	map<string,function<int(int,int)>> m;
	m.insert({"+",[](int a,int b){return a+b;}});
	m.insert({"-",minus<int>()});
	m.insert({"*",multiplie});
	m.insert({"/",divides});
	LongDouble L;
	//LongDouble l = L+1;
	int a,b;
	string s;
	while(cin>>a>>s>>b)//ÓÃ¿Õ¸ñ¸ô¿ª 
	{
	    cout<<m[s](a,b)<<endl;
	}
	long a1 = 100;
	double b1 = 100.1;
	cout<<a1+b1<<endl; 
	int a2 = -1;
	unsigned b2 = 1;
	cout<<a2+b2<<endl;
	//f(10);
	f(10);
	return 0;
}
