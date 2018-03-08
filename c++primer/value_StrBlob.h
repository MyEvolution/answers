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
		其他的和原来是一样的
		我们之所以用智能指针，只是为了weak_ptr弱指针
		其他部分是完全可以用普通指针代替的 
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
		size_type count;//位置 
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
