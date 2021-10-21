/*
	group : AtCoder - AtCoder Beginner Contest 223
	name : C - Doukasen.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Doukasen.cpp
	url : https://atcoder.jp/contests/abc223/tasks/abc223_c
*/
/**
 *    author:  Aryan Agarwal
 *    created: 21.10.2021 10:57:49 IST
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
	int n;
	cin>>n;

	vector<pair<int,int> > v(n+1);
	vector<long double> time(n+1);

	for(int i=1;i<=n;i++){
		cin>>v[i].first>>v[i].second;
		time[i]+=time[i-1];
		time[i]+= (long double)v[i].first/v[i].second;
	}

	for(int i=1;i<=n;i++){

		long double c2 = time[n] - time[i];
		long double c1 = time[i-1];

		long double z = ((c2-c1)*v[i].second + v[i].first)*0.5;

		if(!(z<0) && !(z>v[i].first)){
			int d=0;
			for(int j=1;j<i;j++)d+=v[j].first;
			// dbg(i,d,z);
			cout<<z+d<<"\n";
			return;
		}

	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout<<fixed<<setprecision(10);
	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 21-October-2021 10:54:09 IST