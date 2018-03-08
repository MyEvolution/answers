#ifndef STRBLOB_H
#define STRBLOB_H

#include<vector>
#include<str>
#include<memory>

/*
这个头文件定义了一个类 顺便总结一下这两天学的智能指针
之前我们学的类都是独自存在的如vector
StrVec v1{"vector","unique"},v2(v1);
当v1或者v2销毁是 另一个资源不受影响
有的类资源是共享的 如标准库的Blob
Blob<str> b1{"vector","unique"};
{
   Bolb<str> b2(b1);
}
//b2离开作用域被销毁  不过资源依然存在，因为有b1指向他  他们资源共享
这种类在需要资源共享时是非常有用的，方便也节省了内存空间

下面我们尝试定义一个StrBlob，它和StrVec不同的地方就是
资源共享。我们用智能指针来实现它
*/
using std::vector;
using std::str;
using std::shared_ptr;
using std::make_shared; 
using std::weak_ptr;

class StrBlobptr;
class StrBlob
{
	friend class StrBlobptr;//因为这个类需要指向data指向的内存  
	//那么它必须能访问StrBlob的私有成员，所以我们将他声明为友元 
	public:
		typedef StrVec::size_type size_type;
		void push_back(const str &s)const{data->push_back(s);}
		void push_back( str &&s) const{data->push_back(std::move(s));}
		void pop_back(){data->pop_back();}
	    const str &front()const{return _front();}
	    str &front(){return const_cast<str &>( _front());}
	    const str &back()const{return _back();};
	    str &back(){return const_cast<str &> (_back());}
	    StrBlob():data(make_shared<StrVec>()){}//指向一个空的vector 
	    StrBlob(std::initializer_list<str> il):data(make_shared<StrVec>(il)){}
	    StrBlob(size_type i):data(make_shared<StrVec>(i)){}//vector有接受一个size_type的参数的构造函数 
	    StrBlobptr begin()const;
		StrBlobptr end()const;
		const str &get_str(size_type i)const
		 {
		 	return (*data)[i];
		 }
	
	private:
		void check(size_t i,const str &s)const
		{
		   if(i>=data->size())
		   throw std::out_of_range(s);
		}
		const str & _front()const
		{
			check(0,"empty StrBlob");
			return data->front(); 
		}
		const str &_back()const
		{
			check(0,"empty StrBlob");
			return data->back();
		}
		shared_ptr<StrVec> data;//指向StrVec的智能指针 
/*
因为智能指针的存在  类可以使用默认的赋值拷贝等等
并且会自动释放引用数为0的内存
普通指针是无法做到的 
*/		
 }; 
 /*
 以上一个StrBlob的类就基本做好了
 可是如何访问其中的元素是个问题
 在vector中定义了[]运算符，at函数，以及迭代器
 我们可以随意访问  但是仅凭我们现在建立的类  我们只能访问一个对象的front和back
 而重载运算符将是后面的内容，所以我们可以尝试给他建立一个伴随指针类
 它就像是StrBlob的迭代器 ，并且可以阻止我们访问无效的StrBlob
 现在想想 想要访问其中的元素  我们需要指向该内存的指针  但是当SubBlob对象被
 销毁时候，不能因为有他指向而阻止内存的释放  
 一个普通指针似乎满足这样的条件 但是普通指针十分危险  因为我们无法得知他指向的块是否被释放掉了
 还好我们有weak_ptr，它就像是shared_ptr的仆人 为他服务 但不会增加他的引用计数
 同时可以保证访问未被释放的内存
 */
 class StrBlobptr//而且我们 必须保证StrBlob在StrBlobptr之前定义 同时StrBlobptr又要在StrBlob 定义前声明 
 {
 	public:
 		using size_type = StrVec::size_type ;
 		StrBlobptr():curr(0){}
 		StrBlobptr(const StrBlob &SB,size_type c = 0):curr(c),wptr(SB.data){}
 		str &deref()const//这个const应该会导致最后返回的也是conststr的引用 
 		{                    //事实证明并不会  仔细想想这里的const意思是this指针是指向const，
		                       // 也就是wptr是常量指针，并且curr也是常量 
		                         //但是我们可以改变常量指针指向的元素 只要它是变量 
 			auto ptr = check(curr,"the end of the vector");
 			return (*ptr)[curr];
		 }
		 StrBlobptr &incr()
		 {
		 	check(curr,"already end");
		 	++curr;
		 	return *this;
		 }

		 bool is_equal(const StrBlobptr & SBp)
		 {
		 	return wptr.lock() == SBp.get_wptr() && curr== SBp.get_curr();
		 }
		 inline const shared_ptr<StrVec> get_wptr()const{return wptr.lock();}
		 inline size_type get_curr()const{return curr;};
		 
 	private:
 		shared_ptr<StrVec> check(size_type si,const str &s)const
 		{
 			//check要声明为const，因为const函数中不能调用非const成员函数 
 			auto ptr = wptr.lock();
 			if(!ptr)
 			throw std::runtime_error("the StrBlobptr is ineffective");
 			if(si>=ptr->size())//我们没有提供递减的操作 ，所以初始化时候才有可能出现负数，不过size_type是无符号
			              //会转化为正数，但是若超过了范围 ，解引用以及递增时候会抛出异常 
 			throw std::out_of_range(s);
 			return ptr;
		 }
 		weak_ptr<StrVec> wptr;//这个弱指针指向它主人的内存
		size_type curr;//表示这个类指向的位置 
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
