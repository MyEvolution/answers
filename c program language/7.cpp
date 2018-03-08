#include<stdio.h>
#include<string.h>
/*main()//À„ ı µœ÷ 
{    
    int i=0;
     double num;
	scanf("%lf",&num);


   long long p=(long long)num;
	while(p!=0)
	{
		 i++;
	p /=10;
	}
	printf("%d",i);
}*/
main()
{    
       int i,j;
	char num[60];
	scanf("%s",num);
	for(i=0;i<strlen(num);i++)
		if(num[i]=='.')
		
			break;
		
		

	for(j=0;j<strlen(num);j++)
	
		if(num[j]!='0')
		
			break;
		
printf("%d",i-j);
}
