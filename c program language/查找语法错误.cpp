#include<stdio.h>
#define ERROR 0
#define OK 1
#define MAXSIZE 1000
int single(void);//��鵥�����Ƿ�ɶԵĺ����� 
int pair(void);//���˫���ţ� 
int note(int a);
int list[2];//���/*���͵�ע�ͷ� 
int bracket(char a[],int z);//�ж������Ƿ�ɶ� 
main(){

	int c;
	int s[MAXSIZE];//ͨ����ֵ�жϵ������Ƿ����  
	int p[MAXSIZE];//ͨ����ֵ�ж�˫�����Ƿ���� 
	char bket[MAXSIZE];
	int i=0;
	int j=0;
	int z=0;//���ŵĸ��� 

	int b=2;//ͨ����ֵ�ж�ע�ͷ��Ƿ�ɶԣ� 
	int n=1;
	while((c=getchar())!=EOF){
	if(c=='/'){
		c=getchar();
		if(c=='/'){
			c=getchar();
			while(c!='\n'){
				c=getchar();
			}
		}
		else if(c=='*'){
			b=0;
			while(b==0||b==1){
				
			b=note(b);	
			 
			}
			if(b==-1){
				break;
			}
		}
	}
	else if(c=='\''){
	
	 	
	 	s[i]=single();
	 	i++;
	 	
	 	
	 	
	 }
	else if(c=='\"'){
		p[j]=pair();
		j++;
		
	}
	else if(c=='('||c=='{'||c=='['||c==')'||c=='}'||c==']'||c=='<'||c=='>') {
		bket[z]=c;//�����ŷŵ������ 
		z++;
		
	
	}
	else if(c=='\\'){
		c=getchar();
	
	}	
	} 

	if(b!=2){
		printf("ERROR:ע�ͷ����ɶ�\n"); 
	}
	int q=0;
	while(q<i){
		if(s[q]!=OK){
			printf("ERROR:�����Ų��ɶ�\n");
			break;
		}
		q++;
	}
    int	m=0;
	while(m<j){
		if(p[m]!=OK){
			printf("ERROR:˫���Ų��ɶ�\n");
			break;
		}
		m++;
	}
	n=bracket(bket,z);
	if(n==OK&&b==2&&q==i&&m==j){
		printf("OK\n");
	}
} 
int single(void){
	char c;
	while((c=getchar())!='\''&&c!='\n'){
		;
	}

	if(c=='\n'){
		return ERROR;
	}
	else return OK;
}
int pair(void){
		char c;

	while((c=getchar())!='\"'&&c!='\n'){
		;
	}

	if(c=='\n'){
		return ERROR;
	}
	else return OK;
	
}
int note(int a){
	int i;
for(i=a;i<2;i++){
	list[i]=getchar();
	if(list[i]==EOF) return -1;
}
	
	if(list[1]=='*'){
		list[0]=list[1];
		return 1;
	}
	else if(list[1]=='/'&&list[0]=='*') return 2;
	else return 0;
	
	
}
int bracket(char a[],int z){

	int o,x=0;
    if(z==0) return OK;
	if(a[0]=='}'||a[0]==']'||a[0]==')'||a[0]=='>') {
		printf("ERROR:'%c'�����\n",a[0]);
	return ERROR;}
	char line[MAXSIZE];
	for(o=0;o<z;o++){
		if(a[o]=='('||a[o]=='{'||a[o]=='['||a[o]=='<'){
			line[x]=a[o];
			x++;
			
		}
		else if(a[o]=='}'){
			if(line[x-1]=='{') x=x-1;
			else {
			printf("ERROR����{}�������\n"); 
			return ERROR;}
			
		}
	    else if(a[o]==']'){
	    	if(line[x-1]=='[') x=x-1;
			else {
			printf("ERROR����[]�������\n"); 
			return ERROR;}	
	    }
	    else if(a[o]==')'){
	    	if(line[x-1]=='(') x=x-1;
			else {
			printf("ERROR����()�������\n"); 
			return ERROR;}
		}
		 else if(a[o]=='>'){
	    	if(line[x-1]=='<') x=x-1;
			else {
			printf("ERROR����<>�������\n"); 
			return ERROR;}
		}
	}
	    
	    if(x!=0)  {
	    	printf("ERROR:'%c'�����\n",line[0]);
		return ERROR;}
		else return OK;
		
	
}
