#include<stdio.h>
#include<string.h>
void swap(char *,int ,int );
void sort(char *,int ,int );
main()
{
	
	int c;
	char s[10];
	char *q=s;
	while((c=getchar())!=EOF)
	{
		if(c!='\n')
		*q++=c;
		else {
			*q='\0';
			sort(s,0,strlen(s)-1);
			printf("%s\n",s);
			q=&s[0];
		}
	 
	}
} 
void swap(char *s,int a,int b)
{
	
	char temp;
	temp=s[a];
	s[a]=s[b];
	s[b]=temp;
}
void sort(char *s,int left,int right)//¿ìËÙÅÅÐò 
{
	int last,i;
	if(left>=right) return;
	last=left;
	swap(s,left,(left+right)/2);
	for(i=left;i<=right;i++)
	if(s[i]<s[left])
	swap(s,++last,i);
	swap(s,left,last);
	sort(s,left,last);
	sort(s,last+1,right);
}