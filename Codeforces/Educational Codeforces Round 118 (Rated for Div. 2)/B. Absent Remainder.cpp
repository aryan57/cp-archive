/*
	group : Codeforces - Educational Codeforces Round 118 (Rated for Div. 2)
	name : B. Absent Remainder.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Absent_Remainder.cpp
	url : https://codeforces.com/contest/1613/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 01.12.2021 20:16:41 IST
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
	vector <int> v(n);
	int mxn = 1e6;
	vector <bool> cnt(mxn+1);
	for(int i=0;i<n;i++){
		cin>>v[i];
		cnt[v[i]]=true;
	}

	sort(v.begin(),v.end());

	set<pair<int,int> > ans;

	for(int i=n-1;i>=1;i--){
		if(ans.size() == n/2)break;
		int x=v[i];
		int y=v[i-1];

		while (ans.size() != n/2)
		{
			if(!cnt[x%y]){
				ans.insert({x,y});
				break;
			}
			y=x%y;
		}
			
		
	}

	assert(ans.size()==n/2);
	for(auto p : ans){
		cout<<p.first<<" "<<p.second<<"\n";
	}
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
//	parsed : 01-December-2021 20:09:30 IST