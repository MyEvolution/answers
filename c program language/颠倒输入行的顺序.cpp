#include<stdio.h>
#define SIZE 1000
int getline(char line[],int size);
void reverse(char to[]);
void printfline(char line[]);
main(){
	int len;
	char line[SIZE];
	while((len=getline(line,SIZE))>0){
		
		reverse(line);
		printfline(line);
	}
}
int getline(char line[],int size){
	
	int i;
	int c;
	for(i=0;i<size&&(c=getchar())!=EOF&&c!='\n';i++){
		line[i]=c;
		
	}
	line[i]='\0';
	return i;
}
void reverse(char a[]){
	int i=0,j;
	char c;
	while(a[i]!='\0'){
		i++;
	}
	for(j=0;j<i/2;j++){
		c=a[j];
		a[j]=a[i-1-j];
		a[i-1-j]=c;
	}
}
void printfline(char a[]){
	int i=0;
	while(a[i]!='\0'){
		putchar(a[i]);
		i++;
	}
	putchar('\n');
}
