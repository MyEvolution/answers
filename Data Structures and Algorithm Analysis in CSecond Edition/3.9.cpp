#include"任意精度整数多项式.h"
int main()
{
	int i;
	while(1)
	{
		int n; 
	Poly p1,p2,p3,p4;
	int c;
	p1=Create();
	p2=Create();
	p3=Create();
	p4=Create();
	ScanfPoly(p1);
	while((c=getchar())==')'||isspace(c))
	        ;
	if(c!='^'&&c!='/')
	{
    ScanfPoly(p2);
	if(c=='+')
	AddPoly(p1,p2,p3);
	else if(c=='-')
	SubPoly(p1,p2,p3);
	else if(c=='*')
	MultPoly(p1,p2,p3);	 
	PrintPoly(p3);
	putchar('\n');	
	}
	
	else if(c=='^')
	{
		scanf("%d",&n);
		MakeZore(p3);
		Power(p1,n,p3);	
	PrintPoly(p3);
	putchar('\n');	
	}
	else 
	{
	ScanfPoly(p2);
	DivPoly(p1,p2,p3,p4,6000);	
	PrintPoly(p3);
	if(!IsZore(p4))
	{
	putchar('.');
	PrintPoly(p4);	
	}
     putchar('\n');
	}
	}


	return 0;
}
