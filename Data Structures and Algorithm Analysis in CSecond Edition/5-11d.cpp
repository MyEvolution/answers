#include<stdio.h>
#include<string.h>
#include<math.h>
typedef unsigned int Index;

Index Hash(const char *key)//不用哈希表 ,用的话装填因子尽量接近1，这个表应该很大 
{
	Index HashVal=0;
	while(*key!='\0')
	HashVal=HashVal<<2+*key++;
	return HashVal; 
}
/*void Strncpy(char *copy,const char *current,int len)//为什么用自己的strncpy函数呢  因为似乎系统的函数不会添加结束符 
{
	char *start=copy;
	while(*current!='\0'&&copy-start<len)
	*copy++=*current++;
	*copy='\0';
}*/
int main()
{
	char a[1000];
	char b[100];
	char copy[100];
	char *current,*m;
	int len,pos;
	pos=-1;//表示没有查找到 
	Index In1,In2;
	printf("请输入长字符串：\n");
	scanf("%s",a);
	printf("请输入需要查找的字符串:\n");
	scanf("%s",b);
	len=strlen(b);
	In1=Hash(b);
	current=a;
	strncpy(copy,current,len);
	In2=Hash(copy);
	while(strlen(copy)==len&&(In2!=In1||strcmp(copy,b)!=0))//确保长度相等，否则表示扫描结束了已经 
	{
		m=current;
		current++;
		strncpy(copy,current,len);
		In2=Hash(copy);
	}
    if(strlen(copy)==len)
	pos=current-a+1;
	printf("%d\n",pos);
	return 0;
}
