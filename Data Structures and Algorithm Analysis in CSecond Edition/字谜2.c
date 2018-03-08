#include"HashTable.h"

#define MinLen 2
#define MaxLen 8

int min(int a,int b,int c);
void RightBias(const char **wordlist,int num,char *string,int x,int y);
void LeftBias(const char **wordlist,int num,char *string,int x,int y);
void Line(const char **wordlist,int num,char *string,int th,int x,int y);
void Vert(const char **wordlist,int num,char *string,int th,int x,int y);
void PrintWord(char *word,HashTable H);
void reverse(char *s);

int main()
{
	char Words[9];
	char *WordList[100];
	HashTable H;
	int maxlen;
	int th,n;
	H=InitailizeTable(20);
	char c;
	int num,i,j;
	int line,vert;//行和列 
	printf("请输入单词表内单词个数:\n");
	scanf("%d",&n);
	printf("请依次输入各个单词：\n");
	for(i=0;i<n;i++)//把各单词输入进去了 
	{
	 scanf("%s",Words);
	 Insert(Words,H);
	}
	char word[9];
	printf("请输入字母表的行数和列数：\n");
	scanf("%d %d",&line,&vert); 
		getchar(); 
   for(i=0;i<line;i++)
   WordList[i]=(char *)malloc(sizeof(vert));
	printf("请依次输入各个字母：\n");
	for(i=0;i<line;i++)
	  for(j=0;j<vert;j++)
	   {
	   	  c=getchar();
	   	  WordList[i][j]=c;
	   	  getchar();
	  }
    maxlen=min(line,vert,MaxLen);
   
   for(num=2;num<=maxlen;num++)
   {
   	for(i=0;i<=line-num;i++)
   	  for(j=0;j<=vert-num;j++)
   	  {
   	  	 for(th=0;th<num;th++)
   	  	   	{
		Line(WordList,num,word,th,i,j);
		PrintWord(word,H);
		Vert(WordList,num,word,th,i,j);
		PrintWord(word,H); 
     	}
		RightBias(WordList,num,word,i,j);
		PrintWord(word,H);		
		LeftBias(WordList,num,word,i,j);
		PrintWord(word,H);
		 }
   }
   if(maxlen<MaxLen&&maxlen<line)
   {
      maxlen=line<MaxLen?line:MaxLen;
        for(num=vert+1;num<=maxlen;num++)
   	  for(i=0;i<=line-num;i++)
   	  for(th=0;th<vert;th++)
   	  {
   	  	    Vert(WordList,num,word,th,i,0);
            PrintWord(word,H);
		 }
   }
   else if(maxlen<MaxLen&&maxlen<vert)
   {
   	maxlen=vert<MaxLen?vert:MaxLen;
   	  for(num=line+1;num<=maxlen;num++)
   	  for(j=0;j<=vert-num;j++)
   	  for(th=0;th<line;th++)
   	  {
   	  	    Line(WordList,num,word,th,0,j);
            PrintWord(word,H);
		 }
   }
   return 0;
}
int min(int a,int b,int c)
{
	return (a<=b&&a<=c)?a:(b<=c?b:c); 
}
void RightBias(const char **wordlist,int num,char *string,int x,int y)
{
	int i;
	for(i=0;i<num;i++)
	*string++=wordlist[x+i][y+i];
	*string='\0';
}
void LeftBias(const char **wordlist,int num,char *string,int x,int y)
{
	int i;
	for(i=0;i<num;i++)
	*string++=wordlist[x+i][y+num-1-i];
	*string='\0';
}
void Line(const char **wordlist,int num,char *string,int th,int x,int y)
{
  int i; 
  for(i=0;i<num;i++)   
  *string++=wordlist[x+th][y+i];
  *string='\0';
 }
void Vert(const char **wordlist,int num,char *string,int th,int x,int y)
{
	int i;
	for(i=0;i<num;i++)
	*string++=wordlist[x+i][y+th];
	*string='\0';
}
void PrintWord(char *word,HashTable H)
{
	   	if(Find(word,H))
   	  	printf("%s\n",word);
   	  	reverse(word);
   	  	if(Find(word,H))
   	  	printf("%s\n",word);
   	  	
}
void reverse(char *s)
{
	char *q=s;
	char temp;
	while(*(q+1)!='\0')
	q++;
	while(q>=s)
	{
	temp=*q;
	*q=*s;
	*s=temp;
	q--,s++;	
	}
}
