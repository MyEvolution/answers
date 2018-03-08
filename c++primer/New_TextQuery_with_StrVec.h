#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include<iostream>
#include<memory>
#include<fstream>
#include<map>
#include<set>
#include<sstream>
#include"StrVec.h"



using namespace std;
/*
这个类用来保存查询的文本以及各个出现的次数和行号
*/ 
class QueryResult;
class TextQuery
{
	friend class QueryResult;
  public:
  TextQuery()=default;
  TextQuery(istream &is);
  QueryResult query(const string &s);
  private:
  shared_ptr<StrVec> the_content;//文本的内容，逐行读取 
  shared_ptr<map<string,set<size_t>>> mapped; //单词对应的行号 
  shared_ptr<map<string,size_t>> word_num;
 };
 TextQuery::TextQuery(istream &is)
 {
 	string line;
 	size_t line_n= 0;
 		the_content = make_shared<StrVec>();
 		mapped = make_shared<map<string,set<size_t>>>();
 		word_num = make_shared<map<string,size_t>>();
 	while(getline(is,line))
 	{
 		
 		++line_n;
 	
 	the_content->push_back(line);
 	 istringstream iss(line);
 	 string word;
 	 while(iss>>word)
 	   {
		(*mapped)[word].insert(line_n);
 	   ++(*word_num)[word];
       }
   }
 }
 /*
 这个类是伴随类，用来返回特定单词的行号以及文本内容
 出现次数等
 */ 
class QueryResult
{
	public:
		QueryResult(const string &s,const TextQuery &TQ);
		void print(ostream &os)
		{
			os<<word<<" occurs "<<num<<(num>1?" times ":" time ")<<endl;
		    for(auto i:(*mapped)[word])
		      os<<"(line "<<i<<")"<<(*data)[i-1]<<endl;
		}
	private:
	  shared_ptr<StrVec> data;
	  shared_ptr<map<string,set<size_t>>> mapped;
       string word;
      size_t num;
};
QueryResult::QueryResult(const string &s,const TextQuery &TQ)
{
	word = s;
	data  = TQ.the_content;
	mapped = TQ.mapped;//连接到主类的指针上，达到数据共享 
	num = (*TQ.word_num)[s];
};
QueryResult TextQuery::query(const string &s)
{
	QueryResult QR(s,*this);
	return QR;
}
#endif
