#include<stdio.h>
/*main()
{
	int n,m;
	int j,i;
	int sum=0;
	int q=0;
   while(scanf("%d %d",&n,&m)==2){
   		for(i=2,j=1;j<=n;j++,i+=2)
	   if(j%m==0||j==n)
	   {
	   	sum+=i;
	   	q++;
	   	printf(j==n?"%d":"%d ",sum/q);
	   	q=0;
	   	sum=0;
	   }
	   
	   
	   else {
	   	sum+=i;
	   	q++;
	   }
	   putchar('\n');
   }
   


}*/


			 


int main(void)
{
    int i, n, m, b, c;

    while (scanf("%d%d", &n, &m) != EOF)
    {
        b = 2;
        c = 0;
        for (i = 0 ; i < n / m ; i++)
        {
            printf(c++ ? " %d" : "%d", b + m - 1);//数学问题 平均值=b+(m-1)
            b += m * 2;
        }
        printf(n % m ? " %d\n" : "\n", b + n % m - 1);
    }

    return 0;
}
			
		
 


