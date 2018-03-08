#include<iostream>
#include<vector>
#include<string>
using namespace std; 
int main()
{
	string text{"what_the_Fuck! TMD!!\n"};
	for(decltype(text.begin()) it=text.begin();it!=text.end()&&!isspace(*it);
	  ++ it)
	  {
	  *it=toupper(*it);
	  cout<<*it;
      }
      cout<<endl;
      return 0;
}
