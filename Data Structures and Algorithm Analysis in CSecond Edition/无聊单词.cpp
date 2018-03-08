#include"WordHash.h"
#include"windows.h"
#include<time.h>


int unknown[1000];
int UNknow=0;
int RandInt(int num);
void InitailArray(int *order,int n);
void RandArray(int *order,int n);
void LookToThink(HashTable H,int *order,int n,int num);
void Spell(HashTable H,int *order,int n,int num);
void copy(int *order);
void swap(int *a,int *b);
void ChangeOrInsert(char *,char *,FILE *fp,HashTable H); 
void DeleteWord(char *,HashTable H,FILE *fp);
int main()
{
	FILE *fp;
	Position Pos;
	int i=0;
	char c;
	char word[20];
	char translate[50];
	HashTable H;
	int *order;
	H=InitailizeTable(100);
	char Word[20];
	char Translate[50];
   fp=fopen("wordlist.txt","r");
	if(fp==NULL)
	printf("can not open the file!\n");
    else
     while(fgets(Word,20,fp))
	{
	
		Word[strlen(Word)-1]='\0';
		fgets(Translate,50,fp);
		Translate[strlen(Translate)-1]='\0';
		H=Insert(Word,Translate,H);
	}
	order=(int *)malloc(sizeof(int)*H->TableSize);
	fclose(fp);
    printf("1.打印单词\n");
	printf("2.看单词想翻译\n");
	printf("3.拼写练习\n");
	printf("4.查单词(词库太少，可能查不到)\n");
	printf("5.添加或者更改单词的翻译\n");
	printf("6.删除单词\n");
	printf("0.退出\n");
	while(c=getchar())
	{
		getchar();
		switch (c)
			{
				case '1':
					PrintTable(H);
					getchar(); 
					break;
				case '2':
					InitailArray(order,H->TableSize);
					LookToThink(H,order,H->TableSize,H->num);
					printf("你已经认识所有单词！\n");
					Sleep(1000);
					break;
				case '3':
					InitailArray(order,H->TableSize);
					Spell(H,order,H->TableSize,H->num);
					printf("你已经会拼写所有的单词！\n");
					Sleep(1000); 
					break;
				case '4':
					  system("cls");
				      scanf("%s",word);
				      getchar();
				      Pos=Find(word,H);
				      if(Pos->Info==Empty)
				      {
				      printf("未收录！\n");
				      getchar();
					  }
				      else
				      {
				      system("cls");
				      printf("%s\n%s\n",Pos->word,Pos->translate);
					  getchar();
			      	
					  }

				      break;
				case '5':
					printf("请输入单词和翻译：\n");
					scanf("%s\n%s",word,translate);
					getchar();
					fp=fopen("wordlist.txt","r");
					ChangeOrInsert(word,translate,fp,H);
	                  printf("已添加!\n");
	                  Sleep(1000);
	                  break;
	            case '6':
	            	printf("请输入要删除的单词:\n");
	            	scanf("%s",word);
	            	getchar();
	            	fp=fopen("wordlist.txt","r");
	            	DeleteWord(word,H,fp);
	            	printf("已删除！\n");
					Sleep(1000);
					break; 
				case '0':
					 return 0;
				default:
					  break;
			}
			system("cls");
	printf("1.打印单词\n");
	printf("2.看单词想翻译\n");
	printf("3.拼写练习\n");
	printf("4.查单词(词库太少，可能查不到)\n");
	printf("5.添加或者更改单词\n");
	printf("6.删除单词\n");
	printf("0.退出\n");
	}
	return 0;
	
}
int RandInt(int num)
{
	srand((unsigned)time(NULL));
	return rand()%num;
 }
void RandArray(int *order,int n)
{
	int i;
	for(i=1;i<n;i++)
	swap(&order[i],&order[RandInt(i)]);
}
void InitailArray(int *order,int n)
{
	int i;
	for(i=0;i<n;i++)
	order[i]=i;
}
void LookToThink(HashTable H,int *order,int n,int num)
{
	int i;
	char c;
	int j;
	j=0;
	UNknow=0;
    RandArray(order,n);
	 system("cls");
	for(i=0;i<n;i++)
	if(H->TheList[order[i]]->Info==Legitimate)
		{
			 printf("-----------------------------\n");
			printf("|  进度：%d/%d   不认识：%d  |\n",j,num,UNknow);
			printf("-----------------------------\n");
			printf("%s\n",H->TheList[order[i]]->word);
			printf("你认识吗?\n1.认识\n2.不认识\n");
			c=getchar();
			getchar();
			if(c=='1')
			     j++;
			    else
			unknown[UNknow++]=order[i];
			system("cls");
			printf("%s\n%s\n",H->TheList[order[i]]->word,H->TheList[order[i]]->translate);
		   getchar();
		   		system("cls");
		}
	if(UNknow!=0){

		printf("继续熟悉不认识的单词！\n"); 
		Sleep(1000);
	copy(order);
		n=UNknow;
	LookToThink(H,order,n,n);
	}	
}
void Spell(HashTable H,int *order,int n,int num){
	int i;
	char word[20];
	UNknow=0;
	RandArray(order,n);
	int j=0;
	system("cls");
	  for(i=0;i<n;i++)
		if(H->TheList[order[i]]->Info==Legitimate)
		{   
		    printf("-----------------------------\n");
			printf("|  进度：%d/%d    错误：%d  |\n",j,num,UNknow);
			printf("-----------------------------\n");
			printf("%s\n",H->TheList[order[i]]->translate);
			scanf("%s",word);
			getchar();
			if(strcmp(word,H->TheList[order[i]]->word)==0)
			   {
			   	printf("Right!\n");
			   	j++;
			   	Sleep(1000);
				  }   
			 else
			 {
			 	printf("Wrong!\n");
				 unknown[UNknow++]=order[i];
			printf("%s\n%s\n",H->TheList[order[i]]->word,H->TheList[order[i]]->translate);
	              getchar(); 
			 }
		
			 system("cls");   
		}
	
		if(UNknow!=0){
				printf("你已经掌握%d个单词的拼写！还有%d个单词的拼写未掌握！\n",j,UNknow); 
			printf("继续拼写曾经出错的单词！\n");
			Sleep(1000);
	copy(order);
		n=UNknow;
	Spell(H,order,n,n);
	}	
}
void copy(int *order)
{
	int i;
	for(i=0;i<UNknow;i++)
	order[i]=unknown[i];
}
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void ChangeOrInsert(char *word,char *translate,FILE *fp,HashTable H)
{
	int i;
	FILE *fp2;
	fp2=fopen("haha.txt","w+");
	int find=0;
	char copy1[100],copy2[100];
	char *Point;
      Insert(word,translate,H);
	sprintf(copy2,"%s\n",word);
    	while(fgets(copy1,50,fp))
           {
           	fputs(copy1,fp2);
			   if(!strcmp(copy1,copy2))
			   {
			   	fgets(copy1,50,fp);
			   	fprintf(fp2,"%s\n",translate);
			   	find=1;
			   }
		   }
		if(find==0)
		{
				fputs(copy2,fp2);
		fprintf(fp2,"%s\n",translate);	
		}
      fclose(fp);
      fclose(fp2);
      	 system("del wordlist.txt /q");
  system("ren haha.txt wordlist.txt");		 
 }
 void DeleteWord(char *word,HashTable H,FILE *fp)
 {
 	FILE *fp2;

 	char copy1[50],copy2[50];
 	sprintf(copy2,"%s\n",word);
 	if(Delete(word,H))
 	{
	  	fp2=fopen("haha.txt","w+");
 		 	while(fgets(copy1,50,fp))
 	            if(strcmp(copy1,copy2))
 	         fputs(copy1,fp2);
 	            else
			    fgets(copy1,50,fp);	  
		fclose(fp);  
		fclose(fp2);
	system("del wordlist.txt /q");
  system("ren haha.txt wordlist.txt");
    }
 	    
 }
