#ifndef _BinHeap_h
 
#include<stdio.h>
#include<stdlib.h>
#define MINSIZE 10
#define MinElement -1//这是最小的元素  可以把他放在0的位置 用处后面会看到 
/*
这个程序是关于堆的操作的头文件；
因为是很长时间以前看的 所以在这里先整理一下堆的思路
堆 是优先队列  将值最小的排在最前面  可以用完全二叉树来实现
最小的元素在堆的顶部  每一个子树都是一个堆
（最小堆）也就是双亲结点小于孩子结点
为何用完全二叉树？
这个是好问题  ，对于二叉排序树来说 因为大于的在右小于的在左，所以基本会自己寻到位置
而堆再插入时候不考虑上述规则 当然是顺着往后插最简单 
实际上 完全二叉树也是很方便的数据结构  ，可以发现  完全二叉树可以用数组来表示
a的左孩子是2a，右孩子是2a+1；
下面开始尝试一下用完全二叉树实现堆操作 //用数组表示的完全二叉树 
*/ 
struct HeapStruct;//定义一下堆 
typedef struct HeapStruct *Heap;
typedef int ElementType;
typedef int position;

Heap InitailizeHeap(int Size);
void Insert(ElementType Element,Heap H);
void error(const char * string);
ElementType FindMin(Heap H);
ElementType Delete(Heap H);//删除是关键   堆得删除操作是删除最小值 并返回 
void PrintHeap(Heap H);
void Add(int n,Heap H);
void BuildHeap(Heap H);
void MakeCorrect(Heap H,position i);

struct HeapStruct
{
    int HeapSize;//这是堆的最大范围
    int n;//这个表示现在堆里有多少元素 
    ElementType *List;//这是堆指向的数组
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
    while(Element<H->List[Position/2])//如果没有最小的元素在数组头  就需要多加一个判断） 
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
		 	while((last=Position)&&Position*2<=H->n)//到最后都没找到 
     	{     //在这里晕了很长时间 原来是没有加括号  从此应该记住 &&的优先级大于赋值= 
		 //表示刚开始的位置  也就是空穴 
        if((Position=Position*2)!=H->n&&H->List[Position+1]<H->List[Position])//这个保证是两个孩子,最后一个孩子是序号为奇数
		 Position++;	//position现在处于这个位置 即将填补空穴的位置	
		 if(H->List[Position]<=Wait)//如果都小于的话就填补空穴   如果不是就说明找到了该填补的位置 
	      H->List[last]=H->List[Position];
	      else
	      break;
		 
	}
	   H->List[last]=Wait; //找到空穴位置
	   
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
	printf("请依次输入要添加的数字 ，中间用空格隔开，最后用回车结束\n");
    for(i=1;i<=n;i++)
    {
    	scanf("%d",&Element); 
    	getchar();
    	H->List[H->n+i]=Element; 
	}
	H->n+=n;
}
void BuildHeap(Heap H)//一组无序的完全二叉树  把转化为堆 
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
    
