#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char buf[100]; 
	FILE *fp;
	fp=fopen("b.txt","r+");
	fgets(buf,100,fp);
      fseek(fp,0,SEEK_CUR);
	                 fprintf(fp,"�Ź���\n");
	       fputs("woshizhangguoq",fp);
	        return 0;
}
