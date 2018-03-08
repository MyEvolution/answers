#include<stdio.h>
#include<string.h>
#define MAXSIZE 100
int _day(int ,int ,int);
int getline(char *l,int max);
char day[2][12]=
{
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31}
};
main()
{     
        
        int year,month,day;
       char line[MAXSIZE];
       while(getline(line,MAXSIZE)>0)
       {
       	   sscanf(line,"%d/%d/%d",&year,&month,&day);
          
           printf("%d\n",_day(year,month,day));
	   }

}
int _day(int y,int m,int d)
{
	int _year;
	int sum=0;
	int i;
	_year=(y%4==0&&y%100!=0||y%400==0)?1:0;
	for(i=0;i<m-1;i++)
	sum+=day[_year][i];
	sum+=d;
	return sum;
	
}
int getline(char *l,int max)
{
	char *q=l;
	int c;
	while((c=getchar())!=EOF&&c!='\n'&&q-l<max)
		*q++=c;
		if(c=='\n')
		{
			*q++='\n';
			*q='\0';
		}
		
	return q-l;
}
