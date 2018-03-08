#include<fcntl.h>
#include<unistd.h>//read,write
#include<stdlib.h>

#define EOF (-1)
#define BUFSIZ 1 
#define OPEN_MAX 20//一次最多打开这么多文件

typedef struct _iobuf
{
	int cnt;//剩余的字符
	char *ptr;//指向下一个字符 的指针
	char *base;//缓冲区的位置
	int flag;//访问的模式
	int fd;//文件描述符 
 } FILE;
 extern FILE _iob[OPEN_MAX];
 #define stdin (&_iob[0])//标准输入（连接键盘） 
 #define stdout (&_iob[1])//标准输出 （连接显示器） 
 #define stderr (&_iob[2])//标准错误 （连接显示器）

 
 enum _flags{
 	_READ =  01,//只读模式 
 	_WRITE = 02,//写 
 	_UNBUF = 04,//不为文件进行缓冲 
 	_EOF =  010,//到达文件结尾 
 	_ERR =  020,//该文件发生错误 
 }; 
  FILE _iob[OPEN_MAX]=
 {
 	{0,(char *)0,(char *)0,_READ,0},
 	{0,(char *)0,(char *)0,_WRITE,1},
 	{0,(char *)0,(char *)0,_READ|_WRITE,2}
 };
 int _fillbuf(FILE *);
 int _flushbuf(int ,FILE *);
 #define feof(p) (((p)->flag&_EOF)!=0)
 #define ferror(p) (((p)->flag&_ERR)!=0)
 #define fileno(p) ((p)->fd)
 #define getc(p) (--(p)->cnt>=0?(unsigned char)*(p)->ptr++: _fillbuf(p))//从文件p中读 
 #define putc(x,p) (--(p)->cnt>=0?*(p)->ptr++=(x):_flushbuf((x),p))  //把b输出到文件p        
 #define getchar() getc(stdin)
 #define putchar(x) putc((x),stdout)  
 #define PERMS 0666
  FILE *fopen(char *name,char *mode)
 {    
       FILE *fp;
       int fd;
 	if(*mode!='r'&&*mode!='a'&&*mode!='w')
 	  return NULL;
 	  for(fp=_iob;fp<_iob+OPEN_MAX;fp++)
 	  if((fp->flag&(_READ|_WRITE))==0)//寻找空闲位置(可打开的文件位置) 
 	    break;
 	    if(fp>=_iob+OPEN_MAX)//没有空闲位置 
 	    return NULL;
 	if(*mode=='r')
	   fd=open(name,O_RDONLY,0);
	  else if(*mode=='w')
	    fd=creat(name,PERMS); 
		else if(*mode=='a')//读写模式，无法读打开则创建 ,当可以读时把位置移到最后 
		{
			if((fd=open(name,O_RDONLY,0))==-1)
		         fd=creat(name,PERMS);
		         lseek(fd,0,2);
			
		 }
		 if(fd==-1)
		 return NULL;
		 fp->fd=fd;
		 fp->cnt=0;
		 fp->base=NULL;
		 fp->flag=((*mode=='r')?_READ:_WRITE);
		 return fp; 
 }
 int _fillbuf(FILE *fp)
 {
     int bufsize;
    if((fp->flag&(_READ|_WRITE|_ERR))!=_READ)
     return EOF;
     bufsize=(fp->flag&_UNBUF)?1:BUFSIZ;
   if(fp->base==NULL)
       if((fp->base=(char *)malloc(bufsize))==NULL)
    return EOF;
    fp->ptr=fp->base;
    fp->cnt=read(fp->fd,fp->ptr,bufsize);//如果文件大小不是 BUFSIZ的倍数，则对read的某次调用会返回一个较小的字节数，write再
	//按这个字节数写，此后在调用read将返回0； 
    
    if(--fp->cnt<0)//将cnt-1，因为已经返回了一个读入的字符 
    {
    	
    	if(fp->cnt==-1){
    		
    	fp->flag|=_EOF;//到结尾了 
		}
    	
    	else 
		
			fp->flag|=_ERR;//出错了 
			
    	fp->cnt=0;
    	return EOF;
		}
	
    return (unsigned char)*fp->ptr++;
     
 }
int _flushbuf(int c,FILE *fp)
 {
 	int num_written,bufsize;//实际写入的数目 
 	unsigned char uc=(unsigned char)c;
 	if(fp->base==NULL&&(fp->flag&_UNBUF)==0)
       if((fp->base=(char *)malloc(BUFSIZ))==NULL)//看是否到分配缓冲区 
 	        fp->flag|=_UNBUF;
 	        else 
			 {
			 	fp->ptr=fp->base;
			 	fp->cnt=BUFSIZ-1;
			  } 
			  if(fp->flag&_UNBUF)//mei有缓冲区 
			  {
			  	fp->cnt=0;
			  	num_written=write(fp->fd,&uc,1);
			  	bufsize=1;
			  	
			  	
			  }else {
			  	if(c!=EOF)
			  	*fp->ptr++=uc;
			  	bufsize=(int)(fp->ptr-fp->base);
			  	num_written=write(fp->fd,fp->base,bufsize);
			  	fp->ptr=fp->base;
			  	fp->cnt=BUFSIZ-1;//必要的 ，因为要做初始化 
			  	
			  }
			  if(num_written==bufsize)
			  return c;
			  else 
			  {
			  	fp->flag|=_ERR;
			  	return EOF;
			  }
			  
 }
 void filecopy(FILE*p,FILE*q)
 {
 	int c;
 	while((c=getc(p))!=EOF)
 	     putc(c,q);
 }
 int fflush(FILE *fp)//冲刷流 ,出现错误了返回-1 
{    
    int retval=0;
    int i;
	if(fp==NULL)
	for(i=0;i<OPEN_MAX;i++){
		if((_iob[i].flag&_WRITE)&&(fflush(&_iob[i])==-1))
	    retval==-1;
	}
	
	    else 
	    {
	    	if(fp->flag&_WRITE==0)
	    	retval=-1;
	    	_flushbuf(EOF,fp);
	    	if(fp->flag&_ERR)
	    	retval=-1;
		}
		return retval;
	
}
int fclose(FILE *fp)
{
	int fd;//文件描述符
	if(fp==NULL)
	return -1;
	fd=fp->fd;
	fflush(fp);
	fp->cnt=0;
	fp->flag=0;
	fp->ptr=NULL;
	if(fp->base!=NULL)
	fp->fd=-1;
	free(fp->base);
 return close(fd);
 } 
  int fseek(FILE *fp,long offset,int origin)
 {
 	if((fp->flag&_UNBUF)==0&&fp->base==NULL)//和缓冲区一起处理 
 	{
 		if(fp->flag&_READ==1)//是只读模式，则往缓冲流中的东西不影响移动,下一次读从新移动的字符读起而已 
 		{
 			fp->cnt=0;
 			fp->ptr=fp->base;
		 }
		 else if(fp->flag&_WRITE==1)//是只写模式  则把缓冲流内的东西写出 
		 	fflush(fp);
		 
	 }
	 return lseek(fp->fd,offset,origin);
 }
 	

 main(int argc, char **argv)
 {   
 int n;
 
 FILE *fp1,*fp2;
 if(argc==1)
 {
 	filecopy(stdin,stdout); 
 }
 else {
 	
 	fp1=fopen(argv[1],"r");
 	
 	
 	fp2=fopen(argv[2],"w");
 	 
    filecopy(fp1,fp2);
    
 	
 }

 
	}


 
 /*fillbuf
 与flusbuf设计思路：
 如果剩余字符为0，，则根据读写应用fill或者flush
 检查是否带缓冲区也就是（UNBUF），若带缓冲区 
并且base指向NULL，也就是没有分配缓冲区 
 则分配缓冲区。 
 缓冲区分配失败，fill返回eof，而flush则变为不带缓冲区模式，
 也就是将c输出到文件内，并且剩余字符为0.
 注意  如果fill分配失败则返回eof，这是因为如果至少有一个位置才能存放读取的字符。而分配失败则无法储存，
 而flush分配失败后，函数自带的x依然可以输入，只是没有缓冲区了而已。
 有缓冲区的好处是putc函数直接用缓冲区的指针复制即可，不用调用flush函数
 所以带不带缓冲区：除了刚开始主动选择，主要取决于向文件写入时是否分配到。 */
 /*flush的作用是缓冲区满了后，全部写入，所以cnt=BUFSIZ-1，就是为了给最后留一个空
 而fill则是将缓冲区填满，然后一个一个地读取*/ 
