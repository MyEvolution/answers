#include<vector>
#include<iostream>
using std::vector;
class Example
{
	public:
		static constexpr double rate = 6.5;//6.5Ҳ���ԣ����Ǳ��������ͳ����� 
		static constexpr int vecSize = 10;//const���ҳ�ʼֵ�ǳ������ʽҲ��  ���Ǽ�Ȼ�ǳ������ʽ��Ӧ��ʹ��constexpr 
		 static vector<double> vec;//���Ƿ�����ֵ  ���Բ������ڳ�ʼ��
		 //����ķ���ʤ���� 
}; 
constexpr double Example::rate;
vector<double>Example::vec(10);
int m;
const int i = 10;
//const ������������ʽ�Ļ�  ��constexpr��һ����Ч��  ����constexpr���죬
//�������ڱ���ʱ�ڼ�����浽���ǲ��ǳ������ʽ 
int array[i];
int main()
{
	
	std::cout<<Example::rate<<std::endl<<Example::vec.size()<<std::endl;
	return 0;
}
