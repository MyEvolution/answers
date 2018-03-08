#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
void filecopy(int from,int to);
main(int argc,char **argv)
{
	int f1;
	if(argc==1)
	
	filecopy(0,1);
	else
	  while(--argc>0)
	  {
	  	while((f1=open(*++argv,O_RDONLY))>0)
  		filecopy(f1,1);
  	}
}
void filecopy(int from,int to)
{
	char *buf;
	buf=(char *)malloc(BUFSIZ);
	int n;
	while((n=read(from,buf,BUFSIZ))>0)
	write(1,buf,n);
	close(from);
}