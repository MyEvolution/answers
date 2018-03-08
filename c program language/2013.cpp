#include<stdio.h>
int num(int );
main()
{
	int day;
	while(scanf("%d",&day)!=EOF)
	printf("%d\n",num(day));
} 
int num(int day)
{
	if(day==1)
	return 1;
	else return (num(day-1)+1)*2;
}