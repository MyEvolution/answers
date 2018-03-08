#ifndef STRBLOB_H
#define STRBLOB

#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
using std::string;
using std::vector;
using std::shared_ptr;
using std::initializer_list;
class strBlobptr;
class strBlob
{
	friend class strBlobptr;
	public:
		typedef vector<string>::size_type size_type;
		strBlob();
		strBlob(initializer_list<string> il);
		void pop_back(){
			data->pop_back();
		};
		void push_back(const string &s){
			return data->push_back(s);
		};

	public:
		const string &front()const
		{
			return _front();
		}
		string &front()
		{
		return const_cast<string &>(_front());
		}
		const string &back()const
		{
			check(0,"empty strBlob!");
			return data->back();
		}
		string &back()
		{
			check(0,"empty strBlob!");
			return data->back();
		}
	size_t _count()
	{
		return data.use_count();
	}
	   strBlobptr begin()
	   {
	   	return strBlobptr(*this,0);
	   }
	   strBlobptr end()
	   {
	   	return strBlobptr(*this,data->size());
	   }
	private:
		const string & _front()const
		{
		check(0,"empty strBlob!");
		return data->front();
		}
		void check(size_type i,const string &s)const
		{
			if(i>=data->size());
			throw std::out_of_range(s);
		}
		shared_ptr<vector<string>> data;		
};
strBlob::strBlob():data(std::make_shared<vector<string>>()){}
strBlob::strBlob(initializer_list<string> il):data(std::make_shared<vector<string>>(il)){}
class strBlobptr
{
	public :
		strBlobptr():curr(0){}
		strBlobptr(strBlob &s,size_t c = 0):curr(c),wptr(s.data){}
		string &deref()const//解引用，因为没有改变值，所以声明为const 
		{
			auto i = check(curr,"dereference past end");
			return (*i)[curr];
		}
		strBlobptr &intr()
		{
			check(curr,"increment past end of StrBlobptr");
			++curr;
			return *this;
		 } 
	private :
		weak_ptr<vector<string>> check(size_t j,const string &s)
		{
			auto i = wptr.lock();
			if(!i)
			throw runtime_error("unbound strBlobptr");
			if(j>=i->size())
            throw out_of_range(s);
			  return i;
		}
		  weak_ptr<vector<string>> wptr;
		  size_t curr;//表示位置 
}; 
/*
friend 友元的概念
我们想在别的类访问一个类的私有成员
比如B要用到A的私有成员
那么我们就要将B声明为A的友元
*/ 
#endif
