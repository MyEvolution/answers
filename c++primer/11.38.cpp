#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<string>
using namespace std;
int main()
{
	unordered_map<string ,size_t> word_count;
	unordered_set<string> ignore{"the","a"};
	
	string word;
	while(cin>>word)
	{
		if(ignore.find(word)==ignore.end())
	   ++word_count.insert({word,0}).first->second;
	}
	for(auto i:word_count)
	cout<<i.first<<":"<<i.second<<endl;
	return 0;
 } 
