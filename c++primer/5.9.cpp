#include<iostream>
using namespace std;
int main()
{
	int a_num=0,e_num=0,i_num=0,o_num=0,u_num=0;
	char word;
	while(cin>>word)
	{
		switch(word)
		{
			case 'a':
				case 'A': 
				a_num++;
				break;
			case 'e':
			case 'E':
			e_num++;
			break;
			case 'i':
			case 'I':
			i_num++;
			break;
			case 'o':
			case 'O':
			++o_num;
			break;
			case 'u':
			case 'U':
			++u_num;
			break;
			default:
			break;	
		}
	}
	cout<<"a:"<<a_num<<'\n'
	    <<"i:"<<i_num<<'\n'
	    <<"e:"<<e_num<<'\n'
	    <<"o:"<<o_num<<'\n'
	    <<"u:"<<u_num<<endl;
	    return 0;
}
