#include<stdio.h>
#include<windows.h>
#define NALLOC 1024 
typedef double Align;//����double���͵ı߽����
union header{/*���ͷ��*/ 
	struct {
		union header *ptr;
		unsigned size;
	}s;
	Align x;//ǿ�ƿ�Ķ��� 
}; 
void free(void *);
typedef union header Header;
static Header base;//�ӿ�����ʼ
static Header *freep=NULL;//��������ĳ�ʼָ��
void *malloc(unsigned nbytes)
{
	Header *p,*prevp;//pָ��ͷ������¼freep��λ�ã�������ú�ŵ���β��freep��¼��һ���ҵ�����λ�õĵط� 
	Header *morecore(unsigned);
	unsigned nunits;
	nunits =(nbytes+sizeof(Header)-1)/sizeof(Header)+1;
	//Ϊ����ͷ������������������ͷ�������볤�ȣ�Ҳ�������headerΪ8����Ҫ����Ϊ4�������8����ѧ���⣬����Ļ�
	//���˻�Ϊ0������Ҫ����һ��header�Ĵ�С�����Ǹպù��ͻ����䣬����Ҫ��1 
	if((prevp=freep)==NULL)//û�п������� 
	{
		base.s.ptr=freep=prevp=&base;
		base.s.size=0;
	}
	for(p=prevp->s.ptr;;prevp=p,p=p->s.ptr)//�տ�ʼ���prevp��ָ��Ҳ��ָ���Լ������ 
	{
		if(p->s.size>=nunits){
		
		if(p->s.size==nunits)
		prevp->s.ptr=p->s.ptr;
		else 
		{
			p->s.size-=nunits;
			p+=p->s.size;
			p->s.size=nunits;
		}
		freep=prevp;
		return (void*)(p+1);
		}
		if(p==freep)//�ջ��Ŀ�������
		 if((p=morecore(nunits))==NULL)
		 return NULL;//û��ʣ��Ĵ���ռ� 
	}
 } 
 static Header *morecore(unsigned nu)
 {
 	char *cp;
 	Header *up;
 	if(nu<NALLOC)
 	nu=NALLOC;
 	cp=HeapAlloc(nu*sizeof(Header));
 	if(cp==(char *)-1)/*û�пռ�*/
	 return NULL;
	 up=(Header *)cp;
	 up->s.size=nu;
	 free((void*)(up+1));
	 return freep; 
 }
 void free(void *ap)
 {
 	Header *bp,*p;
 	for(p=freep;!(bp>p&&bp<p->s.ptr);p=p->s.ptr)
 	if(p>=p->s.ptr&&(bp>p)||(bp<p->s.ptr))
 	  break;/*���ͷŵĿ�������Ŀ�ͷ���߽�β*/
	   if(bp+bp->s.size==p->s.ptr)
	   {
	   	bp->s.size+=p->s.ptr->s.size;
	   	bp->s.ptr=p->s.ptr->s.ptr;
		} else 
		bp->s.ptr=p->s.ptr;
		if(p+p->s.size==bp)
		{
			p->s.size+=bp->s.size;
			p->s.ptr=bp->s.ptr;
		}else
		  p->s.ptr=bp;
		  freep=p;
 }
 main()
 {
 	char *q;
 	q=(char *)malloc(100);

 	scanf("%s",q);
 	printf("%s",q);
 }
