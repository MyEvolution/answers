#include<stdio.h>
#include<time.h>
#include<stdlib.h>//exit()��return������ 
/*int returnexit(int);//1.�ݹ�����У�returnֻ���ص���һ������exit�������� 
main()             //2.������������������������е�exitҲ��������� 
{
	int i;
	scanf("%d",&i);
	returnexit(i);
	printf("%d",100);
}
int returnexit(int i)
{
	if(i>4)
	returnexit(i-1);
	printf("%d\n",i);
	return 1;
}*/
#define frand() ((double)rand()/(RAND_MAX+1))//����0-1֮������С�� 
main()
{   
srand(time(NULL));//srand����һ�����ӣ� �������κ�ֵ 
	int i;
	for(i=0;i<10;i++)
	printf("%f ",frand());
	
}
