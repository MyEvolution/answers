#include<iostream>
#include<string>
using std::endl;
using std::cout;
using std::cin;
using std::string;
int main()
{
	string line;
	//while(getline(cin,line))
	//cout<<line<<endl;/*不能相连我想可能是因为读完第一条后cin里最后剩下的是文件结束符 */
	while(cin>>line)
	cout<<line<<endl;
	return 0;
}
