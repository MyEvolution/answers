#include<stdio.h>
void squeeze(char a[],char b[]);
main(){
	
	char a[100],b[100];
scanf("%s",&a);
scanf("%s",&b);
squeeze(a,b);
printf("%s",a);
	
}
void squeeze(char a[],char b[]){
	int i,j,m;
	m=0;
	while(b[m]!='\0'){
		for(i=j=0;a[i]!='\0';i++){
			if(a[i]!=b[m]){
			
			a[j++]=a[i];
			a[j]='\0';}
		}
		m++;
	}
	
	
}
