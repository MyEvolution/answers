#include<iostream>
#include<string>

using namespace std;
string up("bdfhklt");
string down("gjpqy");
string not_here = up+down;
int main()
{
	string word;
	string word1;
	if(cin>>word)
	{
		int pos = 0;
		int last_pos = -1;
		int begin=0;
		int length_max = 0,length = 0;
		while((pos = word.find_first_of(not_here,pos))!=string::npos)//���Ǹ���ϰ��  posӦ����size_type�͵� 
		{
			if((length = pos - last_pos - 1)>length_max)
			{
				length_max = length;
					begin = last_pos+1;
			}
			last_pos = pos;
			++pos;
		}
		if(last_pos!=word.size()&&(length = word.size()-last_pos-1)>length_max)
		  {
		  begin = last_pos+1;
		  length_max = length;
	      }
		if(length_max)
		{
			word1 = word.substr(begin,length_max);//��begin��ʼ���� 
			cout<<word1<<endl;
		}
	}
	return 0;
}
/*
���С����ȴ���˺ܳ�ʱ�� 
ȱ���������ϰ

���˼· ���ҳ������������ģ��м���ı�������Ҫ�ҵ�
������ֵ���泤�ȺͿ�ʼ��λ��   ֱ���ҵ��������ִ�

ʵ��ʱ���м���ϸ��û��ע�⣺
1.��Ϊpos������ǲ��ڷ�Χ�ڵģ�����last_pos�ĳ�ʼֵӦ����-1,���������׸�Ԫ��  
2.find_fist_of()���������� ������д�ڶ���
3.����˳�ѭ��pos��npos  �������Ǽ�����ʱӦ�ü�����last_pos
4.string�ĳ�ʼ�� ����  �滻����������Ϥ 
*/ 
 
