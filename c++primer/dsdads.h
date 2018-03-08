#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include<iostream>
#include<memory>
#include<fstream>
#include<map>
#include<set>
#include<sstream>
#include<vector>

using namespace std;

class QueryResult;
class TextQuery
{
	friend class QueryResult;
	
public:
	typedef size_t line_no;
	TextQuery(istream &is);//从一个流中读取内容，并且用它来构建一个对象
	QueryResult query(const string &s)const;
private:
	map<string , shared_ptr<set<size_t>>> mapped;
	shared_ptr<vector<string>> content;//把每一行都放在一个string里，而行号就是vector的下标（或者下标加1）
};
TextQuery::TextQuery(istream &is)
{
	string line;
	string key;
	content =shared_ptr<vector<string>>( new vector<string>());
	while (getline(is, line))
	{

		content->push_back(line);
		istringstream is(line);
		while (is >> key)
		{
			if (mapped.find(key) == mapped.end())
				mapped[key] = shared_ptr<set<size_t>>(new set<size_t>());//如果没有这个单词，需要建立一个空的set;
			mapped[key]->insert(content->size());
		}
	}
}
class QueryResult
{
	friend void print_result(ostream &os, const QueryResult & q);
public:

	QueryResult(const TextQuery &tq, const string &s):word(s),line_content(tq.content)
	{
		//string a = "haha";
		if (tq.mapped.find(s) == tq.mapped.end())
		{
			line_No = shared_ptr<set<size_t>>(new set<size_t>());
		}
		else
			line_No = tq.mapped[s];//为何使用mapped[]不可以？？
		                       
	}
	QueryResult(const string &s,shared_ptr<set<size_t>> p,shared_ptr<vector<string>> v):word(s),line_No(p),line_content(v){}
	set<size_t>::const_iterator begin()const
	{
		return line_No->begin();
	}
	set<size_t>::const_iterator end()const
	{
		return line_No->end();
	}
	shared_ptr<vector<string>> get_file()const
	{
		return line_content;
	}
	QueryResult() = default;
private:

	shared_ptr<vector<string>> line_content ;//与TextQuery共享文本的内容
	shared_ptr<set<size_t>> line_No;//本单词出现的行号
	string word;
};

QueryResult TextQuery::query(const string &s)const
{
	return QueryResult(*this, s);
}
void print_result(ostream &os, const QueryResult & q)
{
	os << q.word << " occurs " << q.line_No->size() << " times : " << endl;
	for (auto i : *q.line_No)
		os << "(" << i << "):" << (*q.line_content)[i - 1] << endl;
}
#endif

