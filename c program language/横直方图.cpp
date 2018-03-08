
#include<stdio.h>
#define SIZE 15
#define IN 1
#define OUT 0
 main()
{
   int c,nl=0;
   int i;
   int state=OUT;
   int a[SIZE];
   for(i=0;i<SIZE;i++){
   	a[i]=0;
   }
   while((c=getchar())!=EOF){
   	if(c=='\n'||c=='\t'||c==' '){
   		a[nl-1]++;
   		state=OUT;
   		nl=0;
   	
	   }
	   else if(state==OUT){
	   state=IN;

	   }
	   if(state==IN){
	   	nl++;
	   }
	   
   }
   int j;
   for(i=0;i<SIZE;i++){
   	printf("%3d |",i+1);
   	for(j=0;j<a[i];j++){
   		putchar('*');
	   }
   	printf("\n");
   }
 
}
