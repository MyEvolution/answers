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
    char CoeffArray[MaxDegree];//��һλ��Ž����� 
	unsigned int HighPower;//��ߵĴ��� 
}P,*Poly;//����ʽ�Ľṹ ��ʵ������10�������Ľṹ�� 


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
void AddPoly(Poly p1,Poly p2,Poly p3)//�Ӷ���ʽ 
{
	int i;
	char remainder;//���� 
	char carry;//��λ 
	char borrow;//��λ 
	int comp;
	MakeZore(p3);
	if(p1->sign==p2->sign)
	{
		p3->sign=p1->sign;
	 for(i=0;i<=max(p1->HighPower,p2->HighPower);i++)
	 {
	 	remainder=(p1->CoeffArray[i]+p3->CoeffArray[i]+p2->CoeffArray[i]-3*'0')%10;
	 	carry=(p1->CoeffArray[i]+p3->CoeffArray[i]+p2->CoeffArray[i]-3*'0')/10;
	 	p3->CoeffArray[i]=remainder+'0';//Ϊʲô���Ǽӵ�����  ��Ϊ֮ǰ�Ѿ��ӹ��˵�1  ����Ҫ�ж��Ƿ����10��ʹ��
		                             // �����ж�ʱ�ּ���һ�� ���ټӾͻ��ظ� 
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
     		 	remainder=p1->CoeffArray[i]+10-p2->CoeffArray[i];//��λ 
     		 	p3->CoeffArray[i+1]-=borrow;//���ܸı�p1���������ǿ��Ըı�p3 
     		 	p3->CoeffArray[i]+=remainder;//�ڼ�����λʱ�������>9�����
				        //���ǿɲ�������=�أ����Ƿ񶨵ģ�
						//��Ϊ�����remainder��û�аѽ����һλ��ȥ 
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
		    remainder=p2->CoeffArray[i]+10-p1->CoeffArray[i];//��λ 
     		 	p3->CoeffArray[i+1]-=borrow;//���ܸı�p1���������ǿ��Ըı�p3 
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
void SubPoly(Poly p1,Poly p2,Poly p3)//������ʽ ͨ����ʵ�� 
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
void Mult(Poly p1,char X,Poly p3,int i)//i��ʾ��p3�ĵڼ�λ��ʼ�洢 
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
	  i=p1->HighPower+p2->HighPower+2;//������������λ���ᳬ�����ֵ 
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
	P q;//����м������ʹ�� 
	int i;
	/*if(p1->sign=='-'||(X&1))//û�б�Ҫ�� 
	  p3->sign='-';           //�˷�ʱ���Ѿ������˷��ŵĴ��� 
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
	i.CoeffArray[0]='1';//i��ʾ1��Ҳ���ǳ���ʱ�� ÿ�μ�һ�������������1 
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
		SubPoly(&P1,&P2,&P3);//��������ȥ���� 
		copy(&P3,&P1);//�൱��p2-p1���浽p1�� 
		AddPoly(&icopy,p3,&q);//p3+1��q 
		copy(&q,p3);//��q�Ż�p3��
		           //�൱��p3+1�� 
		

	}
	bit--;

	}


	for(j=p1->HighPower;p3->CoeffArray[j]=='0';j--)//Ѱ����ߴ� 
	                 ;
	         if(j<0) p3->HighPower=0;
	            else p3->HighPower=j;
	    
	   if(!IsZore(&P1))
	   {
	   	
	   	j=0;
	   	while(j<n&&(!IsZore(&P1)))
	   	{
	   		
	   	   MakeZore(&P3);
	   	   
	   	   Mult(&P1,':',&P3,0);//ÿ�γ���10
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
