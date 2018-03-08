#include<stdio.h>
#include<ctype.h>
#define SIZE 10
int buf[10];
int bufe=0;
int getch(void);
void ungetch(int);
int getint(int *);
main(){
	int n,array[SIZE];
	int i;
	int c;
	for(n=0;n<SIZE&&getint(&array[n])!=EOF;n++)
	             ; 
	for(i=0;i<n;i++){
		printf("%d %d\n",i,array[i]);
		
	}

		
	
} 
int getint(int *pn){//当输入不是数字和结束符时  返回0，当输入为数字时返回下一个输入，将数字赋值给*pn 
	int c;
	int d;//当单独输入 加减时将其压回输入 
	int sign;
	while(isspace(c=getch()))//跳过空白符 
	    ;
	if(!isdigit(c)&&c!=EOF&&c!='+'&&c!='-'){
		ungetch(c);
		return 0;
	}
	sign=(c=='-')?-1:1;
	if(c=='-'||c=='+')    {
	
	d=getch();
	if(isdigit(d)) 
	c=d;
	else {
	ungetch(c);return 0;}}
	
	for(*pn=0;isdigit(c);c=getch())
	    *pn=10**pn+c-'0';
	*pn*=sign;
	if(c!=EOF) ungetch(c);
	 return c;
}
int getch(void){
	return (bufe>0)?buf[--bufe]:getchar();
}
void ungetch(int c){
	if(bufe>SIZE) printf("满了输少点!\n");//虽然不tai可能会出现   隐形卖萌 
	else buf[bufe++]=c;
}
