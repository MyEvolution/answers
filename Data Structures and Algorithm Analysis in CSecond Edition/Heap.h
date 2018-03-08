#ifndef _BinHeap_h
 
#include<stdio.h>
#include<stdlib.h>
#define MINSIZE 10
#define MinElement -1//������С��Ԫ��  ���԰�������0��λ�� �ô�����ῴ�� 
/*
��������ǹ��ڶѵĲ�����ͷ�ļ���
��Ϊ�Ǻܳ�ʱ����ǰ���� ����������������һ�¶ѵ�˼·
�� �����ȶ���  ��ֵ��С��������ǰ��  ��������ȫ��������ʵ��
��С��Ԫ���ڶѵĶ���  ÿһ����������һ����
����С�ѣ�Ҳ����˫�׽��С�ں��ӽ��
Ϊ������ȫ��������
����Ǻ�����  �����ڶ�����������˵ ��Ϊ���ڵ�����С�ڵ��������Ի������Լ�Ѱ��λ��
�����ٲ���ʱ�򲻿����������� ��Ȼ��˳���������� 
ʵ���� ��ȫ������Ҳ�Ǻܷ�������ݽṹ  �����Է���  ��ȫ��������������������ʾ
a��������2a���Һ�����2a+1��
���濪ʼ����һ������ȫ������ʵ�ֶѲ��� //�������ʾ����ȫ������ 
*/ 
struct HeapStruct;//����һ�¶� 
typedef struct HeapStruct *Heap;
typedef int ElementType;
typedef int position;

Heap InitailizeHeap(int Size);
void Insert(ElementType Element,Heap H);
void error(const char * string);
ElementType FindMin(Heap H);
ElementType Delete(Heap H);//ɾ���ǹؼ�   �ѵ�ɾ��������ɾ����Сֵ ������ 
void PrintHeap(Heap H);
void Add(int n,Heap H);
void BuildHeap(Heap H);
void MakeCorrect(Heap H,position i);

struct HeapStruct
{
    int HeapSize;//���Ƕѵ����Χ
    int n;//�����ʾ���ڶ����ж���Ԫ�� 
    ElementType *List;//���Ƕ�ָ�������
    };


#endif

void error(const char *string)
{
    printf("%s",string);
    getchar();
    exit(0);
}
Heap InitailizeHeap(int Size)
{
    Heap H;
    if(Size<MINSIZE)
    error("the Heap's size is too small!\n");
    H=(Heap )malloc(sizeof(struct HeapStruct));
    if(H==NULL)
    error("out of space!\n");
    H->HeapSize=Size;
    H->n=0; 
    H->List=(ElementType *)malloc((Size+1)*sizeof(ElementType));
    if(H->List==NULL)
    error("out of space!\n");
    H->List[0]=MinElement;
    return H;
} 
void Insert(ElementType Element,Heap H)
{
    int Position;
    Position=++H->n;
    if(H->n>=H->HeapSize)
    error("the Heap is full!\n");
    while(Element<H->List[Position/2])//���û����С��Ԫ��������ͷ  ����Ҫ���һ���жϣ� 
    {
        H->List[Position]=H->List[Position/2];
        Position = Position/2;
    }
    H->List[Position]=Element;
}
ElementType FindMin(Heap H)
{
    if(H->n)
    return H->List[1];
}
ElementType Delete(Heap H)
{
    if(!H->n)
    error("the Heap is empty!\n");
    ElementType Wait;
    int Position;
    ElementType Min;
    Min=H->List[1];
    int last;
     Wait=H->List[H->n];
      
     Position = 1;
     if(--H->n>=1)
     {
		 	while((last=Position)&&Position*2<=H->n)//�����û�ҵ� 
     	{     //���������˺ܳ�ʱ�� ԭ����û�м�����  �Ӵ�Ӧ�ü�ס &&�����ȼ����ڸ�ֵ= 
		 //��ʾ�տ�ʼ��λ��  Ҳ���ǿ�Ѩ 
        if((Position=Position*2)!=H->n&&H->List[Position+1]<H->List[Position])//�����֤����������,���һ�����������Ϊ����
		 Position++;	//position���ڴ������λ�� �������Ѩ��λ��	
		 if(H->List[Position]<=Wait)//�����С�ڵĻ������Ѩ   ������Ǿ�˵���ҵ��˸����λ�� 
	      H->List[last]=H->List[Position];
	      else
	      break;
		 
	}
	   H->List[last]=Wait; //�ҵ���Ѩλ��
	   
	 }
        
        return Min;             
}
void PrintHeap(Heap H)
{
    int i;
    if(H->n)
    for(i=1;i<=H->n;i++)
    printf("%d ",H->List[i]);
    else
    printf("the Heap is empty!\n");
}

void Add(int n,Heap H)
{
	int i;
	ElementType Element;
	printf("����������Ҫ��ӵ����� ���м��ÿո����������ûس�����\n");
    for(i=1;i<=n;i++)
    {
    	scanf("%d",&Element); 
    	getchar();
    	H->List[H->n+i]=Element; 
	}
	H->n+=n;
}
void BuildHeap(Heap H)//һ���������ȫ������  ��ת��Ϊ�� 
{
	int i;
	for(i=H->n/2;i>=1;i--)
	  MakeCorrect(H,i); 
}
void MakeCorrect(Heap H,int i)
{
	position Position;
	Position = i;
	ElementType Temp;
	while(Position*2<=H->n)
	{
		if((Position=Position*2)!=H->n&&H->List[Position]>H->List[Position+1])
		Position ++;
		if(H->List[Position]<H->List[i])
		{
			Temp=H->List[Position];
			H->List[Position]=H->List[i];
			H->List[i]=Temp;
			i=Position;
		}
		else
		  break;
	}
}
    
