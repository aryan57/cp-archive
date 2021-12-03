/*
	group : AtCoder - AtCoder Beginner Contest 230
	name : C - X drawing.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_X_drawing.cpp
	url : https://atcoder.jp/contests/abc230/tasks/abc230_c
*/
/**
 *    author:  Aryan Agarwal
 *    created: 03.12.2021 17:48:12 IST
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
	int n,a,b;
	cin>>n>>a>>b;
	int p,q,r,s;
	cin>>p>>q>>r>>s;

	vector< vector<char> >  g(q-p+2,vector<char>(s-r+2,'.'));

	const int INF = 2e18;


	pair <int,int> z ={-INF,INF};
	z.first=max(z.first,p-a);
	z.first=max(z.first,r-b);
	z.first=max(z.first,max(1-a,1-b));
	z.second=min(z.second,q-a);
	z.second=min(z.second,s-b);
	z.second=min(z.second,min(n-a,n-b));

	for(int k=z.first;k<=z.second;k++){
		g[a+k-p+1][b+k-r+1]='#';
		// dbg(a+k,b+k);
	}

	{
		pair <int,int> z ={-INF,INF};
		z.first=max(z.first,p-a);
		z.first=max(z.first,b-s);
		z.first=max(z.first,max(1-a,b-n));
		z.second=min(z.second,q-a);
		z.second=min(z.second,b-r);
		z.second=min(z.second,min(n-a,b-1));

		for(int k=z.first;k<=z.second;k++){
			g[a+k-p+1][b-k-r+1]='#';
			// dbg(a+k,b-k);
		}
	}

	for(int i=1;i<=q-p+1;i++){
		for(int j=1;j<=s-r+1;j++){
			cout<<g[i][j];
		}cout<<"\n";
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
//	parsed : 03-December-2021 17:39:52 IST