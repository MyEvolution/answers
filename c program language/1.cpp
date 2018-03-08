#include<stdio.h>
#define COUNT 30
#define MANPAY 3
#define WMANPAY 2
#define CHILDPAY 1
#define PAY 50
main(){
	int x;//男人的数目
	int y;//女人的数目 
	 for(x=0;x<=COUNT;x++)
	   for(y=0;y+x<=COUNT;y++)
	   
	 if((x*MANPAY+y*WMANPAY+(COUNT-x-y)*CHILDPAY)==PAY)
	 {
	 	printf("men:%d\nwomen:%d\nchild:%d\n",x,y,COUNT-x-y);
	 	
	 }
}
