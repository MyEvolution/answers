int fflush(FILE *fp)//冲刷流 ,出现错误了返回-1 
{    
    int retval=0;
    int i;
	if(fp==NULL)
	for(i=0;i<OPEN_MAX;i++){
		if((_iob[i]->flag&_WRITE)&&(fflush(_iob[i])==-1))
	    retval==-1;
	}
	
	    else 
	    {
	    	if(fp->flag&_WRITE==0)
	    	retval=-1;
	    	_flushbuf(EOF,FILE*fp);
	    	if(fp->flag&_ERR)
	    	retval=-1
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
 		if(f->flag&_READ==1)//是只读模式，则往缓冲流中的东西不影响移动,下一次读从新移动的字符读起而已 
 		{
 			fp->cnt=0;
 			fp->ptr=fp->base;
		 }
		 else if(fp->flag&_WRITE==1)//是只写模式  则把缓冲流内的东西写出 
		 	fflush(fp);
		 
	 }
	 return lseek(fp->fd,offset,origin);
 }
