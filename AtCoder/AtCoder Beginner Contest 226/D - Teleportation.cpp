/*
	group : AtCoder - AtCoder Beginner Contest 226
	name : D - Teleportation.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Teleportation.cpp
	url : https://atcoder.jp/contests/abc226/tasks/abc226_d
*/
/**
 *    author:  Aryan Agarwal
 *    created: 07.11.2021 17:49:16 IST
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

int gcd(int a, int b) /*__gcd doesn't work for big no.s*/
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void solve()
{
	int n;
	cin>>n;

	vector<pair<int,int> > v(n);
	set<pair <int,int> > s;

	for(int i=0;i<n;i++){
		cin>>v[i].first>>v[i].second;
	}

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			// if(i==j)continue;
			int x = v[j].first-v[i].first;
			int y = v[j].second-v[i].second;
			int g = gcd(x,y);
			s.insert({x/g,y/g});
		}
	}

	// dbg(s);

	cout<<2*s.size();
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
//	parsed : 07-November-2021 17:47:53 IST