#include<stdio.h>
#include<string.h>
main()
{
	char a[10000];
	char b[10000];
	int i=0,j=0;
	scanf("%s %s",a,b);
     while(a[i]=='0')
         i++;
    while(b[j]=='0')
          j++;
     while(a[i]==b[j]&&a[i]!='.'&&a[i]!='\0')
           i++,j++;  
           if(a[i]==b[j])
           {
           	while(a[i]==b[j]&&a[i]!='\0')
           	i++,j++;
           	if(a[i]=='\0'&&b[j]=='0')
           	while(b[j]=='0')
                  j++;
				else if(b[j]=='\0'&&a[i]=='0')
           	while(a[i]=='0')
                  i++;	             	
		   }
else if((a[i]=='.'&&b[j]=='\0')||(b[j]=='.'&&a[i]=='\0'))
{
	
	if(a[i]=='.') 
	{ 
	 i++;
			while(a[i]=='0')
			  i++;
	}
	else if(b[j]=='.') 
	{ 
	 j++;

			while(b[j]=='0')
			  j++;
	}
}
	          
  if(a[i]=='\0'&&b[j]=='\0')
  printf("YES\n");
  else printf("NO\n");			       
                
}
