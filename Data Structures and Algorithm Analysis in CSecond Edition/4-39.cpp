#include"ChildAndSib.h"

int main()
{
	Tree T=NULL;
	Queue Q;
	Tree B,C,G,D,E,F,L,M;
	Q=CreateQueue();
	T=Insert('A',T);
	T=Insert('B',T);
	T=Insert('C',T);
	T=Insert('G',T);
	B=T->FirstChild;
	B=Insert('D',B);
	B=Insert('E',B);
	D=B->FirstChild;
	D=Insert('H',D);
	D=Insert('I',D);
	E=D->NextSibling;
	E=Insert('J',E);
	C=B->NextSibling;
	C=Insert('F',C);
	F=C->FirstChild;
	F=Insert('K',F);
	F=Insert('L',F);
	F=Insert('M',F);
	L=F->FirstChild->NextSibling;
	L=Insert('O',L);
	M=L->NextSibling;
	M=Insert('P',M);
	M=Insert('Q',M);
	M=Insert('R',M);
	G=C->NextSibling;
	G=Insert('N',G); 
	PrintTree(T,Q);
	return 0;
}
