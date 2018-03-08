#ifndef STRBLOB_H
#define STRBLOB_H

#include<vector>
#include<string>
#include<memory>

/*
这个头文件定义了一个类 顺便总结一下这两天学的智能指针
之前我们学的类都是独自存在的如vector
vector<string> v1{"vector","unique"},v2(v1);
当v1或者v2销毁是 另一个资源不受影响
有的类资源是共享的 如标准库的Blob
Blob<string> b1{"vector","unique"};
{
   Bolb<string> b2(b1);
}
//b2离开作用域被销毁  不过资源依然存在，因为有b1指向他  他们资源共享
这种类在需要资源共享时是非常有用的，方便也节省了内存空间

下面我们尝试定义一个StrBlob，它和vector<string>不同的地方就是
资源共享。我们用智能指针来实现它
*/
using std::vector;
using std::string;
using std::shared_ptr;
using std::make_shared; 
using std::weak_ptr;

class StrBlobptr;
class constStrBlobptr;
class StrBlob
{
	friend bool operator < (const StrBlob &sb1,const StrBlob &sb2);
	friend class StrBlobptr;//因为这个类需要指向data指向的内存  
	//那么它必须能访问StrBlob的私有成员，所以我们将他声明为友元 
	friend class constStrBlobptr;
	friend bool operator == (const StrBlob &sb1,const StrBlob &sb2);
		friend bool operator != (const StrBlob &sb1,const StrBlob &sb2);
	public:
		typedef vector<string>::size_type size_type;
		void push_back(const string &s)const{data->push_back(s);}
		void push_back( string &&s) const{data->push_back(std::move(s));}
		void pop_back(){data->pop_back();}
	    const string &front()const{return _front();}
	    string &front(){return const_cast<string &>( _front());}
	    const string &back()const{return _back();};
	    string &back(){return const_cast<string &> (_back());}
	    StrBlob():data(make_shared<vector<string>>()){}//指向一个空的vector 
	    StrBlob(std::initializer_list<string> il):data(make_shared<vector<string>>(il)){}
	    StrBlob(size_type i):data(make_shared<vector<string>>(i)){}//vector有接受一个size_type的参数的构造函数 
	    StrBlobptr begin();
		StrBlobptr end();
		constStrBlobptr begin()const;
		constStrBlobptr end()const;
		constStrBlobptr cbegin()const;
		constStrBlobptr cend()const;
		inline size_type size(){return data->size();}
		string & operator [] (size_type n)
		{
			check(n,"out of range!");
			return (*data)[n];
		 }
		const string &get_string(size_type i)const
		 {
		 	return (*data)[i];
		 }
	
	private:
		void check(size_t i,const string &s)const
		{
		   if(i>=data->size())
		   throw std::out_of_range(s);
		}
		const string & _front()const
		{
			check(0,"empty StrBlob");
			return data->front(); 
		}
		const string &_back()const
		{
			check(0,"empty StrBlob");
			return data->back();
		}
		shared_ptr<vector<string>> data;//指向vector<string>的智能指针 
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
 		friend bool operator < (const StrBlobptr &sb1,const StrBlobptr &sb2);
 		friend bool operator == (const StrBlobptr &sb1,const StrBlobptr &sb2);
 		friend bool operator != (const StrBlobptr &,const StrBlobptr &);
 		using size_type = vector<string>::size_type ;
 		StrBlobptr():curr(0){}
 		StrBlobptr( StrBlob &SB,size_type c = 0):curr(c),wptr(SB.data){}//当构造时出错不会检查出来，只有使用时出错才会出问题
		                                       //这有个好处，那就是可以保证尾后迭代器的存在，但是它不能被使用。缺点是，超出范围的
											   //也可能被构造出来 
 		string &deref()const//这个const应该会导致最后返回的也是conststring的引用 
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
         inline char &operator [](size_type n)
         {
         	check(curr,"out of range");
         	return (**this)[n];
	     }
		 bool is_equal(const StrBlobptr & SBp)
		 {
		 	return wptr.lock() == SBp.get_wptr() && curr== SBp.get_curr();
		 }
		 inline const shared_ptr<vector<string>> get_wptr()const{return wptr.lock();}
		 inline size_type get_curr()const{return curr;};
		 StrBlobptr & operator ++ ()
		 {
		 	check(curr,"out of range");//到达尾后，不能递增 
		 	++curr;
		 	return *this;
		 }
		 StrBlobptr & operator -- ()
		 {
		 	check(curr-1,"out of range");
		 	--curr;
		 	return *this;
		 }
		 StrBlobptr operator ++(int )
		 {
		 	StrBlobptr ret(*this);
		 	 ++*this;//包括了异常处理 
		 	 return ret;
		 }
		 StrBlobptr operator --(int )
		 {
		 	StrBlobptr ret(*this);
		 	--*this;
		 	return ret;
		 }
		 StrBlobptr operator +(size_type n)//等于尾后迭代器是合法的 
		 {
		 	StrBlobptr ret(*this);
		 	check(curr+n-1,"out of range");
		 	ret.curr+=n;
		 	return ret;
		 }
		 StrBlobptr operator -(size_type n)//我们应该知道 即使是右值，依然能够改变指针指向的内容 
		 {
		 	StrBlobptr ret(*this);
		 	check(curr-n,"out of range");
		 	ret.curr -= n;
			 return ret; 
		 }
		 string &operator *()
		 {
		 	check(curr,"out of range");
		 	return (*wptr.lock())[curr];
		  }
		  string * operator ->()
		  {
		  	return &(**this);
		   } 
 	private:
 		shared_ptr<vector<string>> check(size_type si,const string &s)const
 		{
 			//check要声明为const，因为const函数中不能调用非const成员函数 
 			auto ptr = wptr.lock();
 			if(!ptr)
 			throw std::runtime_error("the StrBlobptr is ineffective");
 			if(si>=ptr->size()||si<0)//我们没有提供递减的操作 ，所以初始化时候才有可能出现负数，不过size_type是无符号
			              //会转化为正数，但是若超过了范围 ，解引用以及递增时候会抛出异常 
 			throw std::out_of_range(s);
 			return ptr;
		 }
 		weak_ptr<vector<string>> wptr;//这个弱指针指向它主人的内存
		size_type curr;//表示这个类指向的位置 
  };
  
class constStrBlobptr
{
	 	friend bool operator < (const constStrBlobptr &sb1,const constStrBlobptr &sb2);
 		friend bool operator == (const constStrBlobptr &sb1,const constStrBlobptr &sb2);
 		friend bool operator != (const constStrBlobptr &,const constStrBlobptr &);
	public:
		using size_type =vector<string>::size_type;
		constStrBlobptr():curr(0){}
		constStrBlobptr(const StrBlob &sb,size_type c = 0):wptr(sb.data),curr(c){}
		const char &operator [](size_type n)const
		{
			check(curr,"out of range");
			return (**this)[n];
		}
		const string &operator *()const
		{
			check(curr,"out of range");
			return (*wptr.lock())[curr];
		}
			const string * operator ->()
		  {
		  	return &(**this);
		   } 
				 constStrBlobptr & operator ++ ()
		 {
		 	check(curr,"out of range");//到达尾后，不能递增 
		 	++curr;
		 	return *this;
		 }
		 constStrBlobptr & operator -- ()
		 {
		 	check(curr-1,"out of range");
		 	--curr;
		 	return *this;
		 }
		 constStrBlobptr operator ++(int )
		 {
		 	constStrBlobptr ret(*this);
		 	 ++*this;//包括了异常处理 
		 	 return ret;
		 }
		 constStrBlobptr operator --(int )
		 {
		 	constStrBlobptr ret(*this);
		 	--*this;
		 	return ret;
		 }
		
		constStrBlobptr operator +(size_type n)//等于尾后迭代器是合法的 
		 {
		 	constStrBlobptr ret(*this);
		 	check(curr+n-1,"out of range");
		 	ret.curr+=n;
		 	return ret;
		 }
		 constStrBlobptr operator -(size_type n)//我们应该知道 即使是右值，依然能够改变指针指向的内容 
		 {
		 	constStrBlobptr ret(*this);
		 	check(curr-n,"out of range");
		 	ret.curr -= n;
			 return ret; 
		 }
		 inline size_type size()const{return wptr.lock()->size();}
	private:
		//一个常量对象的常量迭代器最重要的是无法通过他改变容器的值，而不是迭代器本身是个常量无法自增自减 
		shared_ptr<vector<string>> check(size_type si,const string &s)const
		{
			auto ptr= wptr.lock();
			if(!ptr)
			 throw std::runtime_error("the shared_ptr is nullptr");
			if(si>=ptr->size()||si<0)
			throw std::out_of_range(s);
			return ptr;
		}
		weak_ptr<vector<string>> wptr;
		size_type curr;
};
StrBlobptr StrBlob::begin()
	    {
	    	return StrBlobptr(*this);
		}
StrBlobptr StrBlob::end()
{
	return StrBlobptr(*this,data->size());
}
constStrBlobptr StrBlob::end()const
{
	return constStrBlobptr(*this,data->size());
}
constStrBlobptr StrBlob::begin()const
	    {
	    	return constStrBlobptr(*this);
		}
constStrBlobptr StrBlob::cbegin()const
{
	return begin();
}
constStrBlobptr StrBlob::cend()const
{
	return end();//这里会自动调用const型的begin，即使它不是常量，因为const限定了他在这里被看作常量 
}
bool operator == (const StrBlob &sb1,const StrBlob &sb2)
{
    return *sb1.data == *sb2.data;//直接比较两个vector对象，如果指向同一个也是可以 
}
bool operator != (const StrBlob &sb1,const StrBlob &sb2)
{
	return !(sb1==sb2);
}
bool operator == (const StrBlobptr &sb1,const StrBlobptr &sb2)
{
        if(!sb1.wptr.lock()||!sb2.wptr.lock())
        throw std::runtime_error("the shared_ptr is null");
	return sb1.wptr.lock() == sb2.wptr.lock() && sb1.curr ==sb2.curr;
}
bool operator == (const constStrBlobptr &sb1,const constStrBlobptr &sb2)
{
        if(!sb1.wptr.lock()||!sb2.wptr.lock())
        throw std::runtime_error("the shared_ptr is null");
	return sb1.wptr.lock() == sb2.wptr.lock() && sb1.curr ==sb2.curr;
}
bool operator != (const StrBlobptr &sb1,const StrBlobptr &sb2)
{
	return !(sb1==sb2);
}
bool operator != (const constStrBlobptr &sb1,const constStrBlobptr &sb2)
{
	return !(sb1==sb2);
}
bool operator < (const StrBlob &sb1,const StrBlob &sb2)
{
	return *sb1.data < *sb2.data;
}
bool operator < (const StrBlobptr &sb1,const StrBlobptr &sb2)//如果迭代器不在同一个vector上，
 {                                      //那他们比较大小毫无意义，
        if(!sb1.wptr.lock()||!sb2.wptr.lock())
        throw std::runtime_error("the shared_ptr is null");
     return (sb1.wptr.lock()== sb2.wptr.lock())?sb1.wptr.lock() < sb2.wptr.lock() : sb1.curr<sb2.curr;	
}
bool operator < (const constStrBlobptr &sb1,const constStrBlobptr &sb2)//如果迭代器不在同一个vector上，
 {                                      //那他们比较大小毫无意义，
        if(!sb1.wptr.lock()||!sb2.wptr.lock())
        throw std::runtime_error("the shared_ptr is null");
     return (sb1.wptr.lock()== sb2.wptr.lock())?sb1.wptr.lock() < sb2.wptr.lock() : sb1.curr<sb2.curr;	
}
#endif
/*
之前有个题 让设计一个conststrblobptr
我觉得这个题是傻逼
因为即使是一个const 的 strblob 我们依然可以对其使用这个伴随指针，
他只是指针是常量  并不影响其中内容的改变 撑死是不能赋值了

现在我才真正理解了题意  作者当然知道普通的迭代器也可以绑定到其上，但是他就是想让我们建立一个const strblob
的伴随指针  好让他像值一样  我们可以访问  但是不能修改
 
 我们想象一下，能否在原有的strblobptr中实现它
 
 首先，我们必须把他的构造函数改成const strblob& 否则常量的无法调用
 但是改成strblob  我们又无法区分传入的对象到底原来是不是个常量  
 从而无法区分该调用哪个成员函数
 
 更重要的是即使是const 型的 strblobptr  我们依然可以通过它改变指向的内容  这是很可怕的 
 
 所以最好的办法就是新建立一个类 ，专门作用于const strblob 
 
 并且限制他的各种行为，让他无法改变内容 
 */ 
