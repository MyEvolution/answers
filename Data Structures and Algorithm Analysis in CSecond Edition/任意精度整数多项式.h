#ifndef Poly_num_h

#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>
#define MaxDegree 10000
int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
struct Node;
typedef struct Node
{
	char sign;
    char CoeffArray[MaxDegree];//加一位存放结束符 
	unsigned int HighPower;//最高的次数 
}P,*Poly;//多项式的结构 （实际上是10进制数的结构） 


Poly Create(void);
void MakeZore(Poly P);
void ScanfPoly(Poly P);
int compare(Poly p1,Poly p2);
void AddPoly(Poly p1,Poly p2,Poly p3);
void SubPoly(Poly p1,Poly p2,Poly p3);
void Mult(Poly p1,char X,Poly p3,int i);
void MultPoly(Poly p1,Poly p2,Poly p3);
 void PrintPoly(Poly p);
 void reverse(Poly p);
 void Power(Poly p1,int X,Poly p3);
 int IsZore(Poly P); 
 void DivPoly(Poly p1,Poly p2,Poly p3,Poly p4,int n); 
 
 #endif

void reverse(Poly p)
{
	char *a,*b;
	char temp;
	a=p->CoeffArray;
	b=a+p->HighPower;
	while(a<b)
	{
	temp=*a;
	*a=*b;
	*b=temp;
	a++,b--;	
	}

	
}
Poly Create(void)
{
	Poly p;
	p=(Poly)malloc(sizeof(struct Node));
	MakeZore(p);
	return p;
}
void MakeZore(Poly p)
{
	int i;
	if(p==NULL)
	{
		fprintf(stderr,"must create a poly first!\n");
		return;
	}
	for(i=0;i<MaxDegree;i++)
	p->CoeffArray[i]='0';
	p->CoeffArray[MaxDegree]='\0';
	p->HighPower=0;
}
void ScanfPoly(Poly p)
{
	MakeZore(p);
	int i;
	char c;
	while(isspace(c=getchar())||c=='(')
	         ;
	if(c=='-')
	  p->sign='-';
	  else
	  p->sign='+';
	  if(!isdigit(c))
	   c=getchar();
	   while(c=='0')
	   c=getchar();
	for(i=0,p->CoeffArray[i++]=c;isdigit(c=getchar());p->CoeffArray[i++]=c)
	                               ;
	        p->HighPower=i-1;
      reverse(p);
}
int compare(Poly p1,Poly p2)
{
	int i;
	if(p1->HighPower!=p2->HighPower)
	 return p1->HighPower-p2->HighPower;
	 else
	 {
	 	for(i=p1->HighPower;i>=0;i--)
	 	 if(p1->CoeffArray[i]!=p2->CoeffArray[i])
	 	 return p1->CoeffArray[i]-p2->CoeffArray[i];
	 }
	 return 0;
}
void AddPoly(Poly p1,Poly p2,Poly p3)//加多项式 
{
	int i;
	char remainder;//余数 
	char carry;//进位 
	char borrow;//借位 
	int comp;
	MakeZore(p3);
	if(p1->sign==p2->sign)
	{
		p3->sign=p1->sign;
	 for(i=0;i<=max(p1->HighPower,p2->HighPower);i++)
	 {
	 	remainder=(p1->CoeffArray[i]+p3->CoeffArray[i]+p2->CoeffArray[i]-3*'0')%10;
	 	carry=(p1->CoeffArray[i]+p3->CoeffArray[i]+p2->CoeffArray[i]-3*'0')/10;
	 	p3->CoeffArray[i]=remainder+'0';//为什么不是加等于呢  因为之前已经加过了的1  由于要判断是否大于10而使用
		                             // 所以判断时又加了一遍 ，再加就会重复 
	 	p3->CoeffArray[i+1]+=carry;
	 }
	 if(p3->CoeffArray[i]!='0')
	    p3->HighPower=i;
	    else
	    p3->HighPower=i-1;
	}
	else
	{
		comp=compare(p1,p2);
		if(comp==0)
		{
			p3->sign='+';
		p3->HighPower=0	;
		}
     	else if(comp>0)
     	{
     		p3->sign=p1->sign;
     		for(i=0;i<=p1->HighPower;i++)
     		 if((p1->CoeffArray[i]+p3->CoeffArray[i]-'0')<p2->CoeffArray[i])
     		 {
     		 	borrow=1;
     		 	remainder=p1->CoeffArray[i]+10-p2->CoeffArray[i];//借位 
     		 	p3->CoeffArray[i+1]-=borrow;//不能改变p1，但是我们可以改变p3 
     		 	p3->CoeffArray[i]+=remainder;//在减法借位时不会出现>9的情况
				        //但是可不可以用=呢？答案是否定的，
						//因为这里的remainder并没有把借的那一位减去 
			  }
			  else
			  {
			  	remainder=p1->CoeffArray[i]-p2->CoeffArray[i];	   
			  	p3->CoeffArray[i]+=remainder;
			  }
			  while(p3->CoeffArray[i]=='0')
			         i--;
			      p3->HighPower=i;
			  	
		 }
		 else
		 {
		 	p3->sign=p2->sign;
		 	for(i=0;i<=p2->HighPower;i++)
		 		if((p2->CoeffArray[i]+p3->CoeffArray[i]-'0')<p1->CoeffArray[i])
		 		{
		 			borrow=1;
		    remainder=p2->CoeffArray[i]+10-p1->CoeffArray[i];//借位 
     		 	p3->CoeffArray[i+1]-=borrow;//不能改变p1，但是我们可以改变p3 
     		 	p3->CoeffArray[i]+=remainder;
				 }
				else
				{
			remainder=p2->CoeffArray[i]-p1->CoeffArray[i];	   
			  	p3->CoeffArray[i]+=remainder;
				}
				 
			 
			   while(p3->CoeffArray[i]=='0')
			      i--;
			      p3->HighPower=i;
			     
		 }
		
	}

}
void SubPoly(Poly p1,Poly p2,Poly p3)//减多项式 通过加实现 
{
	P q;
	int i;
	if(p2->sign=='+')
	  q.sign='-';
	  else
	  q.sign='+';
	  q.HighPower=p2->HighPower;
    for(i=0;i<=MaxDegree;i++)
    q.CoeffArray[i]=p2->CoeffArray[i];
    AddPoly(p1,&q,p3);
}
void Mult(Poly p1,char X,Poly p3,int i)//i表示从p3的第几位开始存储 
{
	int j=0;
	char remainder,carry;
	for(j;j<=p1->HighPower;j++)
	{
		
		while(p3->CoeffArray[i+j]>'9')
		{
		p3->CoeffArray[i+j]-=10;
		p3->CoeffArray[i+j+1]+=1;	
		}	
		remainder=((p1->CoeffArray[j]-'0')*(X-'0'))%10;
		carry=((p1->CoeffArray[j]-'0')*(X-'0'))/10;
		p3->CoeffArray[i+j]+=remainder;
		while(p3->CoeffArray[i+j]>'9')
		{
		p3->CoeffArray[i+j]-=10;
		p3->CoeffArray[i+j+1]+=1;	
		}
		
		p3->CoeffArray[i+j+1]+=carry;
	}
}
void MultPoly(Poly p1,Poly p2,Poly p3)
{
	int i;
	MakeZore(p3);
	p3->sign=(p1->sign==p2->sign)?'+':'-';
	for(i=0;i<=p2->HighPower;i++)
	  Mult(p1,p2->CoeffArray[i],p3,i);
	  i=p1->HighPower+p2->HighPower+2;//两个数相称最高位不会超出这个值 
       while(p3->CoeffArray[i]=='0') 
            i--;
            p3->HighPower=i;
 } 
 void PrintPoly(Poly p)
 {
    if(p->sign!='+')
    putchar(p->sign);
     int i;
     for(i=p->HighPower;i>=0;i--)
     putchar(p->CoeffArray[i]);
 }
 void copy(Poly p,Poly q)
 {
     	int i;
 		q->HighPower=p->HighPower;
 		q->sign=p->sign;
		for(i=0;i<=p->HighPower;i++)
		q->CoeffArray[i]=p->CoeffArray[i];
 }
void Power(Poly p1,int X,Poly p3)
{
	P q;//存放中间变量并使用 
	int i;
	/*if(p1->sign=='-'||(X&1))//没有必要的 
	  p3->sign='-';           //乘法时候已经包含了符号的处理 
	  else
	  p3->sign='+';*/

	if(X==0)
	{
	p3->HighPower=0;
	p3->CoeffArray[0]=1;	
	}
	else if(X==1)
      copy(p1,p3);
	else if(X&1)
	{
	    MultPoly(p1,p1,p3);
	    copy(p3,&q);
		Power(&q,X/2,p3);
		copy(p3,&q);
		MultPoly(&q,p1,p3);
	}
	else
	{
		MultPoly(p1,p1,p3);
		copy(p3,&q);
		Power(&q,X/2,p3);
	}
}
int IsZore(Poly P)
{
	return P->HighPower==0&&P->CoeffArray[0]=='0';
}
void LeftMove(Poly p1,Poly p,int n)
{
	int i;
	MakeZore(p);
	p->HighPower=p1->HighPower+n;
	p->sign=p1->sign;	
	for(i=p->HighPower;i>=n;i--)
	p->CoeffArray[i]=p1->CoeffArray[i-n];
}
void DivPoly(Poly p1,Poly p2,Poly p3,Poly p4,int n)
{
	int bit;
	if(p1->sign==p2->sign)
	p3->sign='+';
	else
	p3->sign='-';
	int j=0;
	P i,P1,P2,P3,q,icopy;
	MakeZore(p3);
	MakeZore(&i);
	i.sign='+';
	i.HighPower=0;
	i.CoeffArray[0]='1';//i表示1，也就是除法时候 每次减一个除数，结果加1 
	MakeZore(&q);
	MakeZore(&P1);
	MakeZore(&P2);
	MakeZore(&P3);
	MakeZore(p4);
	copy(p1,&P1);
	copy(p2,&P2);
	copy(&i,&icopy);
	bit=P1.HighPower-P2.HighPower;
	while(bit>=0)
	{

	   LeftMove(p2,&P2,bit);
	while(compare(&P1,&P2)>=0)
	{
		LeftMove(&i,&icopy,bit);
		SubPoly(&P1,&P2,&P3);//被除数减去除数 
		copy(&P3,&P1);//相当于p2-p1储存到p1中 
		AddPoly(&icopy,p3,&q);//p3+1到q 
		copy(&q,p3);//把q放回p3；
		           //相当于p3+1； 
		

	}
	bit--;

	}


	for(j=p1->HighPower;p3->CoeffArray[j]=='0';j--)//寻找最高次 
	                 ;
	         if(j<0) p3->HighPower=0;
	            else p3->HighPower=j;
	    
	   if(!IsZore(&P1))
	   {
	   	
	   	j=0;
	   	while(j<n&&(!IsZore(&P1)))
	   	{
	   		
	   	   MakeZore(&P3);
	   	   
	   	   Mult(&P1,':',&P3,0);//每次乘以10
            P3.HighPower=P1.HighPower+1;
	      	copy(&P3,&P1);
	      	if(j!=0)
	      	{
	      		MakeZore(&q);
	      	Mult(&i,':',&q,0);
	      	q.HighPower=i.HighPower+1; 
	      	copy(&q,&i);	
			  }

	      	while(compare(&P1,&P2)>=0)
	      	{
	      		
	      		SubPoly(&P1,&P2,&q);
	      		copy(&q,&P1);
	      		AddPoly(&i,p4,&q);
	      		copy(&q,p4);
	      		
			  }
			  j++;
	      	
		   }
		   p4->HighPower=j-1;
		   reverse(p4);
	   }

 } 
