#include<iostream>
#include<stack>
#define NUM 1 
#define ZERO 0

using namespace std;

char buff[10];//用来存放符号的缓冲区 
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
	  		  cerr<<"除数不能为0"<<endl;
	  		  return -1;
	  	case '-':
	  		return b-a;
	  }
}
/*
编写这个计算的过程也坎坷 
边玩游戏边想想不出来思路  所以放到第二天编写  在床上想 其实也没想出来什么
最后用的是c++的stod（）作为关键  如果是符号 放入符号的栈，如果是数字 放入数字的栈


遇到一个运算符号  先检查前面是不是有比他优先级高或者和他相等的，需要先行计算，
除非前面是括号，那么则不必理会之前的优先级 因为括号的优先级最大
当计算时  出栈两个计算

后来发现这样做 会有一个bug
如果括号里表示的是一个负数，上述做法会弹出该数和之前的数，然后相减
如9-（-6）  会弹出来9-6，最后计算0-3 结果是-3
解决的办法是在数字栈里 也用上括号来限制 括号是个很特殊的符号 不同于其他运算符 

其他的毛病还有一些细节
如stod函数 里的指针如果到了结尾，它会指向非数字的后一位，也就是未定义的行为
同样的道理 最后一个是符号的话  我们也不能加1再复制了 因为那个地方的本不存在却被我们调用了
我用一个isover来检查是否到达字符串的结尾

还有就是！搞反了  太他妈坑了 
remember！  if(!f)=>if(f==0)
   if(f)=>if(f!=0) 
*/
