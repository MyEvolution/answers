#include"���闣.h"
#include<ctype.h>
#define NUMB 0200//������ܵ��������һ���� 
#define MAXSIZE 1000
int get(int *e);
int main()
{
	
	int c;
	int e;
	Stack S;
	int m,n;
	char a[30][100];/*
	��һ����ά��������������ı��ʽ 
	����ba+  ����a+b�������� 
	ֻҪ���ʽ��ȷ�������һ����ȫ���ں�Ϊһ�����ʽ
	���������Ӧ�±��е��ַ�������
	ȱ����  �Ƚ��˷ѿռ�  ��Ҫ��ǰ����ռ� ����ÿ����һ������ķ��ž���Ҫ��֮ǰ�ļ���ֵֵ�ŵ����� 
	��̬������ҪƵ������malloc  ���ʽ�Ӻ�С�����Ҳ�ͱȽϺ�
	������ֻ��һ��ʽ����������ʽ ������� ab+cd++  ����Ҫ2��������a+b��c+d��
	����㷨��ȱ�㻹�л����û�б�Ҫ�Ķ�������� 
	���㷨�涨��������Եó�  ������ȷ�������ʽ���������������30��ʽ�������100 
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
