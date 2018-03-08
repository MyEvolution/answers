#include<stdio.h>
main()
{
	int n;
	char name[30];
	int i;
	int sum;
	int k;
	int j,s[30],c[30],count;
	scanf("%d",&n);
	getchar();
	
	for(i=0;i<n;i++)
	{
		sum=k=0;
		scanf("%d",&count);
		getchar();
		
		for(j=0;j<count;j++)
		{
		scanf("%s %d %d",name,&s[j],&c[j]);
		getchar();
	
         }
         for(j=0;j<count;j++)
           if(c[j]<60) break;
           else {
		   sum+=c[j]*s[j];
                  k+=s[j];
				  }
           if(j==count) printf("%.2f\n",(double)sum/(double)k);
           else puts("sorry!\n");

         }
}
