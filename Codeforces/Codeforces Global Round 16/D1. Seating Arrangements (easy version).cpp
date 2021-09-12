/*
	group : Codeforces - Codeforces Global Round 16
	name : D1. Seating Arrangements (easy version).cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D1_Seating_Arrangements_easy_version_.cpp
	url : https://codeforces.com/contest/1566/problem/D1
*/
/**
 *    author:  Aryan Agarwal
 *    created: 12.09.2021 20:46:40 IST
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

bool comp(pair <int,int> a,pair <int,int> b)
{
	if(a.first!=b.first)return a.first<b.first;
	return a.second > b.second;
}

void solve()
{
	int n,m;
	cin>>n>>m;
	int k=n*m;
	vector<pair<int,int> > v(k);

	for(int i=0;i<k;i++)
	{
		cin>>v[i].first;
		v[i].second=i;
	}

	sort(v.begin(),v.end(),comp);

	int ans=0;

	vector <int> pos(k,-1);

	for(int i=0;i<k;i++)
	{
		pos[v[i].second]=i;
	}

	// dbg(pos);

	vector <int> t(k,-1);

	for(int i=0;i<k;i++)
	{
		int z = pos[i];

		for(int j=0;j<k;j++)
		{
			if(j==z){
				t[z]=i;
				break;
			}
			if(t[j]!=-1)ans++;
		}
	}

	cout<<ans;
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
//	parsed : 12-September-2021 20:46:35 IST