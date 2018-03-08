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
   	  /*刚开始我认为创建一个临时对象只是为了方便易读，
		 看了后面才知道这是必要的
		 如果不这样写，我们必须先删除原先的内存，不然指向别人后他将无法删除
		 delete strptr;
		 strptr = new string(*Hs.strptr); 
		 因为赋值拷贝的右侧可以是对象本身
		 如果是这样，那我们将 试图解引用一个什么也没有指的指针
		 这是未定义的，可能会带来灾难性的后果
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
定义一个像值一样的类，就是这样
为每个指针都重新分配出一个值 
*/ 
#endif

