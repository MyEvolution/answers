#include<stdio.h>
#define N 0xa0//���ֻ����� 
main()
{
	char c;//����Ϊchar�ͣ���Ϊchar���Դ��������ֽ���1��Ҳ���Ƿ�ΧΪ11111111�������ֻ������ֵ���������ͻ��ɸ��� 
	int num;//������Ϊint�� ������ݺ��ֻ������жϣ�����N 
	int n;
	int i=0;
	scanf("%d",&n);
	getchar();
	while(i<n)
	{
		num=0;
		while((c=getchar())!='\n')
		if(c<0)
		num++;
		printf("%d\n",num/2);//ÿ������ռ�����ֽڣ�����Ҫ����2 
		i++;
		
	}


					
	}
/*#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    int count;
    char c;

    scanf("%d%*c", &n);

    while (n--)
    {
        count = 0;

        while ((c = getchar()) != '\n')
        {
            if (c < 0)
                count++;
        }

        printf("%d\n", count / 2);
    }

    return 0;
}*/
	
