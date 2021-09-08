/*
	group : local
	name : c.c
	srcPath : /home/aryan/Desktop/cp-workspace/c.c
	url : /home/aryan/Desktop/cp-workspace/c.c
*/
/**
 *    author:  Aryan Agarwal
 *    created: 06.09.2021 13:20:07 IST
**/
#include <stdio.h>

// #define int long long

int func(int x,int y,int z)
{
	int f , mask1,mask2;
	mask1 = ((!x)^(0x01)<<31)>>31;
	mask2 = ((!x)<<31)>>31;

	f = (y&mask1) + (z&mask2);

	return f;
}

int main()
{

	int z = func(0,10,11);

	printf("%d",z);

	return 0;
}