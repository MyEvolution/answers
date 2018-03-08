#include<stdio.h>
#include<windows.h>
void play_mp3(char *s)
{
	char a[100];
	sprintf(a,"start mplay32.exe/play %s",s);
	system(a);
}
int main()
{
	char s[100]="eminem.mp3";
	play_mp3(s);
	getchar();
	return 0;
}
