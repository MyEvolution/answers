#include"Screen.h"
using std::cout;
int main()
{
	Screen myScreen(5,5,'X');
	myScreen.move(4,0).set('#').display(std::cout);
	cout<<'\n';
	myScreen.display(std::cout);
	cout<<std::endl;
	return 0; 
}
