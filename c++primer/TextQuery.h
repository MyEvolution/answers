#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include<iostream>
#include<memory>
#include<fstream>
#include<map>
#include<set>
#include<sstream>
#include<vector>
#include<tuple>

using namespace std;

class QueryResult;
class TextQuery
{
	friend QueryResult;
public:
	TextQuery(istream &is);//从一个流中读取内容，并且用它来构建一个对象
	tuple<shared_ptr<vector<string>>,shared_ptr<set<size_t>>,string > Qquery(const string &s)const;
	QueryResult query(const string &s)const;
private:
	map<string, shared_ptr<set<size_t>>> mapped;
	shared_ptr<vector<string>> content;//把每一行都放在一个string里，而行号就是vector的下标（或者下标加1）
};
TextQuery::TextQuery(istream &is)
{
	string line;
	string key;
	content = shared_ptr<vector<string>>(new vector<string>());
	while (getline(is, line))
	{

		content->push_back(line);
		istringstream is(line);
		while (is >> key)
		{
			if (mapped.find(key)==mapped.end())
				mapped[key] =shared_ptr<set<size_t>>( new set<size_t>());//如果没有这个单词，需要建立一个空的set;
			mapped[key]->insert(content->size());
		}
	}
}
class QueryResult
{
	friend void print_result(ostream &os, const QueryResult & q);
public :
	QueryResult(const shared_ptr<vector<string>> &tq,const shared_ptr<set<size_t>> &tp, const string &s)
		:word(s) ,line_No(tp),line_content(tq){
			/*
			if(tq.mapped.find(s)!= tq.mapped.end())
			{
			   line_No = static_cast<TextQuery >(tq).mapped[s];//常量引用，不能使用[]运算符 
			}
			else  line_No = nullptr;*/
		}
private:

	shared_ptr<vector<string>> line_content;//与TextQuery共享文本的内容
	shared_ptr<set<size_t>> line_No;//本单词出现的行号
	string word;
	
};

tuple<shared_ptr<vector<string>>,shared_ptr<set<size_t>>,string> TextQuery::Qquery(const string &s)const
{
	return make_tuple(content,static_cast<map<string,shared_ptr<set<size_t>>>>(mapped)[s],s);
 } 
QueryResult TextQuery::query(const string &s)const
{
	auto  a = mapped.find(s);
	if(a == mapped.end())
	  return QueryResult(content,make_shared<set<size_t>>(new set<size_t>()),s);
	  else
	return QueryResult(content,a->second, s);
}

typedef tuple<shared_ptr<vector<string>>,shared_ptr<set<size_t>>,string>  tup;
void Print_result(ostream &os, const tup& q)
{
	os<<get<2>(q)<<" occurs "<<get<1>(q)->size()<<" time : "<<endl;
	for(auto i: *get<1>(q) )
	   os << "(" << i << "):" << (*get<0>(q))[i-1] << endl;
}
void print_result(ostream &os, const QueryResult & q)
{
	os << q.word << " occurs " << q.line_No->size() << " times : " << endl;
	for (auto i : *q.line_No)
		os << "(" << i << "):" << (*q.line_content)[i-1] << endl;
}
#endif
