#include "AvlTree.h" 
int main()
{
	int n;
	int i,c;
	AvlTree T=NULL;
	AvlTree R=NULL;
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&c);
		Insert(c,&T);	
		insert(c,&R);
	}
printf("构成的avl树的高度和元素如下：\n");
	PrintTree(T);
	putchar('\n');
	PrintTree(R);
printf("请输入需要删除的元素：\n");
	scanf("%d",&c);
	Delete(c,&T);
	printf("删除后：\n");
	PrintTree(T);
}
