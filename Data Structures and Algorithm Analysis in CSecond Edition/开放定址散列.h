#include<stdio.h>
#include<malloc.h>

#ifndef _HashQuad_H

typedef unsigned int Index;
typedef Index Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitailizeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key,HashTable H);
void Insert(ElementType Key,HashTable H);
ELementType ReTrieve(Position P,HashTable H);
HashTable Rehash(HashTable H);

#endif

enum KindOfEntry{
	Legitimate,Empty,Deleted//合法的，空的，已删除的（懒惰删除） 
};

struct HashEntry
{
	ElementType Element;
	enum KindOfEntry Info;//表示该位置元素的状态 
};
typedef struct HashEntry Cell;

struct HashTbl
{
	int TableSize;
	Cell *TheCell;
 };
 
 HashTable InitailizeTable(int TableSize)
 {
 	HashTable H;
 	int i;
 	if(TableSize<MinTableSize)
 	{
 		printf("the table size is too small!\n");
 		return NULL;
	 }
	 H=(HashTbl )malloc(sizeof(*H));
	 if(H==NULL)
	 {
	 	printf("out of space!\n");
	 	return NULL;
	 }
	 H->TableSize=NextPrime(TableSize);
	 
	 H->TheCell=(Cell *)malloc(sizeof(Cell)*H->TableSize);
	 if(H->TheCell==NULL)
	 {
	 	printf("out of space!\n");
	 	return NULL;
	 }
	 for(i=0;i<H->TableSize;i++)
	 
	 	H->TheCell[i].Info=Empty;
	  return H;
 }
 Position Find(ELementType Key,HashTable H)
 {
 	Position CurrentPos;
 	int CollisionNum=0;
 	CurrentPos=Hash(Key,H->TableSize);
	 while(H->TheCell[CurrentPos].Info!=Empty&&H->TheCell[CurrentPos].Element!=Key)
	 {
	 	CurrentPos+=2*++CullisionNum-1;
	 	if(CurrentPos>=H->TableSize) //第一次大于时候就会减去 所以后面加上来的不会是他的两倍之多 
	 	CurrentPos-=H->TableSize;
	  } 
	  return CurrentPos;
 }
 void Insert(ElementType Key,HashTable H)
 {
 	Position P;
 	P=Find(Key,H);//find如果没有找到 返回的是应该插入的位置 
 	if(H->TheCell[P].Info!=Legitimate)//非法的即为空  或者是已经删除的 
 	{
 	H->TheCell[P].Info=Legitimate;
 	  H->TheCell[P].Element=Key;
  } 
}
HashTable Rehash(HashTable H)//再散列 
{
	int i,OldSize;
	Cell *OldCells;
	OldCells=H->TheCell;
	OldSize=H->TableSize;
	
	H=InitailizeTable(2*OldSize);
	
	for(i=0;i<OldSize;i++)
	  if(OldCells[i].Info=Legitimate)
	  Insert(OldCells[i].Element,H);
	  free(OldCells);
	  return H; 
 } 
