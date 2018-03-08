#include<stdio.h> 
#include<stdlib.h>
#include<math.h>

#ifndef HashTable_H
#define MinTableSize 5
 
typedef int ElementType; 
struct MoNode;//多项式的各单项
typedef struct MoNode *Monomial; 
typedef struct MoNode Cell;
struct ListNode;//哈希表
typedef struct ListNode *List;//指向表的指针
struct HashTbl;
typedef struct HashTbl *HashTable;
typedef List Position; 

Monomial CreateMono(void);
void MonoInsert(ElementType In,ElementType Co,Monomial M);
void MakeEmptyTable(HashTable H);
void MakeEmptyList(List L);
void MakeEmptyMono(Monomial M); 
HashTable InitailizeTable(int TableSize);
void TableInsert(Cell C,HashTable H);
Position Find(Cell C,HashTable H);
unsigned int Hash(Cell C,int TableSize);
void PrintTable(HashTable H);
void PrintMono(Monomial M);
int NextPrime(int num);
int IsPrime(int num);
void PrintList(List L);
void Error(const char *string);
void Multiply(Monomial M1,Monomial M2,Monomial M3,HashTable H);

#endif

struct MoNode
{
	int Index;//指数 
	int coeffic;//系数
	Monomial Next;
};
struct ListNode
{
	Cell Element;
	List Next;
};
struct HashTbl
{
	int TableSize;
	List *TheList;
};
void Error(const char *string)
{
	printf("%s",string);
	exit(0);
}
Monomial CreateMono(void)
{
	Monomial M;
	M=(Monomial )malloc(sizeof(*M));
	if(!M)
	Error("out of space!\n");
	M->Next=NULL;
	return M;
 }
 void MonoInsert(ElementType In,ElementType Co,Monomial M)
 {
 	  Monomial Current=M;
 	  Monomial New;
 	  while(Current->Next!=NULL&&Current->Next->Index>=In)
 	  Current=Current->Next;
 	  if(Current->Index==In)
 	  Current->coeffic+=Co;
 	  else 
 	  {
 	  	New=(Monomial )malloc(sizeof(*M));
 	  	if(!New)
 	  	Error("out of space!\n");
 	  	New->coeffic=Co;
 	  	New->Index=In;
 	  	New->Next=Current->Next;
 	  	Current->Next=New;
	   }
 }
 HashTable InitailizeTable(int TableSize)
 {
 	HashTable H;
 	int i;
     if(TableSize<MinTableSize)
     Error("Table size is too small!\n");
     H=(HashTable )malloc(sizeof(*H));
     if(!H)
     Error("out of space！\n");
     H->TableSize=NextPrime(TableSize);
     H->TheList=(List *)malloc(sizeof(List)*H->TableSize);
     if(!H->TheList)
     Error("out of space!\n");
     for(i=0;i<H->TableSize;i++)
     {
     	H->TheList[i]=(List )malloc(sizeof(struct ListNode));
     	H->TheList[i]->Next=NULL;
	 }
	 return H;
 }
unsigned int Hash(Cell C,int TableSize)
 {
 	return C.Index%TableSize;
  } 
Position Find(Cell C,HashTable H)
{
	Position Pos;
	Pos=H->TheList[Hash(C,H->TableSize)]->Next;
	while(Pos!=NULL&&Pos->Element.Index!=C.Index)
	Pos=Pos->Next;
	return Pos;
 } 
void TableInsert(Cell C,HashTable H)
{
	Position Pos;
	List New;
	Pos=Find(C,H);
	if(Pos)
	Pos->Element.coeffic+=C.coeffic;
	else
	{
		Pos=H->TheList[Hash(C,H->TableSize)];
		New=(List )malloc(sizeof(*New));
		if(!New)
		Error("out of space!\n");
		New->Element.coeffic=C.coeffic;
		New->Element.Index=C.Index;
		New->Next=Pos->Next;
		Pos->Next=New;
	}
 }

void MakeEmptyList(List L)
{
	if(L)
 {
 	MakeEmptyList(L->Next);
 	free(L);
	 }
}
void MakeEmptyTable(HashTable H)
{
	int i;
	if(H)
	{
		for(i=0;i<H->TableSize;i++)
		{
			MakeEmptyList(H->TheList[i]->Next);
			H->TheList[i]->Next=NULL;
		}
	}
}
void MakeEmptyMono(Monomial M)
{
	if(M->Next)
	{
		MakeEmptyMono(M->Next);
		free(M->Next);
	}
}
int IsPrime(int num)
{
	int i;
	for(i=2;i<=(int)sqrt(num);i++)
	if(num%i==0)
	return 0;
	return 1;
 }
 int NextPrime(int num)
 {
 	while(!IsPrime(num))
 	num++;
 	return num;
 }
 void PrintMono(Monomial M)
 {
 	M=M->Next;
 	if(M!=NULL)
 	{ 
 	printf("%dx^(%d)",M->coeffic,M->Index); 
 	M=M->Next;
 	} 
	 while(M!=NULL){
	 	 printf("+%dx^(%d)",M->coeffic,M->Index);
		  M=M->Next;	
	 }
	 putchar('\n'); 
 }
void PrintTable(HashTable H)
{

	int i;
	for(i=0;i<H->TableSize;i++)
	{
		printf("%d:",i);
		PrintList(H->TheList[i]);
		putchar('\n');
	}
}
void PrintList(List L)
{
	L=L->Next;
	while(L!=NULL)
	{
		printf("%d ",L->Element.Index);
		L=L->Next;
	}
}
void Multiply(Monomial M1,Monomial M2,Monomial M3,HashTable H)
{
	MakeEmptyTable(H);
	Monomial Current1,Current2;
	Cell C; 
	Current1=M1->Next;
	List L;
	int i;
	while(Current1!=NULL)
	{
		Current2=M2->Next;
		while(Current2!=NULL)
		{
			C.coeffic=Current1->coeffic*Current2->coeffic;
			C.Index=Current1->Index+Current2->Index;
			TableInsert(C,H);
			Current2=Current2->Next;
		}
		Current1=Current1->Next;
	}
	MakeEmptyMono(M3);
   for(i=0;i<H->TableSize;i++)
     {
     	L=H->TheList[i]->Next;
     	while(L!=NULL)
     	{
		MonoInsert(L->Element.Index,L->Element.coeffic,M3);	
		  L=L->Next;	
		 }

	 }
}
