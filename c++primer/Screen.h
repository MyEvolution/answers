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
		pos position=0;//����λ��
		string content;//��Ļ������
		
	public:
		
	   Screen()=default;
	   Screen(int he,int wi):
	     height(he),wide(wi){
		 }
	Screen(int he,int wi,char c):height(he),wide(wi),content(he*wi,c){
	}
	  Screen &move(int pos)//�ƶ���� 
	  {
	  	position = pos;
	  	return *this;
	  }
	  
	  Screen &move(int x,int y);
	  char get_char(int x,int y);//�õ�mougeλ�õ��ַ� 
	  char get_char(int pos)
	  {
	  	return content[pos];
	  }
	   pos get_pos(){//�õ�����λ�� 
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
	const Screen &display(ostream &os)const//����this��ָ������ָ�� 
	{
		do_display(os);
		return *this;
	}
	/*
	��֮ǰ�Ƚ�string����ʱ��Ҳ�����Ƶ����  �ǳ������ص�Ҳ�ǳ���
	��ʱ����һ��const_cast��ǿ��ת��
	������������Ƕ�������������Ƿ����
	
	Scree &display(ostream &os)
	{
		const_cast<const Screen *> this;
	 } 
	 д���������Ƿ����޷�����ʽָ��ת������ת���Ļ����������޵�ѭ��������ƥ��ǳ��������Բ�����볣���������У�
	 ��������ֻ�ܻ����취��һ�ְ취��������  ��дһ��û�з��ص�  ������ͨ�����ص���������� ��������Ӧ������
	 ���Ƕ��ڱȽϳ���ʱ �������޷������ְ취  ��Ϊ����Ҫֱ�ӷ��ؽ϶̵�
	 һ����˵������������ȱ�д�����Ĳ���  Ȼ�� �ǳ������Լ��ݳ���   ����Ȼ�ͻ�֪����δ��� 
	 */ 
	Screen &display(ostream &os)//this ָ�����ʽ���� 
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
	int pos=x*wide;//��0��ʼ 
	position=pos+y;//һ��
	return *this;
}
inline char Screen::get_char(int x,int y)
{
	int pos=x*wide;//��0��ʼ 
	return content[pos+y];
}
Screen::pos Screen::size()
{
	return height*wide;
}
#endif
