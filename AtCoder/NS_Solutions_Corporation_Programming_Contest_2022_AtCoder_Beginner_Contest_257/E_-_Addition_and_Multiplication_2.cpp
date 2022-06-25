/**
 *    author:  Aryan Agarwal
 *    created: 25.06.2022 18:09:31 IST
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

	vector<pair<int,int> > v(9);
	vector <int> cost(10);
	for(int i=0;i<9;i++){
		int c;
		cin>>c;
		cost[i+1]=c;
		v[i] = {c,i+1};
	}

	sort(v.begin(),v.end(),[](const pair <int,int> &a,const pair <int,int> &b){
		if(a.first!=b.first)return a.first < b.first;
		return a.second > b.second;
	});

	int rem=n;
	string s="";
	while (rem>=v[0].first)
	{
		rem-=v[0].first;
		s+='0'+v[0].second;
	}

	int sz=s.size();
	for(int i=0;i<sz;i++){
		for(int d=9;d>s[i]-'0';d--){
			int extra = cost[s[i]-'0'];
			if(rem+extra>=cost[d]){
				rem+=extra;
				rem-=cost[d];
				s[i]='0'+d;
				break;
			}
		}
		// dbg(i,s);
	}

	cout<<s;
	
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}