/*
	group : local
	name : c.c
	srcPath : /home/aryan/cp-workspace/c.c
	url : /home/aryan/cp-workspace/c.c
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int x=0;
	char z[100];
	strcpy(z,"100\0ojip");
	x=atoi(z);
	printf("%d",x);
}