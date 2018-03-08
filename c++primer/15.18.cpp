#include<iostream>
using namespace std;

class Base
{
	public :
		void pub_mem(){}
	protected :
		void pro_mem(){}
		int prot_mem;
	private :
        void pri_mem(){} 
};

class Priv:private Base
{
	public:
	int f1()const{return prot_mem;}
		void memfcn(Base &b)
	{
		b = *this;
	}
};
class Publ:public Base
{
	public:
	int f2()const{return prot_mem;}
		void memfcn(Base &b)
	{
		b = *this;
	}
};
class Prot:protected Base
{
	public:
	int f3()const{return prot_mem;}
		void memfcn(Base &b)
	{
		b = *this;
	}
};

struct Priv_:public Priv
{
	
};
struct Pub_:public Publ
{
		void memfcn(Base &b)
	{
		b = *this;
	}
};
int main()
{

	Base *p;
	Publ dv1;
	Priv dv2;
	Prot dv3;
	dv2.memfcn(dv3);
	Priv_ dv4;
	Pub_ dv5;
	p = &dv1;
	p = &dv5;
	//p = &dv4;
}

