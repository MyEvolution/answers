#ifndef Hash_Word_INCLUDE

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAXLEN 30
#define MinTableSize 10 

struct WordNode;
typedef struct WordNode *TheWord;
struct HashTbl;
typedef struct HashTbl *HashTable;
typedef unsigned int Index;
typedef char * ElementType;
typedef TheWord Position;

HashTable InitailizeTable(int TableSize);
Index Hash(ElementType Key,int TableSize);
HashTable Insert(ElementType Key,ElementType translate,HashTable H);
Position Find(ElementType Key,HashTable H);
void Error(const char *string);
int NextPrime(int num);
int IsPrime(int num);
void PrintTable(HashTable H);
HashTable ReHash(HashTable H);
int Delete(ElementType Key,HashTable H);

#endif

enum kind
{
	Empty,Legitimate,Deleted 
};
struct WordNode
{
	char word[MAXLEN];
	char translate[50];
	enum kind Info;
 };
struct HashTbl
{
	int num;
	TheWord *TheList;
	int TableSize;
};

void Error(const char *string)
{
	printf("%s",string);
	exit(0);
}
HashTable InitailizeTable(int TableSize)
{
	HashTable H;
	int i;
	if(TableSize<MinTableSize)
	Error("the Table size is too small!\n");
	H=(HashTable )malloc(sizeof(*H));
		H->num=0;
	if(H==NULL)
	Error("out of space!\n");
	H->TableSize=NextPrime(TableSize);
	H->TheList=(TheWord *)malloc(sizeof(TheWord)*H->TableSize);
	if(H->TheList==NULL)
	Error("out of space!\n");

	for(i=0;i<H->TableSize;i++)
	{
		H->TheList[i]=(TheWord )malloc(sizeof(struct WordNode));
		if(H->TheList[i]==NULL)
		Error("out of space!\n");
		H->TheList[i]->Info=Empty;
	 }
	 return H; 
}
Index Hash(ElementType Key,int TableSize)
{
	Index HashVal=0; 
	while(*Key!='\0')
	HashVal=HashVal<<2+*Key++;	
	return HashVal%TableSize;
}
Position Find(ElementType Key,HashTable H)
{
	Index Current;
	int c=0;
    Position Pos;
    Current=Hash(Key,H->TableSize);
    Pos=H->TheList[Current];
    while(Pos->Info==Legitimate&&strcmp(Pos->word,Key)!=0)//被删除的也会被占用 
      {
      	Current+=2*++c-1;
      	if(Current>=H->TableSize)
      	Current-=H->TableSize;
		 Pos=H->TheList[Current]; 
	   } 
	   return Pos;
}
HashTable Insert(ElementType Key,ElementType translate,HashTable H)
{
	Position Pos;
	Pos=Find(Key,H);
	if(Pos->Info==Empty)
	{
		if(H->num>=H->TableSize/2)
		H=ReHash(H);
		Pos=Find(Key,H);
		Pos->Info=Legitimate;
	   strcpy(Pos->word,Key);
	   H->num++;
	}
	else if(Pos->Info==Deleted)
	{
		Pos->Info=Legitimate;
		H->num++;
	}
		strcpy(Pos->translate,translate);
	return H;
}
void PrintTable(HashTable H)
{
	int i;
	if(H)
	{
		
		for(i=0;i<H->TableSize;i++)
		if(H->TheList[i]->Info==Legitimate)
		 printf("%s\n%s\n",H->TheList[i]->word,H->TheList[i]->translate);
		 printf("词库里共包含%d个单词\n",H->num);
	}
}
void DestroyTable(HashTable H)
{
	if(H)
	{
		free(H->TheList);
		free(H);
	}
 } 
HashTable ReHash(HashTable H)
{
	int i;
	HashTable h;
	h=InitailizeTable(H->TableSize*2);
	for(i=0;i<H->TableSize;i++)
	if(H->TheList[i]->Info==Legitimate)
	Insert(H->TheList[i]->word,H->TheList[i]->translate,h); 
	free(H);
	return h;
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
int Delete(ElementType Key,HashTable H)
{
	Position Pos;
	Pos=Find(Key,H);
	if(Pos->Info!=Legitimate)
	      return 0;//表示不存在 
	      else
	      {
	      	Pos->Info=Deleted;
	      	H->num--;
	      	return 1;
		  }
}
