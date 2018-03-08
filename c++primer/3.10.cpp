#include<iostream>
#include<string>
using std::cout;
using std::cin;using std::cout;using std::endl;
using std::string;
int main()
{
	string line;
  if(cin>>line)
  for(auto c:line)
  if(!ispunct(c))
  std::cout<<c;
  std::cout<<endl;
  return 0;
  
 } 
