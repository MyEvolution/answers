#include<stdio.h>
#include<time.h>
#include<stdlib.h> 
/*#define swap(x,y) {\
    x+=y;\
	y-=y;\
	x-=y; \
}*/
void swap(int *i,int *j)
{
	int temp;
	temp=*i;
	*i=*j;
	*j=temp;
}
int Random(int N);
int main()
{
	int a[10];
	int i;
	int m;
	for(i=0;i<10;i++)
	a[i]=i;
	for(i=0;i<10;i++)
	swap(&a[i],&a[Random(10)]);
	
	
	for(i=0;i<10;i++)
	printf("%d ",a[i]);
	
}
int Random(int N)
{
	srand((unsigned)time(NULL));//真正的问题出现在这里  前面都是扯淡啊 
	return rand()%N;
}
