#include<iostream>
#include<string>
#include<iostream>
using std::istream;
using std::string;
typedef double Type;
Type initVal();
class Exercise
{
	public :
		typedef double Type;
		Type setVal(Type);
		string initVal();
	private:
		int val;
 };
Type Exercise::setVal(Type parm)//û�б����޷�ͨ�� ��Ϊtype��string���ǳ�Ա������double 
 {
 	val=parm+::initVal();
	 return val; 
 }
 class ConstRef
 {
 	public:
 		ConstRef(int ii): i(ii),ci(ii),ri(i){
		 }
 		private:
 			int i;
 			const int ci;
 			int &ri;
 };
class ABC
{
	int m;
	ABC(int ;i):m(i){}
};
 
