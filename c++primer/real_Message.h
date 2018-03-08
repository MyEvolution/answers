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
   Message(const Message &msg):contents(msg.contents),folders(msg.folders){add_to_folders();}//�������� 
   Message &operator = (const Message &msg)//������ֵ����� 
   {
    remove_from_folders(); //remove������ǰ���ʱ����ô��ͬ���־͸����� ���ǿ��Խ���������ֵ�����ӵ����ߺ�����   	 
     contents = msg.contents;
     folders = msg.folders;
//���remove��������Ļ���folder�Ѿ����£���ô��ԭ���ĵ��ǲ������ڵĽ��޷�ɾ��,��Ϊfolders�����ˣ���Ҫ�ҵ��������ľͺ������� 
     add_to_folders();
   }
   Message(Message &&msg);
/*
�������ǿ���Ϊ��д��������ƶ�������ƶ���ֵ��
����˼��һ�¸���α�д
�����Ǳ�д�ƶ�����ʱ��  �ƶ���ֵ��ʱ��
���Ƿ��������й�ͬ�Ĳ���  
Ϊ�˱���DRY,���ǽ�����д��Ϊ���ߺ���
��ͬ�Ĳ��־�����Ҫ�����ݸ��£����Ҹ���folders
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
	set<Folder*> folders;//�����Ǽ���Ŀ¼��	
    void add_to_folders();
    void remove_from_folders();
    void move_folders(Message *); 
};
class Folder
{
	public:
		Folder(const string& na = ""):name(na){}
		Folder(const Folder &Fs);
		void addMes( Message *msg)//messages�Ƿǳ���ָ��ļ��ϣ������ǳ���ָ�룬��Ϊ 
		{
			messages.insert(msg);//insert���ܻ��׳��쳣 
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
	/*������У���ɾ���˲���
	����һ��˽�к�����˵ ��ʱ�����ĵط����ò��ϣ���������֮ǰҪ�ǵ��Ƚ�folders�趨��
	*/ 
	for(auto i:folders)
	i->addMes(this);
}
void Message::remove_from_folders()
{
	/* ������ʱ��Ҫ�ڸ���folder֮��*/ 
	for(auto i:folders)
	i->remMes(this);
 }

void Message::save(Folder &F)
{
	F.addMes(this);
    folders.insert(&F);//����ӽ�ȥ��Ŀ¼�ŵ�����������׸�ĸ赥����Щ�� 
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
   	/*������ԭ��ɾ����ǰ������ں�
	   ����������������ν�ģ���Ϊ�����Ĳ�û��ɾ���������folders*/ 
   }
void Message::get_folders(ostream &os)
   {
   	os<<"�������׸�ĸ赥��"<<contents<<endl; 
   	for(auto i:folders)
   	os<<i->get_name()<<" ";
   	os<<endl;
   }
void Message::move_folders(Message *msg)
{
//����foldes����Ϊ�����ƺ�Դ���������裬���Ǳ��뽫��ɾ�� 
    folders = std::move(msg->folders);//������������� ��Ϊ���ĸ���folders�����Ի���׶� 
	for(auto i:folders)
	{
		i->remMes(msg);
		i->addMes(this);
	}
	msg->folders.clear();
	/*�������ݵĸ�����Ҫ����Щ����֮����*/ 
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
	remove_from_folders();//�Ӹ赥��ɾ�� 
	move_folders(&msg);//�����˸赥
    }
	return *this; 
 } 
#endif
