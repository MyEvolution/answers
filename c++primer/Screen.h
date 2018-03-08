#ifndef SCGREEN_H


#include<iostream>
#include<string>
#include<vector>
using std::vector;
using std::string;
using std::ostream;
class Screen;
class Window_mgr
{
	typedef vector<Screen >::size_type screen_index;
	 private:
	 	vector<Screen> screen;
	 	
	 	public:
	 		void clear(screen_index);
	 		Window_mgr();
}; 
class Screen
{
//	friend void Window_mgr::clear(screen_index);
     public:
     	typedef int pos;
	private:
		pos height=0,wide=0;
		pos position=0;//光标的位置
		string content;//屏幕的内容
		
	public:
		
	   Screen()=default;
	   Screen(int he,int wi):
	     height(he),wide(wi){
		 }
	Screen(int he,int wi,char c):height(he),wide(wi),content(he*wi,c){
	}
	  Screen &move(int pos)//移动光标 
	  {
	  	position = pos;
	  	return *this;
	  }
	  
	  Screen &move(int x,int y);
	  char get_char(int x,int y);//得到mouge位置的字符 
	  char get_char(int pos)
	  {
	  	return content[pos];
	  }
	   pos get_pos(){//得到光标的位置 
	   	return position;
	   }
	   char get_pc()
	   {
	   	return content[position];
	   }
	   Screen &set(char c)
	   {
	   	content[position]=c;
	   	return *this;
		}
	Screen &set(int x,int y,char c)
	{
		content[x*wide+y]=c;
		return *this;
	}
	const Screen &display(ostream &os)const//声明this是指向常量的指针 
	{
		do_display(os);
		return *this;
	}
	/*
	在之前比较string长短时候也有类似的情况  非常量返回的也是常量
	当时用了一个const_cast来强制转换
	在这里如果我们定义成那样看看是否可以
	
	Scree &display(ostream &os)
	{
		const_cast<const Screen *> this;
	 } 
	 写到这里我们发现无法将隐式指针转换，不转换的话则会进入无限地循环（优先匹配非常量，所以不会进入常量的重载中）
	 所以我们只能换个办法，一种办法就是这样  编写一个没有返回的  并且在通过重载调用这个函数 并返回相应的引用
	 但是对于比较长短时 我们又无法用这种办法  因为必须要直接返回较短的
	 一般来说遇到这种情况先编写常量的操作  然后 非常量可以兼容常量   ，自然就会知道如何处理 
	 */ 
	Screen &display(ostream &os)//this 指针的隐式传递 
	{
		do_display(os);
		return *this; 
	} 
	pos size();
	private :
		void do_display(ostream &os)const
		{
			os<<content;
		}
	
		
};
Window_mgr::Window_mgr()
{
	screen={Screen(10,10,' ')};
}
/*class Window_mgr
{
	using screen_index=vector<Screen>::size_type;
  private:
  	  vector<Screen > screen{Screen(10,10,' ')};
};*/
inline Screen &Screen::move(int x,int y)
{
	int pos=x*wide;//从0开始 
	position=pos+y;//一样
	return *this;
}
inline char Screen::get_char(int x,int y)
{
	int pos=x*wide;//从0开始 
	return content[pos+y];
}
Screen::pos Screen::size()
{
	return height*wide;
}
#endif
