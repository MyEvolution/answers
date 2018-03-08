#include <stdio.h>

#include <dirent.h>

int main(int argc,char** argv)

{

DIR *dirptr = NULL;

struct dirent *entry;

if(argc<2)

{

printf("the command need a dirname\n");

return 1;

}

if(argc>2)

{

printf("the program can only deal with one dir at once\n");

return 1;

}

if((dirptr = opendir(argv[1])) == NULL)

{

printf("open dir error !\n");

return 1;

}

else

{

while (entry = readdir(dirptr))

{

printf("%s\n", entry->d_name);

}

closedir(dirptr);

}

return 0;

}