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
		   printf("��ӵڼ���λ�ö��뼸���ַ�\n");
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
int get(int fd,int pos,int n)//��posλ�ö�ȡn���ַ� 
{
	if(lseek(fd,pos,0)>=0)
	return read(fd,buf,n);
	else return -1;
	
}
