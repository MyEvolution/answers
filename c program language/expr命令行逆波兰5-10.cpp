#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define MAXSIZE 1000
#define NUMB '0'
void push(double);
double pop(void);
char isnum(char); 
double val[MAXSIZE];//棧 
int j=0;
main(int argc,char **argv){
	double m;
	if(argc<=1) {
	printf("no data!\n");
	return -1;
	}
	while(--argc>0){
	
 switch(isnum((*++argv)[0])){
     case NUMB:
	    push(atof(argv[0]));
		  break;
	case '+':{
		push(pop()+pop());
		break;
	}
	case '*':{
		push(pop()*pop());
		break;
		
	}
	case '-':{
		m=pop();
		push(pop()-m);
		break;
	}    
	case '/':{
		m=pop();
		if(m!=0)
		push(pop()/m);
		else {
		printf("除数为0！\n");
		    return -1;}
		break;
	}

		 	   	
 }
      }
      if(j>1){
      	printf("illegal option!\n");
      	return -1;
	  }
      printf("%g\n",pop());
      return 0;
}
char isnum(char c){//判断第一个是不是数字，若不是则返回该字符，是的话返回numb'表示该指针指向操作数 
	if(isdigit(c)) return NUMB;
	return c;
}
void push(double m){
	val[j++]=m;
	val[j]='\0';
}
double pop(void){
	double m;
	m=val[--j];
	val[j]='\0';
	return m;
}
