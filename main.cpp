#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#define N 1000
using namespace std;
//判断是否为字母及字母大小写
int isLetter(char c){
	if('a' <= c && c <= 'z')
		return 1;
	else if('A' <= c && c <= 'Z')
		return 2;
	else
		return 0;
}
char m_toupper(char c){
	return (char)(c - ('a' - 'A'));
}
char m_tolower(char c){
	return (char)(c + ('a' - 'A'));
}
int cmp(char a,char b){     //stable_sort比较函数
	if(isLetter(a) == 2)
		a = m_tolower(a);
	if(isLetter(b) == 2)
		b = m_tolower(b);
	return (b > a ? 1 : 0);
}
int main(){
	char a[N];
	char b[N];
	//char sorted[N];
	int len_a,len_b = 0;
	while(gets(a)){
		len_a = strlen(a);
		for(int i = 0;i < len_a;i++){  //将字符串中字母复制到b中
			if(isLetter(a[i]))
				b[len_b++] = a[i];
		}
		stable_sort(b,b+len_b,cmp);    //相同元素不变序使用稳定排序
		for(int i = 0,j = 0;i < len_a;i++){
			if(isLetter(a[i])){
				printf("%c",b[j++]);
			}
			else{
				printf("%c",a[i]);
			}
		}
	}
	system("pause");
	return 0;
}
