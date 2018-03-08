#include"5-13BHash.h"

#define MaxLen 11

void GetWord(char **Letter,int x,int y,int Direct,char *word,int num,int Line,int Vert);
void reverse(char *s);
int main()
{
		  
	char c;
	int n;
	int i,j;
	int num;
	int Line,Vert;
	HashTable H;
	H=InitailizeTable(50);
	char word[12];
	char *Letter[100];//字母表 
	printf("请输入单词表中单词的个数：\n");
	scanf("%d",&n);
	printf("请依次输入各个单词：\n");
	int Direct;
	for(i=0;i<n;i++)
	{
		scanf("%s",word);
		Insert(word,H);
	}
	printf("请输入字母表的行数列数：\n");
	scanf("%d %d",&Line,&Vert);
	getchar();
	printf("请按矩阵形式输入各个字母：\n");
	for(i=0;i<Line;i++)
  {
	Letter[i]=(char *)malloc(sizeof(Vert+1)); 
	for(j=0;j<Vert;j++)
	{
		c=getchar();
		Letter[i][j]=c;
		getchar();
	}
	Letter[i][j]='\0';
  } 
  Index pre;
  printf("字母表中找到的单词有：\n"); 
  for(i=0;i<Line;i++)
    for(j=0;j<Vert;j++)
    {
    	for(Direct=0;Direct<8;Direct++)
    	{
    	   	GetWord(Letter,i,j,Direct,word,PREFIX,Line,Vert);//得到前缀 
    
    	   	if(H->TheCells[FindPre(word,H,&pre)].kind==Empty)//没有找到前缀 
    	   	        ;
    	   	else
    	   	{
    	   		 for(num=2;num<=MaxLen;num++)
    	       {
    	   		GetWord(Letter,i,j,Direct,word,num,Line,Vert);  
	
				if(H->TheCells[Find(word,H,pre)].kind==Word)
				         printf("%s\n",word);    	     
			   }
		   }
		}
	}
   return 0;	
}
void GetWord(char **Letter,int x,int y,int Direct,char *Pre,int num,int Line,int Vert)
{
		
	int i;
	if(Direct==0)
	{
		if(Vert-y>=num)
		for(i=0;i<num;i++)
		    *Pre++=Letter[x][y+i];
	}
	else if(Direct==1)
	{
		if(Line-x>=num)
		for(i=0;i<num;i++)
		    *Pre++=Letter[x+i][y];
	}
	else if(Direct==2)
	{
		if(Vert-y>=num&&Line-x>=num)
		for(i=0;i<num;i++)
		  *Pre++=Letter[x+i][y+i];
	}
	else if(Direct==3)
	{
	   if(y+1>=num&&Line-x>=num)
	   for(i=0;i<num;i++)
	     *Pre++=Letter[x+i][y-i];
	}
	else if(Direct==4)
	{
		if(y+1>=num)
		for(i=0;i<num;i++)
		*Pre++=Letter[x][y-i];
	}
	else if(Direct==5)
	{
		if(x+1>=num)
		for(i=0;i<num;i++)
		*Pre++=Letter[x-i][y];
	}
	else if(Direct==6)
	{
		if(Vert-y>=num&&x+1>=num)
		for(i=0;i<num;i++)
		*Pre++=Letter[x-i][y+i];
	}
	else if(Direct==7)
	{
		if(y+1>=num&&x+1>=num)
		for(i=0;i<num;i++)
		*Pre++=Letter[x-i][y-i];
	}
	*Pre='\0';
}

