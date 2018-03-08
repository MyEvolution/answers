#ifndef STRBLOB
#define STRBLOB

#include<string>
#include<memory>
#include<iostream>
#include<vector>

using namespace std;
class StrBlobptr;
class StrBlob
{
	
	friend class StrBlobptr;
	public:
		using size_type = vector<string>::size_type;
		StrBlob():data(make_shared<vector<string>>()){}
		StrBlob(const StrBlob &SB):data(make_shared<vector<string>>(*SB.data)){}
		StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)){}
		StrBlob & operator = (const StrBlob &SB)
		{
			data.reset(new vector<string>(*SB.data));
			return *this;
		 }
		 StrBlobptr begin()const;
		  StrBlobptr end()const;
		/*
		�����ĺ�ԭ����һ����
		����֮����������ָ�룬ֻ��Ϊ��weak_ptr��ָ��
		������������ȫ��������ָͨ������ 
		*/ 
	private:
		shared_ptr<vector<string>> data;
};
class StrBlobptr
{
	public:
		using size_type = StrBlob::size_type;
		StrBlobptr(const StrBlob &SB,size_type c = 0):data(SB.data),count(c){}
		StrBlobptr &add_it()
		{
			check(count,"it's the end");
			++count;
			return *this;
		}
		string &get_it()const
		{
			check(count,"out of range");
			return (*data.lock())[count];
		}
	private:
		weak_ptr<vector<string>> data;
		size_type count;//λ�� 
		 void check(size_type t,const string & s)const
		 {
		 	if(!data.lock())
		 	throw runtime_error("the block is destoried");
		 	if(t>data.lock()->size())
		 	throw out_of_range(s);
		 }
};
StrBlobptr StrBlob::begin()const 
 {
	return StrBlobptr(*this);
		   }  
StrBlobptr StrBlob::end()const 
 {
	return StrBlobptr(*this,data->size());
		   } 
#endif
