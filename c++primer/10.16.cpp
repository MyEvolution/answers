#include<vector>
#include<algorithm>
#include<iostream>
#include<string>

using namespace std;
inline bool isShorter(const string &s1,const string &s2)
{
	return s1.size()<s2.size();
}
void biggies(vector<string> &s,vector<string>::size_type sz);
int main()
{
	vector<string> v{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
	biggies(v,4);
	return 0; 
}
/*���������Ŀ��
�ǽ������еĵ��ʰ��ճ������򣬳�����ͬ�İ��մ�Ц����
�ҳ����ȴ���ĳ��ֵ�ģ�
Ȼ�������Ŀ����һһ���
*/ 
void biggies(vector<string> &s,vector<string>::size_type sz)
{
	sort(s.begin(),s.end());//���ֵ�˳������ 
	auto i=unique(s.begin(),s.end());//��ɾ�����ظ���Ԫ�� 
	s.erase(i,s.end()); 
	stable_sort(s.begin(),s.end(),isShorter);//���������򣬳�����ͬ�ı���ԭ����˳��
	 //vector<string>::const_iterator w = find_if(s.cbegin(),s.cend(),[sz](const string &s){return s.size()>=sz;});//����lambda���ʽ
	 /*
	 auto w = stable_partition(s.begin(),s.end(),[sz](const string &s){
	 	 return s.size()>=sz;//Ϊ1�Ľ���ǰ�� 
	 });
	 auto count = w-s.begin();//������Ŀ 
	 */
	 auto count = count_if(s.cbegin(),s.cend(),[=](const string &s){
	 	return s.size()>=sz;
	 });
	 cout<<count<<" "<<"word"+string((count>1)?"s":"")<<" of length "<<sz<<" or longer"<<endl;//������� 
	 //for_each(s.begin(),w,[](const string &s){cout<<s<<" ";});//������� 
	 //��Χ��������β����Ҫһ�� 
	cout<<endl;
	//no matching function for
	// call to 
	//'for_each(__gnu_cxx::__normal_iterator<const std::basic_string<char>*, 
	//std::vector<std::basic_string<char> > >&, std::vector<std::basic_string<char> >::iterator, 
	//biggies(std::vector<std::basic_string<char> >&, 
	//std::vector<std::basic_string<char> >::size_type)::<lambda(const string&)>)'
}
