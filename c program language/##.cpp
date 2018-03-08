#include<stdio.h>
#define createfun(name1,name2) \
void name1##name2(void){\
	printf("hello,world\n");\
}
#define swap(x,y){\
 int temp; temp=x;x=y;y=temp;}


createfun(the,function);


 main(){
 thefunction();
 int x=10;
 int y=11;
 swap(x,y);
 printf("%d %d",x,y);
getchar(); 
 }   
