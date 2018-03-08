#include<stdio.h>
#include<string.h>
#include<stdlib.h>
static char daytb[2][13]={
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
	};
int main()
{
	char c[2];
	int day,month,year;
	char date[10];
	char dat[10];//date的复制 
	const  char delim[2]="/";
	
	char *d,*m,*y;
	int da,mo,ye;
	int run;//闰年 
	while(printf("(I) Enter a date\n(Q) Quit\n"),scanf("%s",c),strcmp(c,"Q"))
	{
		if(strcmp(c,"I"))
		{
			printf("unknown order!\n");
			continue;
		}
		scanf("%s",date);
		getchar();
		strcpy(dat,date);
		
		d=strtok(date,delim);
		m=strtok(NULL,delim);
		y=strtok(NULL,delim);
		if(strlen(d)!=2||strlen(m)!=2||strlen(y)!=2)
      	{
		printf("Invalid date format:%s\n",dat);
     	}
         else
		  {
		  	da=atoi(d);
		  	mo=atoi(m);
		  	ye=atoi(y)>16?1900+atoi(y):2000+atoi(y);//年份 
		  	run=ye%400==0||(ye%4==0&&ye%100!=0)?1:0;//判断是否是闰年 
		  	if(mo>12||mo<=0||da>daytb[run][mo]||da<=0)
		  		printf("Invalid date format:%s\n",dat);
		  	 else
			   	printf("The date is %s/%s/%d\n",d,m,ye);
				
		  }
	}
	return 0;
}
