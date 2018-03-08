#include<stdio.h>
void p(char a[][3]);
int main()
{
	char a[3][3]={'1','2','3','4','5','\0','7','8','9'};

	printf("%s\n",a[1]);
	p(a);
	return 0;
	
}
void p(char a[][3])
{
	printf("%s",*++a);
}
