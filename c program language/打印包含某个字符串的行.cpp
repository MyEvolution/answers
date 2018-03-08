#define MAXSIZE 1000
#include<stdio.h>
#include<string.h>
int getline(char s[],int lim);
int strindex(char s[],char t[]);
main(){

    char line[MAXSIZE];
    char t[MAXSIZE];
    scanf("%s",&t);
    getchar();
	while(getline(line,MAXSIZE)){
		if(strindex(line,t)) printf("%s\n",line);
	}
} 
int getline(char s[],int lim){
	int c;
	int i=0; 
	while(--lim>=0&&(c=getchar())!=EOF&&c!='\n'){
		s[i++]=c;
	
	}
		s[i]='\0';
       return i;

}
/*int strindex(char s[],char t[]){
	int i,j=0;
	int b;
	for(i=0;i<strlen(s);i++){
		if(s[i]==t[j]) b=i;
		while(s[i]==t[j]&&t[j]!='\0'){
			
			i++;
			j++;
		}
		if(t[j]=='\0') return 1;
		if(j!=0) {
		j=0;
		i=b;}
	}
	return 0;
	
	
}*/
int strindex(char s[],char t[]){
	int i,j,k=0;
	for(i=0;i<strlen(s);i++){
		for(j=i,k=0;s[j]==t[k]&&t[k]!='\0';j++,k++){
			;
		}
		if(t[k]=='\0'&&k>0) return 1;
		
	}
	return 0;
}
