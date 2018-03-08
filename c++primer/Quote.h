#ifndef QUOTE_H
#define QUOTE_H
#include<string>
#include<iostream>
#include<memory>
#include<set>
 
using std::string;
using std::ostream;
using namespace std; 
class Quote
{
    public :
    	Quote()=default;
    	Quote(const string & s,double pri):bookNo(s),price(pri){}
    	virtual double net_price(std::size_t n)const
    	{
    		return n*price;
		}
		string isbn()const{return bookNo;}
		virtual ~Quote()=default;
		virtual void debug(ostream &os)const
		{
			os<<"bookNo:"<<bookNo<<std::endl;
			os<<"price:"<<price<<std::endl;
		}
	private:
		string bookNo;
	protected:
		double price = 0.0;
};
class Disc_quote:public Quote
{	
	public:
		Disc_quote()=default;
	 Disc_quote(const string &s,double pri,size_t min,double dis):
	 	Quote(s,pri),min_pty(min),discount(dis){}
	 	
	 	virtual double net_price(size_t n)const override = 0;//���麯�� 
	protected:
		size_t min_pty = 0;
		double discount = 0.0;
};
class Bulk_quote:public Disc_quote
{
	public :
		Bulk_quote(const string &s,double pri,size_t min,double dis):Disc_quote(s,pri,min,dis){}
		Bulk_quote()=default;
		
		virtual double net_price(std::size_t n)const override
		{
		   if(n<Disc_quote::min_pty)
		     return price*n;
		     else
		     return price*(1-Disc_quote::discount)*n;
		}
		void debug(ostream &os) const override
		{
			Quote::debug(os);
			os<<"min_pty:"<<Disc_quote::min_pty<<std::endl;
			os<<"discount:"<<Disc_quote::discount<<std::endl;
		}
		private: 
			size_t min_pty = 0;
		double discount = 0.0;
		/* 
		֮ǰд��������˸ģ�Ȼ�������˴��� ����Ҳ����һЩ����
		����  ͬ���ĳ�Ա�����Ǹ����еģ������ʼ����û���ᵽҲ�����������ִ��Ĭ�ϳ�ʼ�����������ڳ�ʼֵ��
		��Ҫ���ʸ����  ��Ҫ����������ʷ� 
		*/
	 
};
class Bulk_Quote_most:public Disc_quote 
{
	public :
	  Bulk_Quote_most(const string &s,double pri,size_t max,double dis):
		  Disc_quote(s,pri,max,dis){}
		  virtual double net_price(size_t n)const override
		  {
		  	if(n>min_pty)
		  	return min_pty*price*(1-discount)+(n-min_pty)*price;
		  	else
		  	  return n*price*(1-discount);
		  }

 };
double print_total(std::ostream &os,const Quote &Q,size_t n)
{
	double ret = Q.net_price(n);
	os<<Q.isbn()<<"# sold: "<<n<<" total due :"<<ret<<std::endl;
	return ret;
}
class Basket//���ﳵ����,�������潻�׼�¼
{
private:
	static bool comPare(const shared_ptr<Quote> &s1, const shared_ptr<Quote> &s2)
	{
		return s1->isbn() < s2->isbn();
	}
	multiset<shared_ptr<Quote>, decltype(comPare)*> item{comPare};
public:
	void add_item(const shared_ptr<Quote> &sp) { item.insert(sp); }
	double print_all(ostream &os);

};
double Basket::print_all(ostream &os)
{
	double sum = 0.0;
	for (auto i = item.cbegin(); i != item.cend(); i = item.upped_bound(i))
	{
		sum += print_total(os, **i, item.count(*i));
	}
	return sum;
}
#endif
