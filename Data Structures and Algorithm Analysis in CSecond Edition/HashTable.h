#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h> 

#ifndef HashTable_H
#define MinTableSize 10
 
struct ListNode;
typedef struct ListNode *List;
struct HashTbl;
typedef struct HashTbl *HashTable;
typedef unsigned int Index;
typedef char *ElementType;
typedef List Position;

HashTable InitailizeTable(int TableSize);
Position Find(ElementType Key,HashTable H);
void Insert(ElementType Key,HashTable H);
Index Hash(ElementType Key,int TableSize);
int NextPrime(int Num);
int IsPrime(int Num);
void Error(const char *string);
#endif

struct ListNode
{
	ElementType Key;
	List Next;
};
struct HashTbl
{
	int TableSize;
	List *TheLists;
};

void Error(const char *string)
{
	printf("%s",string);
	exit(0);
}
HashTable InitailizeTable(int TableSize)
{
	int i;
	HashTable H;
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
Position Find(ElementType Key,HashTable H)
{ 
    List L;
    Position Pos;
    L=H->TheLists[Hash(Key,H->TableSize)];
    Pos=L->Next;
    while(Pos!=NULL&&strcmp(Pos->Key,Key)!=0)
    Pos=Pos->Next;
    return Pos;
}
void Insert(ElementType Key,HashTable H)
{
	List L;
	Position Pos;
	Index num;
	num=Hash(Key,H->TableSize);
	L=H->TheLists[num];
	Pos=L->Next;
	while(Pos!=NULL&&strcmp(Pos->Key,Key)!=0)
	Pos=Pos->Next;
	if(Pos==NULL)
	{
		Pos=(List )malloc(sizeof(*Pos));
		if(Pos==NULL)
		Error("out of space!\n");
		Pos->Key=(ElementType )malloc(sizeof(Key+1));
		if(Pos->Key==NULL)
		Error("out of space!\n");
		strcpy(Pos->Key,Key);
		Pos->Next=L->Next;
		L->Next=Pos;
	}
}
Index Hash(ElementType Key,int TableSize)//选一个怎么样的哈希函数 
{        
    Index HashVal=0;                                //对于一个单词来说 
    while(*Key!='\0')                                    //全部相加来说总是不好的，因为覆盖的太少了很容易产生冲突									//不过在这里我也没有打算测试很多单词 所以实际上是无所谓的 
	 HashVal=HashVal<<2+*Key++;
	return HashVal%TableSize; 
}
int IsPrime(int Num)
{
	int i;
	for(i=2;i<=(int)sqrt(Num);i++)
	if(Num%i==0)
	return 0;
	return 1;
}
int NextPrime(int num)
{
	while(!IsPrime(num))
	num++;
	return num;
}
void PrintTable(HashTable H)
{
	int i;
	List L;
	for(i=0;i<H->TableSize;i++)
	{
		L=H->TheLists[i]->Next;
		while(L!=NULL)
		{
		printf("%s\n",L->Key);
		L=L->Next;
		}
		
	}
	
}
