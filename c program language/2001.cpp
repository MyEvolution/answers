#include<stdio.h>
#include<math.h>

	typedef struct piont{
		int x;
		int y;
	}p;
double distanc(p m,p n); 
main()
{
    int c;
	p p1,p2;
	double d;
	while((c=getchar())!=EOF){
		p1.x=c-'0';
	scanf("%d %d %d",&p1.y,&p2.x,&p2.y);
	getchar();
	d=distanc(p1,p2);
	printf("%.2f\n",d);
	}

}
double distanc(p m,p n)
{    double i;
    i=sqrt((double)((m.x-n.x)*(m.x-n.x)+(m.y-n.y)*(m.y-n.y)));
	return i;
}