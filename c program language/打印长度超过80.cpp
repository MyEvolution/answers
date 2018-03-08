#include<stdio.h>
#define MAXSIZE 1000 //最长长度 
int getline(char line[],int maxsize);
void copy(char to[],char from[]);
main(){
	
	int len,i;

	char line[MAXSIZE];//当前输入的行 

	while((len=getline(line,MAXSIZE))>0){
	
	if(len>80) {



for(i=0;i<len;i++){
	putchar(line[i]);
	
}
printf("\n");

}
}
}
	
int getline(char line[],int maxsize){
	int i=0;
	int c;
	for(i=0;i<maxsize&&(c=getchar())!=EOF&&(c!='\n');i++)
	   {
	   line[i]=c;
	}
    return i;	
}

