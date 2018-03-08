#include<stdio.h>
#define NUM 10 
main(){
	int a[12];
	int c,i,num=0;

	for(i=0;i<12;i++){
		a[i]=0;
	}
	while((c=getchar())!=EOF){
		
		if(c>='0'&&c<='9'){
			++a[c-'0'];
		}
		
		else if(c==' '||c=='\n'||c=='\t') a[10]++;
		else a[11]++; 
		
		num++;
	}
	int k;
	for(k=NUM;k>0;k--){
		printf("%3d|",k);
		for(i=0;i<12;i++){
		
		if(a[i]>=k){
			printf(" * ");
			
		}
		else printf("   ");
		
		
		}
		printf("\n");
		
	}
	printf("%3d ",0);
	for(i=0;i<12;i++){
		printf("---");
	}
	printf("\n");
	printf("    ");
	for(i=0;i<10;i++){
		printf("%2d ",i);
		
	}
	
	printf("( )rest\n");
	
 printf("    ");
 for(i=0;i<12;i++){
 	if(a[i]>NUM)
 	    {printf("out");} 
 	 else  printf("   ");
 	
 }
	
	} 
