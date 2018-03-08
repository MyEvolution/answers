#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>
#include<stdlib.h>
#include<time.h>
#define MAXNAME 1024
void dirwalk(char *,void(*fcn)(char *));
void fsize(char *);
main(int argc,char **argv)
{
	if(argc==1)
	fsize(".");
	else 
	while(--argc>0)
	fsize(*++argv);
	
}
void fsize(char *name)
{
	struct stat stbuf;
	struct tm *p;
	char *wday[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
	if(stat(name,&stbuf)==-1){
	fprintf(stderr,"fsize: can't access %s\n",name);
	return ;
	}
	else 
	{
		if((stbuf.st_mode&S_IFMT)==S_IFDIR)
		dirwalk(name,fsize);
		p=localtime(&stbuf.st_atime);
	     printf("last visit time:%4d/%2d/%2d %s %2d:%2d:%2d %6dB %s\n",(1900+p->tm_year),(p->tm_mon+1),p->tm_mday,
		 wday[p->tm_wday],p->tm_hour,p->tm_min,p->tm_sec,stbuf.st_size,name);
	/*time_h是从1900年到现在的秒数，所以月数加1，年数加1900*/ 
	}
	
}
void dirwalk(char *dirname,void(*fcn)(char *))//??????????е???? 
{
	DIR *dp;
	struct dirent *dfd;
	char name[MAXNAME];//??·?? 
	if((dp=opendir(dirname))==NULL)
	{
		fprintf(stderr,"dirwalk:can't open %s\n",dirname);
		return ;
	}
	
		
		while((dfd=readdir(dp))!=NULL){
		if(strcmp(dfd->d_name,".")==0||strcmp(dfd->d_name,"..")==0)//??????????????
		continue;
		if(strlen(dirname)+strlen(dfd->d_name)+2>sizeof(name))
		fprintf(stderr,"name %s/%s too long!\n",dirname,dfd->d_name);
		else 
		{
		sprintf(name,"%s/%s",dirname,dfd->d_name);
		(*fcn)(name);
		}
		
		 
	}
	closedir(dp);
}