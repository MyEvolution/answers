#include<stdio.h>
#define N 0xa0//汉字机内码 
main()
{
	char c;//定义为char型，因为char可以储存的最大字节是1，也就是范围为11111111，而汉字机内码的值超过他，就会变成负数 
	int num;//若定义为int型 ，则根据汉字机内码判断，大于N 
	int n;
	int i=0;
	scanf("%d",&n);
	getchar();
	while(i<n)
	{
		num=0;
		while((c=getchar())!='\n')
		if(c<0)
		num++;
		printf("%d\n",num/2);//每个汉子占两个字节，所以要除以2 
		i++;
		
	}


					
	}
/*#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    int count;
    char c;

    scanf("%d%*c", &n);

    while (n--)
    {
        count = 0;

        while ((c = getchar()) != '\n')
        {
            if (c < 0)
                count++;
        }

        printf("%d\n", count / 2);
    }

    return 0;
}*/
	
