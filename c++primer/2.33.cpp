#include<iostream>
int main()
{
	int i=0,&r=i;//r�ǰ󶨵�i�ϵ�����
	auto a=r;//a��int��
	const int ci = i,&cr = ci;//ci�ǳ���������ͨ���ı�i�ı���ֵ�𣿣�cr�ǳ�������
	auto b = ci;//ci�Ƕ���const  ���Ա�����  b������
	auto c = cr;// cr��ci������  c=int�� 
	auto d = &i;//d��int ָ��
	auto e = &ci;//&ci�ǵײ�const  e��ָ����������ָ��
	const auto f = ci;//f�����ͳ���const int
	auto &g = ci;//auto��������ʱ������ʼֵ������  ��ʼֵ�Ķ���const�����ʲ��ڴ��� ����gΪ��������
	//auto &h = 42;//���� hΪ�ǳ�������  ���ܰ�����ֵ
	const auto &j = 42;//jΪ��������
	auto k = ci,&l = i;//k���ͣ�lΪ��������
	auto &m = ci, *p = &ci;//m��������  pΪָ�����ͳ�����ָ��
	//auto &n=i,*p2=&ci;//����  nΪ�ǳ�������  p2��ָ�����ͳ�����ָ�� ��������һ��
	a=42;b=42;c=42;*d=42;//*e=42;g=42;
	std::cout<<a<<b<<c<<*d<<std::endl; 
	std::cout<<ci<<std::endl;
	i=10;
	std::cout<<ci<<std::endl;
	std::cout<<"���Գ�ʼֵΪ�����ĳ�������ֵ����������ı���ı�"<<std::endl;
	const auto &n = i;//n�ǳ�������
	auto &o = i;//o��ʲô�� 
	o = 40;
	std::cout<<n<<std::endl;
	std::cout<<"��һ���������������ð�  �޷�ͨ���������øı�ñ��� \n��������øó���������Ϊauto�������õ��Ҳ� ���õ�����һ����������"<<std::endl;
	return 0; 
 } 
