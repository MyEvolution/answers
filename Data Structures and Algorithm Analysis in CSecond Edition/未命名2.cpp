#include"ģ���Ŷ�.h"
/*
����㷨��Ҫ����ģ�������Ŷ���������ͳ�Ƶó���Ա������֮��Ĺ���
����Խ��Ч��Խ�� 
*/ 
int IsFree(int *assistant,int n);
int main()
{

	int k,n;
	int i;
	int num;
	int now;
	Client *C;
	Heap H1,H2;
	int theStart,theEnd;
	theTime *T;
	theTime NextHappen;
	theTime *IsHappening;
	int *assistant;
	printf("������˿���Ŀ�ͽ���Ա����Ŀ��\n");
	scanf("%d %d",&n,&k);
	C=(Client *)malloc(n*sizeof(*C)); 
	assistant=(int *)malloc(sizeof(int)*k);
	T=(theTime *)malloc(sizeof(theTime)*n);
	printf("�����ģ������˿��������ʱ��ʹ���ʱ�����£�\n");
/*	RandCustomer(n,C);*/
for(i=0;i<n;i++)
scanf("%d %d",&C[i].come_time,&C[i].stay_time);
	for(i=0;i<n;i++)
	printf("�˿�%3d:����ʱ�䣺%3d ����ʱ���� %3d\n",i,C[i].come_time,C[i].stay_time);
	for(i=0;i<k;i++)
	assistant[i]=0;//0��ʾ���� 
	H1=InitailizeHeap(10000);
	H2=InitailizeHeap(10000);
	for(i=1;i<=n;i++)
	T[i].time=C[i-1].come_time,T[i].Time_Kind=0,T[i].TheNum=i-1,T[i].assistant=-1;//����ʱ��  Ҳ���ǵȴ���ʱ�̣�0��ʾ����,�Լ��ĸ��˿� 
	DisorderInsert(n,T,H1);
	BuildHeap(H1);
	theStart=H1->List[1].time;
	now=theStart;
	while(H1->num!=0||H2->num!=0)
	{

      if(((H1->num!=0&&H2->num==0)||(H1->num!=0&&H1->List[1].time<=H2->List[1].time))&&(num=IsFree(assistant,k))!=-1)//����¼��ǹ˿͵�������н���Ա���� 
      {                               /*�����Ƿ���Ҫ���ںţ�
	                                ������� Ҳ���� ��һ���˵����ͬʱ��һ�����뿪
									������Ӧ���������뿪
									���a������ û�п� ����b��ʱ�뿪�����Ƶ���һ��
									���a������ ���пգ�����b��ʱ�뿪����a���ھͿ��Խ���
									���Լ��ϵ�����û�д����
									������ӵ��� a�������пգ�b�뿪������ʱ���п�  a������ռ��һ���� ����������ѡ��
									����ʵ�������޹ؽ�Ҫ�� 
							*/ 
		if(now<=H1->List[1].time)
      	now=H1->List[1].time;
      	
		  Delete(H1);
      	NextHappen.TheNum=Re.TheNum;
      	NextHappen.time=C[Re.TheNum].stay_time+now;
      	NextHappen.Time_Kind=1;
      	NextHappen.assistant=num;
      	Insert(NextHappen,H2);
      	assistant[num]=1;
      	C[Re.TheNum].assistant=num;
      	C[Re.TheNum].Deal_Time=now;

	  }
	  else
	  {
	  	if(now<=H2->List[1].time)
      	now=H2->List[1].time;
	  	Delete(H2);
	  	assistant[num=Re.assistant]=0;
	  	printf("%d ",num);
	  	if(H1->num!=0&&H1->List[1].time<=Re.time)
	  	{
	  			  	Delete(H1);
	  			  	Re.assistant=num;
	  			  	Re.time=now+C[Re.TheNum].stay_time;
					Re.Time_Kind=1;
					Insert(Re,H2);
					      	C[Re.TheNum].assistant=num;
      	                C[Re.TheNum].Deal_Time=now;
      	                assistant[num]=1;
		  }

		   
	  } /*if(((H1->num!=0&&H2->num==0)||H1->List[1].time>=H2->List[1].time)&&IsFree(assistant,n)==-1)*/
/*�������¼����ǹ˿͵�������뿪 ���¼�뿪ʱ�䣬���ѵ�Ա�ͷţ���ʱ����������һ�¼��ǵ��� ���е�Ա����
  ����ǵ���  ����ȴû�н���Ա ���¼�����뿪��ʱ�� ����������ʱ��Ϊ�뿪ʱ��  �ͷŵ�Ա���������ȵ�����˲���
  */ 

/*
���������������  ��������ѭ��
ԭ�����ǵ���˭��ǰ��˭�ʹ��� ȴ������ ��ʱ������ü�������ǰ�棬����Ա��Ա��ͬʱ�뿪��ȴ����һ�������Ҫ����
����Ӧ�ô�����ǵ��� ����ʵ������ֻ����ĳ������ȥ�������Խ���������ѭ��
�����뵽�Ľ���취�����û�н���Ա  ��ѵ����ʱ���Ϊ�����뿪��ʱ�� 
������������һ������ �������һ���ĵ�����������뿪֮ǰ����ô���ܵ������ǵ����ȼ�����ͬ�� ������ʵ�����������ȼ�Ӧ����
������ͬ��
��һ������취����������
һ����ʾ���� ��һ����ʾ�뿪 
*/ 
	 /* else 
	    if(H->List[1].Time_Kind==1)//�¼��ǹ˿���ȥ 
	    {
	       IsHappening=Delete(H);
	       assistant[IsHappening->assistant]=0;//��ʾ��Ա���� 
		}*/
	}
	theEnd=now;
	
	for(i=0;i<n;i++)
	printf("�˿�%3d����ʱ�䣺%3d  ��ʼ����ʱ��: %3d �뿪ʱ�䣺%3d ����Ա����%3d��\n",i,C[i].come_time,C[i].Deal_Time,C[i].stay_time+C[i].Deal_Time,C[i].assistant);
	printf("%d %d ����ʱ����%d\n",theStart,theEnd,theEnd-theStart);
	return 0;
}
int IsFree(int *assistant,int n)
{
	int i;
	for(i=0;i<n;i++)
	if(!assistant[i])
	return i;
	return -1;
}
/*
//����������Ƿ���� 
int main()
{
	int i,n;
	Client C[10];
	RandCustomer(10,C);
	for(i=0;i<10;i++)
	printf("%d %d\n",C[i].come_time,C[i].stay_time);
	return 0;
 } */

/*int main()
{
//���Ѳ����Ƿ���õ�һЩ���� 
	int i;
	Heap H;
	theTime time[11]; 
	theTime T,*t;
	H=InitailizeHeap(20);
	for(i=1;i<=10;i++)
	scanf("%d %d",&time[i].time,&time[i].Time_Kind);
	DisorderInsert(10,time,H);
	PrintHeap(H);
	BuildHeap(H);
	PrintHeap(H);
	T.time=11;
	T.Time_Kind=1;
	Insert(T,H);
	PrintHeap(H);
	t=Delete(H);
	PrintHeap(H);
	printf("%d %d",t->time,t->Time_Kind);
	
	return 0;
 } */
