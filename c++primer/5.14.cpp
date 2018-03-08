#include<iostream>
#include<string>
using namespace std;
int main()
{
	
	string words;
	string the_word;
	string last_word;
	cin>>the_word;
	last_word=the_word;
	int time=1,max_time=1;
	while(cin>>words)
	{
		if(words==last_word)
		{
		++time;
		if(time>max_time)
		  { 
		max_time = time;
		the_word=last_word; 
		   } 
	    }
	    else
	    {
	    	time=1;
	    	last_word=words;
		}
	}
	(max_time>1)?cout<<the_word<<" shows up for "<<max_time<<endl:cout<<"no words shows up for twice and up"<<endl;
	return 0;
		
		 
} 
