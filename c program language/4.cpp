#include<stdio.h>
int _eat(int);
/*main()
{      
    int i;
	int x=1;//ÌÒ×ÓÊı
	for(i=10;i>1;i--)
	 x=_eat(x);
	 printf("%d",x);
}
int _eat(int m)
{
	return (m+1)*2;
}

int fun(int);*/
main()
{
	printf("%d",_eat(1));

}
int _eat(int _day)
{
	if(_day==10)
	return 1;
	else return (_eat(_day+1)+1)*2;
 } 
