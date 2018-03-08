#include<stdio.h>//echo的一个版本 
/*main(int argc,char **argv){
	while(--argc>0)
	printf("%s%s",*++argv,argc>1?" ":"");
	putchar('\n');
	  
} */
//另一个版本
main(int argc,char **argv){
	int i=1;
	while(i<argc){
		printf("%s%s",argv[i++],i<argc?" ":"");
	}
	putchar('\n');
} 
