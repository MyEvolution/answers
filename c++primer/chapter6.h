#ifndef CHAPTER_SIX
#define CHAPTER_SIX
#include<string>
using std::string;
int fact(int i);
int part();
void reset(int &i);
void swap(int &a,int &b);
void swap(int *a,int *b);
int is_upper(const string *);
int is_upper(const string *);
void to_lower(string &);
string (&function())[10];
typedef string array[10];//using array = string [10]
array &function();
auto function()-> string (&)[10];
string a[10];
decltype(a) &function();
#endif
 
