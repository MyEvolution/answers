#include<stdio.h>
int lookfor(int *num,int left,int right)//O(logN)
{
	int mid;
	
	while(left<=right)//����������û�е��ڵ�������������С�ڣ���ǰ��Ķ�С 
	{         
	mid=(left+right)/2;           //������� ����������Ķ������ 
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
	printf("�밴��С�����˳�������������У������е��ڵ����:\n");
	for(i=0;i<n;i++)
	scanf("%d",&num[i]);
	if(lookfor(num,0,n-1)==1)
	printf("yes\n");
	else printf("no\n");
	
}
