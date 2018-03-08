#include<time.h> 
#include<stdio.h>
#include<stdlib.h> 
main(){ 
int i,a[10]; 
srand(time(0));
for(i=0;i<10;i++) 
a[i]=rand()%10; 
for(i=0;i<10;i++) 
printf("%d\n",a[i]); 
} 
