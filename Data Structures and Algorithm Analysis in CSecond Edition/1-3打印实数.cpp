#include<stdio.h>
double dis(double n)//С������������� 
{
	return n-(int)n;
}
void printfDigit(int a)
{
	if(a>=0&&a<10)
	printf("%d",a);
}
void printfOut(int n)
{
	if(n>=10)
	  printfOut(n/10);
	  printfDigit(n%10);
}
double foofii(double n,int bit)//���ȿ�������λС�� 
{           
       int i;                  //Ȼ��ѳ�������5���1λû�����Ͳ���10Ҳ�ͻᱻ��ȥ 
	double add = 0.5;
	for(i=0;i<bit;i++)
	  add/=10;
	  return n+add;
	
}
void priDou(double n,int N)
{
	int i;
	int num;
	int m;
	double ip;
	if(n<0) putchar('-');
	num=(int)n>0?n:-n;
	ip=(n>0?n:(-n))-num;
	ip=foofii(ip,N); 
	printfOut(num);
    
		putchar('.');
		for(i=0;i<N;i++)
		{
			ip*=10;
		   printfOut((int)ip);
			ip=dis(ip);
			}

			/*else {
			  m=(int)ip;
			  ip=dis(ip);
			  ip*=10;
			  if((int)ip>=5)//����ʵ���������� 
			  m++;
			  printfOut(m);
			}*/ 
			
		}
		
		
	
	
	
 
main()
{
		double a;
	scanf("%lf",&a);
	priDou(a,1);
	
	
}
