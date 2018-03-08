#include <stdio.h>
	char line[2];
int search(int pos);//检查后来输入的文本是不是注释结束符*/ 

main(){

	int b=0,c;
	while((c=getchar())!=EOF){
		if(c=='\''||c=='\"'){
			putchar(c);
			if(c=='\''){
			
			while((c=getchar())!='\''&&c!='\n'){
				putchar(c);
			}
			putchar(c);
		}
		else if(c=='\"'){
				while((c=getchar())!='\"'&&c!='\n'){
				putchar(c);
			
		}
		putchar(c);
	}}
		else if(c=='/'){
			c=getchar();
			if(c=='/'){
				c=getchar();
				while(c!='\n'){
				
				c=getchar();}
				putchar(c);
			}
			else if(c=='*'){ 
			b=search(b);
			while(b!=0){
				if(b!=1) b=search(0);
				else b=search(1);
			
			}
		putchar(' ');
				
				}
		
				else{
				 putchar('/');
				putchar(c);
			}
			}
			
	else putchar(c);		
			
			}
		}
	
	

int search(int pos){
	
	
	int i;
for(i=pos;i<2;i++){
	line[i]=getchar();
}
if(line[1]=='*'){
	line[0]='*';
	
		 return 1;
	}
	else if(line[1]=='/'&&line[0]=='*') return 0;
	else return -1;


}


