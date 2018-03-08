#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 1000
#define ADD_SIZE 100
typedef char ElemType;
typedef struct 
{
	
	int stacksize;
	ElemType *base;
	ElemType *top;
	
}Sqstack;//顺序存储 
typedef struct QNode
{
	ElemType data;
	struct QNode *next;
}Queue;
typedef struct {
	Queue *front;
	Queue *rear;
}LinkQueue;//链式队列 
void Initstack(Sqstack *s);
void push(Sqstack *s,ElemType c);
ElemType pop(Sqstack*);
void creat(LinkQueue *q);
void Insert(LinkQueue *q,ElemType c);
ElemType Quit(LinkQueue *q);
main()
{
	ElemType c;
	LinkQueue q;
	ElemType e; 
	Sqstack s;
	int i=0;
	Initstack(&s);
	creat(&q);
	ElemType lan[MAXSIZE];
	while((c=getchar())!=EOF)
	{
		if(c=='B')
		{
			
		Insert(&q,'t');
		Insert(&q,'s');
		Insert(&q,'a');
		Insert(&q,'e');
		Insert(&q,'d');
		Insert(&q,'s');
		Insert(&q,'a');
		Insert(&q,'e');	
		
		}
		else if(c=='A')
		{
		Insert(&q,'s');
		Insert(&q,'a');
		Insert(&q,'e');		
		}
		else if(c=='(')
		{
			
			e=c=getchar();
			while((c=getchar())!=')')
			push(&s,c);
			
			while(s.base!=s.top)
			{
				Insert(&q,e);
				Insert(&q,pop(&s));
			}
			Insert(&q,e);
		}
		else if(c=='\n'){
			
		      
			  while(q.front!=q.rear)
	    lan[i++]=Quit(&q);
	    lan[i]='\0';
	    printf("翻译后如下:\n%s\n",lan);
	  for(i=0;i<strlen(lan);i++)
	    switch(lan[i])
	    {
	    	case 't':
	    		
	    		printf("天");
	    		break;
	        case 'd':
			   printf("地");
			      break;
			case 's':
			   printf("上");
			   break;		
			case 'a':
			   printf("一只");
			   break;
			case 'e':
			   printf("鹅");
			   break;
			case 'z':
			  printf("追");
			  break;
			case 'x':
			    printf("下");
				break;
			case 'g':
			printf("赶");
			  break;
			case 'n':
			  printf("蛋");
			 break;
			case 'h':
			  printf("恨");
			  break;
			default:
			  break;
			  }    
			  putchar('\n');
			  i=0;
			  lan[0]='\0';
		}
		else 
		   Insert(&q,c);
		    
	  }

		} 
void Initstack(Sqstack*s)
{
   s->top=s->base=(ElemType*)malloc(MAXSIZE*sizeof(ElemType));
   if(s->top==NULL)
     return;
     s->stacksize=MAXSIZE;
   	
}
void push(Sqstack *s,ElemType c)
{
	if(s->top-s->base>=MAXSIZE)
	{
	s->base=(ElemType *)realloc(s->base,(ADD_SIZE*(sizeof(ElemType))+s->stacksize));//给指定的指针重新分配大小为n的地址 
	s->top=s->base+s->stacksize;
	s->stacksize+=ADD_SIZE;
	}
	*s->top++=c;

}
ElemType pop(Sqstack *s)
{
	if(s->base==s->top)
	return '#';
	return *--s->top;
	
}
void creat(LinkQueue *q)
{
	q->front=q->rear=(Queue*)malloc(sizeof(Queue));
	if(q->front==NULL) return ;
	q->front->next=NULL;
}
void Insert(LinkQueue *q,ElemType c)
{
	Queue *p;
	p=(Queue *)malloc(sizeof(Queue));
	if(p==NULL) return ;
	p->data=c;
   q->rear->next=p;
    q->rear=p;
    p->next=NULL;
}
ElemType Quit(LinkQueue*q)
{
	ElemType a;

	if(q->front==q->rear)
	return 0;
    Queue*p;
    if(q->front->next==q->rear)
    {
    	p=q->rear;
    	q->rear=q->front;
	}
    else{
    	p=q->front->next;
    q->front->next=q->front->next->next;
	}
    
    a=p->data;
    free(p);
    return a;
}
