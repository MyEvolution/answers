#include<stdio.h>
#include<string.h>
#define MAXLEN 1000//-x��ʾ��ӡ��ģʽƥ������������У�-n��ʾ��ӡ�к� 
int getline(char *line,int maxlen);
main(int argc,char **argv){
char line[MAXLEN];
int c,except=0,number=0,found=0;
long linenum=0;
while(--argc>0&&(*++argv)[0]=='-')//�������������� argv[0]�Ѿ�����ԭ������ �ӵ�ǰ�������ʼ���� 
      while(c=*++argv[0]){
      	switch(c){
		  
      	case'x':
      		  except=1;//��ӡ��ģʽ����� 
      		  break;
      	case'n':
		  number=1;
		  break;
		default:
		    printf("find:illegal option%c\n",c);
			argc=0;
			found=-1;
			break;  	}  
	  }
	  if(argc!=1) 
	      printf("Usage:find -x -n pattern\n");
	      else 
	      while(getline(line,MAXLEN)>0){
	      	linenum++;
	    if((strstr(line,*argv)!=NULL)^except) {//strstr(line,*argv)������null˵������ģʽ������except����1����ִ���������� 
	           if(number) printf("%ld:",linenum);/*�������������Ϊ�� ��ʱӦ����!=����^�� 
			                                           ������Ҫ���ţ���&&��һ�����ž�����||*/
	       printf("%s\n",line);
	       found++;
		   
		   }
		  }
		  return found;
}
int getline(char *line,int maxlen){
	int c;
	char *p=line;
	while((c=getchar())!=EOF&&c!='\n'&&(p-line)<maxlen)
     {    *p++=c;
          *p='\0';
}
    if(c=='\n') *p++='\n',*p='\0';
    return p-line;}
