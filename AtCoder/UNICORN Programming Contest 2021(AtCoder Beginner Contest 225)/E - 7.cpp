/*
	group : AtCoder - UNICORN Programming Contest 2021(AtCoder Beginner Contest 225)
	name : E - 7.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_7.cpp
	url : https://atcoder.jp/contests/abc225/tasks/abc225_e
*/
/**
 *    author:  Aryan Agarwal
 *    created: 30.10.2021 18:24:56 IST
**/
#include <bits/stdc++.h>
using namespace std;

// #define int long long

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
	int n;
	cin>>n;
	vector<pair<int,int> > v(n);
	for(int i=0;i<n;i++){
		cin>>v[i].first>>v[i].second;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)continue;
			if(v[i].first>v[j].first || v[i].second>v[j].second)continue;
			dbg(i,j,v[i],v[j]);
		}
	}

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
//	parsed : 30-October-2021 18:17:36 IST