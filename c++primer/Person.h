#ifndef PERSON_H
#include<iostream>
#include<string>
using std::istream;
using std::ostream;
using std::string;

struct Person
{
	friend istream &get_inf(istream & is,Person &per);
	friend ostream &print_inf(ostream &os,const Person &per);
	private: 
	string name="a";
	string address="a";
		public:
     Person()//有显式初始化默认的优先执行显式初始化 
	{
		name="zgq";
		address="yc";
	}

	Person(const string &na,const string &ad):name(na),address(ad){}
	Person(const string &na):name(na){}//而在初始值列表中未赋值的元素执行的是隐式初始化 
	Person(istream &is)
	{
		is>>name>>address;
	}
	string _address()const {return this->address;}//this是指针 
	string _name()const {return name;} 

	
};
istream &get_inf(istream & is,Person &per);
ostream &print_inf(ostream &os,const Person &per);
#endif
