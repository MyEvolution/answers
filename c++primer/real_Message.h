#ifndef MESSAGE_H
#define MESSAGE_H

#include<iostream>
#include<string>
#include<set>

using namespace std;
class Folder;
class Message
{
   public :
   Message(const string &s = ""):contents(s){}
   Message(const Message &msg):contents(msg.contents),folders(msg.folders){add_to_folders();}//拷贝构造 
   Message &operator = (const Message &msg)//拷贝赋值运算符 
   {
    remove_from_folders(); //remove放在最前面的时候，那么共同部分就更多了 我们可以将下连个赋值的语句加到工具函数中   	 
     contents = msg.contents;
     folders = msg.folders;
//如果remove放在这里的话，folder已经更新，那么在原来的但是不在现在的将无法删除,因为folders更新了，想要找到包含他的就很难找了 
     add_to_folders();
   }
   Message(Message &&msg);
/*
现在我们考虑为编写的类添加移动构造和移动赋值符
我们思考一下该如何编写
当我们编写移动构造时候  移动赋值符时候
我们发现他们有共同的部分  
为了避免DRY,我们将它编写成为工具函数
共同的部分就是需要将内容更新，并且更新folders
*/ 
   static void swap(Message &,Message &);
   void save(Folder &F);
   void remove(Folder &F);
   ~Message(){remove_from_folders();}
   Message & operator = (Message &&);
   void get_folders(ostream &os);

   string get_content()
   {
   	return contents;
   }
   private:
    string contents;
	set<Folder*> folders;//它在那几个目录里	
    void add_to_folders();
    void remove_from_folders();
    void move_folders(Message *); 
};
class Folder
{
	public:
		Folder(const string& na = ""):name(na){}
		Folder(const Folder &Fs);
		void addMes( Message *msg)//messages是非常量指针的集合，不能是常量指针，因为 
		{
			messages.insert(msg);//insert可能会抛出异常 
		}
		void remMes(Message *msg)
		{
			messages.erase(msg);
		}
		Folder &operator =(const Folder & Fs)
		{
			remove_from_message();
				name = Fs.name;
	         messages = Fs.messages;
	            add_to_message();	
		}
		void get_message(ostream &os)
		{
			for(auto i:messages)
			os<<i->get_content()<<" ";
			os<<endl;
		}
		string get_name()
		{
		//	cout<<name<<endl;
			return name;
		}
	private:
		string name;
		set<Message*> messages;
		void remove_from_message()
		{
			for(auto i:messages)
			i->remove(*this); 
		}
		void add_to_message()
		{
			for(auto i:messages)
			i->save(*this); 			
		}
};
Folder::Folder(const Folder &Fs) 
{
	name = Fs.name;
	messages = Fs.messages;
	add_to_message();
}
void Message::add_to_folders()
{
	/*在这次中，我删除了参数
	对于一个私有函数来说 暂时其他的地方还用不上，不过在他之前要记得先将folders设定好
	*/ 
	for(auto i:folders)
	i->addMes(this);
}
void Message::remove_from_folders()
{
	/* 操作他时，要在更新folder之后*/ 
	for(auto i:folders)
	i->remMes(this);
 }

void Message::save(Folder &F)
{
	F.addMes(this);
    folders.insert(&F);//将添加进去的目录放到这里（包含这首歌的歌单有哪些） 
}
 void Message::swap(Message & m1,Message &m2)
   {
   	using std::swap;
   	for(auto i:m1.folders)
   	i->remMes(&m1);
   	for(auto i:m2.folders)
   	i->remMes(&m2);
   	swap(m1.contents,m2.contents);
   	swap(m1.folders,m2.folders);
   	for(auto i:m1.folders)
   	i->addMes(&m1);
   	for(auto i:m2.folders)
   	i->addMes(&m2);
   	/*体现了原则：删除在前，添加在后
	   但是在这里是无所谓的，因为交换的并没有删除或者添加folders*/ 
   }
void Message::get_folders(ostream &os)
   {
   	os<<"包含这首歌的歌单："<<contents<<endl; 
   	for(auto i:folders)
   	os<<i->get_name()<<" ";
   	os<<endl;
   }
void Message::move_folders(Message *msg)
{
//更新foldes，因为对于移后源对象不作假设，我们必须将他删除 
    folders = std::move(msg->folders);//把这个放在这里 因为下文更新folders，所以会更易读 
	for(auto i:folders)
	{
		i->remMes(msg);
		i->addMes(this);
	}
	msg->folders.clear();
	/*对于内容的更新需要在哪些操作之后吗*/ 
}
Message::Message(Message &&msg):contents(std::move(msg.contents))//,folders(std::move(msg.folders))
{
	if(this!=&msg)
	{
	move_folders(&msg);
	}
}
Message &Message::operator = (Message && msg)
{
	if(this!=&msg)
	{
	contents = std::move(msg.contents);
	remove_from_folders();//从歌单中删除 
	move_folders(&msg);//更新了歌单
    }
	return *this; 
 } 
#endif
