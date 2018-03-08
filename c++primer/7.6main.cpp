#include"Sales_data.h"
#include<fstream>

int main(int argc,char **argv)
{
	Sales_data item,last;
	std::ifstream file(argv[1]);
	std::ofstream file2(argv[2],std::ofstream::out|std::ofstream::app);
	if(read(file,last))
	{ 
     	while(read(file,item))
	 {
			if(item.isbn()==last.isbn())
			last.combine(item);
			else
			{
				print(file2,last);
				file2<<std::endl;
				last=item;
			}
	 }
      print(file2,last);
      file2<<std::endl;
      file.close();
      file2.close();
      
      return 0;
	}else
	{
		std::cerr<<"no data?"<<std::endl;
		return -1; 
	}
}
