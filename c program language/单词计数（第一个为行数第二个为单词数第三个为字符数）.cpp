#include<stdio.h>

main(){
int c,nl,nw,nc,state;
state=0;
nl=nw=nc=0;
while((c=getchar())!=EOF){
	
	++nc;
	if(c=='\n') ++nl;
	if(c==' '||c=='\n'||c=='\t') {
		
		state=0;
	}
   else if(state==0){
   	++nw;
   	state=1;
   }
}

printf("%d %d %d",nl,nw,nc);


}
