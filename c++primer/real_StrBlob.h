#ifndef STRBLOB_H
#define STRBLOB_H

#include<vector>
#include<string>
#include<memory>

/*
���ͷ�ļ�������һ���� ˳���ܽ�һ��������ѧ������ָ��
֮ǰ����ѧ���඼�Ƕ��Դ��ڵ���vector
vector<string> v1{"vector","unique"},v2(v1);
��v1����v2������ ��һ����Դ����Ӱ��
�е�����Դ�ǹ���� ���׼���Blob
Blob<string> b1{"vector","unique"};
{
   Bolb<string> b2(b1);
}
//b2�뿪����������  ������Դ��Ȼ���ڣ���Ϊ��b1ָ����  ������Դ����
����������Ҫ��Դ����ʱ�Ƿǳ����õģ�����Ҳ��ʡ���ڴ�ռ�

�������ǳ��Զ���һ��StrBlob������vector<string>��ͬ�ĵط�����
��Դ��������������ָ����ʵ����
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
	friend class StrBlobptr;//��Ϊ�������Ҫָ��dataָ����ڴ�  
	//��ô�������ܷ���StrBlob��˽�г�Ա���������ǽ�������Ϊ��Ԫ 
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
	    StrBlob():data(make_shared<vector<string>>()){}//ָ��һ���յ�vector 
	    StrBlob(std::initializer_list<string> il):data(make_shared<vector<string>>(il)){}
	    StrBlob(size_type i):data(make_shared<vector<string>>(i)){}//vector�н���һ��size_type�Ĳ����Ĺ��캯�� 
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
		shared_ptr<vector<string>> data;//ָ��vector<string>������ָ�� 
/*
��Ϊ����ָ��Ĵ���  �����ʹ��Ĭ�ϵĸ�ֵ�����ȵ�
���һ��Զ��ͷ�������Ϊ0���ڴ�
��ָͨ�����޷������� 
*/		
 }; 
 /*
 ����һ��StrBlob����ͻ���������
 ������η������е�Ԫ���Ǹ�����
 ��vector�ж�����[]�������at�������Լ�������
 ���ǿ����������  ���ǽ�ƾ�������ڽ�������  ����ֻ�ܷ���һ�������front��back
 ��������������Ǻ�������ݣ��������ǿ��Գ��Ը�������һ������ָ����
 ��������StrBlob�ĵ����� �����ҿ�����ֹ���Ƿ�����Ч��StrBlob
 �������� ��Ҫ�������е�Ԫ��  ������Ҫָ����ڴ��ָ��  ���ǵ�SubBlob����
 ����ʱ�򣬲�����Ϊ����ָ�����ֹ�ڴ���ͷ�  
 һ����ָͨ���ƺ��������������� ������ָͨ��ʮ��Σ��  ��Ϊ�����޷���֪��ָ��Ŀ��Ƿ��ͷŵ���
 ����������weak_ptr����������shared_ptr������ Ϊ������ �����������������ü���
 ͬʱ���Ա�֤����δ���ͷŵ��ڴ�
 */
 class StrBlobptr//�������� ���뱣֤StrBlob��StrBlobptr֮ǰ���� ͬʱStrBlobptr��Ҫ��StrBlob ����ǰ���� 
 {
 	public:
 		friend bool operator < (const StrBlobptr &sb1,const StrBlobptr &sb2);
 		friend bool operator == (const StrBlobptr &sb1,const StrBlobptr &sb2);
 		friend bool operator != (const StrBlobptr &,const StrBlobptr &);
 		using size_type = vector<string>::size_type ;
 		StrBlobptr():curr(0){}
 		StrBlobptr( StrBlob &SB,size_type c = 0):curr(c),wptr(SB.data){}//������ʱ�������������ֻ��ʹ��ʱ����Ż������
		                                       //���и��ô����Ǿ��ǿ��Ա�֤β��������Ĵ��ڣ����������ܱ�ʹ�á�ȱ���ǣ�������Χ��
											   //Ҳ���ܱ�������� 
 		string &deref()const//���constӦ�ûᵼ����󷵻ص�Ҳ��conststring������ 
 		{                    //��ʵ֤��������  ��ϸ���������const��˼��thisָ����ָ��const��
		                       // Ҳ����wptr�ǳ���ָ�룬����currҲ�ǳ��� 
		                         //�������ǿ��Ըı䳣��ָ��ָ���Ԫ�� ֻҪ���Ǳ��� 
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
		 	check(curr,"out of range");//����β�󣬲��ܵ��� 
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
		 	 ++*this;//�������쳣���� 
		 	 return ret;
		 }
		 StrBlobptr operator --(int )
		 {
		 	StrBlobptr ret(*this);
		 	--*this;
		 	return ret;
		 }
		 StrBlobptr operator +(size_type n)//����β��������ǺϷ��� 
		 {
		 	StrBlobptr ret(*this);
		 	check(curr+n-1,"out of range");
		 	ret.curr+=n;
		 	return ret;
		 }
		 StrBlobptr operator -(size_type n)//����Ӧ��֪�� ��ʹ����ֵ����Ȼ�ܹ��ı�ָ��ָ������� 
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
 			//checkҪ����Ϊconst����Ϊconst�����в��ܵ��÷�const��Ա���� 
 			auto ptr = wptr.lock();
 			if(!ptr)
 			throw std::runtime_error("the StrBlobptr is ineffective");
 			if(si>=ptr->size()||si<0)//����û���ṩ�ݼ��Ĳ��� �����Գ�ʼ��ʱ����п��ܳ��ָ���������size_type���޷���
			              //��ת��Ϊ�����������������˷�Χ ���������Լ�����ʱ����׳��쳣 
 			throw std::out_of_range(s);
 			return ptr;
		 }
 		weak_ptr<vector<string>> wptr;//�����ָ��ָ�������˵��ڴ�
		size_type curr;//��ʾ�����ָ���λ�� 
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
		 	check(curr,"out of range");//����β�󣬲��ܵ��� 
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
		 	 ++*this;//�������쳣���� 
		 	 return ret;
		 }
		 constStrBlobptr operator --(int )
		 {
		 	constStrBlobptr ret(*this);
		 	--*this;
		 	return ret;
		 }
		
		constStrBlobptr operator +(size_type n)//����β��������ǺϷ��� 
		 {
		 	constStrBlobptr ret(*this);
		 	check(curr+n-1,"out of range");
		 	ret.curr+=n;
		 	return ret;
		 }
		 constStrBlobptr operator -(size_type n)//����Ӧ��֪�� ��ʹ����ֵ����Ȼ�ܹ��ı�ָ��ָ������� 
		 {
		 	constStrBlobptr ret(*this);
		 	check(curr-n,"out of range");
		 	ret.curr -= n;
			 return ret; 
		 }
		 inline size_type size()const{return wptr.lock()->size();}
	private:
		//һ����������ĳ�������������Ҫ�����޷�ͨ�����ı�������ֵ�������ǵ����������Ǹ������޷������Լ� 
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
	return end();//������Զ�����const�͵�begin����ʹ�����ǳ�������Ϊconst�޶����������ﱻ�������� 
}
bool operator == (const StrBlob &sb1,const StrBlob &sb2)
{
    return *sb1.data == *sb2.data;//ֱ�ӱȽ�����vector�������ָ��ͬһ��Ҳ�ǿ��� 
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
bool operator < (const StrBlobptr &sb1,const StrBlobptr &sb2)//�������������ͬһ��vector�ϣ�
 {                                      //�����ǱȽϴ�С�������壬
        if(!sb1.wptr.lock()||!sb2.wptr.lock())
        throw std::runtime_error("the shared_ptr is null");
     return (sb1.wptr.lock()== sb2.wptr.lock())?sb1.wptr.lock() < sb2.wptr.lock() : sb1.curr<sb2.curr;	
}
bool operator < (const constStrBlobptr &sb1,const constStrBlobptr &sb2)//�������������ͬһ��vector�ϣ�
 {                                      //�����ǱȽϴ�С�������壬
        if(!sb1.wptr.lock()||!sb2.wptr.lock())
        throw std::runtime_error("the shared_ptr is null");
     return (sb1.wptr.lock()== sb2.wptr.lock())?sb1.wptr.lock() < sb2.wptr.lock() : sb1.curr<sb2.curr;	
}
#endif
/*
֮ǰ�и��� �����һ��conststrblobptr
�Ҿ����������ɵ��
��Ϊ��ʹ��һ��const �� strblob ������Ȼ���Զ���ʹ���������ָ�룬
��ֻ��ָ���ǳ���  ����Ӱ���������ݵĸı� �����ǲ��ܸ�ֵ��

�����Ҳ��������������  ���ߵ�Ȼ֪����ͨ�ĵ�����Ҳ���԰󶨵����ϣ������������������ǽ���һ��const strblob
�İ���ָ��  ��������ֵһ��  ���ǿ��Է���  ���ǲ����޸�
 
 ��������һ�£��ܷ���ԭ�е�strblobptr��ʵ����
 
 ���ȣ����Ǳ�������Ĺ��캯���ĳ�const strblob& ���������޷�����
 ���Ǹĳ�strblob  �������޷����ִ���Ķ��󵽵�ԭ���ǲ��Ǹ�����  
 �Ӷ��޷����ָõ����ĸ���Ա����
 
 ����Ҫ���Ǽ�ʹ��const �͵� strblobptr  ������Ȼ����ͨ�����ı�ָ�������  ���Ǻܿ��µ� 
 
 ������õİ취�����½���һ���� ��ר��������const strblob 
 
 �����������ĸ�����Ϊ�������޷��ı����� 
 */ 
