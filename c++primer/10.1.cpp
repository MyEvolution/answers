#include<iostream>
#include<algorithm>
#include<vector>
#include<string>


using namespace std;

int main()
{
	vector<int>/*list<string>*/ v;
	int /*string*/num;
	//const char a[]="hello";
	const char b[]="helloc";
	const char *a ="hello";
	//const char *b = "helloc";
	//ֻΪ�����ַ�������ֵ������һ���ڴ� 
	vector<string> v1({a});
	//vector<string> v2=v1;
	vector<const char *> v2({b});
	//������string ����ʼ�� const char*�� 
	while(cin>>num)
	v.push_back(num);
	cin.clear();
	cin>>num;
	cout<<count(v.begin(),v.end(),num);
	cout<<accumulate(v.begin(),v.end(),0)<<endl;
	cout<<equal(v1[0].cbegin(),v1[0].cend(),begin(b));
	cout<<equal(v1.begin(),v1.end(),v2.begin())<<endl;
	return 0;
}
