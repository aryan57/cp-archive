/*
	group : Facebook Coding Competitions - Facebook Hacker Cup 2021 Round 2
	name : A: Runway.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Runway.cpp
	url : https://www.facebook.com/codingcompetitions/hacker-cup/2021/round-2/problems/A
*/
/*
	author : aryan57
	created : 25-September-2021 22:52:29 IST
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
	int n,m;
	cin>>n>>m;

	unordered_map<int,pair <int,int> > mp;

	F(i,0,m-1){
		int x;
		cin>>x;
		mp[x].X++;
		mp[x].Y++;
	}
	int ans=0;
	F(i,0,n-1)
	{
		int z=0;
		unordered_map<int,int > mp2;
		F(j,0,m-1)
		{
			int x;
			cin>>x;
			mp2[x]++;
		}

		for(auto x : mp2)
		{
			int s=x.X;
			int cnt=x.Y;

			int cs=mp[s].X-min(mp[s].X,cnt);
			int us=mp[s].Y;
			mp[s].Y-=min(cs,us);
			z+=cs-min(cs,us);
			mp[s].X=cnt;
		}

		ans+=z;
	}

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
//	parsed : 25-September-2021 22:30:33 IST