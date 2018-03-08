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
	public://这里sB的&是否是必要的？答案是否，我们需要他来初始化新的值，他们只要值相同就行了，不过是引用也挺好 
	    //这里出问题了吗？ 
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
	//在这之前就会崩溃 
	os<<qr.sought<<" occurs "<<qr.occur_time<<(qr.occur_time>1?" times ":" time ")<<endl;
	if(qr.occur_time)
	for(auto i:*qr.word_line_no)
	   os<<"line("<<i<<")"<<" "<<qr.the_content.get_string(i)<<endl;
	   return os;
}
QueryResult TextQuery::query(const string &s)
{
	return QueryResult(s,the_content,word_line_no[s]);//word_line_no[]是空 
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
		auto &i = word_line_no[word];//这里会建立空的智能指针（如果之前没有的话）
		             //引用是必要的  我们可能需要将空的指针指向一个新的set 
		if(!i)
		 i.reset(new set<line_no>);//new返回一个set的指针，按道理他直接可以转化成智能指针 
		 i->insert(no); 
	 }
	 
	 ++no;
    }	
}
#endif
