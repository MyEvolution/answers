#include<fstream>
#include<iostream>
using namespace std;

int main()
{
	fstream inOut("F:\\copy.txt",fstream::ate|fstream::in|fstream::out);
	
	if(!inOut)
	{
		cerr<<"the file maybe not exist\n";
		return 0;
	}
	auto end_mark = inOut.tellg();
	inOut.seekg(0,fstream::beg);
	string line;
	int m = 0;
	//	cout<<inOut.tellg()<<endl;
   while(inOut&&inOut.tellg()!=end_mark&&getline(inOut,line))
   {
   	cout<<line<<endl;
   	//auto now = inOut.tellg();
   	
   //inOut.seekp(0,fstream::end);
   	//m+=line.length()+1;
   	//inOut<<m;
   	//if(now!=end_mark)
   	//inOut<<" ";
   	inOut.seekg(inOut.tellg());
   }
   inOut.seekp(0,fstream::end);
   inOut<<"\n";
   inOut.close();
}
