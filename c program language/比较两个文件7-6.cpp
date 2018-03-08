#include<stdio.h>
#include<stdlib.h>
#define MAXLINE 1000
#include<string.h>
main(int argc,char **argv)
{     
     FILE *fp1;//文件指针1 
     FILE *fp2;//文件指针2 
     char line1[MAXLINE];
     char line2[MAXLINE];
     char *p1;//指向第一个文件的行 
     char *p2;//指向第2个文件的行 
	if(argc==3)
	{
	 fp1=fopen(argv[1],"r");
	 fp2=fopen(argv[2],"r");
	 if(fp1==NULL||fp2==NULL){
	 	printf("不能正常打开文件%s或者%s\n",argv[1],argv[2]);
	 exit(2);
	 }
	 
	 while((p1=fgets(line1,MAXLINE,fp1))&&(p2=fgets(line2,MAXLINE,fp2)))//a&&b 如果a不符合条件则b将不被执行 
	                                                                    //a||b 如果a符合条件b将不被执行,使用时应当注意 
	          if(strcmp(line1,line2)!=0){
	    		printf("%s:%s\n%s:%s\n",argv[1],line1,argv[2],line2);
	    		exit(1);
			}
		    
	  	
	   
	if(p1==NULL)
	  
	   if((p2=fgets(line2,MAXLINE,fp2))==NULL)
	   {
	   	printf("两个文件内容相同\n");
		 exit(0);
	   }
	   else {
	   	printf("%s:%s\n%s到结尾\n",argv[2],line2,argv[1]);
	   	exit(0);
	   }
		
			
	else if((p1=fgets(line1,MAXLINE,fp1))==NULL){
			printf("两个文件内容相同\n");
		 exit(0);
	}else {
		printf("%s:%s\n%s到结尾\n",argv[1],line1,argv[2]);
	   	exit(0);
	}
	
			
		 }
		 else printf("不是两个文件\n");
		 exit(1);
	}


