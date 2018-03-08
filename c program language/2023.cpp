#include<stdio.h>
main()
{
	double a[50][5];
	int n,m;
	double sum;
	int i,j;
	double avg1[50];//学生的 平均成绩 
	double avg2[5];//课的平均成绩 
	int num=0;
	scanf("%d %d",&n,&m);
	getchar();
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	scanf("%lf",&a[i][j]);
	for(i=0;i<m;i++)
	{
		sum=0.0;
		for(j=0;j<n;j++)
		sum+=a[j][i];
		avg2[i]=sum/n;
	}
	for(i=0;i<n;i++)
	{
		sum=0.0;
		for(j=0;j<m;j++)
		sum+=a[i][j];
		
		avg1[i]=sum/m;
		
	}
	for(i=0;i<n;i++)
	printf(i==(n-1)?"%.2f\n":"%.2f ",avg1[i]);
	for(i=0;i<m;i++)
	printf(i==(m-1)?"%.2f\n":"%.2f ",avg2[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		if(a[i][j]<avg2[j])
		break;
		if(j==m) num++;
	}
	
	
printf("%d\n",num);
	
	
}
