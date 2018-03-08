#include<stdio.h>
void swap(int *x,int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
main(){
	int x,y;
	scanf("%d %d",&x,&y);
	swap(&x,&y);
	printf("%d %d",x,y);
}
