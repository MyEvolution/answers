#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<iostream>

class Account
{
	public:
		void calculate(){
			amount+=amount*interestRate;
		}
		static double rate()
		{
			return interestRate;
		}
		static void rate(double);
		explicit Account(const std::string &s="",double d = 0.0):owner(s),amount(d){
		}
		
	private:
		std::string owner;
		double amount = 0.0;
		static double interestRate;
		static double initRate();
};
#endif
double Account::interestRate=initRate();
double Account::initRate()
{
	return 0.0;
}
 //double Account::interestRate;
 //在外部定义时候不用写static
 void Account::rate(double newRate)
 {
 	interestRate = newRate;
  } 
