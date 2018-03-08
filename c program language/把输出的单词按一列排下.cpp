#include<stdio.h>
 main(){
	int c,num=0,state=0;
	while((c=getchar())!=EOF){
	
		if(c==' '||c=='\t'||c=='\n'){
			state=0;
					printf("\n");
				c=getchar();
			while(c==' '||c=='\t'||c=='\n'){
		

	 	c=getchar();
	
		
	}}
		if(c==EOF) break;
	if(state==0) {
		state=1;
		num++;
	}

	putchar(c);

	
}
printf("一共有%d个单词",num);
}
