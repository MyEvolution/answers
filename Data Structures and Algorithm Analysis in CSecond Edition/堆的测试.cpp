#include"Heap.h"
#include<windows.h> 

int main()
{
	printf("����������ţ�\n");
	printf("1.����һ����\n");
	printf("2.��������Ԫ��\n");
	printf("3.ɾ���Ѷ�Ԫ��\n"); 
	printf("4.��ӡ��\n");
	printf("5.����������ȫ������\n");
	printf("6.������\n");
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
   			printf("������ѵĴ�С:\n");
   			scanf("%d",&n);
   			getchar();
   			H=InitailizeHeap(n);
   			printf("���Ѿ�������ɣ�\n");
   			break;
   		case '2':
   		
   			if(H!=NULL)
   				{
   		    printf("������Ҫ��ӵ����֣�\n");
   			scanf("%d",&ELement);
   			getchar();
   			Insert(ELement,H);
   			printf("����ӣ�\n");
			   }
   			
   			else
   			printf("��û�н��ѣ�\n");
   		
   			break;
   		case '3':
            	if(H==NULL)
   			printf("��û�н��ѣ�\n");
   			else{
   			ELement=Delete(H);
   			printf("��ɾ����СԪ�أ�%d\n",ELement);
   		     }
   			break;
   		case '4':
   			if(H==NULL)
   			printf("��û�н��ѣ�\n");
   			else{
   				PrintHeap(H);
   			getchar();
			   }

   			break;
   		case '5':
   			if(H==NULL)
   			printf("��û�н��ѣ�\n");
   			else{
		     printf("��Ҫ��������в������Ԫ�أ�\n");
		     scanf("%d",&n);
		     getchar();
		     Add(n,H);
		     printf("�������ȫ�������Ĵ���\n"); 
		 }
		 break;
		 case '6':
		 	if(H==NULL)
		 	printf("��û�н��ѣ�\n");
		 	else
		 	{
			BuildHeap(H);
		 	printf("����ɣ�\n");
			 }	 
		 	break;
   		default:
   			break;
   			}
	   Sleep(1000);
	   system("cls");
	printf("����������ţ�\n");
	printf("1.����һ����\n");
	printf("2.��������Ԫ��\n");
	printf("3.ɾ���Ѷ�Ԫ��\n"); 
	printf("4.��ӡ��\n");
	printf("5.����������ȫ������\n");
	printf("6.������\n");
   }
   return 0;
}
