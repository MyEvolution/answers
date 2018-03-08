 #include"Quote.h"
 
 using namespace std;
 
 int main()
 {
 	//Disc_quote q;//abstract type 
 	Bulk_quote q("999999",10.5,10,0.2);
 	Bulk_Quote_most q2("9999999",10.5,10,0.2);
 	q.debug(cout);
 	print_total(cout,q,11); 
 	print_total(cout,q2,11); 
 }
