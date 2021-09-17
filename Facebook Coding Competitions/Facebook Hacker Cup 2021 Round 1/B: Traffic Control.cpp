/*
	group : Facebook Coding Competitions - Facebook Hacker Cup 2021 Round 1
	name : B: Traffic Control.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Traffic_Control.cpp
	url : https://www.facebook.com/codingcompetitions/hacker-cup/2021/round-1/problems/B
*/
/*
	author : aryan57
	created : 12-September-2021 13:09:45 IST
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
	int n,m,a,b;
	cin>>n>>m>>a>>b;

	int a1=a-(m+n-2);
	int b1=b-(m+n-2);

	if(a1<=0 || b1<=0 || a1>1000 || b1>1000){
		cout<<"Impossible\n";
		return;
	}
	cout<<"Possible\n";
	F(i,1,n)
	{
		F(j,1,m)
		{
			if(i==n && j==m)cout<<a1<<" ";
			else if(i==n && j==1)cout<<b1<<" ";
			else cout<<"1 ";
		}cout<<"\n";
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
#ifndef ONLINE_JUDGE
// freopen("input.txt","r",stdin);
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
//	parsed : 12-September-2021 13:07:43 IST