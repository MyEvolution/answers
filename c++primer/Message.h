#ifndef MESSAGE
#define MESSAGE

#include<iostream>
#include<string>
#include<set>

using namespace std;

class Folder;
class Message
{

  friend class Floder;
  public:
  	explicit Message(const string &s = ""):contents(s){}//explicit表示他不能发生隐式转换 
  	Message(const Message &msg);
  	Message &operator = (const Message &);//包含析构和拷贝构造 
  	~Message(); 
  	void save(Folder &);
  	void remove(Folder &);
  private:
    string contents;
	set<Folder *> folders;//默认构造是空集 
	void add_to_folders(const Message &);
	void remove_to_folders(const Message &);
	static void swap(Message &,Message &);
};

void Message::add_to_folders(const Message &msg)const//避免重复造轮子而使用的工具函数 
{                                         //他向参数msg的folder中添加一个副本 
	for(auto i:msg.folders)
	    i->addMes(this);
}
/*我认为就这点来说是可以将参数忽略的，因为在构造时候，msg的folder和本来的已经是一样的了*/ 
Message::Message(const Message &msg):contents(msg.contents),folders(msg.folders) 
{
	add_to_folders(msg);	
}
void Message::remove_from_folders()//同理  它从参数msg的floder中删除本条信息 
{
	for(auto i:folders)
	i->remMes(this);
}
Message::~Message()
{
	remove_from_folders();
 }
Message & Message::operator = (const Message & msg)
{
	/*想一下自赋值的情况
	当右侧是自己时候，都没变，
	然后添加时候因为添加的是自己，所以不会添加成功，但是删除时候却成功了*/ 
	contents = msg.contents;
	folders = msg.folders;
	remove_from_folders();
		add_to_folders(msg);
		return *this; 
}
void Message::save(Folder &F)
{
	F.addMes(this);
	folder.insert(&F);
}
void Message::remove(Folder &F)
{
	F.erase(this);
	folder.erase(&F);
}
void Message::swap(Message &M1,Message &M2)
{
	using std::swap;
	for(auto i:M1.folder)
    {
    	i->remMes(&M1);
    	i->addMes(&M2);
	}
	for(auto i:M2.folder)
	{
		i->remMes(&M2);
		i->addMes(&M1);
	}
	swap(M1.contents,M2.contents);
	swap(M2.folders,M2.folders);
	/*
	folders中储存了收录本信息的目录，
	当我们交换后，目录folders也应该交换，
	但是真正的目录却依然收录这原来的本信息（它实际上已经是别人了） 
	*/
}
#endif 
/*
讨论一下add_of_folders没有参数的话时候合理

没有参数，则会从folders中添加一个this指针
从平常来看这是完全没有的操作  因为this的folder中一定已经包含了this
但是这个函数发生在构造之前，我们只是拷贝了folder，并没有将其添加
所以对于拷贝构造来说是完全可以的
那么对于拷贝赋值运算符来说呢？
拷贝赋值运算符用到的添加是在删除之后添加，并且他的folder也是先拷贝后了
所以我觉得也是可以de
总之一句话，析构和拷贝构造的结合，便是赋值了
*/ 

