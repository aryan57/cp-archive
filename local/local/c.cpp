/*
	group : local
	name : c.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/c.cpp
	url : /home/aryan/Desktop/cp-workspace/c.cpp
*/
/**
 *    author:  Aryan Agarwal
 *    created: 06.09.2021 13:20:07 IST
**/
#include <bits/stdc++.h>
using namespace std;

// #define int long long

int func(int x,int y,int z)
{
	int f , mask1,mask2;
	mask1 = ((!x)^(0x01)<<31)>>31;
	mask2 = ((!x)<<31)>>31;

	f = (y&mask1) + (z&mask2);

	return f;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout<<func(0,10,11);

	return 0;
}