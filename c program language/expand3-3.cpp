#include<stdio.h>
void expand(char from[],char to[]);//把a-c等速记字符扩展为abc
main(){
	char a[1000],b[1000];
	scanf("%s",&a);
	expand(a,b);
	printf("%s",b);

	
} 
void expand(char from[],char to[]){
	int i=0,j=0;
	
	while(from[i]!='\0'){
	
	if(i=='0') to[j++]=from[i++];
	else if(from[i]=='-'){
                i++;
			for(j;to[j-1]<from[i];j++){
				to[j]=to[j-1]+1;
			
			}
			i=i+1;
		}
		else to[j++]=from[i++];
		
	}
	to[j]='\0';
} 
