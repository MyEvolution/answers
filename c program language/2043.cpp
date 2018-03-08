#include<stdio.h>
#include<string.h>
main()
{
	char crt[50];
	int n;
	int i,count1,count2,count3,count4;
	scanf("%d",&n);
	getchar();
	while((n--)&&gets(crt))
	{
		
		count1=count2=count3=count4=0;
		for(i=0;i<strlen(crt);i++)
	      if(crt[i]>='A'&&crt[i]<='Z')
	        count1=1;
	        else if(crt[i]>='a'&&crt[i]<'z')
	        count2=1;
	        else if(crt[i]>='0'&&crt[i]<='9')
	        count3=1;
	        else if(crt[i]=='~'||crt[i]=='#'||crt[i]=='@'||crt[i]=='$'||crt[i]=='^'||crt[i]=='!')
	        count4=1;
	        else ;
	if(count1+count2+count3+count4>=3)
	printf("YES\n");
	else printf("NO\n");
	}
 } 
