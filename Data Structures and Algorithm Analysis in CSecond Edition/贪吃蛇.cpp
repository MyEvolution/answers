#include<stdlib.h>
#include<stdio.h>
#include<time.h> 
#include<conio.h>
#include<windows.h>
#define C 50 
#define D 20 
#define RIGHT 0
#define LEFT 1 
#define UP 2
#define DOWN 3

int Space [D][C];
void DefineSpace(void)//首先确定下空间   也就是整个游戏的边界 
{
	int i,j;
	    i=0;
     while(i<D)
     {
     	if(i==0||i==D-1)	
     	  for(j=0;j<C;j++)
     	Space[i][j]=004;	 

     	else
     	{
     		Space[i][0]=Space[i][C-1]=004;
     		 for(j=1;j<C-1;j++)
     		 Space[i][j]=' ';
		 }
       i++;
	 }
}
typedef struct
{
	int x;//横坐标
	int y;//纵坐标 
 }F;//定义坐标体制 
 typedef struct 
 {
 	F food;
 	int ISEAT;//是否被吃掉 
 }fo,*Food;
typedef struct Node
{
    F Body[100];//最长 
    int size;//蛇的身长
	int life;//蛇的死活 
	int dir;//蛇运动的方向 
	int Add;//表示蛇身是否应该伸长 
 } *snake;
snake Create(void)
{
  snake s;
  s=(snake)malloc(sizeof(*s));
  if(s==NULL)
  {
  	printf("Can not Create a Snake!\n");
  	return NULL;
  }
  s->life=1;//1表示活着
  s->size=1;//表示蛇的身长为1
  s->Body[0].x=C/2;//刚出生的蛇是诞生在屏幕的中央 
  s->Body[0].y=D/2;  
  s->dir=RIGHT;//刚出生的蛇，默认向右移动 
  s->Add=0;
  return s; 
};
int RandInt(int c)//随机生成C以内的数字 
{
	srand(unsigned(time(NULL)));
	return rand()%(c-2)+1;//把0和c-1都要排除掉  所以实际上是1到c-2 
 }
int IsHit(snake s,int x,int y)
{
	int i;
	for(i=0;i<s->size;i++)
	if(s->Body[i].x==x&&s->Body[i].y==y)
	  return 1;
	  return 0;
}
void CreateFood(Food f,snake s)
{
	
   if(f->ISEAT==1)
   {
   	f->food.x=RandInt(C);
   	f->food.y=RandInt(D);  //生成一个随机的作标 
     while(IsHit(s,f->food.x,f->food.y))
     {
        f->food.x=RandInt(C);
   	    f->food.y=RandInt(D);
	 }
	f->ISEAT=0;
   }
}
void Print(snake s,Food f)
{
	int i,j;
	for(i=1;i<s->size;i++)
	Space[s->Body[i].y][s->Body[i].x]=001;
	Space[s->Body[0].y][s->Body[0].x]=002;
	Space[f->food.y][f->food.x]=003;
	for(i=0;i<D;i++)
	{
	  for(j=0;j<C;j++)
       putchar(Space[i][j]);
	   putchar('\n');		//到边界处换行 
	}	  
}
void SnakeMove(snake s)
{
	int c;
	int i;
	if(_kbhit()) 
	{
		c=getch();
		if(c=='w'&&s->dir!=DOWN)
		s->dir=UP;
		else if(c=='s'&&s->dir!=UP)
		s->dir=DOWN;
		else if(c=='a'&&s->dir!=RIGHT)
		s->dir=LEFT;
		else if(c=='d'&&s->dir!=LEFT)
		   s->dir=RIGHT;
		   
  }
      if(s->Add==1)
      {
      	s->Body[s->size].x=s->Body[s->size-1].x;
      	s->Body[s->size].y=s->Body[s->size-1].y;
      	s->size++;
      	s->Add=0;
	  }
	  else Space[s->Body[s->size-1].y][s->Body[s->size-1].x]=' ';
  		for(i=s->size-1;i>0;i--)// 
		{
			s->Body[i].x=s->Body[i-1].x;
			s->Body[i].y=s->Body[i-1].y;
		}
  if(s->dir==RIGHT)//在这里是控制蛇的移动的 
    s->Body[0].x++;
    else if(s->dir==LEFT)
    s->Body[0].x--;
    else if(s->dir==UP)
    s->Body[0].y--;
    else if(s->dir==DOWN)
    s->Body[0].y++;
}
void AddSize(snake s,Food f)
{
	if(IsHit(s,f->food.x,f->food.y))
	{		
        s->Add=1;	 
	 f->ISEAT=1;//被吃掉了 
	 	
	}
		//这里比想象中要容易一点
		//因为吃的运动实际上也就是在移动  所以不用特别说明  只用把size+1；这样到时候move函数会自动把这一截填上 
		//出错了 看来不是我想的那样
		//因为每次都要清尾部
	 
}
void IsAlive(snake s)
{
	int i;
	if(s->Body[0].x==0||s->Body[0].x==C-1||s->Body[0].y==0||s->Body[0].y==D-1)
	s->life=0;
	else
	{
		for(i=3;i<s->size;i++)
		if(s->Body[i].x==s->Body[0].x&&s->Body[i].y==s->Body[0].y) 
		   {
		   	s->life=0;
		   break;
		   }	
	}
}
 int main()
{
	
	DefineSpace();
	snake s;
	s=Create();
	fo o;//定义一个食物的变量 
	o.ISEAT=1;
	Food f=&o;//因为函数中用的大都是指针 所以还是用指针指向它，方便操作 
    printf("■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("■          本游戏用wasd控制上下左右          ■\n");
    printf("■              请选择难度：                  ■\n");
    printf("■                (1)easy                     ■\n");
    printf("■                (2)medium                   ■\n");
    printf("■                (3)difficult                ■\n");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■\n");
	int n,c;
	if((c=getchar())=='1')
	n=1000;
	else if(c=='2')
	n=100;
	else if(c=='3')
	n=30;
	else 
	  n=1;
	  getchar();
	system("cls");

	while(s->life==1)
	{
		
		CreateFood(f,s);//食物被吃掉的时候生成食物	
			Print(s,f);
		SnakeMove(s);
	   AddSize(s,f);
		IsAlive(s); 
		if(n==1000)
		  printf("Easy_Mode    ");
		  else if(n==100)
		  printf("Medium_Mode    ");
		  else 
		  printf("Difficult_Mode   ");
		  printf("haha");
		printf("Score:%d\n",(s->size-1)*1000/n);

		Sleep(n);//暂停100毫秒 
		system("cls");
		
	 } 
    printf("■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("■                 GAME OVER                  ■\n");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■\n");
 	return 0;
 }
