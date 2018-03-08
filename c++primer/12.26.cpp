#include<memory>
#include<iostream>
#include<iterator>
#include<string>

using namespace std;

int main()
{
	allocator<string> alloc;
	auto const i = alloc.allocate(10);
    istream_iterator<string> begin(cin),eof;
    uninitialized_copy(begin,eof,i);
    auto p = i;
    for( ;p!=i+10;++p)
       cout<<*p<<endl;
    while(p!=i)
      alloc.destroy(--p);
      alloc.deallocate(i,10);
      return 0;
}
