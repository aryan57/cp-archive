/*
	group : Codeforces - Codeforces Round #750 (Div. 2)
	name : C. Grandma Capa Knits a Scarf.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Grandma_Capa_Knits_a_Scarf.cpp
	url : https://codeforces.com/contest/1582/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 25.10.2021 12:14:23 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 2e18;
string s;
int f(int l,int r,char x)
{
	if(l>=r)return 0;
	if(s[l]==s[r])return f(l+1,r-1,x);
	int ans=INF;
	if(x=='$' || s[l]==x)ans=min(ans,1+f(l+1,r,s[l]));
	if(x=='$' || s[r]==x)ans=min(ans,1+f(l,r-1,s[r]));
	return ans;
}

void solve()
{
	int n;
	cin>>n;
	cin>>s;

	int ans=f(0,n-1,'$');
	if(ans==INF)ans=-1;
	cout<<ans<<"\n";
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
//	parsed : 25-October-2021 12:14:20 IST