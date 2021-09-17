/*
	group : Google Coding Competitions - Round D 2019 - Kick Start 2019
	name : Latest Guests.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Latest_Guests.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/0000000000051061/0000000000161427
*/
/*
	author : aryan57
	created : 17-September-2021 20:22:08 IST
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

// #define int long long
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
	int n,g,m;
	cin>>n>>g>>m;

	vector< vector<vector <int> > > v(2,vector <vector <int> > (n));
	vector< vector<int> > cnt(2,vector <int> (n,0));

	for(int i=0;i<g;i++)
	{
		int p;cin>>p;
		char c;cin>>c;

		p--;

		if(c=='A')
		{
			p-=m;
			p%=n;
			p+=n;
			p%=n;
			v[0][p].push_back(i);
		}
		else
		{
			p+=m;
			p%=n;
			v[1][p].push_back(i);
		}
	}

	vector <int> ans(g,0);
	vector <int> left(n),right(n);

	{
		int i=0;
		int tot=0;
		int prev=-1;
		while (tot<=2*n)
		{
			if(!v[0][i].empty())prev=i;
			left[i]=prev;
			i++;
			i%=n;
			tot++;
		}
	}
	{
		int i=0;
		int tot=0;
		int prev=-1;
		while (tot<=2*n)
		{
			if(!v[1][i].empty())prev=i;
			right[i]=prev;
			i--;
			i%=n;
			i+=n;
			i%=n;
			tot++;
		}
	}

	// dbg(left,right);
	

	for(int i=0;i<n;i++)
	{
		// assert(left[i]!=-1 && right[i]!=-1);
		bool ol=true;
		bool orr=true;
		if(left[i]==-1)ol=false;
		if(right[i]==-1)orr=false;

		int l=(n+i-left[i])%n;
		int r=(n+right[i]-i)%n;

		if(l>m || (l>r && right[i]!=-1))ol=false;
		if(r>m || (r>l && left[i]!=-1))orr=false;

		// dbg(i,l,r,ol,orr);

		if(ol)cnt[0][left[i]]++;
		if(orr)cnt[1][right[i]]++;
	}

	for(int i : {0,1})
	{
		for(int j=0;j<n;j++)
		{
			for(int node : v[i][j])
			{
				ans[node]+=cnt[i][j];
			}
		}
	}

	for(int x : ans)cout<<x<<" ";
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
//	parsed : 17-September-2021 19:39:08 IST