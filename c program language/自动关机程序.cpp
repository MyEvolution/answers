#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
void print(void);
main()
{
 
	print();
	char cmd[MAX]="shutdown -s -t ";
	char t[MAX];
	char t1[MAX];
	char temp[MAX];
	int c;
	scanf("%d",&c);//%d ʱ������ ���� ��Ϊ�����ַ�����Ϊ0�� 
	getchar(); 
	switch(c)
	{
		case 1:
			printf("�����ڶ������ػ���\n");
			scanf("%s",t);
			getchar();//���ջ��з� 
			system(strcat(cmd,t));
			printf("��Ҫȡ���ػ����밴#�ż�\n");
			scanf("%c",&c);
			if(c=='#')
			system("shutdown -a");
			
			break;
		case 2:
		printf("������ػ���ʱ��(��22:00):\n");
		scanf("%s",t1);
		getchar();
		sprintf(temp,"schtasks /create /tn ��ʱ�ػ� /tr \"shutdown /s\" /sc once /st %s",t1);
		printf("%s\n",temp);
		system(temp);
		printf("��Ҫȡ���ػ����밴#�ż�\n");
		scanf("%c",&c);
			if(c=='#')
			system("schtasks /delete /tn ��ʱ�ػ� /f");
		break;	
		case 3:
		  system("shutdown -r") ;
			break;
		case 4:
		 system("shutdown -p");
		 break;
		case 5:
		system("shutdown -l");
		break;
		case 6:exit(0);
		default :
		printf("δָ֪�\n");
		break; 	
	}
   
      
getchar();	
}
void print(void)
{
printf("          ================c���Թػ�����==============\n");
printf("          ||      1.����ʱ�ػ�                     ||\n");                 
printf("          ||      2.��ʱ�ػ�                       ||\n");
printf("          ||      3.��������                       ||\n");
printf("          ||      4.���̹ػ�                       ||\n");
printf("          ||      5.ע��                           ||\n");
printf("          ||      6.�˳�����                       ||\n");
printf("          ===========================================\n"); 
}
