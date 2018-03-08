#include"Quote.h"
using namespace std;
int main()
{
	Bulk_quote Bq("999-9999-9999",10.5,10,0.2);
	Quote q("1111-1111-111",10.5);
	Bulk_Quote_most bq("999-999-10000",10.5,10,0.2);
    print_total(cout,Bq,11);
	print_total(cout,q,10); 
	print_total(cout,bq,11);
	return 0;
 } 
