#include<stdio.h>
/*int num(int );
main()
{
	int c;
	while(scanf("%d",&c)!=EOF)
	{
		getchar();
		if(c==0) break;
		else 
		printf("%d\n",num(c));
		
		
	}
}
int num(int year)
{
	if(year<4)
	return year;//1 2 3 4 6 9 13 19 28 41 
    else return num(year-1)+num(year-3);
}*/
main()
{
	int n;
	int i;
	while(scanf("%d",&n)&&n!=0)
	{
	int age[4]={1,0,0,0};//age[0]表示可以生小牛了 
	for(i=1;i<n;i++)
	{
	    age[0]+=age[3];
	    age[3]=age[2];
	    age[2]=age[1];
	    age[1]=age[0];
	    
	}
	printf("%d\n",(age[0]+age[1]+age[2]+age[3]));
	}

}

