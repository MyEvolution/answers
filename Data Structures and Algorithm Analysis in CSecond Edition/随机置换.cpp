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
int RandInt(int p,int j,int *Rand,int n)//���ɴ�i��j������� 
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
	int b;//�������� 
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
	 
	/* for(i=1;i<=n;i++)//һ��Ҫ��1��ʼ ��Ϊ�������1��ʼ 
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
	for(i=1;i<n;i++)//Ϊ��������������ȴ���Ǻ�n���ڵ���������� 
	{               //srand��ʱ���������ӣ�һ������������һ���ģ���Ϊʱ�侫ȷ���룬���Ժܿ�ͻ���� 
	     RandInt(1,n,Rand,n);
		swap(&num[i],&num[Rand[i]]);
	}
	                                      //�����ú��ԭ�� 
                                    //���ǵ����滻��ÿ���滻���ﶼ��������������� 
	  for(i=0;i<n;i++)              //���Իᷢ������ 
	  printf("%d ",num[i]);
	  getchar();
	} 


