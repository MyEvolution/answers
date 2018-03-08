#include<stdio.h>
#include<stdlib.h>
struct c{
	int x;
	int y;
	int ord;//表示从这个节目开始看，最多可以看的节目组数 
}d[100];//节目的时间
int cmd(const void *a,const void *b)
{
    struct c *p=(struct c*)a;
    struct c *q=(struct c*)b;
    if(p->x==q->x)
       return p->y-q->y;
       else return p->x-q->x;
 } 
int main()
{
	int n;
	int i,j;
	int max;
	scanf("%d",&n);
	for(max=i=0;i<n;i++)
	{
		scanf("%d %d",&d[i].x,&d[i].y);
		d[i].ord=1;
	}
	qsort(d,n,sizeof(d[0]),cmd);
	for(i=n-2;i>=0;i--)
	{
	   for(j=i+1;j<n;j++)
	   if(d[i].y<=d[j].x&&d[i].ord<d[j].ord+1)
	    d[i].ord=d[j].ord+1;
	    if(max<d[i].ord) max=d[i].ord;
	}
	printf("%d\n",max);
}
