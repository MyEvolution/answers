#include<stdio.h>
int way1(int );
int way2(int );
main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
		printf("%d\n",way2(n));
	
}
int way1(int n)//n=1��Ϊ3�� ������ĩβΪo��1�� 
{             //n=2��������9�֣����ǵ���һ��o�ǣ�Ҫ��һ�֣�8�� ����ĩβΪo��2�� ���ԣ���β��o�ĸ����͵����ϴ����еķ�����ȥ�ϴν�β��o�ķ���
            //ͬʱ����ε��ŷ������ϴε��ŷ���3��ͬʱ��ȥ�ϴν�βΪo���ŷ�,���Ի�����õݹ鼴����� 
	 if(n==1) return 1;//n=3  8*3-2 22  
	 else return way2(n-1)-way1(n-1);
	
}
int way2(int n)
{
	if(n==1) return 3;
	else return way2(n-1)*3-way1(n-1);
}

	
