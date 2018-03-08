#include<iostream>
#include<vector>
using namespace std;
int main()
{
	unsigned int array[10];
	unsigned int array2[10];

	for(int i=0;i<10;i++)
	array[i]=i;
	vector<int> array1;
	for(int i=0;i<10;i++)
     array1.push_back(i);
     int i=0;
    for(auto a:array)
	array2[i++]=a;
     return 0;
}
