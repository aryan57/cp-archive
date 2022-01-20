/*
	group : local
	name : c.c
	srcPath : /home/aryan/Desktop/cp-workspace/c.c
	url : /home/aryan/Desktop/cp-workspace/c.c
*/
/**
 *    author:  Aryan Agarwal
 *    created: 14.01.2022 10:13:01 IST
**/
#include <stdio.h>

int main()
{
	int t=567;
	char buf[100];
	int k = sprintf(buf,"%d",t);
	printf("%d",k);
	return 0;
}