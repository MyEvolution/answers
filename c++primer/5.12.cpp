#include<iostream>
#include<string>

using namespace std;

const string str[]={"ff","fl","fi"};

int sfind(string s1,string s2);
int strfind(string s1);

int main()
{
	string word;
	int i_num=0,l_num=0,f_num=0;
	while(cin>>word)
	{
		int n=strfind(word);
		switch(n)
		{
			case 1:
				  ++f_num;
				  break;
			case 2:
				 ++l_num;
				 break;
			case 3:
				++f_num;
				++l_num;
				break;
			case 4:
				++i_num;
				break;
			case 5:
				++f_num;
				++i_num;
				break;
			case 6:
				++l_num;
				++i_num;
				break;
			case 7:
				++f_num,++i_num,++l_num;
				break;
			default:
				break;
		}
	}
	cout<<"fi:"<<i_num<<'\n'
	    <<"fl:"<<l_num<<'\n'
	    <<"ff:"<<f_num<<endl;
	    return 0;
}
int strfind(string s1)
{
	int i,j,q,m;
	i=sfind(s1,str[0]);
	j=( (m=sfind(s1,str[1]))?m+1:0);
	q=( (m=sfind(s1,str[2]))?m+3:0);
	return i+j+q;
	
}
int sfind(string s1,string s2)
{
	
	for(auto i=s1.begin();i!=s1.end()-s2.size()+1;++i)
	  {
	  	auto j=s2.begin();
	  	int n=s2.size();
	  	/*while(n)
	  	{
	  		if(*(i+s2.size()-n)!=*j++)//如果在这里添加n--的话 最后一个数是否符合都会使n变为0 
	  		                           //java中则无需担心  因为它可以用标签直接跳到最外层的循环 
	  		break;
	  		--n;
	    }*/
	    do
	    {
	    	if(*(i+s2.size()-n)!=*j++)
	    	break;
		}while(--n);
	    if(n==0)
		  return 1;
	  }
	  return 0;
}
