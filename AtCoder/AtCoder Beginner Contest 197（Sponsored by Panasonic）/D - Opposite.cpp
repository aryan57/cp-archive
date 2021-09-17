/*
	group : AtCoder - AtCoder Beginner Contest 197（Sponsored by Panasonic）
	name : D - Opposite.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Opposite.cpp
	url : https://atcoder.jp/contests/abc197/tasks/abc197_d
*/
/**
 *    author:  Aryan Agarwal
 *    created: 17.09.2021 10:30:04 IST
**/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	int x0,y0,xn,yn;
	cin>>n;
	cin>>x0>>y0;
	cin>>xn>>yn;
	double a=x0,b=y0,c=0.5*(x0+xn),d=0.5*(y0+yn);

	a=a-c;
	b=b-d;

	double theta = 2*acos(-1)/n;

	double ra = a*cos(theta) - b*sin(theta);
	double rb = a*sin(theta) + b*cos(theta);

	a=ra+c;
	b=rb+d;

	cout<<a<<" "<<b;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout<<setprecision(10);

	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 17-September-2021 08:29:36 IST