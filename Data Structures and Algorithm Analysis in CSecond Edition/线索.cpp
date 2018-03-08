#include"线索二叉树.h" 

int main()
{
	TBTree T=NULL;
	Tree t=NULL;
	int n,i,c;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&c);
		t=Insert(c,t);
		T=TInsert(c,T);
	}
	printf("没有线索化的树中序输出为：\n");
	PrintTree(t);
	printf("线索树中序输出（带线索）:\n");
	PrintTBree(T);
	MakeItToThreaded(t,t,t);//线索化 
	printf("线索化后的树的中序输出为：\n"); 
	PrintTBree(t);
	printf("请输入需要删除的元素：\n");
	scanf("%d",&c);
	
	
    printf("删除后的线索树为：\n") ;
    T=TDelete(c,T);
	PrintTBree(T); 
	printf("删除后的线索化的树为:\n");
	t=TDelete(c,t);
	PrintTBree(t);
	inOrderTravel(T); 
	return 0;
	
}
