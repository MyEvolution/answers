#include<iostream>
#include<stdexcept>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		try {
			if(!b)
			throw runtime_error("除数不能为0！");
		cout<<(double)a/b<<endl;
		
	}catch(runtime_error err)
	{
		cout<<err.what()<<
		"\n Try again?Enter Y or N"<<endl;
		char c;
		if(!(cin>>c)||c=='N')
		 break;
	}
	}
	return 0;
}
