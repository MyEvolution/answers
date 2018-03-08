#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class ScanfString
{
	public :
		ScanfString(istream &o):is(o){}
		void operator()(vector<string> &v)
		   {
		   	string line;
		      while(getline(is,line))
		      v.push_back(line);
		   }
	private:
		istream &is;
 };

class If_else_then
{
	public:
		int operator()(int a,int b,int c)
		{
			if(a)
			return b;
			else return c;
		}
};
class _compare
{
	public:
		_compare(int a):v(a){}
		bool operator()(int i)
		{
			return i == v;
		}
		private:
			int v;
};
int main()
{
	ScanfString ss(cin);
	vector<string> v;
	If_else_then i;
	 ss(v);
	 for(auto i:v)
	 cout<<i<<endl;
	cout<<i(1,2,3);
	vector<int> iv{1,5,3,9,6,2,4,1,2,1};
	replace_if(iv.begin(),iv.end(),_compare(1),100);
	for(auto i:iv)
	cout<<i<<" ";
	return 0;
}
