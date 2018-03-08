#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#ifndef _Hash_List_H
#define MinTableSize 5
 
typedef int ElementType;
struct ListNode;
typedef struct ListNode *List;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;
typedef unsigned int Index;

Index Hash(ElementType Key,int TableSize);
HashTable InitailizeTable(int TableSize);
Position Find(ElementType Key,HashTable H);
void Insert(ElementType Key,HashTable H);
void Delete(ElementType Key,HashTable H);
void MakeEmpty(List L);
void DestroyTable(HashTable H);
ElementType Retrieve(Position P);
int NextPrime(int Num);
void Error(const char *string);
int IsPrime(int Num);
void PrintTable(HashTable H);
void PrintList(List L);

#endif

struct ListNode
{
	ElementType Element;
	List Next;
};
struct HashTbl
{
 	int TableSize;
 	List *TheLists;
};
Index Hash(ElementType Key,int TableSize)
{
     return Key%TableSize;
}
HashTable InitailizeTable(int TableSize)
{
	HashTable H;
	int i;
	if(TableSize<MinTableSize)
      Error("the table size is too small!\n");
	H=(HashTable )malloc(sizeof(*H));
	if(H==NULL)
	Error("out of space!\n");
	H->TableSize=NextPrime(TableSize);
	H->TheLists=(List *)malloc(sizeof(List)*H->TableSize);
	if(H->TheLists==NULL)
	Error("out of space!\n");
	for(i=0;i<H->TableSize;i++)
	{
		H->TheLists[i]=(List )malloc(sizeof(struct ListNode));
		if(H->TheLists[i]==NULL)
		Error("out of space!\n");
		H->TheLists[i]->Next=NULL;
	}
	return H;
}
void Error(const char *string)
{
	printf("%s",string);
	exit(0);
}
void MakeEmpty(List L)//这里说是把表制空  实际上是把表删除了 因为没有留下表头 
{
	if(L)
	{
		MakeEmpty(L->Next);
		free(L);
	}
}
void DestroyTable(HashTable H)
{
	int i;
  if(H)
  {
  	for(i=0;i<H->TableSize;i++)
  	MakeEmpty(H->TheLists[i]);
  	free(H->TheLists);
  	free(H);
	  }	
}
Position Find(ElementType Key,HashTable H)
{
	Index Pos;
	List L;
	Pos=Hash(Key,H->TableSize);
	L=H->TheLists[Pos]->Next;
	while(L!=NULL&&L->Element!=Key)
		L=L->Next;
		return NULL;
}
void Insert(ElementType Key,HashTable H)
{
	Position P;
	Position NewCell;
	P=Find(Key,H);
	if(!P)//Key不在表内 
	{
		P=H->TheLists[Hash(Key,H->TableSize)];
		NewCell=(List )malloc(sizeof(struct ListNode));
		if(NewCell==NULL)
		Error("out of space!\n");	
		NewCell->Element=Key;
		NewCell->Next=P->Next;
		P->Next=NewCell;
	}
}
void Delete(ElementType Key,HashTable H)
{
	Position P,Old;
	P=Find(Key,H);
	if(P)
	{
		Old=H->TheLists[Hash(Key,H->TableSize)];
		while(Old->Next!=P)
			Old=Old->Next;
		Old->Next=P->Next;
		free(P);
	}
}
ElementType Retrieve(Position P)
{
	return P->Element;
 }
int NextPrime(int Num)
{
	while(!IsPrime(Num))
	   Num++;
	   return Num;
}
int IsPrime(int Num)
{
	int i;
	for(i=2;i<=(int)sqrt(Num);i++)
	if(Num%i==0)
	return 0;
	return 1;
}
void PrintList(List L)
{
	if(L->Next==NULL)
	printf("Empty");
	else
	{
		L=L->Next;
		printf("%d",L->Element);
		while(L->Next!=NULL)
		{
			L=L->Next;
			printf(" %d",L->Element);
		}
	}
}
void PrintTable(HashTable H)
{
	int i;
	for(i=0;i<H->TableSize;i++)
	{
		printf("%d:",i);
		PrintList(H->TheLists[i]);
		putchar('\n');
	}
}
