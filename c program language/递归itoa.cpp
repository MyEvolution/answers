#include<stdio.h>
void itoa(int n,char []);


main(){
	int n;

	char s[1000];
	scanf("%d",&n);
	itoa(n,s);
	printf("%s",s);
	
}
void itoa(int n,char s[])
{
    static int i;
          

	if(n/10) {
	itoa(n/10,s);
	}
	else {
	      i=0;
       if(n<0) s[i++]='-';

	     } 
	     if(n<0) n=-n;
	 s[i++]=n%10+'0';//可以用绝对值abs函数，头文件math.h 
	 s[i]='\0';

}
