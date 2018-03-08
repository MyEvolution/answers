#ifndef STRBLOB_H
#define STRBLOB_H

#include<vector>
#include<str>
#include<memory>

/*
���ͷ�ļ�������һ���� ˳���ܽ�һ��������ѧ������ָ��
֮ǰ����ѧ���඼�Ƕ��Դ��ڵ���vector
StrVec v1{"vector","unique"},v2(v1);
��v1����v2������ ��һ����Դ����Ӱ��
�е�����Դ�ǹ���� ���׼���Blob
Blob<str> b1{"vector","unique"};
{
   Bolb<str> b2(b1);
}
//b2�뿪����������  ������Դ��Ȼ���ڣ���Ϊ��b1ָ����  ������Դ����
����������Ҫ��Դ����ʱ�Ƿǳ����õģ�����Ҳ��ʡ���ڴ�ռ�

�������ǳ��Զ���һ��StrBlob������StrVec��ͬ�ĵط�����
��Դ��������������ָ����ʵ����
*/
using std::vector;
using std::str;
using std::shared_ptr;
using std::make_shared; 
using std::weak_ptr;

class StrBlobptr;
class StrBlob
{
	friend class StrBlobptr;//��Ϊ�������Ҫָ��dataָ����ڴ�  
	//��ô�������ܷ���StrBlob��˽�г�Ա���������ǽ�������Ϊ��Ԫ 
	public:
		typedef StrVec::size_type size_type;
		void push_back(const str &s)const{data->push_back(s);}
		void push_back( str &&s) const{data->push_back(std::move(s));}
		void pop_back(){data->pop_back();}
	    const str &front()const{return _front();}
	    str &front(){return const_cast<str &>( _front());}
	    const str &back()const{return _back();};
	    str &back(){return const_cast<str &> (_back());}
	    StrBlob():data(make_shared<StrVec>()){}//ָ��һ���յ�vector 
	    StrBlob(std::initializer_list<str> il):data(make_shared<StrVec>(il)){}
	    StrBlob(size_type i):data(make_shared<StrVec>(i)){}//vector�н���һ��size_type�Ĳ����Ĺ��캯�� 
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
		shared_ptr<StrVec> data;//ָ��StrVec������ָ�� 
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
 		using size_type = StrVec::size_type ;
 		StrBlobptr():curr(0){}
 		StrBlobptr(const StrBlob &SB,size_type c = 0):curr(c),wptr(SB.data){}
 		str &deref()const//���constӦ�ûᵼ����󷵻ص�Ҳ��conststr������ 
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

		 bool is_equal(const StrBlobptr & SBp)
		 {
		 	return wptr.lock() == SBp.get_wptr() && curr== SBp.get_curr();
		 }
		 inline const shared_ptr<StrVec> get_wptr()const{return wptr.lock();}
		 inline size_type get_curr()const{return curr;};
		 
 	private:
 		shared_ptr<StrVec> check(size_type si,const str &s)const
 		{
 			//checkҪ����Ϊconst����Ϊconst�����в��ܵ��÷�const��Ա���� 
 			auto ptr = wptr.lock();
 			if(!ptr)
 			throw std::runtime_error("the StrBlobptr is ineffective");
 			if(si>=ptr->size())//����û���ṩ�ݼ��Ĳ��� �����Գ�ʼ��ʱ����п��ܳ��ָ���������size_type���޷���
			              //��ת��Ϊ�����������������˷�Χ ���������Լ�����ʱ����׳��쳣 
 			throw std::out_of_range(s);
 			return ptr;
		 }
 		weak_ptr<StrVec> wptr;//�����ָ��ָ�������˵��ڴ�
		size_type curr;//��ʾ�����ָ���λ�� 
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
