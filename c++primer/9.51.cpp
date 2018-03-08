#ifndef DATA_H

#define DATA_H

#include<iostream>
#include<string>
#include<sstream>

using namespace std;
const int ping[12]={31,28,31,30,31,30,31,31,30,31,30,31};
const int  run[12]={31,29,31,30,31,30,31,31,30,31,30,31};
const string num = "1234567890\b ";
const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\b ";
const string month1[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
const string month2[12]={"January","Februry","March","April","May","June","July","August","September","October","November","December"};
class Date
{
 private:
     int day=1;
	 int month=1;
	 int year = 1;
	 int _error();
	 int error;
public:
  Date()=default;
  Date(istream &is);
  void get_date()
  {
  	cout<<month<<"/"<<day<<"/"<<year<<endl;
  }
};

#endif

Date::Date(istream &is)
{
	
  	string s;
   while(getline(is,s))
  {
  	
  	if(s.find_first_not_of(num)<s.find_first_not_of(alphabet))//�����ų��˿ո����� 
    {
    	  istringstream ss(s);
    	  string _mon,_day,_year;
    	  ss>>_mon>>_day>>_year;
    	  if(_mon.size() == 3)
    	   {
    	   	month = 0;
		   for(int i = 0;i<12;++i)
    	      if(_mon == month1[i])
    	      {
				    month = i+1;
    	         break;
    	     }
    	 }
    	 else
    	 {
		   for(int i = 0;i<12;++i)
    	      if(_mon == month2[i])
    	      {
				    month = i+1;
    	         break;
    	     }    	 
		 }
		 day = stoi(_day);
		 year = stoi(_year);     
  }
  else
     {
     	string::size_type p;//���������Ϊָ�룬����û�г�ʼ������ָ��  ���ں�������ָ������ݱ��ı� ������Ϊ��δ����� 
     	month = stoi(s,&p);//���ֵ� ��ô��ָ�������ˡ����� 
     	day = stoi((s=s.substr(p+1)),&p);
     	year = stoi((s=s.substr(p+1)),&p);
     }
     	if(error = _error())
     	{
     		error==1?cout<<"wrong month!"<<endl:cout<<"wrong day!"<<endl;
     	    cout<<"try again!"<<endl;
     	}
     	    else
     	      break;
		 
     	
	 }
}
int Date::_error()
{
	if(month<=0||month>12)
	  return 1;
	if(year%4==0&&year%100!=0||year%400==0)
	        if(day>run[month-1])
	           return 2;
	           else 
	             if(day>ping[month-1])
	             return 2;
	   return 0;
}
int main()
{
	Date c(cin);
	c.get_date();
	return 0;
}
