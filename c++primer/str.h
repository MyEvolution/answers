#ifndef STR_H
#define STR_H
#include<utility>
#include<memory>
#include<algorithm>
#include<iostream>
 using std::allocator;
 using std::pair;
 using std::initializer_list;
 using namespace std;
class str
{
	friend bool operator == (const str &,const str &);
		friend bool operator != (const str &,const str &);
	public:
	str():data(nullptr),first_free(nullptr),cap(nullptr){}

	str(const str &);
	str(const char *);
	str(str &&s):data(s.data),first_free(s.first_free),cap(s.cap){s.data = s.first_free = s.cap = nullptr;cout<<"移动构造str&&"<<endl;}
	str& operator = (str &&s)
	{
		if(this != &s)
		{
			free();
			data = s.data;
			first_free = s.first_free;
			cap = s.cap;
			s.data = s.first_free = s.cap = nullptr;
		}
		return *this;
	 } 
	str& operator =(const str &);
	char *begin()const{return data;}
	char *end()const{return first_free;}
	inline size_t size()const{return first_free - data;}
	inline size_t capacity()const{return cap - data;}
	ostream & operator << (ostream &os);
	void free();
	private:
	char *data;
	char *first_free;
	char *cap; 
	static allocator<char> alloc;
	pair<char*,char*> alloc_n_copy(const char *,const char *);
	void chk_n_alloc();
	void reallocate();
};
allocator<char> str::alloc;
void str::reallocate()
{
    size_t si = size();
    auto newcapacity = si?2*si:1;
    auto newbegin = alloc.allocate(newcapacity);
    /*因为是内置类型，所以就不用移动构造了吧*/
	uninitialized_copy(data,first_free,newbegin);
	free();
	data = newbegin;
	first_free = newbegin+si;
	cap = newbegin +  newcapacity;   
}
void str::chk_n_alloc()
{
	if(size()==capacity())
	reallocate();
}
pair<char*,char*> str::alloc_n_copy(const char *begin,const char *end)
{
	  auto si = end - begin;
	  auto nbegin = alloc.allocate(si);
	  return {nbegin,uninitialized_copy(begin,end,nbegin)};
}
void str::free()
{
	if(data)
	{
		for_each(data,first_free,[](char &s){alloc.destroy(&s);});
		alloc.deallocate(data,capacity());
	}
}
str::str(const char *a)
{
	  size_t si = 0;
	  const char *q = a;
	  while(*q!='\0')
	       ++si,++q;
//	cout<<"size"<<si<<endl;
	auto ca = alloc_n_copy(a,a+si);//这会跳过空字符
		data = ca.first;
	first_free = ca.second;
	cap = first_free; 
}
str::str(const str & s)
{
	cout<<"拷贝构造str(const str &)"<<endl;
	auto ca = alloc_n_copy(s.data,s.first_free);
		data = ca.first;
	first_free = ca.second;
	cap = first_free;
}
str &str::operator = (const str & s)
{
	cout<<" operator = (const str &)"<<endl;
	auto ca = alloc_n_copy(s.data,s.first_free);
	free();
		data = ca.first;
	first_free = ca.second;
	cap = first_free;
}
ostream & str::operator << (ostream & os)
{
	for(auto i:*this)
	    os<<i;
	    return os;
 }
 bool operator == (const str &s1,const str &s2)
 {
 	if(s1.size()!=s2.size())
 	return false;
 	  auto i = s1.data,j = s2.data;
 	  while(i!=s1.first_free&&j!=s2.first_free)
 	  {
 	  	if(*i == *j)
 	  	   ++i,++j;
 	  	   else
 	  	   return false;
	   }
	   return true;
 }
 bool operator !=(const str &s1,const str &s2)
 {
 	return !(s1==s2);
 }
#endif
