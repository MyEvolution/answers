#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
struct PersonInfo
{
	string name;
	vector<string> phone_number;
	void printInfo()const
	{
		cout<<name<<endl;
		for(auto i:phone_number)
		   cout<<i<<ends;
		   cout<<endl;
	}
};
int vail(string s)
{
	for(auto i:s)
	if((i<'0'||i>='9')&&i!='-')
	return 0;
	return 1;
	
}
int main()
{
	vector<PersonInfo> people;
	
	string line,word;
	istringstream record;
	while(getline(cin,line))
	{
	record.str(line);
	//cout<<record.fail() <<endl;
	//�����������俴������ȡ״̬ʧ�� ���Ե�����״̬δ��ˢ��ʱ�������¶��� 
	PersonInfo info;
	   record>>info.name;
	   while(record>>word)
	   info.phone_number.push_back(word);
	   people.push_back(info);
	   record.clear(); 
    }
    for(const auto &i:people)
      {
      	ostringstream formatted,badNums;
      	for(const auto &j:i.phone_number)
      	if(!vail(j))
      	   badNums<<j<<" ";
      	   else
      	     formatted<<j<<" ";
      	     if(badNums.str().empty())
      	        cout<<i.name<<"\n"<<formatted.str()<<endl;
      	        else
      	        cout<<"error input:"<< i.name<<"\n"<<badNums.str()<<endl;//�����������������Ҫ�Ľ����
				  //���Ƕ�֪��������ʾ��������״̬ 
	  }
	  return 0;
}
	   

