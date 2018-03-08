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
	printf("没有文件!\n");
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
void filecopy(FILE *p,FILE *q)//把文件p写进文件q内 
{
             int c;
	while((c=getc(p))!=EOF)//getc返回指针的下一个字符 
	  putc(c,q);//把c输出到文件q内 
}
