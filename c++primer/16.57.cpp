#include<iostream>
#include<string>
#include<sstream>
#include<utility>
#include<type_traits>
//std::forward; 
int i;

using namespace std;
 
template <typename T>
 string debug_rep(const T & i)
 {
ostringstream ret;
  ret<<i;
  return ret.str();
 }
 template <typename T>
 string debug_rep(T * p)
 {
     ostringstream ret;
     ret<<"pointr:";
     if(p)
     ret<<*p;
     else
     ret<<"nullptr";
     return ret.str();
 }
 template <>  
 string debug_rep(const string & s)
 {
 	ostringstream ret;
 	ret<<s;
 	return ret.str();
  }
  template <> 
  string debug_rep(const char *s)
  {
  	return debug_rep(string(s));//调用非模板的，因为第一个和非模板匹配度相同，但是非模板更特例化 
  }
  template<>
  string debug_rep(char *s)//为什么我们需要单独特例化char*版本？如果没有 的话  它会被进入T*模板，T绑定到char并且不是我们想要的输入 
  {
  	return debug_rep(string(s));
  }
  template<typename T>
  ostream &print(ostream &os,const T &t)
  {
  	os<<t<<endl;
  	return os;
  }
template <typename T,typename ... Args>
  ostream &print(ostream &os,const T & t,const Args&...args)
  {    
  os<<t<<",";
  return print(os,args...);
  }
  template <typename ... Args> 
    ostream & error_Msg(ostream &os,const Args &...args)
    {
    	return print(os,debug_rep(args)...);
}
template <typename T> constexpr T&& fun(typename std::remove_reference<T>::type &&x)noexcept
{
	return ;
}

int  main()
{
	const string i = "dklasdsa";
	std::forward<string>(i);
	//std::forward<int>(i);
	string b("haha"),*a = &b ;
	error_Msg(cout,"ABG",string("wocao!"),a,b);
}
