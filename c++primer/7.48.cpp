#include"Sales_data.h"
int main()
{
	std::string null_isbn("9-999-99999-9");//���ǹ��캯�����еĳ�ʼ�� 
	//�����ǽ�const char*��ʽת�����ڶ�null_isbn���е�ֱ�ӳ�ʼ�� 
	//�������֤�� 
	std::string n(null_isbn);//ֱ�ӳ�ʼ�� 
	Sales_data item1(null_isbn); //���캯�����еĳ�ʼ�� 
	Sales_data item2("9-999-99999-9");//������ֻ���Զ�ִ��һ����ʽת�� 
	Sales_data item3(item2); 
	//����� ��һ���������ʽת����� ֱ�ӳ�ʼ������ô����Ӧ�û�ִ��������ʽת�� 
	//1.const char*ת����string  2.stringת����Sales_data
	//����ʵ�����������ǲ������
	//���Ե�һ����Ķ����Թ��캯����ʽ��ʼ����ʱ�� ��ִ�е��ǵ��ù��캯�����еĳ�ʼ��
	//�����ǹ��캯�������� 
	std::cout<<null_isbn<<n<<item3.isbn();
	//std::string a = item1;//��ʽ��ʼ���ǵ���� 
	Sales_data item4 = n;
	Sales_data item5 = {"9-999-99999-9",25,15.99}; 
	std::cout<<item5.isbn()<<std::endl;
	
	return 0;
 } 
