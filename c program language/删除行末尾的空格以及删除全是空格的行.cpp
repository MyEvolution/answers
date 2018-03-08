#include<stdio.h>
#define SIZE 1000
int getline(char line[],int size);
void printfline(char line[],int len);
main(){
	
int len,j;
char line[SIZE];
while((len=getline(line,SIZE))>0){

		for(j=0;j<len;j++){
			if(line[j]!=' '&&line[j]!='\t')
			break;
		}
		
	if(j==len) ;
	
	
	else if(line[len-1]==' '||line[len-1]=='\t'){
		printfline(line,len-1);
	}
	else printfline(line,len);
}
}
int getline(char line[],int n){
	int c,i=0;
	while(i<n&&(c=getchar())!=EOF&&c!='\n'){
		line[i]= c;
		i++;
	}
	return i;
}
void printfline(char line[],int len){
	int i;
	for(i=0;i<len;i++){
		putchar(line[i]);
	}
	printf("\n");
}

