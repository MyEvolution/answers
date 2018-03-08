#include<stdio.h>
#define N 10
#define TAB 8
char line[TAB];
int extab(int pos);//把制表符换位相应数量的空格 
void printfl(int pos);//打印该行 
int findl(int pos);//回查 
int newl(int pos);//把pos之后的排到新的数组中 
main(){
	int c; 
	int pos=0;//记录当前文本行的位置 
	while((c=getchar())!=EOF){
    
     if(c=='\t') pos=extab(pos);
     else if(c=='\n') {
     	if(pos==0) ;
     	else{
		 
     	line[pos]='\0';
     
     	pos--;
	pos=findl(pos);
	pos=newl(pos);
	if(pos!=-1){
	
	printfl(pos);}}
	pos=-1; 
       
     
	
	        }
	 else line[pos]=c;
     if((pos+1)>=N){
     	pos=findl(pos);
     	pos=newl(pos);
     	
	 }
     pos++;

	}
}
void printfl(int pos){
	int j;
	for(j=0;j<=pos;j++){
		putchar(line[j]);
	}
	putchar('\n');

}
int extab(int m){
	int i;
	if(m>TAB-1) {
	printfl(m);
	return -1;
}
	else {
	for(i=m;i<=TAB-1;i++){
		line[i]=' ';
	}
	return TAB-1;
	}
	
}
int findl(int pos){
	int i,b;
	for(i=pos;i>=0;i--){
		if(line[i]==' '){
			b=i;
	while(line[i]==' '&&i>=0){
		i=i-1;
	}
	if(i<0) 	i=b;	
		else printfl(i);
	
		
	       break;}
	}
if(i<0) {
	
printfl(pos);
b=i;}

return b;
	
}
int newl(int pos){
	int j=0,i=pos+1;
	if(i>0){
	
	for(j;line[i]!='\0';j++){
		line[j]=line[i];
		i++;}
	}
	return (j-1);
}
