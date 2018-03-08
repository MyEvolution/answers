#include<iostream>
#include<vector>
#include<string>
#include<iterator>

using namespace std;

class Chk_len
{
	public:
		Chk_len(size_t s):num(s){}
		bool operator()(const string &s)
		{
			return num == s.size();
		}
    private:
 size_t num;
 };
 class chk_len
 {
 	public :
	 chk_len(size_t s):num(s){}
 	bool operator()(const string &s)const
 	{
 		return !(num>s.size());
	 }
	 private:
	 	size_t num;
 };
 int main()
 {
 	istream_iterator<string> begin(cin),eof; 
 	vector<string> v(begin,eof);
 	for(size_t i = 1;i<=10; ++i)
 	{
 		Chk_len cl(i);
 		size_t n = 0;
 		for(auto j:v)
 		if(cl(j))
        {
		++n;
		break;//找到长度就不用检查后面的了
	    }
		cout<<"length is "<<i<<" : "<<n<<endl;	
	 }
	 size_t n = 0;
	 for(auto j:v)
	 if(chk_len(10)(j))
	 ++n;
	   cout<<"length more than 10 : "<<n<<endl;
	   cout<<"length less than 10 : "<<v.size()-n<<endl;
	 return 0;
 }
