#include<stdio.h>
#include<string.h>
char buf[BUFSIZ];
void cat(char *name)//把文件输出的屏幕 
{
	FILE *fp;
	int n;
	if(fp=fopen(name,"r"))
	{
		while(n=fread(buf,1,BUFSIZ,fp))
		fwrite(buf,1,n,stdout);
	}
	else fprintf(stderr,"error:cat can't open %s\n",name);
}
void printinfile(char *name1)
{
	printf("******************************%s*********************************\n",name1);
	cat(name1);
	char name[20];
	char _name[BUFSIZ];
	char *q;
	FILE *fp;
	int i;
	int j;
	if(fp=fopen(name1,"r"))
	while(fgets(buf,BUFSIZ,fp))//从文件中读取一行 
	{
		                
	   if((q=strstr(buf,"#include"))!=NULL&&*(q-1)!='"')
	   {
	   	
	   	q+=8;
	   	while(*q==' '||*q=='\t')
	   	      q++;
	   	     
	   	if(*q=='<')
	   	{
	   		i=0;
	   		q++;
	   		while(*q!='>')
	   		 name[i++]=*q++;
	   		 name[i]='\0';
	   		
		   }
		   else if(*q=='"')
		   {
		   	i=0;
	   		q++;
	   		while(*q!='"')
	   		 name[i++]=*q++;
	   		 name[i]='\0';	   	
		   }
	   
	   sprintf(_name,"include/%s",name);
	   printinfile(_name);
        }
        
        
	}
	else fprintf(stderr,"error:printinfile can't open %s\n",name);

}
main(int argc,char **argv)
{
	
	FILE *fp;
	char *q;
	int i;
	char name[20];
	char _name[BUFSIZ];
	if(argc==1)
	if(fp=fopen("1-4.cpp","r"))
	while(fgets(buf,BUFSIZ,fp))//从文件中读取一行 
	{
	  if((q=strstr(buf,"#include"))!=NULL&&*(q-1)!='"')
	   {
	   	
	   	q+=8;
	   	while(*q==' '||*q=='\t')
	   	      q++;
	   	if(*q=='<')
	   	{
	   		i=0;
	   		q++;
	   		while(*q!='>')
	   		 name[i++]=*q++;
	   		 name[i]='\0';
	   		
		   }
		   else if(*q=='"')
		   {
		   	i=0;
	   		q++;
	   		while(*q!='"')
	   		 name[i++]=*q++;
	   		 name[i]='\0';	   	
		   }
		sprintf(_name,"include/%s",name);
	   printinfile(_name); 
	   
	   }
	   
         
	}
	else fprintf(stderr,"fopen can not open 1-4.cpp");
	else 
	while(--argc>0)
	{
		if(fp=fopen(*++argv,"r"))
	while(fgets(buf,BUFSIZ,fp))//从文件中读取一行 
	{
		
	  if((q=strstr(buf,"#include"))!=NULL&&*(q-1)!='"')
	   {
	   	q+=8;
	   	while(*q==' '||*q=='\t')
	   	      q++;
	   	if(*q=='<')
	   	{
	   		i=0;
	   		q++;
	   		while(*q!='>')
	   		 name[i++]=*q++;
	   		 name[i]='\0';
	   		
		   }
		   else if(*q=='"')
		   {
		   	i=0;
	   		q++;
	   		while(*q!='"')
	   		 name[i++]=*q++;
	   		 name[i]='\0';	   	
		   }
		sprintf(_name,"include/%s",name);
	   printinfile(_name); 
	   
	   }
	   
         
	}
	else fprintf(stderr,"fopen can not open %s\n",*argv);
	}
}
