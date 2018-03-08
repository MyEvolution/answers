#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h> 

#ifndef HashTable_h

#define PREFIX 2
#define MinTableSize 10

typedef char *ElementType;
enum Kind{Empty,Prefix,Word};//标志是空还是word 
typedef int Position;
typedef unsigned int Index;
struct ListNode;
typedef struct ListNode Cell;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitailizeTable(int TableSize);
Position Find(ElementType Key,HashTable H,Index Pre);
Position FindPre(ElementType Key,HashTable H,Index *Pre);
void Insert(ElementType Key,HashTable H);
Index Hash(ElementType Key,int TableSize,Index Pre);
Index PreHash(ElementType Key,int TableSize);
int IsPrime(int num);
int NextPrime(int num);
void Error(const char *);

#endif

struct ListNode
{
    enum Kind kind;
	ElementType Key;	
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
Index PreHash(ElementType Key,int TableSize)
{
	int i;
	Index HashVal=0;
	
	for(i=0;i<PREFIX&&*Key!='\0';i++)
	  HashVal=HashVal*2+*Key++;
	  return HashVal%TableSize;
}
HashTable InitailizeTable(int TableSize)
{
	HashTable H;
	int i;
	if(TableSize<MinTableSize)
	Error("the table size is too small!\n");
	H=(HashTable )malloc(sizeof(*H));
	if(!H) Error("out of space!\n");
	H->TableSize=NextPrime(TableSize);
	H->TheCells=(Cell *)malloc(sizeof(Cell)*H->TableSize);
	if(H->TheCells==NULL) Error("the table size is too small!\n");
	for(i=0;i<H->TableSize;i++)
	H->TheCells[i].kind=Empty;
	return H;
}
Position Find(ElementType Key,HashTable H,Index Pre)
{
	Position Current;
	int mid=0;
	Current=Hash(Key,H->TableSize,Pre);
	while(H->TheCells[Current].kind!=Empty&&strcmp(H->TheCells[Current].Key,Key)!=0)
	{
		Current+=2*++mid-1;
		if(Current>=H->TableSize)
		Current-=H->TableSize;
	 }
	 return Current;
}
Position FindPre(ElementType Key,HashTable H,Index *Pre)
{
	char a[PREFIX+1];
	Position Current;
	int mid=0;
	Current=PreHash(Key,H->TableSize);
	*Pre=Current;
	strncpy(a,Key,PREFIX);
	a[PREFIX]='\0';
	while(H->TheCells[Current].kind!=Empty&&strcmp(H->TheCells[Current].Key,a)!=0)
	{
		Current+=2*++mid-1;
		if(Current>=H->TableSize)
		Current-=H->TableSize;
	 }
	 return Current;
} 
void Insert(ElementType Key,HashTable H)//把前缀和整个单词都加入 
{
	Position Pos;
	Index Pre;
	Pos=FindPre(Key,H,&Pre);
	if(H->TheCells[Pos].kind==Empty)
	{
			H->TheCells[Pos].kind=Prefix;
			H->TheCells[Pos].Key=(ElementType )malloc(sizeof(PREFIX+1));
			strncpy(H->TheCells[Pos].Key,Key,PREFIX);
			H->TheCells[Pos].Key[PREFIX]='\0';
	}
	Pos=Find(Key,H,Pre);
	if(H->TheCells[Pos].kind!=Word)
	{
		H->TheCells[Pos].kind=Word;
		H->TheCells[Pos].Key=(ElementType )malloc(sizeof(Key));
		strcpy(H->TheCells[Pos].Key,Key); 
	}
}
Index Hash(ElementType Key,int TableSize,Index Pre)
{
	int i;
	Index HashVal=Pre;
	for(i=0;i<PREFIX;i++)
	 if(*Key++=='\0')
	 return Pre;
	while(*Key!='\0')
	HashVal=HashVal*2+*Key++;
	return HashVal%TableSize;
}
int IsPrime(int num)
{
	int i;
	for(i=2;i<=(int )sqrt(num);i++)
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
void PrintTable(HashTable H)
{
	int i;
	for(i=0;i<H->TableSize;i++)
	if(H->TheCells[i].kind!=Empty)
	printf("%d %s\n",i,H->TheCells[i].Key);
}

