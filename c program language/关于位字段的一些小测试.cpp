#include<stdio.h>
struct Bit{//位字段
 unsigned b1:1;//除了char 是1，其他分配皆大于等于2，int为4，short为2，位字段也为4（不确定，不会小于4）；所有指针皆为8 
   unsigned b2:1;//给分配的是 为各个分配的之和（因为对齐为变量分配的为各个变量中的最大） 
  unsigned b3:1;//包括指针,给a分配8，如果b+c<8，那么总的为16 (个体变量总的分配为最大的倍数（不考虑数组）) 
  unsigned b4:2;
  unsigned :0;                //空过去了 101101 
  unsigned b5:2;

/*char *p;
int m;
short q;
char n;*/
}B;
int p(int p); 
main(){
	struct Bit *c=&B;
	float m=sizeof(B);//(B值逆序取，取最后位的非空位置那一串为值);例如b1,b2,b3,b4,则为b4b3b2b1,若b1前为空，则值不变， 若b1 后为空则值为b1; 

	B.b1=1;//没有赋值则默认为零 
    B.b2=1;
     B.b3=1;
	 /*注意:
（1）一个位段必须存储在同一存储单元（即字）之中，不能跨两个单元。如果其单元空间不够，则剩余空间不用，从下一个单元起存放该位段。
（2）可以通过定义长度为0的位段的方式使下一位段从下一存储单元开始。
（3）可以定义无名位段。
（4）位段的长度不能大于存储单元的长度。
（5）位段无地址，不能对位段进行取地址运算。
（6）位段可以以%d，%o，%x格式输出。
（7）位段若出现在表达式中，将被系统自动转换成整数。*/
    
     B.b4=2;
    // B.b5=2;
  int a=0123;//8进制表示法
  int d=0X123; //16进制表示法256 + 32 + 3 
  int b=123;
    printf("%d %d %d ",a,b,d);
//45(101101)=b5b4b3b2b1; 
	printf(" %g ",m);
printf("%d",B.b4);

} 
int p(int p)
{
	return p;
}
/*若不用位字段；
则
#define KEYWORD 01;001
#define EXTERNAL 02;010
#define STATIC 04;100(定义的屏蔽码必须为2的幂）
flag|=EXTERNAL|STATIC(010|100=110 ,按位或后其他位不变，KEYWORD,EXTERNAL置为1）
flag&=~(EXTERNAL|STATIC)(11111001,按位与后其他位不变，KEYWORD,EXTERNAL置为0）
若这两位为0；flag&(EXTERNAL|STATIC)==0为真； */
