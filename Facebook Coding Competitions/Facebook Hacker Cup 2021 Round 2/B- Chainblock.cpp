/*
	group : Facebook Coding Competitions - Facebook Hacker Cup 2021 Round 2
	name : B: Chainblock.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Chainblock.cpp
	url : https://www.facebook.com/codingcompetitions/hacker-cup/2021/round-2/problems/B
*/
/*
	author : aryan57
	created : 25-September-2021 23:44:02 IST
*/
#include <bits/stdc++.h>
#include <sys/resource.h>

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

// #define int long long
#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define F(i, a, b) for (int i = a; i <= b; i++)
#define RF(i, a, b) for (int i = a; i >= b; i--)



void dfs(int u,int p,vector< vector<int> > &adj,vector <int> &par)
{
	par[u]=p;

	for(auto to : adj[u])
	{
		if(to==p)continue;
		dfs(to,u,adj,par);
	}
}

void solve_GOOGLE()
{
	int n;
	cin>>n;

	map<pair <int,int> ,int> mp2;
	vector< vector<int >>  adj(n);
	vector <int> par(n,-1);

	F(i,0,n-2)
	{
		int u,v;
		cin>>u>>v;
		--u;--v;
		assert(u!=v);
		adj[u].push_back(v);
		adj[v].push_back(u);
		mp2[{u,v}]=i;
		mp2[{v,u}]=i;
	}
	unordered_map<int,vector<int>> f;
	F(i,0,n-1)
	{
		int x;
		cin>>x;
		f[x].push_back(i+1);
	}

	// dbg(f);

	dfs(0,-1,adj,par);

	vector <bool> pro(n-1,false);

	for(auto qq : f)
	{
		int t=sz(qq.Y);
		if(t<=1)continue;


		unordered_map<int,int> mp;

		for(int node : qq.second)
		{
			int cur=node-1;

			while (true)
			{
				if(par[cur]==-1)break;
				int ed=mp2[{par[cur],cur}];
				// if(pro[ed])break;
				mp[ed]++;
				cur=par[cur];
			}
			
		}

		for(auto zz : mp)
		{
			if(zz.Y!=t){
				pro[zz.X]=true;
			}
		}

		// dbg(pro);

	}

	int ans=0;

	F(i,0,n-2){
		if(!pro[i])ans++;
	}

	cout<<ans;
	cout<<"\n";

}

signed main()
{

	rlimit R;
getrlimit(RLIMIT_STACK, &R);
R.rlim_cur = R.rlim_max;
setrlimit(RLIMIT_STACK, &R);

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// cout.tie(nullptr);
#ifndef ONLINE_JUDGE
freopen("b.txt","r",stdin);
freopen("output.txt","w",stdout);
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
//	parsed : 25-September-2021 23:43:57 IST