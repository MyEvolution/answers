#include"Hasptr.h"
#include<algorithm>
#include<vector>

int main()
{
	vector<string> o= {"wocao","Fuck","fuck","nima"};
	vector<Hasptr> i(o.begin(),o.end()); 
	sort(i.begin(),i.end());//������õ���std���swap 
	for(auto j:i)
	cout<<j.get_string()<<endl;
	return 0;
 } 
