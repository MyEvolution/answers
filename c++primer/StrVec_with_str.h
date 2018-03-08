#ifndef STRVEC_H
#define STRVEC_H
/*
这个类即将实现类似StrVec的功能
*/
#include<memory>
#include"str.h"
#include<utility>
#include<iostream>
#include<algorithm>
 
 //str;
 using std::allocator;
 using std::pair;
 using std::initializer_list;
 using std::cout;
class StrVec
{
	public:
		StrVec():element(nullptr),first_free(nullptr),cap(nullptr){}
		StrVec(const StrVec &);
		void swap(StrVec & sv1,StrVec &sv2)
		{
			using std::swap;
			swap(sv1.element,sv2.element);
			swap(sv1.first_free,sv2.first_free);
			swap(sv1.cap,sv2.cap);
		}
		StrVec(StrVec &&)noexcept;
		StrVec &operator = (StrVec &&)noexcept; 
		StrVec(const initializer_list<str> &);
		StrVec &operator = (const StrVec &);
		StrVec & operator = (StrVec sv)//这里是拷贝或者移动传值 
              {
              	cout<<"交换赋值"<<std::endl; 
            swap(*this,sv);
             return *this;
                }
		~StrVec(){	free();	}
		void push_back(const str& );
		void push_back(str &&s)
		{
			chk_n_alloc();
			alloc.construct(first_free++,std::move(s));
			//经过测试，s是左值，即对右值的引用是左值 
		}
		size_t capacity()const {return cap - element;}
		size_t size()const{return first_free - element;}
		void resize(size_t );
		void resize(size_t n,const str &s);
		void reserve(size_t );
		str * begin()const{return element;}
		str * end()const{return first_free;}
		str operator[](size_t n)//这个符号十分简陋！只是暂时用的 
		{
			return *(element+n);
		}
	private:
		str *element;//指向第一个str
		str *first_free;//指向尾后
		str *cap;//指向分配的内存的尾后 
		static allocator<str> alloc;//用来分配内存的 
		pair<str *,str *> alloc_n_copy(const str *begin,const str*end);
		void free();
		void chk_n_alloc();//保证有足够空间 
		void reallocate();
 };
 
 allocator<str> StrVec::alloc;//需要在外重新定义 
 void StrVec::reallocate()//分配新的内存  并且移动过来，调用move函数 
 {
 	size_t si = size(); 
 	auto newcapacity = si?2*si:1;
 	auto newbegin = alloc.allocate(newcapacity);
 	/*在这里我们要用移动
	 实际上如果调用allocator的uninitialized_copy函数会提高开发效率
	 但是这样的拷贝是没有必要的 我们还会将原来的内存释放
	 用移动的话，我们需要对每个内存手动构造*/ 
	 
 	for(size_t i = 0;i!=si;++i)
 	{
 	alloc.construct(newbegin+i,std::move(*(element+i)));
 }
	 //这里调用的是移动构造啊！ 
 	free();
 	element = newbegin;
 	first_free = element + si;//这里原来是size()，殊不知size在free后已经是未定义的值！ 
 	cap = newcapacity +  element;
 	
 }
 void StrVec::free()
 {
 	if(element)
 	{
 		
 /*	for(auto i = first_free;i!=element;)
 	alloc.destroy(--i);
 	alloc.deallocate(element,capacity());//这里要释放的是原来所有的内存 */
 	for_each(element,first_free,[](str &s){alloc.destroy(&s);});//这里用不用写成常量引用？是不用的 因为我们包含的是str而非const str 
 		alloc.deallocate(element,capacity());
    }
 }
 void StrVec::chk_n_alloc()
 {
 	if(size()==capacity())// 所有内存被占用 
 	{
 		reallocate();
 	
	 }
 }
pair<str*,str*> StrVec::alloc_n_copy(const str *begin,const str *end)
{
	auto newbegin = alloc.allocate(end-begin);
	auto newend = uninitialized_copy(begin,end,newbegin);
	return {newbegin,newend};//返回一个pair,新的开始和尾后指针 
}
 StrVec::StrVec(const StrVec &sv)
 {
 	auto i = alloc_n_copy(sv.element,sv.first_free);
 	element = i.first;
 	cap = first_free = i.second;
 }
StrVec & StrVec::operator = (const StrVec &sv)
{
	/*对于拷贝控制，我们要知道他是析构和拷贝构造的结合*/
	 /*如果我们不先分配内存，自赋值则会出现错误*/ 
	auto i = alloc_n_copy(sv.element,sv.first_free); 
	free();
 	element = i.first;
 	cap = first_free = i.second;
 	return *this;
}
void StrVec::push_back(const str & s)
{
	chk_n_alloc();
	alloc.construct(first_free++,s);//记住这里的内存是未构造的！
	
}
void StrVec::reserve(size_t n)
{
	if(n<capacity())
	return;
	auto newbegin = alloc.allocate(n);
	auto newend = newbegin ;
	for(size_t i = 0;i != size(); ++ i)
	  alloc.construct(newend++,std::move(*(element+i)));
	  free();
	 element = newbegin;
	 first_free = newend;
	 cap = newbegin + n;
}
void StrVec::resize(size_t n)
{
       resize(n,"");
}
void StrVec::resize(size_t n,const str &s)
{
	if(n<size())
	first_free = element + n;
	else while(size()!=n)
	      push_back(s);//添加空字符 
}
	StrVec::StrVec(const initializer_list<str> & il)
	{
	   auto i = alloc_n_copy(il.begin(),il.end());
	   element = i.first;
	   cap = first_free = i.second;
	}
StrVec::StrVec(StrVec &&sv)noexcept:element(sv.element),first_free(sv.first_free),cap(sv.cap)
{
	sv.element = sv.first_free = sv.cap = nullptr;
}
StrVec & StrVec::operator = (StrVec && sv)noexcept//没有内存的分配不会抛出异常 
{
	if(this != &sv)
	{
		free();
		element = sv.element;
		first_free = sv.first_free;
		cap = sv.cap;
	sv.element = sv.first_free = sv.cap = nullptr;
	}
	return *this;
}
/*
这里我们讨论下另一种实现是否可行

首先 我们已经定义了swap函数（专属于这个类的swap函数）
然后我们在定义拷贝赋值符时可以这样

StrVec & operator = (StrVec sv)//这里是拷贝或者移动传值 
{
swap(*this,sv);
return *this;
}
当sv是右值时候调用移动，左值调用拷贝
更关键的是，一个函数即可定义了拷贝以及移动赋值
在message类中我们不使用swap的原因是
他需要更新很多次floders
swap需要删除两次，增加两次
因为传值 所以又要删除，增加一次
使用引用我们只需要删除一次，增加一次 
 这个问题在这里不负存在，他们都需要申请内存，所以用swap实现开发效率增加不少
 实际效率也与原来没有多少差距 
*/
#endif
