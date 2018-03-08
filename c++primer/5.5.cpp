#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	vector<string> _class{"F","D","C","B","A","A++"};
	vector<string> _grade;
	int grades[]={59,60,88,76,99,43,84,100,63};
	for(int *g=grades;g<(grades+sizeof(grades)/sizeof(*grades));++g)
	  (*g<60)? 
	     _grade.push_back(_class[0])
	     :
	     
	     (*g==100)?
	     	_grade.push_back(_class[5])
	     	:
	     	_grade.push_back(_class[(*g-60)/10+1]+((*g%10<=3)?"-":*g%10>=7?"+":""));
		 for(auto i:_grade)
		 cout<<i<<" ";
		 cout<<endl;
		 return 0;
 } 
