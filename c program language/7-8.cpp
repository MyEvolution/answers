#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINE 1000
void filecopy(FILE *,FILE *);
main(int argc,char **argv)
{
	 char line[MAXLINE];
	 int i=1;
	 FILE *fp;
	if(argc==1)
	printf("û���ļ�!\n");
	/*else {
		while(--argc>0)
		{     
			if(fp=fopen(*++argv,"r")){
				 printf("                 *********************%s**********************\n",*argv);
				while(fgets(line,MAXLINE,fp))
				printf("%s\n",line);
			
				printf("                                                                       %d",i++);
				putchar('\f');
				
				
				
			}
			else printf("can't open %s\n",*argv);
		}
	}*/
	else {
		while(--argc>0)
		{
			if(fp=fopen(*++argv,"r"))
			{
				 printf("                 *********************%s**********************\n",*argv);
				filecopy(fp,stdout);
				fclose(fp);
				
				printf("\n                                                                       %d",i++);
				putchar('\f');
				putchar('\n');
			}
			else {
			printf("can't open %s\n",*argv);
			
			}
		}
	}
}
void filecopy(FILE *p,FILE *q)//���ļ�pд���ļ�q�� 
{
             int c;
	while((c=getc(p))!=EOF)//getc����ָ�����һ���ַ� 
	  putc(c,q);//��c������ļ�q�� 
}
