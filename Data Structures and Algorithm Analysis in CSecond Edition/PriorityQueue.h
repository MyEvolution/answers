#ifndef _left_heap_h

#include <stdio.h>
#include <stdlib.h> 

typedef int ElementType; 
struct TreeNode;
typedef struct TreeNode *PriorityQueue;

int IsEmpty(PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);
void SwapChildren(PriorityQueue H);
PriorityQueue Insert1(ElementType Element,PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1,PriorityQueue H2);
PriorityQueue Mergel(PriorityQueue H1,PriorityQueue H2);
ElementType FindMin(PriorityQueue H);
void PrintHeap(PriorityQueue H);

#define Insert(Element,H) \
H=Insert1(Element,H)
#define DeleteMin(H) {\
int a; a=FindMin(H);H=DeleteMin1(H);return a;\
}

#endif

struct TreeNode
{
  PriorityQueue Left,Right;
  ElementType Element;
  int RoadLength;//路径长	
};

int IsEmpty(PriorityQueue H)
{
	if(H==NULL)
	return 1;
	else return 0;
}
PriorityQueue Merge(PriorityQueue H1,PriorityQueue H2)
{
	if(H1==NULL)
	return H2;
	if(H2==NULL)
	return H1;
	if(H1->Element>H2->Element)
    return Mergel(H1,H2);//把1和2的右子树合并 
    else 
    return Mergel(H2,H1);
    
}
PriorityQueue Mergel(PriorityQueue H1,PriorityQueue H2) //这个是把两个左式树合并  所以已经保证零路径等等是正确的 
{
    if(H2->Left==NULL)//单节点 因为在左式堆中不会出现有有孩子而没有左孩子的节点
     H2->Left=H1;//保证是左式树 
    else
    {
    	H2->Right=Merge(H2->Right,H1);
  
	   
    	if(H2->Left->RoadLength<H2->Right->RoadLength)
    	SwapChildren(H2);
    	H2->RoadLength=H2->Right->RoadLength+1;
}
	return H2;
}

//左式树 真的叼 
PriorityQueue Insert1(ElementType Element,PriorityQueue H)
{
    PriorityQueue h;
    h=(PriorityQueue )malloc(sizeof(*h));
    if(h==NULL)
    printf("out of space!\n");
    else
    {
    h->Element=Element;
	h->Left=h->Right=NULL;
	h->RoadLength=0;	
	}

	return Merge(h,H); 
}
PriorityQueue DeleteMin1(PriorityQueue H)
{
	if(IsEmpty(H))
	printf("the Heap is Empty!\n");
	else
	 if(H->Left==NULL)
	 H=NULL;
	 else
	 {
	 
	   if(H->Right==NULL||H->Left->Element<H->Right->Element)
	   {
	   	H->Element=H->Left->Element;
	   		   H->Left=DeleteMin1(H->Left);
	   		  
	   }
	   else 
	   {
	   	H->Element=H->Right->Element;
		   H->Right=DeleteMin1(H->Right); 
	   } 
       if(H->Left==NULL||H->Right==NULL)
       {
       	H->RoadLength=0;
       	if(H->Right!=NULL)
       	SwapChildren(H);
	   }
	   else
	   {
	   	if(H->Left->RoadLength<H->Right->RoadLength)
	   		SwapChildren(H);
	   		H->RoadLength=H->Right->RoadLength+1;
	   		
		   }
	   
   }
	   return H;
}
void SwapChildren(PriorityQueue H)
{
	PriorityQueue Temp;
	if(H==NULL)
	return;
	Temp=H->Left;
	H->Left=H->Right;
	H->Right=Temp;
}
void PrintHeap(PriorityQueue H)
{
   if(H!=NULL)
   {
   printf("%d\n",H->Element);
   PrintHeap(H->Left);
   PrintHeap(H->Right);
   }
 } 
/*
非递归做法是将右路径上的树排序，最后若有不符合左式堆结构的则进行交换 
对于这个算法来说编程较为困难  因为考虑到对零路径长的更新  从下往上合并更好一点  
这就需要加额外指针  指向个节点的父母
下面的算法只是把树排序 并算不上真正意义的合并  虽然他满足堆序性  却不满足左式堆的特点  

void Merge(PriorityQueue H1,PriorityQueue H2)
{
PriorityQueue Queue;
if(H1->Element>H2->Element)
{
 Queue=H2;
 H2=H2->Right; 
}
else
{
Queue = H1;
H1=H1->Right
} 
 
   while(H1!=NULL&&H2!=NULL)
   {
    if(H1->Element>H2->Element)
	{ Queue->Right=H2;
	Queue=Queue->Right;
	H2=H2->Right;
    }
    else
    {
    Queue->Right=H1;
    Queue=Queue->Right;
	H1=H1->Right;
     }
}
   Queue->Right=H1==NULL?H2:H1;
   return Queue;

} 
*/

