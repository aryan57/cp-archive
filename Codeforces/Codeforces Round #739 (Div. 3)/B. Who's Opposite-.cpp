/*
	group : Codeforces - Codeforces Round #739 (Div. 3)
	name : B. Who's Opposite?.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Who_s_Opposite_.cpp
	url : https://codeforces.com/contest/1560/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 18.08.2021 21:44:03 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;

bool f(int a,int b,int c,int d){

	set<int> z;
	z.insert(a);
	z.insert(b);
	z.insert(c);
	z.insert(d);

	if(z.size()!=4 || (*z.rbegin()>n))return false;

	int cnt=0;

	if(b<a)cnt++;
	if(c<b)cnt++;
	if(d<c)cnt++;

	return cnt<=1;

}

void solve()
{
	int a,b,c;
	cin>>a>>b>>c;

	if(a>b)swap(a,b);

	int d = c + b-a;
	int d2 = c - (b-a);

	n=2*(b-a);

	if(d>=1 && d<=n && (f(a,c,b,d) || f(a,d,b,c))){
		cout<<d<<"\n";
		return;
	}

	if(d2<=0)d2+=n;
	d=d2;
	if(d>=1 && d<=n && (f(a,c,b,d) || f(a,d,b,c))){
		cout<<d<<"\n";
		return;
	}

	cout<<"-1\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 18-August-2021 21:39:14 IST