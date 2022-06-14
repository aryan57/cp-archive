/*
	group : Google Coding Competitions - Round F 2021 - Kick Start 2021
	name : Graph Travel.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Graph_Travel.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435bae/0000000000888764
*/
/*
	author : aryan57
	created : 19-September-2021 00:14:44 IST
*/
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define F(i, a, b) for (int i = a; i <= b; i++)
#define RF(i, a, b) for (int i = a; i >= b; i--)

const int mxn = 1e5;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

void solve_GOOGLE()
{
	int n,m,k;
	cin>>n>>m>>k;

	vector< vector<bool> > e(n,vector <bool> (n));

	vector<pair<pair <int,int> ,int> > v(n);

	F(i,0,n-1)
	{
		cin>>v[i].X.X>>v[i].X.Y>>v[i].Y;
	}

	F(i,0,m-1)
	{
		int u,v;
		cin>>u>>v;
		e[u][v]=true;
		e[v][u]=true;
	}

	int pw=(int)pow(2,n);

	vector <int> s(pw);
	vector<pair<int,int> > d(pw);
	F(i,0,pw-1)
	{
		F(bit,0,n-1)
		{
			if((i>>bit)&1)s[i]+=v[bit].Y;
		}
		d[i].Y=i;
		d[i].X = __builtin_popcountll(i);
	}

	sort(all(d));
	vector <int> dp(pw);
	
	F(i,1,pw-1)
	{
		int mask=d[i].Y;
		if(d[i].X==1){
			dp[mask]=1;
		}

		set<int> pp;

		F(bit,0,n-1)
		{
			if(((mask>>bit)&1)==0)continue;
			
			F(t,0,n-1)
			{
				if(((mask>>t)&1))continue;
				if(!e[bit][t])continue;
				if(v[t].X.X>s[mask] || s[mask]>v[t].X.Y)continue;
				int newmask=mask;
				newmask += (1ll<<t);
				assert(newmask!=mask);
				pp.insert(newmask);

			}
		}
			
		for(int k : pp)dp[k]+=dp[mask];

	}

	int ans=0;
	F(i,1,pw-1)if(s[i]==k)ans+=dp[i];
	cout<<ans;
	cout<<"\n";


}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
#ifndef ONLINE_JUDGE
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
#endif
#ifdef ARYAN_SIEVE
	sieve();
#endif
#ifdef ARYAN_SEG_SIEVE
	segmented_sieve();
#endif
#ifdef ARYAN_FACT
	fact_init();
#endif
	// cout<<fixed<<setprecision(10);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve_GOOGLE();
	}
	return 0;
}
//	parsed : 18-September-2021 23:47:47 IST