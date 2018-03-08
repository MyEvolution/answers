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
void qsort(int v[],int left,int right)//对v[left]......v[right]递增排序 
{     int i,last;//last表示第一个子集的最后一位 

  if(left>=right) return ;//小于两个元素了 
  swap(v,left,(left+right)/2);
  last = left;
  for(i=left+1;i<right;i++)
  	if(v[i]<v[left]) swap(v,++last,i);
swap(v,last,left);//下标为left储存着第一个子集中最大的元素 
  	qsort(v,left,last);
  	qsort(v,last+1,right);
  
	
}
