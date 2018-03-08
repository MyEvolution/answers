#include"Heap.h"
#include<windows.h> 

int main()
{
	printf("输入以下序号：\n");
	printf("1.创建一个堆\n");
	printf("2.向堆内添加元素\n");
	printf("3.删除堆顶元素\n"); 
	printf("4.打印堆\n");
	printf("5.构建无序完全二叉树\n");
	printf("6.构建堆\n");
   char c;
   int n;
   
   ElementType ELement;
   Heap H=NULL;
   while((c=getchar())!='0')
   {
   	getchar();
   	system("cls");
   	switch(c)
   	{
   		
   		case '1':
   			printf("请输入堆的大小:\n");
   			scanf("%d",&n);
   			getchar();
   			H=InitailizeHeap(n);
   			printf("堆已经创建完成！\n");
   			break;
   		case '2':
   		
   			if(H!=NULL)
   				{
   		    printf("请输入要添加的数字：\n");
   			scanf("%d",&ELement);
   			getchar();
   			Insert(ELement,H);
   			printf("已添加！\n");
			   }
   			
   			else
   			printf("还没有建堆！\n");
   		
   			break;
   		case '3':
            	if(H==NULL)
   			printf("还没有建堆！\n");
   			else{
   			ELement=Delete(H);
   			printf("已删除最小元素：%d\n",ELement);
   		     }
   			break;
   		case '4':
   			if(H==NULL)
   			printf("还没有建堆！\n");
   			else{
   				PrintHeap(H);
   			getchar();
			   }

   			break;
   		case '5':
   			if(H==NULL)
   			printf("还没有建堆！\n");
   			else{
		     printf("你要像二叉树中插入多少元素？\n");
		     scanf("%d",&n);
		     getchar();
		     Add(n,H);
		     printf("已完成完全二叉树的创建\n"); 
		 }
		 break;
		 case '6':
		 	if(H==NULL)
		 	printf("还没有建堆！\n");
		 	else
		 	{
			BuildHeap(H);
		 	printf("已完成！\n");
			 }	 
		 	break;
   		default:
   			break;
   			}
	   Sleep(1000);
	   system("cls");
	printf("输入以下序号：\n");
	printf("1.创建一个堆\n");
	printf("2.向堆内添加元素\n");
	printf("3.删除堆顶元素\n"); 
	printf("4.打印堆\n");
	printf("5.构建无序完全二叉树\n");
	printf("6.构建堆\n");
   }
   return 0;
}
