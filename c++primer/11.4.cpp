#include<iostream>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

int main()
{
	map<string,size_t> word_count;
	set<string> ignore_word{"the","a"};
	static set<char> ignore_al{',' ,'.',';','"','!','?','\''};
	string word;
	while(cin>>word)
	{
		word.erase(remove_if(word.begin(),word.end(),[](char c){
			return ignore_al.find(c)!=ignore_al.end();}),word.end());//这里有问题 
			/*
			刚开始这里出错   因为没有加if
			后来依然会停止运行  原来忘记加范围迭代器的后面
			remove_if如果没有找到符合条件的会返回尾后迭代器
			如果发现了会将后面的元素前移，也就是并没有真正删除元素 
			后面有残留数据是未知的，所以需要再用erase真正将其删除 
			没有加范围迭代器erase会单独删除其中迭代器所指的元素，
			但是删除尾后迭代器将是未定义的行为
			如果加了尾后迭代器   那么没有找到的话将不会删除任何值
			*/ 
			transform(word.begin(),word.end(),word.begin(),::tolower);//将最后谓词的值拷贝到开始的位置 
			if(ignore_word.find(word)==ignore_word.end())
		  ++word_count[word];
	}
	for(auto i:word_count)
	   cout<<i.first<<":"<<i.second<<endl;
	   return 0;
 }
