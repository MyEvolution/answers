#include"Employee.h"
int main()
{
	Employee e1("Jordan");
	Employee e2(e1);
	e1.get_info(cout);
	e2.get_info(cout);
	e2 = string("Mike");//������ֻ�Զ�ִ��һ����ʽת�� 
	e2.get_info(cout);
	return 0;
}
/*
����Ҫ�����
���ȿ������캯���Ϳ�����ֵ���������Ҫ�Լ�����
�������ϳɵĿ�������ֵ��ʹ����ͬ�Ĺ�Ա֤��
�����������úϳɵļ���
*/
 
