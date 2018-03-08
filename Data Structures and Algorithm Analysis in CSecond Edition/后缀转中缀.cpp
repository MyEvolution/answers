#include"数组棧.h"
#include<ctype.h>
#define NUMB 0200//代表接受的输入的是一个数 
#define MAXSIZE 1000
int get(int *e);
int main()
{
	
	int c;
	int e;
	Stack S;
	int m,n;
	char a[30][100];/*
	用一个多维数组来储存计算后的表达式 
	比如ba+  储存a+b到数组中 
	只要表达式正确，到最后一定会全部融合为一个表达式
	所以输入对应下标中的字符串即可
	缺点是  比较浪费空间  需要提前分配空间 比如每遇到一个计算的符号就需要把之前的计算值值放到其中 
	动态分配需要频繁调用malloc  如果式子很小用这个也就比较好
	不可以只用一个式子来储存表达式 如果遇到 ab+cd++  就需要2个来储存a+b和c+d。
	这个算法的缺点还有会产生没有必要的多余的括号 
	本算法规定的数组可以得出  可以正确表达的最大式子中运算符号少于30，式子最长少于100 
	*/ 
 
	  int i=0;
	S=Create(MAXSIZE);
	while((c=get(&e))!=EOF)
	{
		if(c=='\t'||c==' ')
		   continue;

			 else	 
               switch(c)
               {
               	case NUMB:
				   Push(e,S); 
				   break;
				case '*':
				case '/':
				case '+':
				case '-':
				case '^':
                    m=TopAndPop(S);
                    n=TopAndPop(S);
                    if(isalnum(n)&&isalnum(m))
                    {
                       Push(i,S);
                       sprintf(a[i++],"%c%c%c",n,c,m);
	   	
					}
					else if(!isalnum(n)&&isalnum(m))
					   {
					   	Push(i,S);
					   	sprintf(a[i++],"(%s)%c%c",a[n],c,m);
					   }
					   else if(!isalnum(m)&&isalnum(n))
					   {
					   	Push(i,S);
					   	sprintf(a[i++],"%c%c(%s)",n,c,a[m]);
					
					   }
					   else 
					   {
					   	Push(i,S);
					   	sprintf(a[i++],"(%s)%c(%s)",a[n],c,a[m]);
					   }
					   break;
				case '\n':
					  m=TopAndPop(S);
					  i=0;
					  MakeEmpty(S);
					  
					  printf("%s\n",a[m]);
					  break;
				default:
					break;
 	   }
		      
	}
 }
int get(int *e)
{
	*e=getchar();
	if(isalnum(*e))
	  return NUMB;
	  else
	    return *e;
}
