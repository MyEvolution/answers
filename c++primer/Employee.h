#ifndef EMPLOYEE
#define EMPLOYEE
#include<iostream>
#include<string>
using namespace std;
class Employee
{
private:
    string E_name;
	static size_t the_no;	
	size_t E_no;
public :
	Employee():E_no(the_no++){}
	Employee(const string &name):E_no(the_no++),E_name(name){}
	Employee(const Employee & e):E_no(the_no++),E_name(e.E_name){}
	Employee & operator =(const Employee &e){
	E_name = e.E_name;
	return *this;
	}
	 
	void get_info(ostream &os)
	{
		os<<"name:"<<E_name<<'\n'<<"no:"<<E_no<<endl;
	}
	
 };
 size_t Employee::the_no = 0; 
 #endif
 
