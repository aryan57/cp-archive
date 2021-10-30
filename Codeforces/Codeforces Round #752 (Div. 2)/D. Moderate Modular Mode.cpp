/*
	group : Codeforces - Codeforces Round #752 (Div. 2)
	name : D. Moderate Modular Mode.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Moderate_Modular_Mode.cpp
	url : https://codeforces.com/contest/1604/problem/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 30.10.2021 21:59:46 IST
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
	int x,y;
	cin>>x>>y;
	int n=1;
	if(y<x){
		n=x+y;
	}else if(x==y){
		n=x;
	}else{
		n=(y+x)/2;
	}

	dbg(n%x,y%n);

	cout<<n;
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
//	parsed : 30-October-2021 21:59:42 IST