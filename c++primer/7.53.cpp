#ifndef DEBUG_H
#define DEBUG_H
#include<string>
#include<iostream>
class Debug
{
	public:
		
		constexpr Debug(bool b = true ):hw(b),io(b),other(b){
		}//�Ѿ��ṩĬ�Ϲ��� 
		constexpr Debug(bool h,bool i,bool o):hw(h),io(i),other(o){
		}
		Debug(bool h,bool i):hw(h),io(i){
		}
	    const/*expr*/ bool any(){
	    	return hw||io||other;
		}//���������const����  ���޷�����m.any()�� 
		void set_io(bool b){
			io = b;
		}
		void set_hw(bool h)
		{
			hw = h;
		}
		void set_other(bool o)
		{
			other = o;
		}
	private:
		bool io;
		bool hw;
		bool other;
	
};
class de//��Ҳ������ֵ���� 
{
	int a;
	//Debug d=Debug(1,0); ������һ��� ��Ϊ�õĲ���constexpr���� ���Ը��಻������ֵ������ 
};
#endif
//constexpr int i = 20;
constexpr int  abc(Debug)//de��Ҫ��������ֵ������ 
{
	return 100;
}
constexpr int abcd(int i)
{
	return 100;
 } 
  Debug n(1,1);
  constexpr Debug m(1);
   int b[abc(m)]; 
 int a[abc(n)];
 int i;
int c[abcd(i)]; 
int main()
{
   const int & a = i;
   constexpr Debug m(1);//�������Ĭ�ϳ�ʼ�����޷�ͨ������
    // ��Ϊconstexpr���캯�����ܹ����constexpr����
    Debug n(1,1);
	
	abc(n); 
	if(m.any())
	//	[Error] passing 'const Debug' as 'this' argument of 'const bool Debug::any()' discards qualifiers [-fpermissive]
	 //��Ϊ�ǳ�������   ��anyδ������const���͵ĺ���  ���Ա�������Ϊthisָ����ܻ�ı䳣�������ֵ �޷�ͨ������
	 //��const�޹� ʵ����ȥ��constҲ��һ����
	 //��constexpr�����ĺ�������ʽconstde  ���Կ���ͨ������ 
	 //ʵ��������   constexpr������Ϊ���޶�  �����޷���������return�Ŀ�ִ�в���  Ҳ���һ������ı�ʲôֵ��
	 //��������ʽconst�ĺ��� 
	std::cerr<<"print appropriate error messages"<<std::endl;
	//if(prod.any())
	//std::cerr<<"print an error message"<<std::endl;
	return 0;
 } 
/*
constexpr�����ڱ���׶α������Ϳ��Լ��������Ƿ��ǳ������ʽ
��ֻ���ڶ�������ֵʱ�õ�
����ǳ�ʼֵ��һ���������ʽ�����ͨ������
������ı�����һ������ 

ͬʱ��constexpr���εĺ�����˼���ڱ���׶ξͿ��Ե�֪�䷵��ֵ�ǲ��ǳ������ʽ
��Ȼ�Ⲣ����ζ��constexpr���ܷ��طǳ������ʽ 
��ʵ����constexpr����������ֵʱ  ��const���εĳ������ʽ��һֱ��Ч��������Ҫconstexpr�ĵط���Ҳ�����ϱ��綨��һ�������ά��
����Ҫʱ������Ҳ����const���ε��Ƿ��ǳ������ʽ�� 
 ������const������Ը��ǳ������ʽ
constexpr���治����  ���ȷ���ǳ������ʽ �����constexpr���� �ٶȸ���
�����κ���ʱ  constexpr�����ڱ���ʱ�ڼ�ⷵ��ֵ�ǲ��ǳ������ʽ  ���Ƿǳ������ʽҲ���ᱨ��
���������const���εĻ� ����������Ϊ�����ص�һ�����ǳ������ʽ
����������������const���ε��Ƿ񷵻�һ���������ʽ����ֱ���϶������ǣ� 
�綨������ά��ʱ  ������ص��ǳ������ʽ �������constexpr������
�������޷���const���εĺ��������� 
constexpr���εĺ���ֻ��һ����ִ��������return ���ҷ��������Լ��β�һ��������ֵ����



Ҳ������������
ʲô������ֵ�����ࣿ
1.�ۺ��ಢ�����е����ݳ�Ա���Ͷ�������ֵ
2.�������������
 �����ٺ���1��constexpr���캯��
 �����б����ĳ�Ա  �ó�Ա��ʼ������constexpr���캯�������
 ���ڳ�ʼ����ʼֵһ���ǳ������ʽ
 ���ݳ�Ա��������ֵ
 
 ������������һ������������ֵ������ 
 ��һ����������� ����ֻ��һ�����
 �б��ʼ������Ĭ�Ϲ��죬��ÿ����Ա����Ĭ�ϳ�ʼ�� 
 �ڶ���ȴ���������������԰������� �������constexpr���캯�������
�Ǹ��������ʽ 
 �����������캯����������� ����
 ��ֻ��constexpr���캯���ܹ����constexpr�������Ӧconstexpr int i=10,��������Ǹ��������ʽ 
 �籾�����56��  ���޷��ڸö���ǰ����constexpr���� ��Ϊ������constexpr��������� 
 ��Ȼ   �����������ֵ�����࣬������ֵ���ͣ����Ķ��������Ϊconstexpr�����Ĳ���
 �������������constexpr���캯�����������   ���ص�ֵ�����ڱ�����ȷ���Ǹ��������ʽ
 ��51-53�� 
 �������������͵�����ֵ  ��int ֮�����һ�µ� 
 ��54��
 ���������ǳ������ʽ  �䷵��ֵҲ���ǳ������ʽ 
*/ 
