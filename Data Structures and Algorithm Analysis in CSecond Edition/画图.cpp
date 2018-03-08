#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

#define MAXX 77
#define MAXY 40

int X=MAXX/2;
int Y=MAXY/2;//刚开始光标的位置 
int Space[MAXY][MAXX];//在数组里 行表示在前面
void DefineSpace(void)
{
	int i,j;
	for(i=0;i<MAXY;i++)
 	if(i==0||i==MAXY-1)
 	{
 		for(j=0;j<MAXX;j++)
 	    Space[i][j]=004; 
	 }
	 else
	 {
	 	for(j=1;j<MAXX-1;j++)
	 	Space[i][j]=' ';
	 	Space[i][0]=Space[i][MAXX-1]=004;
	 }	
 } 
void PrintSpace(void)
{
	int i,j;
	for(i=0;i<MAXY;i++)
	  {
	  	for(j=0;j<MAXX;j++)
	  	putchar(Space[i][j]);
	  	putchar('\n');
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
void Move(int *x,int *y)
{
   int c;
   while(c=getch())
   {
    if(c=='w')
   *y-=1;
   else if(c=='s')
   *y+=1;
   else if(c=='a')
   *x-=1;
   else if(c=='d')
   *x+=1;

   else if(c>='0'&&c<='9'||c==' ') 
   {
   	ungetch(c);
   	break;
   }
    else
       ;
    gotoxy(*x,*y);
   }

}
int IsOut(void)
{
	
	if(X>=MAXX-1||Y>=MAXY-1||X<=0||Y<=0)
	return 1;
	return 0;
}
void Paint(void)
{
	int c;
	if(IsOut())
	{
		gotoxy(0,MAXY+1);
		printf("you can not paint out of this space!\n");
		Sleep(1000);
		gotoxy(0,MAXY+1);
		printf("                                       ");

	 } 
	 else
	while(c=getch())
		if(c=='1')
		putchar(001);
		else if(c=='2')
		putchar(002);
		else if(c=='3')
		putchar(003);
		else if(c=='4')
		putchar(004);
		else if(c==' ')
		putchar(' ');
		else 
		{
			ungetch(c);
			break;
		}
		     
}
int main()
{
	DefineSpace();
	PrintSpace();
	int c;
	int *x,*y;
	gotoxy(0,MAXY);
	printf("1-%c,2-%c,3-%c,4-%c",1,2,3,4);
	x=&X;
	y=&Y;
	gotoxy(X,Y);
	while((c=getch())!='\n')
	{
		if(c=='0')
		{
			system("cls");
			PrintSpace();
				gotoxy(0,MAXY);
	printf("1-%c,2-%c,3-%c,4-%c",1,2,3,4);
	gotoxy(X,Y);
		}
		else 
		{
		ungetch(c);
		Move(x,y);
		Paint();
		}

	 } 
	 getchar();
	 return 0;
}
