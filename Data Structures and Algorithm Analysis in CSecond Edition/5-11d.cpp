#include<stdio.h>
#include<string.h>
#include<math.h>
typedef unsigned int Index;

Index Hash(const char *key)//���ù�ϣ�� ,�õĻ�װ�����Ӿ����ӽ�1�������Ӧ�úܴ� 
{
	Index HashVal=0;
	while(*key!='\0')
	HashVal=HashVal<<2+*key++;
	return HashVal; 
}
/*void Strncpy(char *copy,const char *current,int len)//Ϊʲô���Լ���strncpy������  ��Ϊ�ƺ�ϵͳ�ĺ���������ӽ����� 
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
	pos=-1;//��ʾû�в��ҵ� 
	Index In1,In2;
	printf("�����볤�ַ�����\n");
	scanf("%s",a);
	printf("��������Ҫ���ҵ��ַ���:\n");
	scanf("%s",b);
	len=strlen(b);
	In1=Hash(b);
	current=a;
	strncpy(copy,current,len);
	In2=Hash(copy);
	while(strlen(copy)==len&&(In2!=In1||strcmp(copy,b)!=0))//ȷ��������ȣ������ʾɨ��������Ѿ� 
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
