#include<stdio.h>
#include<math.h>
#include<string.h>
main()
{    
      int i;  
    int n;
	scanf("%d",&n);
	getchar();
	char a[100];
	scanf("%s",a);
	int b;
	int sum=0;
	for(i=0,b=strlen(a);i<b;i++)
	{
		sum+=pow(n,(b-1-i))*(a[i]-'0');
	}
	printf("%d",sum);
}
