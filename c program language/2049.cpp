/*#include<stdio.h>
int posb(int x);
 int l(int x);
main()
{
	int n;
	int x;
	int i;
	scanf("%d",&n);
	double b;
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(x==1) printf("%.2f%%\n",0);
		else printf("%.2f%%\n",(double)l(x)/(double)posb(x)*100);
	}
 } 
 int posb(int x)
 {
 	int n=x;
 	int sum=1;
  for(x;x>1;x--)
  sum*=x;
  return sum;
//ǰn-1���õĶ������Լ���Ʊ   
//��n�����Լ���Ʊȥ����������һ���˽������������е����õĶ������Լ���Ʊf[n-1]�ֻ��� 
// ǰn-1����n-2ren�õĲ����Լ���Ʊ������n��n-1�����������Լ���f[n-2]
//���õĲ����Լ���Ʊ����n-1��n-2�õ��ǣ���ô�����������ཻ�����1�ظ�
// 

	 
 }
 int l(int x)
 {
 	if(x==1) return 0;
 	if(x==2) return 1;
 	if(x==3) return 2;
 	else return (l(x-1)+l(x-2))*(x-1);
 }*/
 #include <math.h>
#include <stdio.h>

int main(void)
{
    int i, n;
    __int64 d[21][2] = {{1,0},{1,0},{2,1},{6,2}};

    for (i = 4; i < 21; i++)
    {
        d[i][0] = i * d[i-1][0];
        d[i][1] = (i - 1) * (d[i-1][1] + d[i-2][1]);
    }
    scanf("%d", &n);
    while (n-- && scanf("%d", &i))
        printf("%.2f%%\n", d[i][1]*100.0/d[i][0]);

    return 0;
}
			
	
