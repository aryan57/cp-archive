/*
	group : AtCoder - AtCoder Beginner Contest 216
	name : C - Many Balls.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Many_Balls.cpp
	url : https://atcoder.jp/contests/abc216/tasks/abc216_c
*/
/**
 *    author:  Aryan Agarwal
 *    created: 29.08.2021 17:37:36 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

// unordered_map<int,bool> vis;
unordered_map<int,int> val;

int f(int n){
	
	if(n==0){
		return 0;
	}

	if(val[n]){
		return val[n];
	}

	assert(n>0);

	int ans = 500;

	if(n%2==0)ans=min(ans,1+f(n/2));
	ans=min(ans,1+f(n-1));

	val[n]=ans;
	return ans;
}

void solve()
{
	int n;
	cin>>n;

	string z="";

	while(n>0){
		if(n%2==0){
			z+='B';
			n/=2;
		}
		if(n%2==1){
			z+='A';
			n--;
		}
	}

	reverse(z.begin(),z.end());

	cout<<z;


}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 29-August-2021 17:36:30 IST