#include <stdlib.h>
#include <graphics.h>
#include <stdio.h>
#include <time.h>
typedef struct Link/*双链表结点定义*/
{
   int data;
   struct Link *right;
   struct Link *left;
   int num;/*给链表加序号,为了演示时计算正确位置*/
}linkx,*linky;
void Init(void);/*图形驱动*/
void Close(void);/*图形关闭*/
void InitList(void);/*建立双链表,边建立边插入*/
void PrLink(linky p,int n);/*每次插入后输出链表*/
void DrawChange(int data,int i,int n);/*画链表插入的指针变化*/
void main(void)
{
   Init();/*图形驱动*/
   InitList();/*建立链表*/
   Close();/*图形关闭*/
   exit(0);
}

int random(int number) /*随机数生成*/
{ 
  return (int)(number/(float)RAND_MAX * rand()); 
} 



void InitList(void) /*建立双向链表,边建立边插入*/
{
   linky head,p,q,s;/*head头结点  s是随机产生的结点*/
   int n=0;
   char str[5];
   srand(time(NULL));
   rand();/*随机数发生机*/
   setcolor(BLUE);
   outtextxy(200,20,"按任意键开始程序");
   getchar();
   head=s=(linky)malloc(sizeof(linkx));
   s->data=rand()%100;/*随机生成100以内的数字*/
   s->num=n;
   sprintf(str,"%d",s->data);/*将数字转换成字符串并输出*/
   setfont(20,0,"宋体");
   setcolor(WHITE);
   outtextxy(50,50,"节点数据:");
   outtextxy(50,70,"双链表:");
   setcolor(WHITE);
   outtextxy(155+n*35,50,str);/*显示数据*/
   getchar();
   s->right=NULL;
   s->left=NULL;
   PrLink(head,n);/*每次插入新数字后都显示当前链表*/
   n++;
   while(n!=8)
   {
      s=(linky)malloc(sizeof(linkx));
      s->data=rand()%100;
      s->num=n;
      sprintf(str,"%d",s->data);/*将数字转换成字符串并输出*/
      setcolor(WHITE);
      outtextxy(155+n*35,50,str);
      getchar();
      p=head;/*每生成一个结点，将该结点插入到有序双链表中*/
      if(s->data<=head->data)/*小于头结点，插在头*/
      {
	 DrawChange(s->data,-1,n);/*显示插入的具体过程*/
	 s->right=head;
	 s->left=NULL;
	 s->num=0;
	 head->left=s;
	 head=s;
	 q=head->right;
	 while(q!=NULL)/*后面所有数的序号都加1，相当于数据后移*/
	 {
	    q->num++;
	    q=q->right;
	 }
      }
    else/*其他情况*/
    {
      while(s->data > p->data&&p!=NULL)
      {
	 q=p;
	 p=p->right;
     }
      if(p==NULL)//这个数是当前最大的数，插在尾部
      {
	 DrawChange(s->data,n-1,n);//显示插入的具体过程
	 q->right=s;
	 s->right=NULL;
	 s->left=q;
	 s->num=n;
      }
      else  //结点插入位置位于两数之间
      {
	 q->right->left=s;
	 s->right=q->right;
	 s->left=q;
	 q->right=s;
	 s->num=q->num+1;
	 DrawChange(s->data,q->num,n);/*显示插入的具体过程*/
	 s=s->right;
	 while(s!=NULL) /*后面所有数的序号都加1*/
	 {
	    s->num++;
	    s=s->right;
	 }
     }
   }
   PrLink(head,n);/*每次插入新数据后都显示新链表*/
   n++;
   }
}
/*画链表插入的具体过程，data是要插入的数据，i为插入结点前驱结点序号，n为当前结点个数，先将前驱结点和后继之间的指针线擦除，显示新结点插入过程，插入后擦除插入过程，恢复删除的前驱结点的指针线*/
void DrawChange(int data,int i,int n)
{
   char str[5];
   setfillstyle(SOLID_FILL,BLACK);
   setcolor(RED);/*插入链表的新数据用红色显示*/
   sprintf(str,"%d",data);
   outtextxy(55+70*i+35,100+n*50,str);/*输出插入的位置*/
   bar(50+70*i+35,100+(n-1)*50-20,50+70*i+65,100+(n-1)*50+20);
   /*去除插入结点位置原结点间的指针线*/
   setcolor(BLUE);/*线的颜色*/
   if(i!=-1) /*不是插在头，新结点的前驱指针线*/
   {
      line(50+70*i+34,100+n*50,50+70*i+30,100+n*50);
      line(50+70*i+30,100+n*50,50+70*i+30,100+n*50-25);
      line(50+70*i+30,100+n*50-25,50+70*i+27,100+n*50-22);
      line(50+70*i+30,100+n*50-25,50+70*i+33,100+n*50-22);
      getchar();
   }
   if(i!=n-1)/*不是插在尾，新结点的后继指针线*/
   {
      line(50+70*i+61,100+n*50,50+70*i+65,100+n*50);
      line(50+70*i+65,100+n*50,50+70*i+65,100+n*50-25);
      line(50+70*i+65,100+n*50-25,50+70*i+62,100+n*50-22);
      line(50+70*i+65,100+n*50-25,50+70*i+68,100+n*50-22);
      getchar();
   }
   setcolor(GREEN);
   if(i!=-1)/*不是插在头，新结点前驱结点的后继指针线*/
   {
      line(50+70*i+20,100+n*50-25,50+70*i+20,110+n*50);
      line(50+70*i+20,110+n*50,50+70*i+34,110+n*50);
      line(50+70*i+34,110+n*50,50+70*i+31,110+n*50-3);
      line(50+70*i+34,110+n*50,50+70*i+31,110+n*50+3);
      getchar();
   }
   setcolor(GREEN);
   if(i!=n-1) /*不是插在尾，新结点后继结点的前驱指针线*/
   {
      line(50+70*i+75,100+n*50-25,50+70*i+75,110+n*50);
      line(50+70*i+75,110+n*50,50+70*i+61,110+n*50);
      line(50+70*i+61,110+n*50,50+70*i+64,110+n*50-3);
      line(50+70*i+61,110+n*50,50+70*i+64,110+n*50+3);
      getchar();
   }
   setcolor(GREEN);
   if(i!=n-1&&i!=-1)/*第一个节点和最后一个结点不恢复指针*/
   {
      line(50+70*i+35,100+(n-1)*50,50+70*i+65,100+(n-1)*50);/*画前驱指针*/
      line(50+70*i+35,100+(n-1)*50,50+70*i+40,95+(n-1)*50);
      line(50+70*i+35,110+(n-1)*50,50+70*i+65,110+(n-1)*50);/*画右指针*/
      line(50+70*i+65,110+(n-1)*50,50+70*i+60,115+(n-1)*50);
   }
   bar(0,100+(n-1)*50+21,640,120+n*50);/*擦掉插入过程的指针线*/
}
void PrLink(linky p,int n)/*每次插入后输出链表*/
{
   char str[20];
   while(p!=NULL)/*不为空就输出*/
   {
      sprintf(str,"%d",p->data);
      setcolor(GREEN);
      outtextxy(55+70*p->num,100+n*50,str); /*输出数据*/
      setcolor(RED);/*链表双向箭头*/
      if(p->left!=NULL)/*第一个节点不显示左指针*/
      {
	 line(50+70*(p->num-1)+35,100+n*50,50+70*(p->num-1)+65,
	     100+n*50);/*画左指针*/
	 line(50+70*(p->num-1)+35,100+n*50,50+70*(p->num-1)+
	     40,95+n*50);
      }
      if(p->right!=NULL)
      {
	 line(50+70*p->num+35,110+n*50,50+70*p->num+65,110+n*50);/*画右指针*/
	 line(50+70*p->num+65,110+n*50,50+70*p->num+60,115+n*50);
      }
      p=p->right;
   }
}
void Init(void)/*图形驱动*/
{
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"c:\\tc");   
   cleardevice();
}
void Close(void)/*图形关闭*/
{
   getchar();
   closegraph();
}


