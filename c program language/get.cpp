#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
char buf[BUFSIZ];
int get(int ,int ,int );
main(int argc,char **argv){
	int fd;
	int pos;
	int n,m;
	
	if(argc==1)
	while(( m=get(0,0,BUFSIZ))>0)
		write(1,buf,m);
	
	
		
	else {
		
		while(--argc>0)
		{      
		   printf("想从第几个位置读入几个字符\n");
		   scanf("%d %d",&pos,&n);
		   
			if((fd=open(*++argv,O_RDONLY))>=0)
			{
				m=get(fd,pos,n);
				write(1,buf,m);
				putchar('\n');
				close(fd);
			}
			else fprintf(stderr,"can't open %s\n",*argv);
		}
	}
	
}
int get(int fd,int pos,int n)//从pos位置读取n个字符 
{
	if(lseek(fd,pos,0)>=0)
	return read(fd,buf,n);
	else return -1;
	
}
