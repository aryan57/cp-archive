/*
	group : AtCoder - KEYENCE Programming Contest 2021 (AtCoder Beginner Contest 227)
	name : D - Project Planning.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Project_Planning.cpp
	url : https://atcoder.jp/contests/abc227/tasks/abc227_d
*/
/**
 *    author:  Aryan Agarwal
 *    created: 13.11.2021 17:48:03 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void solve()
{
	int n,k;
	cin>>n>>k;
 
	vector <int> v(n);
	for(int &x : v)cin>>x;
 
	int ans=0;
 
	int INF = 1e18;
	int l=0;
	int r=INF;
 
	while (l<=r)
	{
		int m = (l+r)/2;
		
		int tot=0;

		for(int x : v){
			tot+= min(m,x);
		}
 
		if((tot/k) >= m){
			ans=max(ans,m);
			l=m+1;
		}else{
			r=m-1;
		}
 
	}
 
	cout<<ans;

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
//	parsed : 13-November-2021 17:46:40 IST