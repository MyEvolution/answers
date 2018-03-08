#include<iostream>
#include<vector>
using namespace std;
//using int_array=int [4];
typedef int int_array [4];
int main()
{
	int ia[3][4]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	for(int_array &i:ia )//·¶Î§ 
	  for(int j:i)
	    cout<<j<<" ";
	    cout<<endl;
	for(int i=0;i<3;i++)
	  for(int j=0;j<4;j++)
	  cout<<ia[i][j]<<" ";
	  cout<<endl;
	for(int_array *i=ia;i<ia+3;i++)
	  for(int *j=*i;j<*i+4;j++)
	  	  cout<<*j<<" ";
	  cout<<endl;
	  return 0;
}
