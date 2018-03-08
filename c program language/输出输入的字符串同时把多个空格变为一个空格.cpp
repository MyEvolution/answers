#include<stdio.h>

main(){


int c;
c=getchar();
while(c!=EOF){
if(c==' '){
	putchar(c);
		c=getchar();
while(c==' ')  {
	c=getchar();
}


		
	}
	putchar(c);
	c=getchar();
}

	

}
     

