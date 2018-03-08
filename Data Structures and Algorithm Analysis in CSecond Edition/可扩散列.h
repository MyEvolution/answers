#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#ifndef Extendible_Hashing_H

#define M 4
typedef unsigned char ElementType;
struct ListNode;
typedef ElementType *Position;
typedef struct ListNode *List;
struct HashTbl;
struct DirNode; 
typedef struct HashTbl *HashTable;
typedef unsigned int Index;

HashTable InitailizeTable(int TheNum);
HashTable ReHash(HashTable H);
void DestroyTable(HashTable H);
Index Hash(ElementType Element,int TheNum);
Position Find(ElementType Element,HashTable H);
HashTable Insert(ElementType Element,HashTable H);
void Error(const char *string);
void PrintTable(HashTable H);

#endif

struct DirNode
{
ElementType Dir;
int Num;//表示这个表中的个数 
  ElementType *TheList;	
};
struct HashTbl
{
	int TheNum;
	struct DirNode *DIR; 
};
void Error(const char *string)
{
	printf("%s",string);
	exit(0);
}
HashTable InitailizeTable(int TheNum)
{
	int i;
	HashTable H;
	H=(HashTable )malloc(sizeof(*H));
	if(H==NULL)
	Error("the table size is too small!\n");
	H->TheNum=TheNum;
	H->DIR=(struct DirNode *)malloc(sizeof(struct DirNode)*pow(2,H->TheNum));
	for(i=0;i<pow(2,H->TheNum);i++)
	{
		
		H->DIR[i].TheList=NULL;
		H->DIR[i].Dir=i;
		H->DIR[i].Num=0;
	}
	return H;
}
HashTable ReHash(HashTable H)
{
	int i,j;
	HashTable ReH;
	ReH=InitailizeTable(H->TheNum+1);
	for(i=0,j=0;i<pow(2,ReH->TheNum)&&j<pow(2,H->TheNum);i+=2,j++)
	{
		ReH->DIR[i].TheList=ReH->DIR[i+1].TheList=H->DIR[j].TheList;
		 ReH->DIR[i].Num=ReH->DIR[i+1].Num=H->DIR[j].Num;
	}
	free(H); //之前在这里直接把表摧毁  这是不应该的 ，因为新表指向的还是原来的List，摧毁了那一块也相当于被释放了 
	return ReH; 
}
void DestroyTable(HashTable H)
{
	int i;
	if(H)
	{
		for(i=0;i<pow(2,H->TheNum);i++)
		   if(H->DIR[i].TheList==H->DIR[i+1].TheList||H->DIR[i].TheList==NULL) ;
		      else 
		        free(H->DIR[i].TheList);
	  free(H);
	}
}
Index Hash(ElementType Element,int TheNum)
{
	return Element>>(sizeof(ElementType )*8-TheNum);
}
Position Find(ElementType Element,HashTable H)
{
	int i;
	int hash;
	hash=Hash(Element,H->TheNum);
	  
	for(i=0;i<H->DIR[hash].Num;i++)
	 if(H->DIR[hash].TheList[i]==Element)
	 break;
	 if(i>=M||i==0)
	 return NULL;
	 return &H->DIR[hash].TheList[i]; 
}
HashTable Insert(ElementType Element,HashTable H)
{
	Position Pos;
	int hash=Hash(Element,H->TheNum);
	int start,end;
	ElementType Elements[M];
	int i;
	Pos = Find(Element,H);

	if(Pos==NULL)
	{
		if(H->DIR[hash].Num==0)
		{
			H->DIR[hash].TheList=(ElementType *)malloc(sizeof(ElementType )*M);
			H->DIR[hash].TheList[0]=Element;
			H->DIR[hash].Num++;
		}
		else if(H->DIR[hash].TheList!=H->DIR[hash-1].TheList&&H->DIR[hash].TheList!=H->DIR[hash+1].TheList)
		{
			H=ReHash(H);
			H=Insert(Element,H);
		}
		else//多个目录指向同一个表的情况 
		{
			for(i=hash-1;i>=0;i--)
			if(H->DIR[i].TheList!=H->DIR[hash].TheList)
			   break;
			   start=i+1;
			for(i=hash+1;i<pow(2,H->TheNum);i++)
			if(H->DIR[i].TheList!=H->DIR[hash].TheList)
			   break;
			   end=i-1;
              for(i=0;i<M;i++)
			Elements[i]=H->DIR[hash].TheList[i];
			free(H->DIR[hash].TheList);
		for(i=start;i<=end;i++)
		{ 
		  H->DIR[i].TheList=NULL;  
		  H->DIR[i].Num=0;
	      }
	      for(i=0;i<M;i++)
	      H=Insert(Elements[i],H);
	      H=Insert(Element,H);
		}
	}else if(*Pos!=Element){//这里是有问题的  因为是没有赋值的未定义 可能会有很小的可能他们是相等的 
				for(i=hash-1;i>=0;i--)
			if(H->DIR[i].TheList!=H->DIR[hash].TheList)
			   break;
			   start=i+1;
			for(i=hash+1;i<pow(2,H->TheNum);i++)
			if(H->DIR[i].TheList!=H->DIR[hash].TheList)
			   break;
			   end=i-1;
			for(i=start;i<=end;i++)
		H->DIR[i].Num++;
		*Pos=Element; 	
	}
	return H;
}
void PrintTable(HashTable H)
{
	int i,j;
	if(H)
	{
	for(i=0;i<pow(2,H->TheNum);i++)
	{
		printf("%d %d:",H->DIR[i].Dir,H->DIR[i].Num);
		for(j=0;j<H->DIR[i].Num;j++)
		printf("%d ",H->DIR[i].TheList[j]);
		putchar('\n');
		}	
	}
 } 
  
