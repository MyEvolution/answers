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
    printf("1.��ӡ����\n");
	printf("2.�������뷭��\n");
	printf("3.ƴд��ϰ\n");
	printf("4.�鵥��(�ʿ�̫�٣����ܲ鲻��)\n");
	printf("5.��ӻ��߸��ĵ��ʵķ���\n");
	printf("6.ɾ������\n");
	printf("0.�˳�\n");
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
					printf("���Ѿ���ʶ���е��ʣ�\n");
					Sleep(1000);
					break;
				case '3':
					InitailArray(order,H->TableSize);
					Spell(H,order,H->TableSize,H->num);
					printf("���Ѿ���ƴд���еĵ��ʣ�\n");
					Sleep(1000); 
					break;
				case '4':
					  system("cls");
				      scanf("%s",word);
				      getchar();
				      Pos=Find(word,H);
				      if(Pos->Info==Empty)
				      {
				      printf("δ��¼��\n");
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
					printf("�����뵥�ʺͷ��룺\n");
					scanf("%s\n%s",word,translate);
					getchar();
					fp=fopen("wordlist.txt","r");
					ChangeOrInsert(word,translate,fp,H);
	                  printf("�����!\n");
	                  Sleep(1000);
	                  break;
	            case '6':
	            	printf("������Ҫɾ���ĵ���:\n");
	            	scanf("%s",word);
	            	getchar();
	            	fp=fopen("wordlist.txt","r");
	            	DeleteWord(word,H,fp);
	            	printf("��ɾ����\n");
					Sleep(1000);
					break; 
				case '0':
					 return 0;
				default:
					  break;
			}
			system("cls");
	printf("1.��ӡ����\n");
	printf("2.�������뷭��\n");
	printf("3.ƴд��ϰ\n");
	printf("4.�鵥��(�ʿ�̫�٣����ܲ鲻��)\n");
	printf("5.��ӻ��߸��ĵ���\n");
	printf("6.ɾ������\n");
	printf("0.�˳�\n");
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
			printf("|  ���ȣ�%d/%d   ����ʶ��%d  |\n",j,num,UNknow);
			printf("-----------------------------\n");
			printf("%s\n",H->TheList[order[i]]->word);
			printf("����ʶ��?\n1.��ʶ\n2.����ʶ\n");
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

		printf("������Ϥ����ʶ�ĵ��ʣ�\n"); 
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
			printf("|  ���ȣ�%d/%d    ����%d  |\n",j,num,UNknow);
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
				printf("���Ѿ�����%d�����ʵ�ƴд������%d�����ʵ�ƴдδ���գ�\n",j,UNknow); 
			printf("����ƴд��������ĵ��ʣ�\n");
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
