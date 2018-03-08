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
	scanf("%d",&c);//%d 时候输入 整型 若为其他字符，则为0； 
	getchar(); 
	switch(c)
	{
		case 1:
			printf("你想在多少秒后关机？\n");
			scanf("%s",t);
			getchar();//吸收换行符 
			system(strcat(cmd,t));
			printf("若要取消关机，请按#号键\n");
			scanf("%c",&c);
			if(c=='#')
			system("shutdown -a");
			
			break;
		case 2:
		printf("请输入关机的时刻(如22:00):\n");
		scanf("%s",t1);
		getchar();
		sprintf(temp,"schtasks /create /tn 定时关机 /tr \"shutdown /s\" /sc once /st %s",t1);
		printf("%s\n",temp);
		system(temp);
		printf("若要取消关机，请按#号键\n");
		scanf("%c",&c);
			if(c=='#')
			system("schtasks /delete /tn 定时关机 /f");
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
		printf("未知指令！\n");
		break; 	
	}
   
      
getchar();	
}
void print(void)
{
printf("          ================c语言关机程序==============\n");
printf("          ||      1.倒计时关机                     ||\n");                 
printf("          ||      2.定时关机                       ||\n");
printf("          ||      3.重新启动                       ||\n");
printf("          ||      4.立刻关机                       ||\n");
printf("          ||      5.注销                           ||\n");
printf("          ||      6.退出程序                       ||\n");
printf("          ===========================================\n"); 
}
