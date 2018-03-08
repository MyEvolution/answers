#include"BinTree.h"

int main()
{
	BinTree T1,T2;
	BinTree B1,B2,C1,C2,E1,E2,G1,G2; 
	T1=T2=NULL;
	T1=Insert('A',T1,0);
	T1=Insert('B',T1,LEFT);
	T1=Insert('C',T1,RIGHT);
	B1=T1->Left;
	C1=T1->Right;
	B1=Insert('D',B1,LEFT);	
	B1=Insert('E',B1,RIGHT);
	E1=B1->Right;
	E1=Insert('F',E1,LEFT);
	C1=Insert('G',C1,LEFT);
	G1=C1->Left;
	G1=Insert('H',G1,LEFT); 

	T2=Insert('A',T2,0);
	T2=Insert('C',T2,LEFT);
	T2=Insert('B',T2,RIGHT);
	C2=T2->Left;
	C2=Insert('G',C2,LEFT);
	G2=C2->Left;
	G2=Insert('H',G2,RIGHT);
	B2=T2->Right;
	B2=Insert('E',B2,LEFT);
	B2=Insert('D',B2,RIGHT);
	E2=B2->Left;
	E2=Insert('F',E2,LEFT);
	
	PrintTree(T1);
	putchar('\n');
	PrintTree(T2);
	putchar('\n');
	
	printf(Isomorphic(T1,T2)?"Yes":"No");
	
 } 
