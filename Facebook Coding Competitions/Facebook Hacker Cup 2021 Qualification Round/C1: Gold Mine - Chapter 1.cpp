/*
	group : Facebook Coding Competitions - Facebook Hacker Cup 2021 Qualification Round
	name : C1: Gold Mine - Chapter 1.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C1_Gold_Mine_Chapter_1.cpp
	url : https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/C1
*/
/*
	author : aryan57
	created : 30-August-2021 20:21:34 IST
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

const int mxn = 50;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);


vector<int> adj[mxn+1];
int deg[mxn+1]={};
vector <int>  val(mxn+1);
int c[mxn+1]={};
int ans;
int dfs(int u,int p=-1){

	val[u]+=c[u];

	priority_queue<int> m;

	for(int to : adj[u]){
		if(to==p)continue;
		m.push(dfs(to,u));
	}

	if(u==1){
		ans=0;
		int k=2;
		while(!m.empty() && k>0){
			k--;
			ans+=m.top();
			m.pop();
		}
	}
	else{
		if(!m.empty())val[u]+=m.top();
	}
	return val[u];
}

void solve_GOOGLE()
{
	int n;
	cin>>n;

	for(int i=0;i<=n;i++){
		adj[i].clear();
		deg[i]=0;
		val[i]=0;
		c[i]=0;
	}

	for(int i=1;i<=n;i++){
		cin>>c[i];
	}

	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}

	dfs(1);


	cout<<ans+c[1];
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
//	parsed : 30-August-2021 20:21:26 IST