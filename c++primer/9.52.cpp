#include<iostream>
#include<stack>
#define NUM 1 
#define ZERO 0

using namespace std;

char buff[10];//������ŷ��ŵĻ����� 
int buf= 0;

string num = "0123456789. \n\b";
string sign = "+-*/\n\b()";
double number;
char get_what(string &s);
double get_num(stack<double> &s);
int isover=0;

int main()
{
	string s;
	stack<double> st;
    while(getline(cin,s))
    {
    	isover=0;
    	char c;
    	while(!isover&&(c=get_what(s)))
    	{
    		switch(c)
    		{
    			case '+':
    			case '-':
    				  if(buf&&buff[buf-1]!='(')
    				   st.push(get_num(st));
    				   buff[buf++] = c;
    				   break;
    			case '*':
    			case '/':
    				   if(buf&&(buff[buf-1]=='*'||buff[buf-1]=='/')&&buff[buf-1]!='(')
    				   st.push(get_num(st));
    				   buff[buf++] = c;
    				    break;
    			case '(':
    				   buff[buf++] = c;
    				   st.push(c);
    				   break;
    			case ')':
    				      while(buff[buf-1]!='(')
    				      st.push(get_num(st));
    				        --buf;
    				      break;
    			case NUM:
    				    st.push(number);
    				       break;
    		    default:
    		    	break;
    				    
			}			  
		}
				while(buf)
			   st.push(get_num(st));
			   //cout<<get_num(st)<<endl;
			   if(!st.empty())
		  cout<<st.top()<<endl,st.pop();
		  else
	          cout<<"no input "<<endl;
		 
	}
	return 0;
}

char get_what(string &s)
{
	char _sign;
	
	string::size_type pos1,pos2;
	pos1=s.find_first_not_of(num);
	pos2=s.find_first_not_of(sign);
       if( pos1<pos2)
           {
           	_sign = s[pos1];
    
           if(pos1+1<s.size())
           	s=s.substr(pos1+1);
           	else isover = 1;
           	
           	return _sign;
		   }
		   else if(pos2!=string::npos)
		   {
		   	string::size_type p;
		   	number = stod(s,&p);
		   	if(p>=s.size())
		   	   isover = 1;
		   	else
		   		s = s.substr(p);
		   	return NUM;
		   }
		   else{
		   
		      isover = 1;
		      return -1;
		  }
}
double get_num(stack<double> &s)
{
	double a,b;
	a=s.top();
	s.pop();
	b = (s.empty()||s.top()=='('?0:s.top());
	if(!s.empty()) s.pop();
    
	switch(buff[--buf])
	  {
	  	case '*':
	  		return b*a;
	  	case '+':
	  		return b+a;
	  	case '/':
	  		if(a!=0)
	  		return b/a;
	  		else
	  		  cerr<<"��������Ϊ0"<<endl;
	  		  return -1;
	  	case '-':
	  		return b-a;
	  }
}
/*
��д�������Ĺ���Ҳ���� 
������Ϸ�����벻����˼·  ���Էŵ��ڶ����д  �ڴ����� ��ʵҲû�����ʲô
����õ���c++��stod������Ϊ�ؼ�  ����Ƿ��� ������ŵ�ջ����������� �������ֵ�ջ


����һ���������  �ȼ��ǰ���ǲ����б������ȼ��߻��ߺ�����ȵģ���Ҫ���м��㣬
����ǰ�������ţ���ô�򲻱����֮ǰ�����ȼ� ��Ϊ���ŵ����ȼ����
������ʱ  ��ջ��������

�������������� ����һ��bug
����������ʾ����һ�����������������ᵯ��������֮ǰ������Ȼ�����
��9-��-6��  �ᵯ����9-6��������0-3 �����-3
����İ취��������ջ�� Ҳ�������������� �����Ǹ�������ķ��� ��ͬ����������� 

������ë������һЩϸ��
��stod���� ���ָ��������˽�β������ָ������ֵĺ�һλ��Ҳ����δ�������Ϊ
ͬ���ĵ��� ���һ���Ƿ��ŵĻ�  ����Ҳ���ܼ�1�ٸ����� ��Ϊ�Ǹ��ط��ı�������ȴ�����ǵ�����
����һ��isover������Ƿ񵽴��ַ����Ľ�β

���о��ǣ��㷴��  ̫������� 
remember��  if(!f)=>if(f==0)
   if(f)=>if(f!=0) 
*/
