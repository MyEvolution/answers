#include<iostream>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

int main()
{
	map<string,size_t> word_count;
	set<string> ignore_word{"the","a"};
	static set<char> ignore_al{',' ,'.',';','"','!','?','\''};
	string word;
	while(cin>>word)
	{
		word.erase(remove_if(word.begin(),word.end(),[](char c){
			return ignore_al.find(c)!=ignore_al.end();}),word.end());//���������� 
			/*
			�տ�ʼ�������   ��Ϊû�м�if
			������Ȼ��ֹͣ����  ԭ�����Ǽӷ�Χ�������ĺ���
			remove_if���û���ҵ����������Ļ᷵��β�������
			��������˻Ὣ�����Ԫ��ǰ�ƣ�Ҳ���ǲ�û������ɾ��Ԫ�� 
			�����в���������δ֪�ģ�������Ҫ����erase��������ɾ�� 
			û�мӷ�Χ������erase�ᵥ��ɾ�����е�������ָ��Ԫ�أ�
			����ɾ��β�����������δ�������Ϊ
			�������β�������   ��ôû���ҵ��Ļ�������ɾ���κ�ֵ
			*/ 
			transform(word.begin(),word.end(),word.begin(),::tolower);//�����ν�ʵ�ֵ��������ʼ��λ�� 
			if(ignore_word.find(word)==ignore_word.end())
		  ++word_count[word];
	}
	for(auto i:word_count)
	   cout<<i.first<<":"<<i.second<<endl;
	   return 0;
 }
