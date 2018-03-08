#include"New_TextQuery_with_StrVec.h"
int main()
{
	string file;
	cin>>file;
	ifstream ifs(file);
	TextQuery Query(ifs);
     cout<<"enter word to look for ,or q to quit"<<endl;
     string s;
while(cin>>s&&s!="q")
	{
		Query.query(s).print(cout);
		cout<<"enter word to look for ,or q to quit"<<endl;
	 }
	 return 0;
}
