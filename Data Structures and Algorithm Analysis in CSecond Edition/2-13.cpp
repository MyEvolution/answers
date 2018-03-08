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
int isprime(int n)//任何合数都可以表示为素数的乘积，当根号n才是最小的步骤 
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
	  }            //2^B=N，根号N=2^(B/2) 
	  printf("%d\n",b-1);//所以运行时间也就是O(2^(B/2)) 
	 if(isprime(n))//用B表示更精准，因为B更精准地描述了输入的大小。 
	printf("yes\n");//比如63，用二进制表示占5位，而计算4次 
	else            //实际上从3到7，3 5 7，也就是3次，而用根号N表示是7次 
	  printf("no\n"); 
	}

}
