#include<iostream>
#include<string>

using namespace std;

int main()
{
	string name = "James";
	string before = "Mr.";
	string after = "Jr.";
	name.insert(name.begin(),before.begin(),before.end());
    //name.insert(0,before);
    //name.insert(name.size(),before);
    name.append(after);
    cout<<name<<endl;
    return 0;
}
