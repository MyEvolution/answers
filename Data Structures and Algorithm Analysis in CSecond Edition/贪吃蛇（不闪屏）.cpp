#include<stdlib.h>
#include<stdio.h>
#include<time.h> 
#include<conio.h>
#include<windows.h>
#define C 50
#define D 20 
#define FOOD '0'
#define SNAKE '*'
#define EDGE 'o'
#define RIGHT 0
#define LEFT 1 
#define UP 2
#define DOWN 3
#define EASY 1000
#define MEDIUM 500
#define DIFFICULT 250
#define CRAZY 125
#define DEVIL 62
int gotoxy(int x,int y)
{
	HANDLE hout;
	COORD coord={0,0};
	coord.X=x;
	coord.Y=y;
	hout=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout,coord);
}
//�ѹ���ƶ�����x��y�� 
int Space[D][C];
void DefineSpace(void)//����ȷ���¿ռ�   Ҳ����������Ϸ�ı߽� 
{
	int i,j;
	    i=0;
     while(i<D)
     {
     	if(i==0||i==D-1)	
     	  for(j=0;j<C;j++)
     	Space[i][j]=EDGE;	 

     	else
     	{
     		Space[i][0]=Space[i][C-1]=EDGE;
     		 for(j=1;j<C-1;j++)
     		 Space[i][j]=' ';
		 }
       i++;
	 }
}
typedef struct
{
	int x;//������
	int y;//������ 
 }F;//������������ 
 typedef struct 
 {
 	F food;
 	int ISEAT;//�Ƿ񱻳Ե� 
 }fo,*Food;
typedef struct Node
{
    F Body[100];//� 
    int size;//�ߵ���
	int life;//�ߵ����� 
	int dir;//���˶��ķ��� 
	int Add;//��ʾ�����Ƿ�Ӧ���쳤 
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
  s->life=1;//1��ʾ����
  s->size=1;//��ʾ�ߵ���Ϊ1
  s->Body[0].x=C/2;//�ճ��������ǵ�������Ļ������ 
  s->Body[0].y=D/2;  
  s->dir=RIGHT;//�ճ������ߣ�Ĭ�������ƶ� 
  s->Add=0;
  return s; 
}
int RandInt(int c)//�������C���ڵ����� 
{
	srand(unsigned(time(NULL)));
	return rand()%(c-2)+1;//��0��c-1��Ҫ�ų���  ����ʵ������1��c-2 
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
   	f->food.y=RandInt(D);  //����һ����������� 
     while(IsHit(s,f->food.x,f->food.y))
     {
        f->food.x=RandInt(C);
   	    f->food.y=RandInt(D);
	 }
	f->ISEAT=0;
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
	  else 
	  {
	  	gotoxy(s->Body[s->size-1].x,s->Body[s->size-1].y);
	  	putchar(' ');
	  }
  		for(i=s->size-1;i>0;i--)// 
		{
			s->Body[i].x=s->Body[i-1].x;
			s->Body[i].y=s->Body[i-1].y;
		}
  if(s->dir==RIGHT)//�������ǿ����ߵ��ƶ��� 
    s->Body[0].x++;
    else if(s->dir==LEFT)
    s->Body[0].x--;
    else if(s->dir==UP)
    s->Body[0].y--;
    else if(s->dir==DOWN)
    s->Body[0].y++;
}
void PrintSpace(void)
{
	int i,j;
	for(i=0;i<D;i++)
	{
			 for(j=0;j<C;j++)
	 	putchar(Space[i][j]);
	 	putchar('\n');
	}	 
 }
void PrintFoodAndSnake(snake s,Food f)
{
	int i=1;
	gotoxy(f->food.x,f->food.y);
	putchar(FOOD); 
   	gotoxy(s->Body[0].x,s->Body[0].y);
	putchar(SNAKE); 
	while(i<s->size)
	{
		gotoxy(s->Body[i].x,s->Body[i].y);
		putchar(SNAKE);
		i++;
	}
	
}
void AddSize(snake s,Food f)
{
	if(IsHit(s,f->food.x,f->food.y))
	{	
	gotoxy(s->Body[0].x,s->Body[0].y);
	putchar(SNAKE);	
        s->Add=1;	 
	 f->ISEAT=1;//���Ե��� 
	 
	 	
	}
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
	int score=0; 
	int ss;
	int PriSize=0;//ԭ������ 
	DefineSpace();
	snake s;
	s=Create();
	fo o;//����һ��ʳ��ı��� 
	o.ISEAT=1;
	Food f=&o;
	printf("������������������������������������������������\n");
    printf("��          ����Ϸ��wasd������������          ��\n");
    printf("��              ��ѡ���Ѷȣ�                  ��\n");
    printf("��                (1)easy                     ��\n");
    printf("��                (2)medium                   ��\n");
    printf("��                (3)difficult                ��\n");
    printf("��                (4)crazy                    ��\n");
    printf("��                (5)devil                    ��\n");
    printf("������������������������������������������������\n");
	int n,c;
	if((c=getchar())=='1')
	n=1000;
	else if(c=='2')
	n=500;
	else if(c=='3')
	n=250;
	else if(c=='4') 
	  n=125;
	  else if(c=='5')
	    n==62;
	  getchar();
	system("cls");
	PrintSpace();
   while(s->life==1)
   {
   	CreateFood(f,s);
   	SnakeMove(s);
     PrintFoodAndSnake(s,f);
     
     AddSize(s,f);
     IsAlive(s);
     gotoxy(0,D);
     if(n==1000)
     {
     	ss=5;
     	    printf("Easy_Mode      ");
	 }
		  
		  else if(n==500)
		  {
		  	ss=10;
		  	printf("Medium_Mode    ");
		  }
		  
		  else if(n==250)
		  {
		  		  ss=25;
		  printf("Difficult_Mode   ");	
		  }

		  else if(n==125)
		  {
		  			  ss=50;
		  printf("Crazy_Mode       ");
		  }

		  else if(n==62)
		  {
		  			  ss=100;
		  printf("Devil_Mode       ");
		  }

		  score=ss*(s->size-1);
	printf("Score:%d",score);
	while(s->size-PriSize>=10)
	{
		
		gotoxy(0,D+1);
		
		if(n>=125)
		{	 
		n/=2;
		printf("it has been more difficult!");
		Sleep(1000);
		gotoxy(0,D+1);
		printf("                              ");
		} 
		else
		{
		  printf("�����!\n");
			Sleep(1000);
		gotoxy(0,D+1);
		printf("                              ");
				
		}
		
		 
		PriSize=s->size;
	}
   	         Sleep(n);
   }
   system("cls");
    printf("������������������������������������������������\n");
    printf("��                 GAME OVER                  ��\n");
    printf("������������������������������������������������\n");
   return 0;
}
