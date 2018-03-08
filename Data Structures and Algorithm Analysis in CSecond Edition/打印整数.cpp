#include<stdio.h>
void printfDigit(int a)
{
	if(a>=0&&a<10)
	printf("%d",a);
}
void printfOut(int n)
{
	if(n>=10)
	  printfOut(n/10);
	  printfDigit(n%10);
}
main()
{
	int a;
	scanf("%d",&a);
	printfOut(a);
}
