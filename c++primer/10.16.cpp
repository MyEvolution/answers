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
/*这个函数的目的
是将容器中的单词按照长度排序，长度相同的按照大笑排序
找出长度大于某个值的，
然后输出数目，再一一输出
*/ 
void biggies(vector<string> &s,vector<string>::size_type sz)
{
	sort(s.begin(),s.end());//按字典顺序排序 
	auto i=unique(s.begin(),s.end());//”删除“重复的元素 
	s.erase(i,s.end()); 
	stable_sort(s.begin(),s.end(),isShorter);//按长度排序，长度相同的保持原来的顺序
	 //vector<string>::const_iterator w = find_if(s.cbegin(),s.cend(),[sz](const string &s){return s.size()>=sz;});//调用lambda表达式
	 /*
	 auto w = stable_partition(s.begin(),s.end(),[sz](const string &s){
	 	 return s.size()>=sz;//为1的将往前排 
	 });
	 auto count = w-s.begin();//计算数目 
	 */
	 auto count = count_if(s.cbegin(),s.cend(),[=](const string &s){
	 	return s.size()>=sz;
	 });
	 cout<<count<<" "<<"word"+string((count>1)?"s":"")<<" of length "<<sz<<" or longer"<<endl;//输出个数 
	 //for_each(s.begin(),w,[](const string &s){cout<<s<<" ";});//依次输出 
	 //范围迭代器首尾类型要一致 
	cout<<endl;
	//no matching function for
	// call to 
	//'for_each(__gnu_cxx::__normal_iterator<const std::basic_string<char>*, 
	//std::vector<std::basic_string<char> > >&, std::vector<std::basic_string<char> >::iterator, 
	//biggies(std::vector<std::basic_string<char> >&, 
	//std::vector<std::basic_string<char> >::size_type)::<lambda(const string&)>)'
}
