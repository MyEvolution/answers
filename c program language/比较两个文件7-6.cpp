#include<stdio.h>
#include<stdlib.h>
#define MAXLINE 1000
#include<string.h>
main(int argc,char **argv)
{     
     FILE *fp1;//�ļ�ָ��1 
     FILE *fp2;//�ļ�ָ��2 
     char line1[MAXLINE];
     char line2[MAXLINE];
     char *p1;//ָ���һ���ļ����� 
     char *p2;//ָ���2���ļ����� 
	if(argc==3)
	{
	 fp1=fopen(argv[1],"r");
	 fp2=fopen(argv[2],"r");
	 if(fp1==NULL||fp2==NULL){
	 	printf("�����������ļ�%s����%s\n",argv[1],argv[2]);
	 exit(2);
	 }
	 
	 while((p1=fgets(line1,MAXLINE,fp1))&&(p2=fgets(line2,MAXLINE,fp2)))//a&&b ���a������������b������ִ�� 
	                                                                    //a||b ���a��������b������ִ��,ʹ��ʱӦ��ע�� 
	          if(strcmp(line1,line2)!=0){
	    		printf("%s:%s\n%s:%s\n",argv[1],line1,argv[2],line2);
	    		exit(1);
			}
		    
	  	
	   
	if(p1==NULL)
	  
	   if((p2=fgets(line2,MAXLINE,fp2))==NULL)
	   {
	   	printf("�����ļ�������ͬ\n");
		 exit(0);
	   }
	   else {
	   	printf("%s:%s\n%s����β\n",argv[2],line2,argv[1]);
	   	exit(0);
	   }
		
			
	else if((p1=fgets(line1,MAXLINE,fp1))==NULL){
			printf("�����ļ�������ͬ\n");
		 exit(0);
	}else {
		printf("%s:%s\n%s����β\n",argv[1],line1,argv[2]);
	   	exit(0);
	}
	
			
		 }
		 else printf("���������ļ�\n");
		 exit(1);
	}


