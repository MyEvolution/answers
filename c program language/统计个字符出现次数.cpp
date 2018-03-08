#include<stdio.h>
main(){
	int a[12];
	int c,i,num=0;
	for(i=0;i<12;i++){
		a[i]=0;
	}
	while((c=getchar())!=EOF){
		
		if(c>='0'&&c<='9'){
			++a[c-'0'];
		}
		
		else if(c==' '||c=='\n'||c=='\t') a[11]++;
		else a[10]++; 
		
		num++;
	}
	printf("字符串中一共有%d个字符\n",num);
	for(i=0;i<10;i++){
		printf("输入的字符串中出现数字%d的次数为：%d\n",i,a[i]);
		
	}
	
	printf("空白符的出现次数为：%d\n",a[11]);
	printf("其他字符出现次数为：%d\n",a[10]);
}
