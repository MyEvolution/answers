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
     Person()//����ʽ��ʼ��Ĭ�ϵ�����ִ����ʽ��ʼ�� 
	{
		name="zgq";
		address="yc";
	}

	Person(const string &na,const string &ad):name(na),address(ad){}
	Person(const string &na):name(na){}//���ڳ�ʼֵ�б���δ��ֵ��Ԫ��ִ�е�����ʽ��ʼ�� 
	Person(istream &is)
	{
		is>>name>>address;
	}
	string _address()const {return this->address;}//this��ָ�� 
	string _name()const {return name;} 

	
};
istream &get_inf(istream & is,Person &per);
ostream &print_inf(ostream &os,const Person &per);
#endif
