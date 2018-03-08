#include<stdio.h>
int binsearch(int x,int v[],int n);
main(){
	int a[1000];
	int n,i=0;
	scanf("%d",&n);
	while(i<n){
	
	scanf("%d",&a[i]);
	i++;

}
printf("%d",binsearch(100,a,n));
}
 /*int binsearch(int x,int v[],int n){
	int mid,high,low;
	high=n-1;
	low=0;
	while(high>=low){
		mid=(low+high)/2;
		if(v[mid]>x) high=mid-1;
		else if(v[mid]<x) low=mid+1;
		else return mid;
	}
	return -1;
}*/
int binsearch(int x,int v[],int n){
	int high,mid,low;
	low=0;high=n-1;
	
	while(v[mid]!=x&&low<=high){
	mid=(low+high)/2;
		if(v[mid]>x) high=mid-1;
		else low=mid+1;
		mid=(low+high)/2;
	}
	if(high>=low)
	return mid;
	else return -1;
}

