#include<stdio.h>
#include<string.h>
void reverser(char [],int i,int j);
void reverse(char s[]); 
void swap(char [],int i,int j);
void reverse(char []);
main(){
	char s[100];
	scanf("%s",&s);
	reverse(s);
	printf("%s",s);
	
}
void reverse(char s[]){
   reverser(s,0,strlen(s)-1);
}
void swap(char v[],int i,int j){
	char temp;
	temp=v[i];
	v[i]=v[j];
	v[j]=temp;
}
/*void reverser(char s[],int left,int right){
	int i;
	int j;
	if(left>=right) return;
	int mid = (left+right)/2;
	int y=(left+right)%2;

	if(y==0){
	
               for(i=left,j=0;i<mid;i++,j++)
	                swap(s,i,mid+j+1);
	               
		reverser(s,left,mid-1);
	    reverser(s,mid+1,right);	
					}
	                
	   
	    else {
	    	for(i=left,j=0;i<mid+1;i++,j++)
	    	  swap(s,i,mid+y+j);
	    	reverser(s,left,mid);
	    	reverser(s,mid+1,right);
	    	
		}
	  
	}*/
	void reverser(char s[],int i,int len){
		if(i<=len){
			swap(s,i,len);
			reverser(s,++i,--len);
		}
		else return ;
	}
