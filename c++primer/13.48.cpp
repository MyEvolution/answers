#include"str.h"
#include<vector>
//#include"StrVec.h"

using namespace std;

int main()
{
vector<str> v;
	v.resize(10,"abc");
	cout<<v.size()<<endl; 
	str s = "233334";
	 cout<<".........."<<endl;
	v.push_back(s);
	cout<<v.size()<<endl; 
	cout<<".........."<<endl;
	v.push_back("2333");
	cout<<".........."<<endl;
	v.push_back(std::move(s));
		cout<<".........."<<endl;
	v.push_back(std::move(s));
			cout<<".........."<<endl;
	v.push_back(std::move(s));
	  return 0;
}
/*
�������ҵ���Ϊʲô������ܶ࿽�������ԭ��

��ϸ����һ��vector�����������

�տ�ʼvector��������0��
����һ������1��
������Ҫ���·����ڴ�  �� 2
������  4 ���Ի�ִ������֮ǰ�Ŀ���
�͸ոյ����������ϵ�
�����ұ�д��StrVec���ǿ��ƶ���ȥ�ģ������vector����������Ȼ��������
����˼��  unbelievable 

�����Ҿ�������������
�뿴�ļ�text4.cpp 
��ʵ֤��  ��������˰�����
 
*/ 
