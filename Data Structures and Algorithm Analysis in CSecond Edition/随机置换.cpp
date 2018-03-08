#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAXSIZE 10000 //
void swap(int *i,int *j)
{
	int temp;
	temp=*i;
	*i=*j;
	*j=temp;
}
int RandInt(int p,int j,int *Rand,int n)//生成从i到j的随机数 
{
	int num;
	int i;
	srand((unsigned)time(NULL));
	for(i=0;i<n;i++)
	Rand[i]=rand()%(j-p+1)+p;
	return 0;
	
} 
main()
{
	
	int n;
	int num[MAXSIZE];
	int i,j;
	int b;//存放随机数 
	int used[MAXSIZE];
	int Rand[MAXSIZE];
	scanf("%d",&n);
	/*for(i=0;i<n;i++)
	{
		while(b=RandInt(1,n))
		{
			 
			for(j=0;j<i;j++)
			  if(b==num[j])
			  break;
			  if(j==i){
  				num[i]=b;
  				break;
  			     }
  			     
	  }
	  printf("%d ",num[i]);
	}*/
	 
	/* for(i=1;i<=n;i++)//一定要从1开始 因为随机数从1开始 
	   used[i]=0;
	   for(i=0;i<n;i++)
	   {
	   	while(b=RandInt(1,n))
	   		if(used[b]==0)
	   		 {
	   		 	num[i]=b;
	   		 	used[b]=1;
	   		 	break;
				}
	   printf("%d ",num[i]);	   
	   }*/
	 for(i=0;i<n;i++)
	 	 num[i]=i+1;  
	for(i=1;i<n;i++)//为何是这样交换，却不是和n以内的随机数交换 
	{               //srand用时间生成种子，一秒以内种子是一样的，因为时间精确到秒，所以很快就会结束 
	     RandInt(1,n,Rand,n);
		swap(&num[i],&num[Rand[i]]);
	}
	                                      //不能用宏的原因 
                                    //宏是单纯替换，每次替换这里都会重新生成随机数 
	  for(i=0;i<n;i++)              //所以会发生错误 
	  printf("%d ",num[i]);
	  getchar();
	} 


