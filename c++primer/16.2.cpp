#include<iostream>
#include"Sales_data.h"
using namespace std;
template<typename T>
int compare(const T&t1,const T&t2)
{
	if(t1<t2)return -1;
	if(t2<t1) return 1;
	else return 0;
 } 
 
 int main()
 {
 	cout<<compare(Sales_data(string("wocao")),Sales_data(string("haha")));
 }
