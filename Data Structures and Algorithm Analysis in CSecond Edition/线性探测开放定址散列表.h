#include<stdio.h>
#include<stdlib.h>

#ifndef HashTable_H

#define MinTableSize 5
struct Node;
typedef struct Node Cell;
struct HashTbl;
typedef struct HashTbl *HashTable;
typedef int Position;
typedef int Index;
typedef int ElementType; 

Index Hash(ElementType Key,int TableSize);
HashTable InitailizeTable(int TableSize);
void Insert(ElementType Key,HashTable H);
void Delete(ElementType Key,HashTable H);
Position Find(ElementType Key,HashTable H);
HashTable ReHash(HashTable H);
void PrintTable(HashTable H);
void DestroyTable(HashTable H);
void Error(const char *string);

#endif
 
enum KindOfOrder
{
	Empty,Legitimate,Deleted 
};
struct Node
{
	enum KindOfOrder Info;
	ElementType ELement;
 };
struct HashTbl
{
   int TableSize;
	Cell *TheCells; 
};

void Error(const char *string)
{
	printf("%s",string);
	exit(0);
}
Index Hash(ElementType Key,int TableSize)
{
	return Key%TableSize;
}
HashTable InitailizeTable(int TableSize)
{
	HashTable H;
	int i;
	if(TableSize<MinTableSize)
	Error("the Table size is too small!\n");
	H=(HashTable )malloc(sizeof(*H));
	//TableSize=NextPrime(TableSize);本次只是实验 所以不需要素数 实际上是需要素数更好 
	if(H==NULL)
	Error("out of space!\n");
	H->TableSize=TableSize;
	H->TheCells=(Cell *)malloc(sizeof(Cell)*H->TableSize);
	if(!H->TheCells)
	Error("out of space!\n");
	for(i=0;i<H->TableSize;i++)
	H->TheCells[i].Info=Empty;
	return H;
}
Position Find(ElementType Key,HashTable H)
{
	Position CurrentPos;
	CurrentPos=Hash(Key,H->TableSize);
	while(H->TheCells[CurrentPos].Info==Legitimate&&H->TheCells[CurrentPos].ELement!=Key)
	{
		CurrentPos++;
		if(CurrentPos>=H->TableSize)
		CurrentPos-=H->TableSize;
	}     	
      	return CurrentPos;
}
void Insert(ElementType Key,HashTable H)
{
	Position Pos;
	Pos=Find(Key,H);
	if(H->TheCells[Pos].Info!=Legitimate)
	{
		H->TheCells[Pos].ELement=Key;
		H->TheCells[Pos].Info=Legitimate;
	}
}
void Delete(ElementType Key,HashTable H)
{
	Position Pos;
	Pos=Find(Key,H);
	if(H->TheCells[Pos].Info==Legitimate)
	H->TheCells[Pos].Info=Deleted;
}
void PrintTable(HashTable H)
{
	int i;
	for(i=0;i<H->TableSize;i++)
	{
		printf("%d:",i);
		if(H->TheCells[i].Info==Legitimate)
		printf("%d",H->TheCells[i].ELement);
		else
		printf("Empty Or Deleted!");
		putchar('\n'); 
	}
}
HashTable ReHash(HashTable H)
{
	HashTable h;
	int i;
	h=InitailizeTable(2*H->TableSize);
	for(i=0;i<H->TableSize;i++)
	if(H->TheCells[i].Info==Legitimate)
	Insert(H->TheCells[i].ELement,h);
	DestroyTable(H);
	return h; 
 } 
void DestroyTable(HashTable H)
{
	if(H)
	{
		free(H->TheCells);
		free(H);
	}
}
