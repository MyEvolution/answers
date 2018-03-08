#include<stdio.h>
#define MAXSIZE 1000 //最长长度 
int getline(char line[],int maxsize);
void copy(char to[],char from[]);
main(){
	
	int len,i;
	int max=0;
	char line[MAXSIZE];//当前输入的行 
	char longest[MAXSIZE];//长度最长的行 
	while((len=getline(line,MAXSIZE))>0){
	
	if(len>max) {
	copy(longest,line);
	max=len;}
}
printf("%d\n",max);

for(i=0;i<max;i++){
	putchar(longest[i]);
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
void copy(char to[],char from[]){
	int i=0;
while((to[i]=from[i])!='\0'){

i++;

	}
	
}
