#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char item1[]="What The";
	char item2[]=" FUck??";
	char item3[50];
	strcpy(item3,item1);
	strcat(item3,item2);
	cout<<item3<<endl;
	return 0;
}
