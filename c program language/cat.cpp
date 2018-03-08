#include<stdio.h>
#include<stdlib.h>
#define getchar() getc(stdin)
#define putchar(c) putc((c),stdout)
void filecopy(FILE *,FILE*); 
/*main(int argc,char **argv)//版本1，错误的诊断信息要在该连接的输出的末尾才能打印 
{
	  FILE *fp;//文件指针 
	if(argc==1)//无参数,复制标准输入 
	{
		filecopy(stdin,stdout);//stdout标准输出stdin标准输入 
		 
		 
	}
	else
	  while(--argc>0)
	    if((fp=fopen(*++argv,"r"))==NULL){
	    	printf("cat:can't open %s\n",*argv);
		} else{
			filecopy(fp,stdout);
			fclose(fp);
		}
		return 0;
}*/
main(int argc,char **argv)
{
	  
	FILE *fp;
	char *p=argv[0];
	if(argc==1)
	filecopy(stdin,stdout);
	else 
	while(--argc>0)
	{
		if((fp=fopen(*++argv,"r"))==NULL)
		{
			fprintf(stderr,"%s can't open %s\n",p,*argv);
			exit(1);
		}else {
			filecopy(fp,stdout);
			fclose(fp);
		}
	}
	if(ferror(stdout)){
		fprintf(stderr,"%s:error writing stdout\n",p);
		exit(2);
	}
	exit(0);
}

void filecopy(FILE *p,FILE *q)//把文件p写进文件q内 
{
	int c;
	while((c=getc(p))!=EOF)//getc返回指针的下一个字符 
	  putc(c,q);//把c输出到文件q内 
}
