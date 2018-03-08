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
	TextQuery(istream &is);//��һ�����ж�ȡ���ݣ���������������һ������
	QueryResult query(const string &s)const;
private:
	map<string , shared_ptr<set<size_t>>> mapped;
	shared_ptr<vector<string>> content;//��ÿһ�ж�����һ��string����кž���vector���±꣨�����±��1��
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
				mapped[key] = shared_ptr<set<size_t>>(new set<size_t>());//���û��������ʣ���Ҫ����һ���յ�set;
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
			line_No = tq.mapped[s];//Ϊ��ʹ��mapped[]�����ԣ���
		                       
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

	shared_ptr<vector<string>> line_content ;//��TextQuery�����ı�������
	shared_ptr<set<size_t>> line_No;//�����ʳ��ֵ��к�
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

