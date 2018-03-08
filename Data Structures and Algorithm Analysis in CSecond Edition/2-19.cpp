#include<stdio.h>
#include<stdlib.h>

int majore(int *num,int n)
{
	int i;
static int *b=(int *)malloc(n*sizeof(int));//À∆∫ıŒﬁ∑® Õ∑≈ 
	int j=0;
	int m;
	int p=0;
	if(n<=2)
	 return num[0];
	for(i=0;i<n;i++)
	b[i]=num[i];
	
	for(i=0;i+1<n;i+=2)
	if(b[i]==b[i+1])
	  num[j++]=b[i];
	  
	  if((n&1)&&(j%2==0))
	  num[j++]=b[n-1];
	   m=majore(num,j);
	 for(i=0;i<n;i++)
	  if(m==b[i])
	    p++;  
	if(p>n/2)
	return m;
	else return '\0';
}
main()
{
	int a[100];
	int n; 
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf(majore(a,n)=='\0'?"no major element!\n":"%d\n",majore(a,n));
 } 
