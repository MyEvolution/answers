int fflush(FILE *fp)//��ˢ�� ,���ִ����˷���-1 
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
 		if(f->flag&_READ==1)//��ֻ��ģʽ�������������еĶ�����Ӱ���ƶ�,��һ�ζ������ƶ����ַ�������� 
 		{
 			fp->cnt=0;
 			fp->ptr=fp->base;
		 }
		 else if(fp->flag&_WRITE==1)//��ֻдģʽ  ��ѻ������ڵĶ���д�� 
		 	fflush(fp);
		 
	 }
	 return lseek(fp->fd,offset,origin);
 }
