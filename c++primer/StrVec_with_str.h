#ifndef STRVEC_H
#define STRVEC_H
/*
����༴��ʵ������StrVec�Ĺ���
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
		StrVec & operator = (StrVec sv)//�����ǿ��������ƶ���ֵ 
              {
              	cout<<"������ֵ"<<std::endl; 
            swap(*this,sv);
             return *this;
                }
		~StrVec(){	free();	}
		void push_back(const str& );
		void push_back(str &&s)
		{
			chk_n_alloc();
			alloc.construct(first_free++,std::move(s));
			//�������ԣ�s����ֵ��������ֵ����������ֵ 
		}
		size_t capacity()const {return cap - element;}
		size_t size()const{return first_free - element;}
		void resize(size_t );
		void resize(size_t n,const str &s);
		void reserve(size_t );
		str * begin()const{return element;}
		str * end()const{return first_free;}
		str operator[](size_t n)//�������ʮ�ּ�ª��ֻ����ʱ�õ� 
		{
			return *(element+n);
		}
	private:
		str *element;//ָ���һ��str
		str *first_free;//ָ��β��
		str *cap;//ָ�������ڴ��β�� 
		static allocator<str> alloc;//���������ڴ�� 
		pair<str *,str *> alloc_n_copy(const str *begin,const str*end);
		void free();
		void chk_n_alloc();//��֤���㹻�ռ� 
		void reallocate();
 };
 
 allocator<str> StrVec::alloc;//��Ҫ�������¶��� 
 void StrVec::reallocate()//�����µ��ڴ�  �����ƶ�����������move���� 
 {
 	size_t si = size(); 
 	auto newcapacity = si?2*si:1;
 	auto newbegin = alloc.allocate(newcapacity);
 	/*����������Ҫ���ƶ�
	 ʵ�����������allocator��uninitialized_copy��������߿���Ч��
	 ���������Ŀ�����û�б�Ҫ�� ���ǻ��Ὣԭ�����ڴ��ͷ�
	 ���ƶ��Ļ���������Ҫ��ÿ���ڴ��ֶ�����*/ 
	 
 	for(size_t i = 0;i!=si;++i)
 	{
 	alloc.construct(newbegin+i,std::move(*(element+i)));
 }
	 //������õ����ƶ����찡�� 
 	free();
 	element = newbegin;
 	first_free = element + si;//����ԭ����size()���ⲻ֪size��free���Ѿ���δ�����ֵ�� 
 	cap = newcapacity +  element;
 	
 }
 void StrVec::free()
 {
 	if(element)
 	{
 		
 /*	for(auto i = first_free;i!=element;)
 	alloc.destroy(--i);
 	alloc.deallocate(element,capacity());//����Ҫ�ͷŵ���ԭ�����е��ڴ� */
 	for_each(element,first_free,[](str &s){alloc.destroy(&s);});//�����ò���д�ɳ������ã��ǲ��õ� ��Ϊ���ǰ�������str����const str 
 		alloc.deallocate(element,capacity());
    }
 }
 void StrVec::chk_n_alloc()
 {
 	if(size()==capacity())// �����ڴ汻ռ�� 
 	{
 		reallocate();
 	
	 }
 }
pair<str*,str*> StrVec::alloc_n_copy(const str *begin,const str *end)
{
	auto newbegin = alloc.allocate(end-begin);
	auto newend = uninitialized_copy(begin,end,newbegin);
	return {newbegin,newend};//����һ��pair,�µĿ�ʼ��β��ָ�� 
}
 StrVec::StrVec(const StrVec &sv)
 {
 	auto i = alloc_n_copy(sv.element,sv.first_free);
 	element = i.first;
 	cap = first_free = i.second;
 }
StrVec & StrVec::operator = (const StrVec &sv)
{
	/*���ڿ������ƣ�����Ҫ֪�����������Ϳ�������Ľ��*/
	 /*������ǲ��ȷ����ڴ棬�Ը�ֵ�����ִ���*/ 
	auto i = alloc_n_copy(sv.element,sv.first_free); 
	free();
 	element = i.first;
 	cap = first_free = i.second;
 	return *this;
}
void StrVec::push_back(const str & s)
{
	chk_n_alloc();
	alloc.construct(first_free++,s);//��ס������ڴ���δ����ģ�
	
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
	      push_back(s);//��ӿ��ַ� 
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
StrVec & StrVec::operator = (StrVec && sv)noexcept//û���ڴ�ķ��䲻���׳��쳣 
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
����������������һ��ʵ���Ƿ����

���� �����Ѿ�������swap������ר����������swap������
Ȼ�������ڶ��忽����ֵ��ʱ��������

StrVec & operator = (StrVec sv)//�����ǿ��������ƶ���ֵ 
{
swap(*this,sv);
return *this;
}
��sv����ֵʱ������ƶ�����ֵ���ÿ���
���ؼ����ǣ�һ���������ɶ����˿����Լ��ƶ���ֵ
��message�������ǲ�ʹ��swap��ԭ����
����Ҫ���ºܶ��floders
swap��Ҫɾ�����Σ���������
��Ϊ��ֵ ������Ҫɾ��������һ��
ʹ����������ֻ��Ҫɾ��һ�Σ�����һ�� 
 ������������ﲻ�����ڣ����Ƕ���Ҫ�����ڴ棬������swapʵ�ֿ���Ч�����Ӳ���
 ʵ��Ч��Ҳ��ԭ��û�ж��ٲ�� 
*/
#endif
