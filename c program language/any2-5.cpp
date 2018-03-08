#include<stdio.h>
int any(char a[],char b[]);
main(){
	char a[100];
	char b[100];
	scanf("%s %s",&a,&b);
	int q=any(a,b);
	printf("%d",q);
}
int any(char a[],char b[]){
	int m,i;
	m=0;
	while(b[m]!='\0'){
		for(i=0;a[i]!='\0';i++){
			if(a[i]==b[m]) return i+1;
			
		}
		m++;
	}
	return -1;
}
