#include"����������.h" 

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
	printf("û�������������������Ϊ��\n");
	PrintTree(t);
	printf("�����������������������:\n");
	PrintTBree(T);
	MakeItToThreaded(t,t,t);//������ 
	printf("��������������������Ϊ��\n"); 
	PrintTBree(t);
	printf("��������Ҫɾ����Ԫ�أ�\n");
	scanf("%d",&c);
	
	
    printf("ɾ�����������Ϊ��\n") ;
    T=TDelete(c,T);
	PrintTBree(T); 
	printf("ɾ���������������Ϊ:\n");
	t=TDelete(c,t);
	PrintTBree(t);
	inOrderTravel(T); 
	return 0;
	
}
