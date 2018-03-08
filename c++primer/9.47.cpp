#include<iostream>
#include<string>

using namespace std;

int main()
{
	string number="0123456789";
	string alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	string s = "ab2c3d7R4E6";
	//因为s里除了数字就是字母  所以可以用find first not of 
	int pos = 0;
	while((pos = s.find_first_not_of(number,pos))!=string::npos)
	{
		cout<<"alp "<<s[pos]<<" in pos "<<pos<<endl;
		++pos;
	}
	pos = 0;
	while((pos = s.find_first_not_of(alphabet,pos))!=string::npos)
	{
		cout<<"num "<<s[pos]<<" in pos "<<pos<<endl;
		++pos;
	}
	return 0;
}
  
