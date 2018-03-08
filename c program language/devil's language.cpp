#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define OK 1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct {
        char* base;
        char* top;
int stacksize;
}SpStack;
typedef struct QNode{
	
	char data;
	struct QNode *next;
	}QNode ,*QueuePtr;
typedef struct{
QueuePtr front;
QueuePtr rear;

	
	}LinkQueue;
int InitStack(SpStack&S);
int Push(SpStack&S ,char e);
int Pop(SpStack&S ,char &e);
int InitQueue(LinkQueue&Q);
int EnQueue(LinkQueue&Q,char e);
int DeQueue(LinkQueue&Q,char&e);
	 
int InitStack(SpStack&S){

    S.base=(char*)malloc(STACK_INIT_SIZE*sizeof(char));
   
     S.top=S.base;
     S.stacksize=STACK_INIT_SIZE;
	 return OK;}

     int Push(SpStack&S, char e){
          if(S.top-S.base>=S.stacksize){
          S.base=(char*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(char));
       
          S.top = S.base+S.stacksize;
          S.stacksize+=STACKINCREMENT;}
          *S.top++ =e;
           return OK;
      }
    int Pop(SpStack&S, char &e){
        if(S.top==S.base) return 0;
         e=*--S.top;
      return OK;
       }


int InitQueue(LinkQueue&Q) {
 Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	Q.front->next=NULL;

	 return OK;
}
int EnQueue(LinkQueue&Q,char e){
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	p->data=e;p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	 return OK;
}
int DeQueue(LinkQueue&Q,char&e){
		QueuePtr p;
	p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p) Q.rear=Q.front;
	free(p);
	 return OK;
}	
int main(){
int n,d=0;
char e,f;
char *q;
SpStack S;
LinkQueue Q;
InitStack(S);
InitQueue(Q);
printf("请输入魔王语言:\n");

char b[100];
scanf("%s",b);
q=b;
n=strlen(b);
q=q+n-1;

while(d<n){

while(*q!='('&&d<n){
Push(S,*q);
q--;
d++;}
if(d==n) break;

   
   while(*(S.top-1)!=')'&&d<n){

Pop(S,e);
EnQueue(Q,e);
}

if(*(S.top-1)==')'&&d<n) {Pop(S,e);}

if(Q.front!=Q.rear&&d<n){

DeQueue(Q,f);
Push(S,f); }
while(Q.front!=Q.rear&&d<n){
DeQueue(Q,e);
Push(S,e);
Push(S,f);

}
if(*q=='('){
q--;
d++;
}

}

printf("翻译成为人类的语言为:\n");
while(S.base!=S.top){
Pop(S,e);EnQueue(Q,e);
if(e=='A') {printf("sae");}
else if(e=='B'){ printf("tsaedsae");}
else {printf("%c",e);}



}
printf("\n");
printf("将魔王语言翻译为中文后为：\n");
while(Q.front!=Q.rear){
DeQueue(Q,e);
switch(e){
case't':printf("天");break;
case'd':printf("地");break;
case'a':printf("一只");break;
case'e':printf("鹅");break;
case'z':printf("追");break;
case'g':printf("赶");break;
case'h':printf("恨");break;
case's':printf("上");break;
case'x':printf("下");break;
case'n':printf("蛋");break;
case'A':printf("上一只鹅");break;
case'B':printf("天上一只鹅地上一只鹅");break;
default:printf("*");break;

}

}
system("pause");
return 0;

}

