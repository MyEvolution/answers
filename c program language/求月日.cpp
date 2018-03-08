#include<stdio.h>
static char daytb[2][13]={
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
	};
static char *daytab[]={daytb[0],daytb[1]};//ָ������ 
int day_of_year(int n,int m,int d);
int month_day(int year,int days,int *month,int *day);
main(){
	int year,month,day,days;
	printf("�����������գ�����:1996 12 31����\n");
	scanf("%d",&year);

	scanf("%d",&month); 

	
	scanf("%d",&day);
       days=day_of_year(year,month,day);
       if(days<1) return 0;
	printf("%d��%d���Ǹ����%d��;\n",month,day,days);
	printf("������������\n"); 
	scanf("%d",&days);
	int b=month_day(year,days,&month,&day);
	if(b==1) printf("��%d���Ǹ���%d��%d�ա�\n",days,month,day);
	else return 0;
	
}
int day_of_year(int year,int month,int day){
	int i=0;
	int days;
	int leap;
     leap=year%4==0&&year%100!=0||year%400==0;
         days=day;
         char*p=daytab[leap];
         	if(month>12) {
			 printf("ERROR:��������12��\n");return 0;}
         	if(day>*(p+month)) {
			 printf("ERROR:%d�²���%d�죡\n",month,day);
			 return 0;}
    
	while(p-daytab[leap]<month){
		days+=*p++;
	
	}

		return days;
	
}
int month_day(int year,int days,int *month,int *day){
	int leap;

	
	leap=year%4==0&&year%100!=0||year%400==0;
	if(days>(leap==1?366:365)) {
	printf("ERROR��%d�겻��%d�죡\n",year,days);return 0;}
	  char*p=daytab[leap];
	while(days>*p){
		days-=*p++;
		
	}
	*day=days;
	*month=p-daytab[leap];
	return 1;
}
