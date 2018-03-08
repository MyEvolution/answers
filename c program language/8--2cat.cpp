#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
main(int argc,char **argv)
{    int n;
    char buf[BUFSIZ];
     int f1;
	if(argc==1)
	
		while((n=read(0,buf,BUFSIZ))>0)
		write(1,buf,n);
	else  
	   while(--argc>0)
	   {
   		if((f1=open(*++argv,O_RDONLY))!=-1)
   		while((n=read(f1,buf,BUFSIZ))>0)
   		write(1,buf,n);
   	else write(2,"error!",6); 
   	}
} 
