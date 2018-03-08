#include<fcntl.h>
#include<unistd.h>//read,write
#include<stdlib.h>

#define EOF (-1)
#define BUFSIZ 1 
#define OPEN_MAX 20//һ��������ô���ļ�

typedef struct _iobuf
{
	int cnt;//ʣ����ַ�
	char *ptr;//ָ����һ���ַ� ��ָ��
	char *base;//��������λ��
	int flag;//���ʵ�ģʽ
	int fd;//�ļ������� 
 } FILE;
 extern FILE _iob[OPEN_MAX];
 #define stdin (&_iob[0])//��׼���루���Ӽ��̣� 
 #define stdout (&_iob[1])//��׼��� ��������ʾ���� 
 #define stderr (&_iob[2])//��׼���� ��������ʾ����

 
 enum _flags{
 	_READ =  01,//ֻ��ģʽ 
 	_WRITE = 02,//д 
 	_UNBUF = 04,//��Ϊ�ļ����л��� 
 	_EOF =  010,//�����ļ���β 
 	_ERR =  020,//���ļ��������� 
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
 #define getc(p) (--(p)->cnt>=0?(unsigned char)*(p)->ptr++: _fillbuf(p))//���ļ�p�ж� 
 #define putc(x,p) (--(p)->cnt>=0?*(p)->ptr++=(x):_flushbuf((x),p))  //��b������ļ�p        
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
 	  if((fp->flag&(_READ|_WRITE))==0)//Ѱ�ҿ���λ��(�ɴ򿪵��ļ�λ��) 
 	    break;
 	    if(fp>=_iob+OPEN_MAX)//û�п���λ�� 
 	    return NULL;
 	if(*mode=='r')
	   fd=open(name,O_RDONLY,0);
	  else if(*mode=='w')
	    fd=creat(name,PERMS); 
		else if(*mode=='a')//��дģʽ���޷������򴴽� ,�����Զ�ʱ��λ���Ƶ���� 
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
    fp->cnt=read(fp->fd,fp->ptr,bufsize);//����ļ���С���� BUFSIZ�ı��������read��ĳ�ε��û᷵��һ����С���ֽ�����write��
	//������ֽ���д���˺��ڵ���read������0�� 
    
    if(--fp->cnt<0)//��cnt-1����Ϊ�Ѿ�������һ��������ַ� 
    {
    	
    	if(fp->cnt==-1){
    		
    	fp->flag|=_EOF;//����β�� 
		}
    	
    	else 
		
			fp->flag|=_ERR;//������ 
			
    	fp->cnt=0;
    	return EOF;
		}
	
    return (unsigned char)*fp->ptr++;
     
 }
int _flushbuf(int c,FILE *fp)
 {
 	int num_written,bufsize;//ʵ��д�����Ŀ 
 	unsigned char uc=(unsigned char)c;
 	if(fp->base==NULL&&(fp->flag&_UNBUF)==0)
       if((fp->base=(char *)malloc(BUFSIZ))==NULL)//���Ƿ񵽷��仺���� 
 	        fp->flag|=_UNBUF;
 	        else 
			 {
			 	fp->ptr=fp->base;
			 	fp->cnt=BUFSIZ-1;
			  } 
			  if(fp->flag&_UNBUF)//mei�л����� 
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
			  	fp->cnt=BUFSIZ-1;//��Ҫ�� ����ΪҪ����ʼ�� 
			  	
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
 int fflush(FILE *fp)//��ˢ�� ,���ִ����˷���-1 
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
	int fd;//�ļ�������
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
 	if((fp->flag&_UNBUF)==0&&fp->base==NULL)//�ͻ�����һ���� 
 	{
 		if(fp->flag&_READ==1)//��ֻ��ģʽ�������������еĶ�����Ӱ���ƶ�,��һ�ζ������ƶ����ַ�������� 
 		{
 			fp->cnt=0;
 			fp->ptr=fp->base;
		 }
		 else if(fp->flag&_WRITE==1)//��ֻдģʽ  ��ѻ������ڵĶ���д�� 
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
 ��flusbuf���˼·��
 ���ʣ���ַ�Ϊ0��������ݶ�дӦ��fill����flush
 ����Ƿ��������Ҳ���ǣ�UNBUF�������������� 
����baseָ��NULL��Ҳ����û�з��仺���� 
 ����仺������ 
 ����������ʧ�ܣ�fill����eof����flush���Ϊ����������ģʽ��
 Ҳ���ǽ�c������ļ��ڣ�����ʣ���ַ�Ϊ0.
 ע��  ���fill����ʧ���򷵻�eof��������Ϊ���������һ��λ�ò��ܴ�Ŷ�ȡ���ַ���������ʧ�����޷����棬
 ��flush����ʧ�ܺ󣬺����Դ���x��Ȼ�������룬ֻ��û�л������˶��ѡ�
 �л������ĺô���putc����ֱ���û�������ָ�븴�Ƽ��ɣ����õ���flush����
 ���Դ����������������˸տ�ʼ����ѡ����Ҫȡ�������ļ�д��ʱ�Ƿ���䵽�� */
 /*flush�������ǻ��������˺�ȫ��д�룬����cnt=BUFSIZ-1������Ϊ�˸������һ����
 ��fill���ǽ�������������Ȼ��һ��һ���ض�ȡ*/ 
