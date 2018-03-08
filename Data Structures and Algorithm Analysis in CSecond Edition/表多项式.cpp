#include<stdio.h>
#define MaxDegree 1000//最高次数 

int max(int a,int b)
{
	return a>b?a:b;
}
typedef struct 
{
	int CoeffArray[MaxDegree+1];//加上一个0次 
	int HighPower;//最高次 
}a,*Polynomial;//多项式的结构 
void ZeroPolynomial(Polynomial Poly)//将多项式初始化为0 
{
	int i;
	for(i=0;i<=MaxDegree;i++)
	Poly->CoeffArray[i]=0;
	Poly->HighPower=0;
}
void AddPolynomial(const Polynomial Poly1,const Polynomial Poly2,Polynomial PolySum)//多项式相加 
{
	int i;
	ZeroPolynomial(PolySum);
	PolySum->HighPower=max(Poly1->HighPower,Poly2->HighPower);
	for(i=0;i<=PolySum->HighPower;i++)
		PolySum->CoeffArray[i]=Poly1->CoeffArray[i]+Poly2->CoeffArray[i];	
}
void MultPolynomial(const Polynomial Poly1,const Polynomial Poly2,Polynomial PolyProd)//多项式相称 
{
	int i;
	int j;
	ZeroPolynomial(PolyProd);
	PolyProd->HighPower=Poly1->HighPower*Poly2->HighPower;
    if(PolyProd->HighPower>MaxDegree)
     return ;
     else 
       for(i=0;i<=PolyProd->HighPower;i++)
       for(j=0;j<=i;j++)
         PolyProd->CoeffArray[i]+=Poly1->CoeffArray[j]*Poly2->CoeffArray[i-j];
	}
	main()
	{
		a p1,p2,ps;
		int n,m;
		int i;
		scanf("%d",&n);
		p1.HighPower=n;
		for(i=0;i<=n;i++)
		scanf("%d",&p1.CoeffArray[i]);
		scanf("%d",&m);
		p2.HighPower=m;
		for(i=0;i<=m;i++)
		scanf("%d",&p2.CoeffArray[i]);
		AddPolynomial(&p1,&p2,&ps);
		for(i=0;i<=ps.HighPower;i++)
		printf("%d ",ps.CoeffArray[i]);		
	}
