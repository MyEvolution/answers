#include<string>
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

ifstream& _read(ifstream &fs,string &s);
void get_word(ifstream &fs,vector<string> &s);
vector<string> _old;
vector<string> _new;
void invect(string &s,vector<string> &v1,vector<string> &v2);
int _replacestr(string::iterator begin,const string &oldstr,string::iterator end);


int main()
{
	string file1,file2,file3,file4;
	cin>>file1>>file2>>file3>>file4;
	string content;
  ifstream readin1(file1,fstream::in);
   ifstream readin2(file2,fstream::in);
   ifstream readin3(file3,fstream::in); 
   ofstream write(file4,fstream::out);
   get_word(readin1,_old);
   get_word(readin2,_new);
   while(getline(readin3,content))
   {
   
   invect(content,_old,_new);
   write<<content<<endl;  
    }
    return 0;
   
   
}

ifstream &_read(ifstream &fs,string &s)
{
	fs>>s;
	return fs;
}
void get_word(ifstream &fs,vector<string> &v)
{
	string s;
	while(_read(fs,s))
	  v.push_back(s);
}
int _replacestr(string::iterator begin,const string &oldstr,string::iterator end)
{
	auto sbegin = oldstr.begin(),send = oldstr.end();
      while(begin != end&&sbegin!=send&&*begin == *sbegin)
      {
      	++begin,++sbegin;
	  }

	  if(sbegin == send)
	  return 1;
	  return 0;
}
void invect(string &s,vector<string> &v1,vector<string> &v2)//对于每一个缩写都扩展成为原型 
{
	auto i = s.begin();
    while(i!=s.end())
    {
    	int pos = i - s.begin();
	
    for(int j = 0;j!=v1.size();++j)
    if(_replacestr(i,v1[j],s.end()))
       {
       	  
	   //s.replace(i,i+v1[j].size(),v2[j]);
	   //s.replace(pos,v1[j].size(),v2[j]);
	   
	   
	   s.erase(pos,v1[j].size());
	   s.insert(pos,v2[j]);

	   //这里迭代器会失效  要及时更新 
	     i = s.begin() -1 + pos + v2[j].size();
	     break;
       }
       
       ++i;
       
   }    
}
