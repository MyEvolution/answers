#include<stdio.h>
typedef struct 
{
	double x;
	double y;
}point;
void stand(point *n1,point *n2)
{     
     double min1,min2,max1,max2;
     min1=(n1->x>n2->x?n2->x:n1->x);
     min2=(n1->y>n2->y?n2->y:n1->y);
     max1=(n1->x>n2->x?n1->x:n2->x);
     max2=(n1->y>n2->y?n1->y:n2->y);
     n1->x=min1,n1->y=min2;
     n2->x=max1,n2->y=max2;

}
main()
{
	point n1,n2,n3,n4;
	point a,b,c,d;
	while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&n1.x,&n1.y,&n2.x,&n2.y,&n3.x,&n3.y,&n4.x,&n4.y)!=EOF)
     {
     	stand(&n1,&n2);
     	stand(&n3,&n4);
        a.x=(n3.x>n1.x)?n3.x:n1.x;
        a.y=(n3.y>n1.y)?n3.y:n1.y;
        b.x=(n2.x>n4.x)?n4.x:n2.x;
        b.y=(n2.y>n4.y)?n4.y:n2.y;	  //ԭ���İ취�����ڷ�Χ��ѡ��Χ��С�����  Ҳ������� ֵС�ڷ�Χ����ѡ���ϴ�ֵ������ֵ�����˷�Χ��
		                                        //���޷�ѡ���ϴ�ֵ�ˣ� 
		 if(a.x>b.x&&a.y>b.y)         //�����Ļ�ѡ�����ĵ����ǻ�С�ڵڶ����㣬Ҳ��û�а취���д����� 
		 printf("%.2f\n",0);
		 else printf("%.2f\n",(b.x-a.x)*(b.y-a.y));
		 
		 } 
}
