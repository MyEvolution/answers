#include<stdio.h>
#include<stdlib.h>
#define getchar() getc(stdin)
#define putchar(c) putc((c),stdout)
void filecopy(FILE *,FILE*); 
/*main(int argc,char **argv)//�汾1������������ϢҪ�ڸ����ӵ������ĩβ���ܴ�ӡ 
{
	  FILE *fp;//�ļ�ָ�� 
	if(argc==1)//�޲���,���Ʊ�׼���� 
	{
		filecopy(stdin,stdout);//stdout��׼���stdin��׼���� 
		 
		 
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

void filecopy(FILE *p,FILE *q)//���ļ�pд���ļ�q�� 
{
	int c;
	while((c=getc(p))!=EOF)//getc����ָ�����һ���ַ� 
	  putc(c,q);//��c������ļ�q�� 
}
