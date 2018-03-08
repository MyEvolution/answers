#ifndef HASPTR_H
#define HASPTR_H 

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Hasptr
{
	public:
   Hasptr():strptr(new string){}
   string get_string()const
   {
   	return *strptr;
   }
   int get_int()const
   {
	return si;
   }
   Hasptr(const string &s):strptr(new string(s)){} 
   Hasptr(const Hasptr &Hs):strptr(new string(Hs.get_string())),si(Hs.get_int()){}
   Hasptr &operator = (const Hasptr &Hs)
   {
   	  auto i = new string(Hs.get_string());
   	  delete strptr;
   	  /*�տ�ʼ����Ϊ����һ����ʱ����ֻ��Ϊ�˷����׶���
		 ���˺����֪�����Ǳ�Ҫ��
		 ���������д�����Ǳ�����ɾ��ԭ�ȵ��ڴ棬��Ȼָ����˺������޷�ɾ��
		 delete strptr;
		 strptr = new string(*Hs.strptr); 
		 ��Ϊ��ֵ�������Ҳ�����Ƕ�����
		 ����������������ǽ� ��ͼ������һ��ʲôҲû��ָ��ָ��
		 ����δ����ģ����ܻ���������Եĺ��
		 */ 
		  
   	  strptr = i;
   	  si = Hs.get_int(); 
   	  return *this;
   }
   ~Hasptr()
   {
   	delete strptr;
   }
   bool operator < (const Hasptr & hp)
   {
   	return *strptr<*hp.strptr;
   }
   static void swap(Hasptr &hp1,Hasptr &hp2)
   {
   	using std::swap;
   	swap(hp1.strptr,hp2.strptr);
   	swap(hp1.si,hp2.si);
   	cout<<"swap"<<endl;
   }
   private:
   string *strptr;
   int si = 0;	
   static int haha;
};

/*
����һ����ֵһ�����࣬��������
Ϊÿ��ָ�붼���·����һ��ֵ 
*/ 
#endif

