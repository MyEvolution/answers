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
printf("���ɵ�avl���ĸ߶Ⱥ�Ԫ�����£�\n");
	PrintTree(T);
	putchar('\n');
	PrintTree(R);
printf("��������Ҫɾ����Ԫ�أ�\n");
	scanf("%d",&c);
	Delete(c,&T);
	printf("ɾ����\n");
	PrintTree(T);
}
