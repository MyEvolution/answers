#ifndef HASPTR
#define HASPTR
#include<iostream>
#include<string>

using namespace std;

class HasPtr
{
	public :
		HasPtr(const string &s):strptr(new string(s)),ref_time(new size_t(1)){}
		HasPtr(const HasPtr &HP):strptr(HP.strptr),ref_time(HP.ref_time),i(HP.i){++*ref_time;}
		HasPtr &operator = (const HasPtr &HP)
		{
			++*HP.ref_time;//������ڵ�һλ����Ҫ  Ϊ�˱�֤�Ը�ֵ����ȷ�� 
			if(--*ref_time==0)
			{
				
				delete strptr;
				delete ref_time;
			}
			strptr = HP.strptr;
			ref_time = HP.ref_time;
			i = HP.i;
		
			return *this;
		 }
		 ~HasPtr()
		 {
		 	if(--*ref_time == 0)
		 	{			
				delete strptr;
				delete ref_time;
		    }
		  } 
	private :
		string * strptr;
		size_t * ref_time;
		int i=0;
 };
 #endif
