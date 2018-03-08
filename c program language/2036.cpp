#include<stdio.h>
#include<math.h>
struct point{
	int x;
	int y;
};
typedef struct point Point;
double square(Point*,int);
main()
{
	Point a[100];
	int n,i;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
		scanf("%d %d",&a[i].x,&a[i].y);
		printf("%.1f\n",square(a,n));
		
	}
}
double square(Point *p,int n)
{
	double a,b,c,q;
	int i;
	double s=0.0;
	for(i=0;i<n-2;i++)
	{
		a=sqrt(pow((p[0].x-p[i+1].x),2)+pow((p[0].y-p[i+1].y),2));	
		b=sqrt(pow((p[0].x-p[i+2].x),2)+pow((p[0].y-p[i+2].y),2));
		c=sqrt(pow((p[i+1].x-p[i+2].x),2)+pow((p[i+1].y-p[i+2].y),2));
		q=(a+b+c)/2;
		s+=sqrt(q*(q-a)*(q-b)*(q-c));
	}
	return s;
}
