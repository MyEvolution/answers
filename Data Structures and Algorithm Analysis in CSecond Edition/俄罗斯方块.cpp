#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#define Z  0
#define FZ 1
#define I  2
#define T  3
#define O  4
#define L  5
#define FL 6 

#define NoChange 10
#define First    11
#define Second   12
#define Third    13

#define UP      'w'
#define DOWN    's'
#define LEFT    'a'
#define RIGHT   'd'


char space[24][22];
int gotoxy(int x,int y);
void Paint(int ,int ,int ,int);
void Clean(int ,int ,int ,int);
void DefineSpace(void)
{
	int i,j;//i表示的是横坐标，j表示纵坐标？ 
	for(j=0;j<22;j++)
	{
		if(j==0||j==21)
			for(i=0;i<24;i++)
			space[i][j]=1;
		else
		{
		for(i=2;i<22;i++)
		space[i][j]=0;
		space[0][j]=space[1][j]=space[22][j]=space[23][j]=1;//应该是正确的 
		}
		
	}

}
void PrintSpace(void)
{
	int i,j;
	for(j=0;j<22;j++)
	for(i=0;i<24;i+=2)
		if(space[i][j]==1)
	   {
	   	gotoxy(i,j);
	   	printf("■");
	   }
	   else 
	   {
	   	gotoxy(i,j);
	   	printf("  ");
	   }
	
	
}
int gotoxy(int x,int y)
{
	HANDLE hout;
	COORD coord={0,0};
	coord.X=x;
	coord.Y=y;
	hout=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout,coord);
}
int RandInt(int c)//随机生成C(0-C-1)以内的数字 
{
	srand(unsigned(time(NULL)));
	return rand()%c;
 }
 int Createn(void)
{
  	int n;
  	n=RandInt(7);
  	return n;
}
int Createz(void)
{
	int z;
	z=RandInt(4);
	return z+10;
}
void NextF(int n,int z)
{	
	if(n==Z&&(z==NoChange||z==Second))
	{
		gotoxy(32,4);
		printf("■■\n");
		gotoxy(34,5);
		printf("■■\n");
	}
	else if(n==Z&&(z==First||z==Third))
	{
		gotoxy(34,3);
		printf("■");
		gotoxy(32,4);
		printf("■■");
		gotoxy(32,5);
		printf("■");
	}
	else if(n==FZ&&(z==NoChange||z==Second))
	{
		gotoxy(34,4);
		printf("■■\n");
		gotoxy(32,5);
		printf("■■\n");
	}
	else if(n==FZ&&(z==First||z==Third))
	{
		gotoxy(32,3);
		printf("■");
		gotoxy(32,4);
		printf("■■");
		gotoxy(34,5);
		printf("■");
	}
	else if(n==I&&(z==NoChange||z==Second))
	{
		gotoxy(30,4);
		printf("■■■■\n");
	}
	else if(n==I&&(z==First||z==Third))
	{
		gotoxy(34,3);
		printf("■");
		gotoxy(34,4);
		printf("■");
		gotoxy(34,5);
		printf("■");
		gotoxy(34,6);
		printf("■");
	}
	else if(n==T&&z==NoChange)
	{
		gotoxy(32,4);
		printf("■■■\n");
		gotoxy(34,5);
		printf("■\n");
	}
	else if(n==T&&z==First)
	{
		gotoxy(34,3);
		printf("■");
		gotoxy(32,4);
		printf("■■");
		gotoxy(34,5);
		printf("■");
	}
	else if(n==T&&z==Second)
	{
		gotoxy(34,4);
		printf("■");
		gotoxy(32,5);
		printf("■■■");
	}
	else if(n==T&&z==Third)
	{
		gotoxy(32,3);
		printf("■");
		gotoxy(32,4);
		printf("■■");
		gotoxy(32,5);
		printf("■");
	}
	else if(n==O)
	{
	gotoxy(32,4);
	printf("■■\n");
	gotoxy(32,5);
	printf("■■\n");
	}
	else if(n==L&&z==NoChange)
	{
		gotoxy(32,4);
		printf("■■■\n");
		gotoxy(32,5);
		printf("■\n");
	}
	else if(n==L&&z==First)
	{
		gotoxy(32,3);
		printf("■■");
		gotoxy(32,4);
		printf("■");
		gotoxy(32,5);
		printf("■");
	}
	else if(n==L&&z==Second)
	{
		gotoxy(36,4);
		printf("■");
		gotoxy(32,5);
		printf("■■■");
	}
	else if(n==L&&z==Third)
	{
		gotoxy(32,3);
		printf("■");
		gotoxy(32,4);
		printf("■");
		gotoxy(32,5);
		printf("■■");
	}
	else if(n==FL&&z==NoChange)
	{
		gotoxy(32,4);
		printf("■■■\n");
		gotoxy(36,5);
		printf("■\n");
	}
	else if(n==FL&&z==First)
	{
		gotoxy(34,3);
		printf("■");
		gotoxy(34,4);
		printf("■");
		gotoxy(32,5);
		printf("■■");
	}
	else if(n==FL&&z==Second)
	{
		gotoxy(32,4);
		printf("■");
		gotoxy(32,5);
		printf("■■■");
	}
	else if(n==FL&&z==Third)
	{
		gotoxy(32,3);
		printf("■■");
		gotoxy(34,4);
		printf("■");
		gotoxy(34,5);
		printf("■");
	}
}

int Move(int n,int *x,int *y,int *z)
{
	int c;
	int i=*x,j=*y,k=*z;
	int speed=0; 
	Clean(n,i,j,k);
	*y+=1;
	if(_kbhit())
	{
	c=getch();
	if(c=='w')
	{
	*z+=1;
	if(*z>13)
	*z=10;
	}
	else if(c=='s')
		   speed=2;
		else if(c=='a')
		*x-=2;
		else if(c=='d')
		*x+=2;	
	}
	if(n==Z&&(*z==NoChange||*z==Second))
		{
		   if(space[*x-2][*y]||space[*x][*y+1])
		      *x=i;
		      else if(space[*x][*y]||space[*x+2][*y+1])
		      *x=i;
			if(space[*x][*y+1]||space[*x+2][*y+1]||space[*x-2][*y])
			{
				*y-=1;
			Paint(n,*x,*y,*z);
			return 1;				
			}

		}
		else if(n==Z&&(*z==First||*z==Third))
		{
			if(space[*x][*y+1]||space[*x][*y+2]||space[*x+2][*y+1]||space[*x+2][*y])
		       *x=i;
			if(space[*x][*y+2]||space[*x+2][*y+1])
			{
				*y-=1;
			Paint(n,*x,*y,*z);
			return 1;				
			}
		}
		else if(n==FZ&&(*z==NoChange||*z==Second))
		{
		    if(space[*x-2][*y+1]||space[*x][*y]||space[*x+2][*y]||space[*x][*y+1])
		          *x=i;
			if(space[*x-2][*y+1]||space[*x][*y+1]||space[*x+2][*y])
			{
				*y-=1;
			Paint(n,*x,*y,*z);
			return 1;				
			}
		}
		else if(n==FZ&&(*z==First||*z==Third))
		{
		if(space[*x][*y]||space[*x][*y+1]||space[*x+2][*y+1]||space[*x+2][*y+2])
		     *x=i;
			if(space[*x+2][*y+2]||space[*x][*y+1])
			{
				*y-=1;
			Paint(n,*x,*y,*z);
			return 1;				
			}
		}
		else if(n==T)
		{
		
			if(*z==NoChange)
			{
			    if(space[*x-2][*y]||space[*x][*y+1]||space[*x+2][*y])
			               *x=i;
				if(space[*x][*y+1]||space[*x-2][*y]||space[*x+2][*y])
			{
				*y-=1;
			Paint(n,*x,*y,*z);
			return 1;				
			}
			}
			else if(*z==First)
			{
			    if(space[*x][*y+1]||space[*x+2][*y]||space[*x+2][*y+1]||space[*x+2][*y+2])
			             *x=i;
				if(space[*x+2][*y+2]||space[*x][*y+1])
					{
						*y-=1;
			Paint(n,*x,*y,*z);
			return 1;				
			}
				
			}
			else if(*z==Second)
			{
				if(space[*x-2][*y+1]||space[*x][*y]||space[*x+2][*y+1])
				     *x=i;
				if(space[*x][*y+1]||space[*x+2][*y+1]||space[*x-2][*y+1])
					{
						*y-=1;
			Paint(n,*x,*y,*z);
			return 1;				
			}
			}
			else if(*z==Third)
			{
				if(space[*x][*y]||space[*x][*y+1]||space[*x+2][*y+1]||space[*x][*y+2])
				          *x=i;
				if(space[*x][*y+2]||space[*x+2][*y+1])
			{
				*y-=1;
			Paint(n,*x,*y,*z);
			return 1;				
			}
			}
		}
			else if(n==O)
			{
				if(space[*x][*y]||space[*x][*y+1]||space[*x+2][*y]||space[*x+2][*y+1])
				      *x=i;
				if(space[*x][*y+1]||space[*x+2][*y+1])
					{
						*y-=1;
			Paint(n,*x,*y,*z);
			return 1;				
			}
			}
			else if(n==I)
			{
			
			if(*z==First||*z==Third)
			{
		        if(space[*x][*y+1]||space[*x][*y+2]||space[*x][*y]||space[*x][*y+3])
		               *x=i; 
				if(space[*x][*y+3])
						{
				*y-=1;
			Paint(n,*x,*y,*z);
			return 1;				
			}
			}
			else if(*z==Second||*z==NoChange)
			{
	          if(space[*x-4][*y]||space[*x+2][*y])
	             *x=i;
				if(space[*x-4][*y]||space[*x-2][*y]||space[*x][*y]||space[*x+2][*y])
				{
					*y-=1;
					Paint(n,*x,*y,*z);
			return 1;				
			}
			}
		}
			else if(n==L)
			{
			
			if(*z==NoChange)
			{
				   if(space[*x-2][*y]||space[*x-2][*y+1]||space[*x+2][*y])
				         *x=i;
				if(space[*x-2][*y+1]||space[*x][*y]||space[*x+2][*y])
						{
							*y-=1;
			Paint(n,*x,*y,*z);
			return 1;				
			}
			}else if(*z==First)
			{
				if(space[*x][*y]||space[*x+2][*y]||space[*x+2][*y+1]||space[*x+2][*y+2])
				    *x=i;
				if(space[*x+2][*y+2]||space[*x][*y])
			{
					*y-=1;
			Paint(n,*x,*y,*z);
			return 1;				
			}
			}else if(*z==Second)
			{
				if(space[*x-2][*y+1]||space[*x+2][*y]||space[*x+2][*y+1])
				         *x=i;
				if(space[*x-2][*y+1]||space[*x][*y+1]||space[*x+2][*y+1])
			{
					*y-=1;
			Paint(n,*x,*y,*z);
			return 1;				
			}
			}
			else if(*z==Third)
			{
				if(space[*x][*y]||space[*x][*y+1]||space[*x][*y+2]||space[*x+2][*y+2])
				      *x=i;
				if(space[*x][*y+2]||space[*x+2][*y+2])
		{
			*y-=1;
			Paint(n,*x,*y,*z);
			return 1;				
			}
			}
		}
		else if(n==FL)
		{
			if(*z==NoChange)
			{
				if(space[*x+2][*y]||space[*x-2][*y]||space[*x+2][*y+1])
				     *x=i;
				if(space[*x+2][*y+1]||space[*x-2][*y]||space[*x][*y])
				{
					*y-=1;
			Paint(n,*x,*y,*z);
			return 1;				
			}
			}
			else if(*z==First)
			{
				if(space[*x][*y+2]||space[*x+2][*y]||space[*x+2][*y+1]||space[*x+2][*y+2])
				    *x=i;
				if(space[*x][*y+2]||space[*x+2][*y+2])
					{
						*y-=1;
			Paint(n,*x,*y,*z);
			return 1;				
			}
			}
			else if(*z==Second)
			{
	          if(space[*x-2][*y]||space[*x-2][*y+1]||space[*x+2][*y+1])
	                   *x=i;
				if(space[*x-2][*y+1]||space[*x][*y+1]||space[*x+2][*y+1])
             	{
				*y-=1;
			Paint(n,*x,*y,*z);
			return 1;				
			}
			}
			else if(*z==Third)
			{
				if(space[*x][*y]||space[*x][*y+1]||space[*x][*y+2]||space[*x+2][*y])
				     *x=i;
				if(space[*x][*y+2]||space[*x+2][*y])
						{
							*y-=1;
			Paint(n,*x,*y,*z);
			return 1;				
			}
			}
		}
	
    Paint(n,*x,*y,*z);
    return speed;
}
void Paint(int n,int x,int y,int z)//画方块   x,y表示坐标  n表示方块的种类，z表示放块的状态 
{
	if(z==NoChange)
	{	
	if(n==Z)
	{
		gotoxy(x-2,y);
		printf("■■");
		gotoxy(x,y+1);
		printf("■■");
		space[x][y+1]=space[x+1][y+1]=space[x+2][y+1]=space[x+3][y+1]=
		space[x-2][y]=space[x-1][y]=space[x][y]=space[x+1][y]=1;
	}
	else if(n==FZ)
	{
		gotoxy(x,y);
		printf("■■");
		gotoxy(x-2,y+1);
		printf("■■");
		space[x][y]=space[x+1][y]=space[x+2][y]=space[x+3][y]=
		space[x-2][y+1]=space[x-1][y+1]=space[x][y+1]=space[x+1][y+1]=1;
	}
	else if(n==I)
	{
		gotoxy(x-4,y);
		printf("■■■■");
		space[x-4][y]=space[x-3][y]=space[x-2][y]=space[x-1][y]=
		space[x][y]=space[x+1][y]=space[x+2][y]=space[x+3][y]=1;
	}
	else if(n==T)
	{
		gotoxy(x-2,y);
		printf("■■■");
		gotoxy(x,y+1);
		printf("■");
		space[x-2][y]=space[x-1][y]=space[x][y]=space[x+1][y]=space[x+2][y]=
		space[x+3][y]=space[x][y+1]=space[x+1][y+1]=1;
	}
	else if(n==O)//biaoji
	{
		gotoxy(x,y);
		printf("■■");
		gotoxy(x,y+1);
		printf("■■");
		space[x][y]=space[x+1][y]=space[x+2][y]=space[x+3][y]=
		space[x][y+1]=space[x+1][y+1]=space[x+2][y+1]=space[x+3][y+1]=1;
	}
	else if(n==L)
	{
		gotoxy(x-2,y);
		printf("■■■");
		gotoxy(x-2,y+1);
		printf("■");
		space[x-2][y+1]=space[x-1][y+1]=space[x-2][y]=
		space[x-1][y]=space[x][y]=space[x+1][y]=space[x+2][y]=space[x+3][y]=1; 
	}
	else if(n==FL)
	{
		gotoxy(x-2,y);
		printf("■■■");
		gotoxy(x+2,y+1);
		printf("■");
		space[x+2][y+1]=space[x+3][y+1]=space[x-2][y]=
		space[x-1][y]=space[x][y]=space[x+1][y]=space[x+2][y]=space[x+3][y]=1; 
	}
}
else if(z==First)
{
	if(n==Z)
	{
		gotoxy(x+2,y);
		printf("■");
		gotoxy(x,y+1);
		printf("■■");
		gotoxy(x,y+2);
		printf("■");
		space[x+2][y]=space[x+3][y]=space[x][y+1]=space[x+1][y+1]=
		space[x+2][y+1]=space[x+3][y+1]=space[x][y+2]=space[x+1][y+2]=1;
	}
	else if(n==FZ)
	{
		gotoxy(x,y);
		printf("■");
		gotoxy(x,y+1);
		printf("■■");
		gotoxy(x+2,y+2);
		printf("■");
			space[x][y]=space[x+1][y]=space[x][y+1]=space[x+1][y+1]=
		space[x+2][y+1]=space[x+3][y+1]=space[x+2][y+2]=space[x+3][y+2]=1;	
	}
	else if(n==I)
	{
		gotoxy(x,y);
		printf("■");
		gotoxy(x,y+1);
		printf("■");
		gotoxy(x,y+2);
		printf("■");
		gotoxy(x,y+3);
		printf("■");
		space[x][y]=space[x+1][y]=space[x][y+1]=space[x+1][y+1]
		=space[x][y+2]=space[x+1][y+2]=space[x][y+3]=space[x+1][y+3]=1;
		 
	}
	else if(n==T)//chu wen ti
	{
		gotoxy(x+2,y);
		printf("■");
		gotoxy(x,y+1);
		printf("■■");
		gotoxy(x+2,y+2);
		printf("■");
		space[x+2][y]=space[x+3][y]=space[x][y+1]=space[x+1][y+1]=space[x+2][y+1]=space[x+3][y+1]
		=space[x+2][y+2]=space[x+3][y+2]=1;
	}
	else if(n==O)
	{
		gotoxy(x,y);
		printf("■■");
		gotoxy(x,y+1);
		printf("■■");
		space[x][y]=space[x+1][y]=space[x+2][y]=space[x+3][y]=
		space[x][y+1]=space[x+1][y+1]=space[x+2][y+1]=space[x+3][y+1]=1;
	}
	else if(n==L)
	{
		gotoxy(x,y);
		printf("■■");
		gotoxy(x+2,y+1);
		printf("■");
		gotoxy(x+2,y+2);
		printf("■");
		space[x][y]=space[x+1][y]=space[x+2][y]=space[x+3][y]=
		space[x+2][y+1]=space[x+3][y+1]=space[x+2][y+2]=space[x+3][y+2]=1; 
	}
	else if(n==FL)
	{

		gotoxy(x+2,y);
		printf("■");
		gotoxy(x+2,y+1);
		printf("■");
		gotoxy(x,y+2);
		printf("■■");
        space[x+2][y]=space[x+3][y]=space[x+2][y+1]=space[x+3][y+1]=
        space[x][y+2]=space[x+1][y+2]=space[x+2][y+2]=space[x+3][y+2]=1;
	}
}
else if(z==Second)
{
	if(n==Z)
	{
		gotoxy(x-2,y);
		printf("■■");
		gotoxy(x,y+1);
		printf("■■");
		space[x][y+1]=space[x+1][y+1]=space[x+2][y+1]=space[x+3][y+1]=
		space[x-2][y]=space[x-1][y]=space[x][y]=space[x+1][y]=1;
	}
	else if(n==FZ)
	{
		gotoxy(x,y);
		printf("■■");
		gotoxy(x-2,y+1);
		printf("■■");
		space[x][y]=space[x+1][y]=space[x+2][y]=space[x+3][y]=
		space[x-2][y+1]=space[x-1][y+1]=space[x][y+1]=space[x+1][y+1]=1;
	}
		else if(n==I)
	{
		gotoxy(x-4,y);
		printf("■■■■");
		space[x-4][y]=space[x-3][y]=space[x-2][y]=space[x-1][y]=
		space[x][y]=space[x+1][y]=space[x+2][y]=space[x+3][y]=1;
	}
	else if(n==T)
	{
		gotoxy(x,y);
		printf("■");
		gotoxy(x-2,y+1);
		printf("■■■");
		space[x][y]=space[x+1][y]=space[x-2][y+1]=space[x-1][y+1]=
		space[x][y+1]=space[x+1][y+1]=space[x+2][y+1]=space[x+3][y+1]=1; 
	}
	else if(n==O)
	{
		gotoxy(x,y);
		printf("■■");
		gotoxy(x,y+1);
		printf("■■");
		space[x][y]=space[x+1][y]=space[x+2][y]=space[x+3][y]=
		space[x][y+1]=space[x+1][y+1]=space[x+2][y+1]=space[x+3][y+1]=1;
	}
	else if(n==L)
	{
		gotoxy(x-2,y+1);
		printf("■■■");
		gotoxy(x+2,y);
		printf("■");
		space[x-2][y+1]=space[x-1][y+1]=space[x][y+1]=space[x+1][y+1]=space[x+2][y+1]=space[x+3][y+1]=
		space[x+2][y]=space[x+3][y]=1;
		
	}
	else if(n==FL)
	{
		gotoxy(x-2,y);
		printf("■");
		gotoxy(x-2,y+1);
		printf("■■■");
		space[x-2][y]=space[x-1][y]=
		space[x-2][y+1]=space[x-1][y+1]=space[x][y+1]=space[x+1][y+1]=space[x+2][y+1]=space[x+3][y+1]=1;
	}
}
else if(z==Third)
{
		if(n==Z)
	{
		gotoxy(x+2,y);
		printf("■");
		gotoxy(x,y+1);
		printf("■■");
		gotoxy(x,y+2);
		printf("■");
		space[x+2][y]=space[x+3][y]=space[x][y+1]=space[x+1][y+1]=
		space[x+2][y+1]=space[x+3][y+1]=space[x][y+2]=space[x+1][y+2]=1;
	}
	else if(n==FZ)
	{
		gotoxy(x,y);
		printf("■");
		gotoxy(x,y+1);
		printf("■■");
		gotoxy(x+2,y+2);
		printf("■");
			space[x][y]=space[x+1][y]=space[x][y+1]=space[x+1][y+1]=
		space[x+2][y+1]=space[x+3][y+1]=space[x+2][y+2]=space[x+3][y+2]=1;	
	}
	else if(n==I)
	{
		gotoxy(x,y);
		printf("■");
		gotoxy(x,y+1);
		printf("■");
		gotoxy(x,y+2);
		printf("■");
		gotoxy(x,y+3);
		printf("■");
		space[x][y]=space[x+1][y]=space[x][y+1]=space[x+1][y+1]
		=space[x][y+2]=space[x+1][y+2]=space[x][y+3]=space[x+1][y+3]=1;
		 	}
	else if(n==T)
	{
		gotoxy(x,y);
		printf("■");
		gotoxy(x,y+1);
		printf("■■");
		gotoxy(x,y+2);
		printf("■");
		space[x][y]=space[x+1][y]=space[x][y+1]=space[x+1][y+1]=space[x+2][y+1]
		=space[x+3][y+1]=space[x][y+2]=space[x+1][y+2]=1;
	}
	else if(n==O)
	{
	    gotoxy(x,y);
		printf("■■");
		gotoxy(x,y+1);
		printf("■■");
		space[x][y]=space[x+1][y]=space[x+2][y]=space[x+3][y]=
		space[x][y+1]=space[x+1][y+1]=space[x+2][y+1]=space[x+3][y+1]=1;
	}
	else if(n==L)
	{
		gotoxy(x,y);
		printf("■");
		gotoxy(x,y+1);
		printf("■");
		gotoxy(x,y+2);
		printf("■■");
		space[x][y]=space[x+1][y]=space[x][y+1]=space[x+1][y+1]=space[x][y+2]=
		space[x+1][y+2]=space[x+2][y+2]=space[x+3][y+2]=1;
	}
	else if(n==FL)
	{
		gotoxy(x,y);
		printf("■■");
		gotoxy(x,y+1);
		printf("■");
		gotoxy(x,y+2);
		printf("■");
		space[x][y]=space[x+1][y]=space[x+2][y]=space[x+3][y]=space[x][y+1]=space[x+1][y+1]=
		space[x][y+2]=space[x+1][y+2]=1;	
}

	
}
}
int GetPoint(int *Point,int Dif)
{
   int i,j;
   int m,n;
   for(j=1;j<21;j++)
   {
   	for(i=2;i<22;i++)
   	if(space[i][j]!=1)
   	break;
   	if(i==22)//说明可以消去了 
      break;
   }
   if(i==22)
   {
   	for(m=j;m>1;m--)//重新构图 
   	{
   		for(n=0;n<24;n++)
   		space[n][m]=space[n][m-1];
	   }
	 for(n=1;n<22;n++)
	 space[n][1]=0; 
	 PrintSpace();
	 *Point+=10000/Dif;
	 return 1;//表示得分了 
   }
   else 
   return 0;
}
void Clean(int n,int x,int y,int z)
{
	if(z==NoChange)
	{
		
	
  if(n==Z)
  {
  	gotoxy(x-2,y);
		printf("    ");
		gotoxy(x,y+1);
		printf("    ");
		space[x][y+1]=space[x+1][y+1]=space[x+2][y+1]=space[x+3][y+1]=
		space[x-2][y]=space[x-1][y]=space[x][y]=space[x+1][y]=0;
  }
  else if(n==FZ)
	{
		gotoxy(x,y);
		printf("    ");
		gotoxy(x-2,y+1);
		printf("    ");
		space[x][y]=space[x+1][y]=space[x+2][y]=space[x+3][y]=
		space[x-2][y+1]=space[x-1][y+1]=space[x][y+1]=space[x+1][y+1]=0;
	}
	else if(n==I)
	{
		gotoxy(x-4,y);
		printf("        ");
		space[x-4][y]=space[x-3][y]=space[x-2][y]=space[x-1][y]=
		space[x][y]=space[x+1][y]=space[x+2][y]=space[x+3][y]=0;
	}
	else if(n==T)
	{
		gotoxy(x-2,y);
		printf("      ");
		gotoxy(x,y+1);
		printf("  ");
		space[x-2][y]=space[x-1][y]=space[x][y]=space[x+1][y]=space[x+2][y]=
		space[x+3][y]=space[x][y+1]=space[x+1][y+1]=0;
	}
	else if(n==O)
	{
		gotoxy(x,y);
		printf("    ");
		gotoxy(x,y+1);
		printf("    ");
		space[x][y]=space[x+1][y]=space[x+2][y]=space[x+3][y]=
		space[x][y+1]=space[x+1][y+1]=space[x+2][y+1]=space[x+3][y+1]=0;
	}
else if(n==L)
	{
		gotoxy(x-2,y);
		printf("      ");
		gotoxy(x-2,y+1);
		printf("  ");
		space[x-2][y+1]=space[x-1][y+1]=space[x-2][y]=
		space[x-1][y]=space[x][y]=space[x+1][y]=space[x+2][y]=space[x+3][y]=0; 
	}
	else if(n==FL)
	{
		gotoxy(x-2,y);
		printf("      ");
		gotoxy(x+2,y+1);
		printf("  ");
		space[x+2][y+1]=space[x+3][y+1]=space[x-2][y]=
		space[x-1][y]=space[x][y]=space[x+1][y]=space[x+2][y]=space[x+3][y]=0; 
	}
}
else if(z==First)
{
	if(n==Z)
	{
		  	gotoxy(x+2,y);
		printf("  ");
		gotoxy(x,y+1);
		printf("    ");
		gotoxy(x,y+2);
		printf("  ");
		space[x+2][y]=space[x+3][y]=space[x][y+1]=space[x+1][y+1]=
		space[x+2][y+1]=space[x+3][y+1]=space[x][y+2]=space[x+1][y+2]=0;  	
	}
	else if(n==FZ)
	{
		gotoxy(x,y);
		printf("  ");
		gotoxy(x,y+1);
		printf("    ");
		gotoxy(x+2,y+2);
		printf("  ");
			space[x][y]=space[x+1][y]=space[x][y+1]=space[x+1][y+1]=
		space[x+2][y+1]=space[x+3][y+1]=space[x+2][y+2]=space[x+3][y+2]=0;	
	}
	else if(n==I)
	{
		gotoxy(x,y);
		printf("  ");
		gotoxy(x,y+1);
		printf("  ");
		gotoxy(x,y+2);
		printf("  ");
		gotoxy(x,y+3);
		printf("  ");
		space[x][y]=space[x+1][y]=space[x][y+1]=space[x+1][y+1]
		=space[x][y+2]=space[x+1][y+2]=space[x][y+3]=space[x+1][y+3]=0;
		 
	}
	else if(n==T)
	{
		gotoxy(x+2,y);
		printf("  "); 
		gotoxy(x,y+1);
		printf("    ");
		gotoxy(x+2,y+2);
		printf("  ");
		space[x+2][y]=space[x+3][y]=space[x][y+1]=space[x+1][y+1]=space[x+2][y+1]=space[x+3][y+1]
		=space[x+2][y+2]=space[x+3][y+2]=0;
	}
	else if(n==O)
	{
		gotoxy(x,y);
		printf("    ");
		gotoxy(x,y+1);
		printf("    ");
		space[x][y]=space[x+1][y]=space[x+2][y]=space[x+3][y]=
		space[x][y+1]=space[x+1][y+1]=space[x+2][y+1]=space[x+3][y+1]=0;
	}
else if(n==L)
	{
		gotoxy(x,y);
		printf("    ");
		gotoxy(x+2,y+1);
		printf("  ");
		gotoxy(x+2,y+2);
		printf("  ");
		space[x][y]=space[x+1][y]=space[x+2][y]=space[x+3][y]=
		space[x+2][y+1]=space[x+3][y+1]=space[x+2][y+2]=space[x+3][y+2]=0; 
	}
	else if(n==FL)
	{

		gotoxy(x+2,y);
		printf("  ");
		gotoxy(x+2,y+1);
		printf("  ");
		gotoxy(x,y+2);
		printf("    ");
        space[x+2][y]=space[x+3][y]=space[x+2][y+1]=space[x+3][y+1]=
        space[x][y+2]=space[x+1][y+2]=space[x+2][y+2]=space[x+3][y+2]=0;
	}
}
else if(z==Second)
{
	if(n==Z)
	{
		gotoxy(x-2,y);
		printf("    ");
		gotoxy(x,y+1);
		printf("    ");
		space[x][y+1]=space[x+1][y+1]=space[x+2][y+1]=space[x+3][y+1]=
		space[x-2][y]=space[x-1][y]=space[x][y]=space[x+1][y]=0;
	}
	else if(n==FZ)
	{
		gotoxy(x,y);
		printf("    ");
		gotoxy(x-2,y+1);
		printf("    ");
		space[x][y]=space[x+1][y]=space[x+2][y]=space[x+3][y]=
		space[x-2][y+1]=space[x-1][y+1]=space[x][y+1]=space[x+1][y+1]=0;
	}
		else if(n==I)
	{
		gotoxy(x-4,y);
		printf("        ");
		space[x-4][y]=space[x-3][y]=space[x-2][y]=space[x-1][y]=
		space[x][y]=space[x+1][y]=space[x+2][y]=space[x+3][y]=0;
	}
	else if(n==T)
	{
		gotoxy(x,y);
		printf("  ");
		gotoxy(x-2,y+1);
		printf("      ");
		space[x][y]=space[x+1][y]=space[x-2][y+1]=space[x-1][y+1]=
		space[x][y+1]=space[x+1][y+1]=space[x+2][y+1]=space[x+3][y+1]=0; 
	}
	else if(n==O)
	{
		gotoxy(x,y);
		printf("    ");
		gotoxy(x,y+1);
		printf("    ");
		space[x][y]=space[x+1][y]=space[x+2][y]=space[x+3][y]=
		space[x][y+1]=space[x+1][y+1]=space[x+2][y+1]=space[x+3][y+1]=0;
	}
	else if(n==L)
	{
		gotoxy(x-2,y+1);
		printf("      ");
		gotoxy(x+2,y);
		printf("  ");
		space[x-2][y+1]=space[x-1][y+1]=space[x][y+1]=space[x+1][y+1]=space[x+2][y+1]=space[x+3][y+1]=
		space[x+2][y]=space[x+3][y]=0;
		
	}
	else if(n==FL)
	{
		gotoxy(x-2,y);
		printf("  ");
		gotoxy(x-2,y+1);
		printf("      ");
		space[x-2][y]=space[x-1][y]=
		space[x-2][y+1]=space[x-1][y+1]=space[x][y+1]=space[x+1][y+1]=space[x+2][y+1]=space[x+3][y+1]=0;
	}
}
else if(z==Third)
{
		if(n==Z)
	{
	gotoxy(x+2,y);
		printf("  ");
		gotoxy(x,y+1);
		printf("    ");
		gotoxy(x,y+2);
		printf("  ");
		space[x+2][y]=space[x+3][y]=space[x][y+1]=space[x+1][y+1]=
		space[x+2][y+1]=space[x+3][y+1]=space[x][y+2]=space[x+1][y+2]=0;
	}
	else if(n==FZ)
	{
			gotoxy(x,y);
		printf("  ");
		gotoxy(x,y+1);
		printf("    ");
		gotoxy(x+2,y+2);
		printf("  ");
			space[x][y]=space[x+1][y]=space[x][y+1]=space[x+1][y+1]=
		space[x+2][y+1]=space[x+3][y+1]=space[x+2][y+2]=space[x+3][y+2]=0;	
	}
	else if(n==I)
	{
		gotoxy(x,y);
		printf("  ");
		gotoxy(x,y+1);
		printf("  ");
		gotoxy(x,y+2);
		printf("  ");
		gotoxy(x,y+3);
		printf("  ");
		space[x][y]=space[x+1][y]=space[x][y+1]=space[x+1][y+1]
		=space[x][y+2]=space[x+1][y+2]=space[x][y+3]=space[x+1][y+3]=0;
		 	}
	else if(n==T)
	{
		gotoxy(x,y);
		printf("  ");
		gotoxy(x,y+1);
		printf("    ");
		gotoxy(x,y+2);
		printf("  ");
		space[x][y]=space[x+1][y]=space[x][y+1]=space[x+1][y+1]=space[x+2][y+1]
		=space[x+3][y+1]=space[x][y+2]=space[x+1][y+2]=0;
	}
	else if(n==O)
	{
	    gotoxy(x,y);
		printf("    ");
		gotoxy(x,y+1);
		printf("    ");
		space[x][y]=space[x][y]=space[x+1][y]=space[x+2][y]=
		space[x][y+1]=space[x][y+1]=space[x+1][y+1]=space[x+2][y+1]=0;
	}
		else if(n==L)
	{
		gotoxy(x,y);
		printf("  ");
		gotoxy(x,y+1);
		printf("  ");
		gotoxy(x,y+2);
		printf("    ");
		space[x][y]=space[x+1][y]=space[x][y+1]=space[x+1][y+1]=space[x][y+2]=
		space[x+1][y+2]=space[x+2][y+2]=space[x+3][y+2]=0;
	}
	else if(n==FL)
	{
		gotoxy(x,y);
		printf("    ");
		gotoxy(x,y+1);
		printf("  ");
		gotoxy(x,y+2);
		printf("  ");
		space[x][y]=space[x+1][y]=space[x+2][y]=space[x+3][y]=space[x][y+1]=space[x+1][y+1]=
		space[x][y+2]=space[x+1][y+2]=0;	
	
      }
   }
}
int IsOver(void)
{
	int i;
	for(i=2;i<22;i+=2)
	if(space[i][1]==1)
	return 1;
	 return 0;
}
void PrintLittle(void)
{
	 int i;
	 gotoxy(26,0);
    printf("next:\n");
     for(i=1;i<=8;i++)
      if(i==1||i==8)
       {
       	gotoxy(26,i);
       	 printf("■■■■■■■■\n");
	   }
	   else
	   {
	   	gotoxy(26,i);
	   	 printf("■            ■\n");
	   }

}
void PrintPoint(int n,int z,int Point,int Dif)
{
	int i,j;
	for(i=29;i<40;i++)
	for(j=2;j<8;j++)
	{
	gotoxy(i,j);
	putchar(' ');
	}
	     NextF(n,z);
		gotoxy(26,12);
	printf("Your Score:%d\n",Point);
	gotoxy(26,14);
	if(Dif==1000)
	printf("     Easy_Mode");
	else if(Dif==500)
	printf("   Medium_Mode");
	else if(Dif==300)
	printf("Difficult_Mode");
	else if(Dif==200)
	printf("    Craze_Mode");
	else 
	printf("    Devil_Mode");
	/*if(atoi(Score)>=Point)
	printf("The Highest Score:%s\n",Score);
	else
	{
		      Itoa(Point,Score);
		 	fwrite(Score,1,10,High);
		 	printf("The Highest Score:%s\n",Score);
	}*/
}
int main()
{
	printf("■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("■          本游戏用wasd控制上下左右          ■\n");
    printf("■              请选择难度：                  ■\n");
    printf("■                (1)easy                     ■\n");
    printf("■                (2)medium                   ■\n");
    printf("■                (3)difficult                ■\n");
    printf("■                (4)crazy                    ■\n");
    printf("■                (5)devil                    ■\n");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■\n");
    int c;
    FILE *HighestScore;
    int Dif;
    c=getch();
    if(c=='1')
    Dif=1000;
    else if(c=='2')
    Dif=500;
    else if(c=='3')
    Dif=300;
    else if(c=='4')
    Dif=200;
    else 
    Dif=100;
    system("cls");
	DefineSpace();
    PrintSpace();
    PrintLittle();
    int n;
    int z;
    int x,y;
    int Point=0;
    int N,Zz;//下一个 
    int sp;
    N=Createn();
    Zz=Createz();
    while(!IsOver())
    {
    	    x=10;
	        y=1;
	        n=Createn();
	        z=Createz(); 
    	Paint(N,x,y,Zz);
    	PrintPoint(n,z,Point,Dif);
    		Sleep(Dif);
    	while((sp=Move(N,&x,&y,&Zz))!=1)
    	{ 
    	if(sp==0)
    		Sleep(Dif);
			else
			   Sleep(1); 
			   } 
    	while(GetPoint(&Point,Dif))//检查是否得分 
	      Sleep(1000);	        
		N=n,Zz=z;
		if(Point/(10000/Dif)>=10)
		   {
		   	gotoxy(26,15);
		   	printf("the Game has been more Difficult!\n");
		   	Sleep(1000);
		   	gotoxy(26,15);
		   	printf("                                     ");
		   	if(Dif==1000)
		   	Dif=500;
		   	else if(Dif==500)
		   	Dif=300;
		   	else if(Dif==300)
		   	Dif=200;
		   	else Dif=100;
		   }

	}
	    system("cls");
		   printf("       You Score is %d!\n           Game Over!\n",Point);
		   
    return 0;
}
