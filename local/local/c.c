/*
	group : local
	name : c.c
	srcPath : /home/aryan/Dropbox/Documents from PC/Sem6/OS/ass2/c.c
	url : /home/aryan/Dropbox/Documents from PC/Sem6/OS/ass2/c.c
*/
#include<stdio.h>
#include<string.h>
int main(){
	char a[2]={};
	char b[4]={};

	for(int i=0;i<2;i++)a[i]='a'+i;
	for(int i=0;i<4;i++)b[i]='a'+i;
	printf("%d",strncmp(a,b,4));
}