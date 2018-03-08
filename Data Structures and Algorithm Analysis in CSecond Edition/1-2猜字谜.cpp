#include<stdio.h>
#include<string.h>
void reverse(char *q);
void search(char *b,char **q);
char *q[10]={"are","baby","cat","dog","eat","fat","good","that","this","two"};
main()
{
	printf("请输入正方形字符矩阵，字符间用空格隔开，\n每行用回车结束，输入结束后输入EOF表示结束：\n");
	char a[10][10];
	char b[10];
	int j=0,i=0;
	int n;
   char d; 
	  int c;
	while((c=getchar())!=EOF)
	{
		d=getchar();//是否该换下一行 
		 a[i][j++]=c;
	  if(d=='\n')
		{
			a[i][j]='\0';
			i++,j=0;
		}
	}
	n=i;//记录行列数 
	for(i=0;i<n;i++)//横向查找 
	{
		strcpy(b,a[i]);
	    search(b,q);
		reverse(b);
		search(b,q);	  
	}
	for(i=0;i<n;i++)//纵向查找 
	{
		for(j=0;j<n;j++)
		b[j]=a[j][i];
		b[j]='\0';
		search(b,q);
		reverse(b);
		search(b,q);
	}
	for(i=0;i<n-1;i++)//左对角线查找 
	{
		if(i==0){
		for(j=0;j<n;j++)
			b[j]=a[j][j];
			b[j]='\0';
	    search(b,q);
		reverse(b);
		search(b,q);
		}
		 
		else
		{
			for(j=0;j<n-i;j++)
			b[j]=a[j][i+j];
		b[j]='\0';
	    search(b,q);
		reverse(b);
		search(b,q);
		for(j=0;j<n-i;j++)
		  b[j]=a[i+j][j]; 
		 b[j]='\0';
	    search(b,q);
		reverse(b);
		search(b,q);	
		}

	}
   for(i=0;i<n-1;i++)//右对角线查找 
   {
   	if(i==0){
   	for(j=0;j<n;j++)
    b[j]=a[j][n-j-1];
    	b[j]='\0';
	    search(b,q);
		reverse(b);
		search(b,q);
	   }
	   else
	   {
	   	for(j=0;j<n-i;j++)
	     b[j]=a[j][n-i-1-j];
	      b[j]='\0';
	    search(b,q);
		reverse(b);
		search(b,q);
		for(j=0;j<n-i;j++)
		  b[j]=a[i+j][n-1-j];
		 b[j]='\0';
	    search(b,q);
		reverse(b);
		search(b,q);
	     
	   }

   }
	
 } 
void search(char *b,char **q)
 {
 	int i;
 	for(i=0;i<10;i++)
    if(strstr(b,q[i])!=NULL)
       printf("%s\n",q[i]);
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
