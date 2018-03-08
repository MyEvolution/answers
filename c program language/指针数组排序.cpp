#include<stdio.h>
#include<string.h>
#define MAXLINES 5000
#define MAXLEN 1000
#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char *allocp=allocbuf;
char *lineptr[MAXLINES];
int readerlines(char *lineptr[],int nlines,char *buf);
char * alloc(int n);
void qsort(char *lineptr[],int left,int right);
char *alloc(int n);
void afree(char *p);
void writelines(char *lineptr[],int nlines);
int getline(char *line,int len);
main(){
	char buf[ALLOCSIZE];
int nlines;
      if((nlines=readerlines(lineptr,MAXLINES,buf))>=0){
	        	  qsort(lineptr,0,nlines-1);
		  writelines(lineptr,nlines);
		   	
	
		    return 0;
			}
		else{
			printf("ERROR:input too big to sort\n");
			return 1;
		}	
	
} 
/*int readerlines(char *lineptr[],int maxlines){
	int len,nlines;
	char line[MAXLEN];
	char *p;
	  nlines=0;
	  while((len=getline(line,MAXLEN))>0){
	  	    
	  	if(nlines>=maxlines||((p=alloc(len))==NULL))
	  	   return -1;
	  	else  {
	  		
	  	line[len-1]='\0';
	  		strcpy(p,line);//复制line到p 
		 lineptr[nlines++]=p;
	
		  
		    }
	  }

	  return nlines;}*/
	  int readerlines(char *lineptr[],int maxlines,char *a){
	  	int len,nlines;
	  	static int i;//记录长度 
	  	char line[MAXLEN];
	  	i=0;
	  	nlines=0;
	//随着指针变化所谓的a[i]已经不是原来的a[i] 
	  	while((len=getline(line,MAXLEN))>0){
	  	
	  		if(nlines>MAXLINES||(i+len)>=ALLOCSIZE)
	  		   return -1;
	  		strcat(a,line);
	  		lineptr[nlines++]=a;
	  		i+=len;
	  	    a[len-1]='\0';
	  		a+=len;
       
	  	
		  }
	
		  return nlines;
	 
	  }
char *alloc(int n)
{
	if(allocbuf+ALLOCSIZE-allocp>n){

	     allocp+=n;
	    return allocp-n;
	}
	else return NULL;
}

void writelines(char *lineptr[],int nlines){
	int i=0;
	while(i<nlines){
		printf("%s\n",lineptr[i++]);
	
	}
}
void swap(char*v[],int i,int j);
void qsort(char *lineptr[],int left,int right){//快速排序 
	int i,last;
	if(left>=right) return;
	swap(lineptr,left,(left+right)/2);
      last=left;
      for(i=left+1;i<=right;i++)
     if(*lineptr[i]<*lineptr[left])
          swap(lineptr,++last,i);
       swap(lineptr,last,left);
	   qsort(lineptr,left,last);
	   qsort(lineptr,last+1,right);   

	 

}
void swap(char*v[],int i,int j){
	char *temp;
	temp=v[i];
	v[i]=v[j];
	v[j]=temp;
}
int getline(char *line,int maxlen){
	int c;
	char *p=line;
while((c=getchar())!=EOF&&c!='\n'&&(line-p)<maxlen){
		*line++=c;
		*line='\0';
	}
    if(c=='\n')   {

	*line++='\n';
           *line='\0';
   }
	return line-p;

}
