#include<list>
#include<vector>
#include<iostream>

using namespace std;
void abc(char *)
{
	return;
 } 
int main()
{
	list<double> l(10,1.1);
	vector<double> v(l.begin(),l.end());
	vector<double> v1 = v;
	list<const char *> l1(10,"wocao!");//×Ö·ûÐÍ³£Á¿const char * 
	vector<string> v2(10);
	vector<string> v3(10);
	v2.assign(v2.cbegin(),v2.cend());
	v3.assign({"djsakl","djksa"});
	char i;
	char *p = &i;
	const char q[]="djkalsd";
	abc("adsajk");//string constant to char*
	return 0;
 } 
