#include<stdio.h>
main()
{
	int a[5]={0,0,0,0,0};//aeiou
	int c,i;
	while((c=getchar())!=EOF)
	{
		
		switch(c){
			case 'a':
			  a[0]++;
			  break;
			  case 'e':
			  	a[1]++;
			  	break;
			 case 'i':
			 a[2]++;
			 break;
			 case 'o':
			 a[3]++;
			 break;
			 case 'u':
			 a[4]++;
			 break;
			 default:
			 break; 	
		}
		if(c=='\n')
		{
			printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",a[0],a[1],a[2],a[3],a[4]);
			for(i=0;i<5;i++)
			a[i]=0;
		}
	}
}
