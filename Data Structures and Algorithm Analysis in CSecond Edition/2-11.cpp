#include<stdio.h>
int lookfor(int *num,int left,int right)//O(logN)
{
	int mid;
	
	while(left<=right)//排列有序并且没有等于的情况，所以如果小于，他前面的都小 
	{         
	mid=(left+right)/2;           //如果大于 ，则他后面的都会大于 
		if(num[mid]>mid)
		  right=mid-1;
		  else if(num[mid]<mid)
		    left=mid+1;
		    else return 1;
	}
	return 0;
	
}
main()
{
	int n;
	int num[1000];
	int i;
	scanf("%d",&n);
	printf("请按从小到大的顺序输入整数数列，不能有等于的情况:\n");
	for(i=0;i<n;i++)
	scanf("%d",&num[i]);
	if(lookfor(num,0,n-1)==1)
	printf("yes\n");
	else printf("no\n");
	
}
