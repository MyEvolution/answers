#include<stdio.h>
#include<math.h>
/*int isprime(int n)//O(N)
{
	int i;
	if(n==1)
	return 0;
	if(n==2)
	  return 1;
   for(i=2;i<=(n/2+1);i++)
   if(n%i==0)
   break;
   if(i==(n/2+2))
     return 1;
     else return 0;
}*/
int isprime(int n)//�κκ��������Ա�ʾΪ�����ĳ˻���������n������С�Ĳ��� 
{
	int i;
	if(n==1)
	 return 0;
	if(n==2)
	 return 1;
	 else if(!(n&1))
	  return 0;
	  else {
	  	for(i=3;i<=(int)sqrt(n);i+=2)
	  if(n%i==0)
	   break;
	   if(i<=(int)sqrt(n)) 
	   return 0;
	   else return 1;
	  }

	   
}
main()
{
	int n;
	int b;
	int num;
	while(scanf("%d",&n)!=EOF)
	{
		b=0;
		num=n;
	  while(num!=0)	
	  {
	  	num>>=1;
	  	b++;       //B=O(logN) 
	  }            //2^B=N������N=2^(B/2) 
	  printf("%d\n",b-1);//��������ʱ��Ҳ����O(2^(B/2)) 
	 if(isprime(n))//��B��ʾ����׼����ΪB����׼������������Ĵ�С�� 
	printf("yes\n");//����63���ö����Ʊ�ʾռ5λ��������4�� 
	else            //ʵ���ϴ�3��7��3 5 7��Ҳ����3�Σ����ø���N��ʾ��7�� 
	  printf("no\n"); 
	}

}
