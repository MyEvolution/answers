#include<iostream>
#include<memory>

using namespace std;
struct destination;
struct connection;//û�����õ��������� �����ڴ����δ���ͷ� ��������malloc������ڴ� 
connection connect(destination *);
void disconnect(connection );
void end_connect(connection *p)
{
	disconnect(*p);
}
void f(destination &d)
{
	connection c = connect(&d);
	shared_ptr<connection> p(&c,[](connection *p){	disconnect(*p);	});
	//ִ�д��� ��ʹ�м��˳�Ҳ�������ͷ�
	disconnect(c); 
}
/*
����ԭ����������
c�Ľṹ����ʱ����������ڴ� ����û�����õ���������
��Ϊcû����ĸ��� ��Ҳ��û����������
��һ���ഴ��ʱ���������ڴ� ��һ�������ͷ��ڴ�ĺ���
��ʹ��������Ӧ�ý����ͷ�
��������������쳣�ж�  �ڴ潫�޷����ʲ��ͷţ���Ϊû��ָ��ָ����
��ʱ������ָ���ʮ����Ч
����Ϊc����Ķ�����һ������ָ��  ��ʹ�ж� ��Ȼ����ͨ������ָ�뽫���ͷ�
������Ϊc���е��ڴ治��ͨ��new���룬û��delete����
�������Ǳ����Լ�����һ������������delete
�������ͨ������c�Ľṹ�е��ͷ��ڴ�ĺ�����ʵ��
������ָ�벻��ָ������ʱ�򣬱��Ը�ָ�����delete����  ͬʱҲ���ǶԸö���������ͷ��ڴ�ĺ���
���ͷŵ�ָ�룬�������������Բ����
*/ 
