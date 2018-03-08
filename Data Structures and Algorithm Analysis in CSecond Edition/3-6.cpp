#include"poly.h"
int main()
{
	List L1;
	List L2;
	List L;
	
	Create(&L1);
	Create(&L2);
	Create(&L);
     int i;
     int n,m;
     double c;
	 int p;
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
     	scanf("%lf %d",&c,&p);
     	Insert(c,p,L1,L1);
	 }
	  scanf("%d",&m);
	    for(i=0;i<m;i++)
     {
     	scanf("%lf %d",&c,&p);
     	Insert(c,p,L2,L2);
	 }
	 
	 AddPoly(L1,L2,L);
	 printf("得到的和多项式的系数和指数为：\n");
	 
	 printlist(L);
	 MultPoly(L1,L2,L);
	 printf("得到的积多项式的系数和指数为：\n");
	 printlist(L); 
	 int q;
	 while(printf("请输入L1的幂次：\n"),scanf("%d",&q)!=EOF)
	 {
	 	L=PowPoly(L1,q);
	 printf("L1的%d次方为：\n",q);
	 printlist(L);
	 }
	 

}
