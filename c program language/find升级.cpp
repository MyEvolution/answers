#include<stdio.h>
#include<string.h>
#define MAXLEN 1000//-x表示打印除模式匹配意外的所有行，-n表示打印行号 
int getline(char *line,int maxlen);
main(int argc,char **argv){
char line[MAXLEN];
int c,except=0,number=0,found=0;
long linenum=0;
while(--argc>0&&(*++argv)[0]=='-')//在这里自增过后 argv[0]已经不是原来的了 从当前的这个开始计数 
      while(c=*++argv[0]){
      	switch(c){
		  
      	case'x':
      		  except=1;//打印除模式外的行 
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
	    if((strstr(line,*argv)!=NULL)^except) {//strstr(line,*argv)不等于null说明符合模式，则若except等于1，则不执行下面的语句 
	           if(number) printf("%ld:",linenum);/*即若你存我亡才为真 此时应该用!=或者^； 
			                                           两个都要活着，用&&，一个活着就行用||*/
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
