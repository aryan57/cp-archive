/*
	group : Codeforces - Educational Codeforces Round 116 (Rated for Div. 2)
	name : C. Banknotes.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Banknotes.cpp
	url : https://codeforces.com/contest/1606/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 29.10.2021 20:27:42 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int f(int k,vector <int> &v)
{
	if(k==0)return 0;
	int n=v.size();
	if(n==1)return k+1;
	int x=v[n-1]-1;
	int cnt=0;

	for(int i=n-2;i>=0;i--){
		int t=x/v[i];
		cnt+=t;
		x-=t*v[i];
	}

	if(cnt==k)return  v[n-1]+f(k-1,v);
	if(1+cnt<=k)return (v[n-1]-1 + (k-cnt+1)*v[n-1]);
	v.pop_back();
	return f(k,v);
}

void solve()
{
	int n,k;
	cin>>n>>k;

	vector <int> v(n);
	for(int &x : v){
		cin>>x;
		x = (int)pow(10,x);
	}

	cout<<f(k,v);
	cout<<"\n";
	
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
//	parsed : 29-October-2021 20:24:02 IST