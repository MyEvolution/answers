#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dir.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/stat.h>
#define NAME_MAX 14
#ifndef DIRSIZ 
#define DIRSIZ 14
#endif
#define MAX_PATH 1024 

struct direct
{
	ino_t d_ino;//目录的i结点 
	char d_name[DIRSIZ];//目录中的名字 
};
void fsize(char *s);//?????????? 
void dirwalk(char *s,void(*fcn)(char *));
typedef struct
{
	long ino;//i?????
	char name[NAME_MAX+1];//???????'\0' 
}Dirent;
typedef struct 
{
	int fd;//?????????
	Dirent d;//???? 
}DIR;//????? 


main(int argc,char **argv)
{
	if(argc==1)//????????? 
	fsize(".");
	else
	   while(--argc>0)
	fsize(*++argv);
	
}

void fsize (char *name)
{
	struct stat stbuf;
	if(stat(name ,&stbuf)==-1)
	{
		fprintf(stderr,"fsize can not access %s\n",name);
		return ;
	}
	if((stbuf.st_mode&S_IFMT)==S_IFDIR)
	
		dirwalk(name,fsize);
		printf("%d %d %d %8d %s\n",stbuf.st_mode,stbuf.st_mtime,stbuf.st_ctime, stbuf.st_atime,stbuf.st_size,name);
	
	
}
DIR *opendir(char *);
void closedir(DIR *);
Dirent *readdir(DIR *);
void dirwalk(char *dir,void(*fcn)(char *))
{
	Dirent *dp;
	DIR *dfd;
	char name[MAX_PATH];
	if((dfd=opendir(dir))==NULL){
		fprintf(stderr ,"dirwalk:can not open %s\n",dir);
		return ;//???????????????? 
	}
	while((dp=readdir(dfd))!=NULL)
	{
		if(strcmp(dp->name,".")==0||strcmp(dp->name,"..")==0)
		continue;//??????????????
		if(strlen(dp->name)+strlen(dir)+2>sizeof(name))
		{
			fprintf(stderr,"name %s/%s too long\n",dir,dp->name);
		 } 
		 else {
		 	sprintf(name,"%s/%s",dir,dp->name);
		 	(*fcn)(name);//?????? 
		 }
	}
	closedir(dfd);
}
DIR *opendir(char *dirname)
{
	int fd;
	struct stat stbuf;
	DIR *dp; 
	if((fd=open(dirname,O_RDONLY,0))==-1
	||fstat(fd,&stbuf)==-1||(stbuf.st_mode&S_IFMT)!=S_IFDIR
	||(dp=(DIR*)malloc(sizeof(DIR)))==NULL)
	return NULL;
	dp->fd=fd;
	return dp;
}
void closedir(DIR *dp)
{
	if(dp!=NULL)
	{
		close(dp->fd);
		free(dp);
	}
}
Dirent *readdir(DIR *dp)
{
	struct direct dirbuf;
	static Dirent d;//?????????????
	while(read(dp->fd,(char *)&dirbuf,sizeof(dirbuf))==sizeof(dirbuf))
	{
		if(dirbuf.d_ino==0)
		  continue;
		  d.ino=dirbuf.d_ino;
		  strncpy(d.name,dirbuf.d_name,DIRSIZ);
		  d.name[DIRSIZ]='\0';
		  return &d;
	 } 
	 return NULL;
}
