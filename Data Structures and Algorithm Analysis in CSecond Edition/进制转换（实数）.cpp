#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXSIZE 100
void reverse(char *);
double dis(double );
void itoten(char *,int ,int );
void dtoten(char *,int ,int );
main()
{
	printf("==============================================\n");
	printf("||*             ~~~~~~~~~~~~~~             *||\n");
	printf("||*             | 进制转换器 |             *||\n");
	printf("||*             ~~~~~~~~~~~~~~             *||\n");
	printf("==============================================\n");
	char num[MAXSIZE];
	char integer[MAXSIZE];
	char decimal[MAXSIZE];
	char *q;
	int n,i;
	int m;
	printf("输入转化前的进制数：\n");
	scanf("%d",&m); 
	printf("输入转化后的进制数：\n");
	scanf("%d",&n);
	getchar();
	
	while(printf("请输入正确的%d进制数（支持浮点数，若小数位数过长最多保留20位）：\n",m)&&scanf("%s",num)!=EOF)
	{
		getchar();
		q=num;
		i=0;
		while(*q!='.'&&*q!='\0')
	         integer[i++]=*q++;
	         integer[i]='\0';
	         itoten(integer,m,n);
	         
	    if(*q=='.')
	    {
	    	q++;
	    	i=0;
	    	while(*q!='\0')
	    	  decimal[i++]=*q++;
	    	  decimal[i]='\0';
	    	  dtoten(decimal,m,n);
	    	  sprintf(num,"%s.%s",integer,decimal);
		}
		else sprintf(num,"%s",integer);
		printf("转化为%d进制数后为：\n",n);
		printf("%s\n",num);
	}
 }
void itoten(char *num,int n,int m)
{
	int i=0;
	int n1;
	int f=1;
	int l=strlen(num)-1;
	char *p;
	
	n1=0;
	
	while(num[i]==' '||num[i]=='\t')
	              i++;
	    if(num[i]=='-') i++,f=-1;
	    else if(num[i]=='+') i++;
	for(i;i<=l;i++)
	n1=n1*n+(num[i]>'9'?num[i]-'a'+10:num[i]-'0');
	p=num;
	   	do
 	{
 	   if(n1%m<10)
 	     *p++=n1%m+'0';
 	     else *p++=n1%m-10+'a';
 	     n1/=m;
 	     
	 }while(n1!=0);
	 if(f<0) *p++='-';
	 *p='\0';
	 reverse(num);
	
}
void dtoten(char *num,int n,int m)
{
	int i;
	double a;
	a=0;
	char *p;
	int b;
	for(i=strlen(num)-1;i>=0;i--)
	 a=a/n+(num[i]>'9'?num[i]-'a'+10:num[i]-'0');
	 a/=n;
	 i=0;
	 p=num;
    while(i<20&&a!=0.0) 
    {
    	b=(int)(a*=m);
    	*p++=(b>9?b-10+'a':b+'0');
    	a=dis(a);
    	i++;
	}
	*p='\0';

}
  double dis(double n)//小数点和整数分离 
{
	return n-(int)n;
}
void reverse(char *q)
{
	char *p=q;
	char temp;
	while(*(p+1)!='\0')
	p++;
	while(p>=q)
	{
		temp=*p;
		*p=*q;
		*q=temp;
		q++,p--;
	}
}
