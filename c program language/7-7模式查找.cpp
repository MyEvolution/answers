#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINE 1000 
int getline(char *,int);
int lookup(char *,char *);//����ģʽ 
main(int argc,char *argv[])
{
	char stencil[100];//ģʽ
	char line[MAXLINE];
	char *name;//ָ���ļ������� 
	int i=1;//�к� 
	FILE *fp;
	scanf("%s",stencil);

	getchar();
	if(argc==1)
	{
		while(getline(line,MAXLINE)>0){
			if(lookup(line,stencil)==NULL)
		 printf("%d:%s",i,line);
		 i++;
		}
		
	}else {
		while(--argc>0)
		{   
			if((fp=fopen(*++argv,"r"))!=NULL)
			{    i=1;
				
				while(fgets(line,MAXLINE,fp)){
				
				if(lookup(line,stencil)==0)
				printf("%s��%d�У�\n%s\n",*argv,i,line);
				i++;
				}
			}
			else printf("can't open %s\n",*argv); 
			
		}
	}
  system("date");	 
}
int getline(char *s,int n)
{
	if(fgets(s,n,stdin)==NULL)
	return 0;
	else return strlen(s);
}
int lookup(char *s,char *p)
{
	char *q;
	 for(q=p;*s!='\0';s++)
	  if(*q==*s){
	  
	  while(*q!='\0')
	   if(*q++!=*s++){
	   	
	   	s-=q-p;
	   	q=p;
	   	break;
	   }
	   if(*q=='\0') return 0;
	   }
	  
	   
	if(*s=='\0')
	return 1;   
}
