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
	 printf("�õ��ĺͶ���ʽ��ϵ����ָ��Ϊ��\n");
	 
	 printlist(L);
	 MultPoly(L1,L2,L);
	 printf("�õ��Ļ�����ʽ��ϵ����ָ��Ϊ��\n");
	 printlist(L); 
	 int q;
	 while(printf("������L1���ݴΣ�\n"),scanf("%d",&q)!=EOF)
	 {
	 	L=PowPoly(L1,q);
	 printf("L1��%d�η�Ϊ��\n",q);
	 printlist(L);
	 }
	 

}
