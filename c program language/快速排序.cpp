#include<stdio.h>
void swap(int [],int i,int j);
void qsort(int [],int left,int right);
main(){
int i; 
	int c[10];
	for(i=0;i<10;i++) 
	scanf("%d",&c[i]);
   qsort(c,0,10);
   for(i=0;i<10;i++)
   printf("%d ",c[i]);
 
	
}

void swap(int v[],int i,int j){
	int temp;
 temp=v[i];
   v[i]=v[j];
   v[j]=temp;
}
void qsort(int v[],int left,int right)//��v[left]......v[right]�������� 
{     int i,last;//last��ʾ��һ���Ӽ������һλ 

  if(left>=right) return ;//С������Ԫ���� 
  swap(v,left,(left+right)/2);
  last = left;
  for(i=left+1;i<right;i++)
  	if(v[i]<v[left]) swap(v,++last,i);
swap(v,last,left);//�±�Ϊleft�����ŵ�һ���Ӽ�������Ԫ�� 
  	qsort(v,left,last);
  	qsort(v,last+1,right);
  
	
}
