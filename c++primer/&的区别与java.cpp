#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a1 = "wjsajdskdjakljdaksldjadlksadsadsadasd;as";
	cout<<sizeof(a1)<<endl;
	int a=1,b=1;
	/*cout<<(bool)(a+b)<<endl; 
	if((a==b)&(a+b))
	cout<<"����"<<endl; 
	else
	cout<<"��λ��"<<endl; */
	if((a-b)&&(b+=1)) ;
	else
	cout<<a<<" "<<b<<endl;
	if((a-b)&(bool)(b+=1)) ;
	else
	cout<<a<<" "<<b<<endl;
	return 0;
}
/*
�ڿ�java�鼮��ʱ��д��
&���Ե����߼�������������� �����ǲ���·��
Ҳ�������ߵĲ���ֵ����������ٽ���������
�������뵽c++���Ƿ�Ҳ�������Ĺ���
��ʵ֤��c++û�� &��c++��ֻ�а�λ�ڵĹ��� 
��������ǲ���ֵ��ת��Ϊ0��1���а�λ�� ��ʵ���Ϻ��߼�����һ����
���ǲ�ͬ�����߼���Ὣ�����ֵȫ��ת��Ϊtrue��
��1&&8���߼�����ture  ���ǰ��հ�λ��Ļ���0

ͬʱjava�в���ֵ�޷�����������
���&�ſ��Խ����߼������� ��Ϊ������಻һ�»ᱨ��
ͬʱ&&���������ǲ���ֵҲ�ᱨ��
����ζ����java���޷�д
if(a+b)����������� �м���Ҫ���ǲ���ֵ 
*/ 
