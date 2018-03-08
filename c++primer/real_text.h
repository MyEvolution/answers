#ifndef TEXTQUERY_H
#define TEXTQUERY_H 
#include"real_StrBlob.h"
#include<map>
#include<set>
#include<fstream>
#include<sstream>
using namespace std;
class QueryResult;
class TextQuery
{
	using line_no = StrBlob::size_type;
	
	public:
		TextQuery(istream &is);
		QueryResult query(const string &s);
	private:
		StrBlob the_content;
		map<string,shared_ptr<set<line_no>>> word_line_no;
};
class QueryResult
{
	using size_type = StrBlob::size_type;
friend	ostream & print(ostream &os,const QueryResult &qr);
	public://����sB��&�Ƿ��Ǳ�Ҫ�ģ����Ƿ�������Ҫ������ʼ���µ�ֵ������ֻҪֵ��ͬ�����ˣ�����������Ҳͦ�� 
	    //������������� 
		QueryResult(const string &s,const StrBlob &sB,shared_ptr<set<size_type>> &sh):
			the_content(sB),sought(s),word_line_no(sh),occur_time(sh?sh->size():0){}
         set<size_type>::iterator begin();
         set<size_type>::iterator end();
         shared_ptr<vector<string>> get_file();
   private:
       StrBlob the_content;
	   shared_ptr<set<size_type>> word_line_no;
	   string sought;	
	   size_type occur_time;
};
ostream& print(ostream &os,const QueryResult &qr)
{
	//����֮ǰ�ͻ���� 
	os<<qr.sought<<" occurs "<<qr.occur_time<<(qr.occur_time>1?" times ":" time ")<<endl;
	if(qr.occur_time)
	for(auto i:*qr.word_line_no)
	   os<<"line("<<i<<")"<<" "<<qr.the_content.get_string(i)<<endl;
	   return os;
}
QueryResult TextQuery::query(const string &s)
{
	return QueryResult(s,the_content,word_line_no[s]);//word_line_no[]�ǿ� 
}
TextQuery::TextQuery(istream &is)
{
	
	string line;
	line_no no = 0;
	while(getline(is,line))
	{
	
	istringstream iss(line);
	the_content.push_back(line);
	string word;
	
	while(iss>>word)
	{
		auto &i = word_line_no[word];//����Ὠ���յ�����ָ�루���֮ǰû�еĻ���
		             //�����Ǳ�Ҫ��  ���ǿ�����Ҫ���յ�ָ��ָ��һ���µ�set 
		if(!i)
		 i.reset(new set<line_no>);//new����һ��set��ָ�룬��������ֱ�ӿ���ת��������ָ�� 
		 i->insert(no); 
	 }
	 
	 ++no;
    }	
}
#endif
