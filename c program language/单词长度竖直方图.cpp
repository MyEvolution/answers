
#include<stdio.h>
#define NUM 10//每个长度下单词个数 
#define SIZE 15//最大单词长度 
#define IN 1
#define OUT 0
 main()
{
   int c,nl=0,p=0;
   int i;
   int state=OUT;
   int a[SIZE+1];
   for(i=0;i<=SIZE;i++){
   	a[i]=0;
   }
   while((c=getchar())!=EOF){
   	if(c=='\n'||c=='\t'||c==' '){
   		if(nl>SIZE) a[SIZE]++;
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
   int j,k;
   for(k=NUM;k>0;k--){
   	printf("%3d|",k);
   	for(i=0;i<=SIZE;i++){
   		if(a[i]>=k) {
   			  	putchar(' ');
		   putchar('*');
		   	putchar(' ');
		   }
   	else{
	   	putchar(' ');
   		  	putchar(' ');
   		  	  	putchar(' ');}
	   }
   	printf("\n");
   }
   printf("   ");
   putchar('|');
   for(i=0;i<=SIZE;i++){
   	putchar('-');
   	putchar('-');
   	putchar('-');
   	
   }

   printf("\n");
   printf("%3d ",0);
   for(i=0;i<SIZE;i++){
   	printf("%2d ",i+1);
   }
 printf(">15\n");
 printf("    ");
 for(i=0;i<=SIZE;i++){
 	if(a[i]>NUM)
 	    {printf("out");} 
 	 else  printf("   ");
 	
 }
   
 
}
