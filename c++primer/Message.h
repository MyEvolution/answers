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
  	explicit Message(const string &s = ""):contents(s){}//explicit��ʾ�����ܷ�����ʽת�� 
  	Message(const Message &msg);
  	Message &operator = (const Message &);//���������Ϳ������� 
  	~Message(); 
  	void save(Folder &);
  	void remove(Folder &);
  private:
    string contents;
	set<Folder *> folders;//Ĭ�Ϲ����ǿռ� 
	void add_to_folders(const Message &);
	void remove_to_folders(const Message &);
	static void swap(Message &,Message &);
};

void Message::add_to_folders(const Message &msg)const//�����ظ������Ӷ�ʹ�õĹ��ߺ��� 
{                                         //�������msg��folder�����һ������ 
	for(auto i:msg.folders)
	    i->addMes(this);
}
/*����Ϊ�������˵�ǿ��Խ��������Եģ���Ϊ�ڹ���ʱ��msg��folder�ͱ������Ѿ���һ������*/ 
Message::Message(const Message &msg):contents(msg.contents),folders(msg.folders) 
{
	add_to_folders(msg);	
}
void Message::remove_from_folders()//ͬ��  ���Ӳ���msg��floder��ɾ��������Ϣ 
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
	/*��һ���Ը�ֵ�����
	���Ҳ����Լ�ʱ�򣬶�û�䣬
	Ȼ�����ʱ����Ϊ��ӵ����Լ������Բ�����ӳɹ�������ɾ��ʱ��ȴ�ɹ���*/ 
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
	folders�д�������¼����Ϣ��Ŀ¼��
	�����ǽ�����Ŀ¼foldersҲӦ�ý�����
	����������Ŀ¼ȴ��Ȼ��¼��ԭ���ı���Ϣ����ʵ�����Ѿ��Ǳ����ˣ� 
	*/
}
#endif 
/*
����һ��add_of_foldersû�в����Ļ�ʱ�����

û�в���������folders�����һ��thisָ��
��ƽ������������ȫû�еĲ���  ��Ϊthis��folder��һ���Ѿ�������this
����������������ڹ���֮ǰ������ֻ�ǿ�����folder����û�н������
���Զ��ڿ���������˵����ȫ���Ե�
��ô���ڿ�����ֵ�������˵�أ�
������ֵ������õ����������ɾ��֮����ӣ���������folderҲ���ȿ�������
�����Ҿ���Ҳ�ǿ���de
��֮һ�仰�������Ϳ�������Ľ�ϣ����Ǹ�ֵ��
*/ 

