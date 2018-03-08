#include<stdio.h>
#include<windows.h>
#define NALLOC 1024 
typedef double Align;//按照double类型的边界对其
union header{/*块的头部*/ 
	struct {
		union header *ptr;
		unsigned size;
	}s;
	Align x;//强制块的对齐 
}; 
void free(void *);
typedef union header Header;
static Header base;//从空链表开始
static Header *freep=NULL;//空闲链表的初始指针
void *malloc(unsigned nbytes)
{
	Header *p,*prevp;//p指向头部，记录freep的位置，当分配好后放到结尾，freep记录上一次找到空闲位置的地方 
	Header *morecore(unsigned);
	unsigned nunits;
	nunits =(nbytes+sizeof(Header)-1)/sizeof(Header)+1;
	//为了是头部的整数倍，（对齐头部）舍入长度，也就是如果header为8，需要分配为4，则分配8，数学问题，不足的话
	//除了会为0，所以要加上一个header的大小，但是刚好够就会多分配，所以要减1 
	if((prevp=freep)==NULL)//没有空闲链表 
	{
		base.s.ptr=freep=prevp=&base;
		base.s.size=0;
	}
	for(p=prevp->s.ptr;;prevp=p,p=p->s.ptr)//刚开始这个prevp的指针也是指向自己本身的 
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
		if(p==freep)//闭环的空闲链表
		 if((p=morecore(nunits))==NULL)
		 return NULL;//没有剩余的储存空间 
	}
 } 
 static Header *morecore(unsigned nu)
 {
 	char *cp;
 	Header *up;
 	if(nu<NALLOC)
 	nu=NALLOC;
 	cp=HeapAlloc(nu*sizeof(Header));
 	if(cp==(char *)-1)/*没有空间*/
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
 	  break;/*被释放的块在链表的开头或者结尾*/
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
