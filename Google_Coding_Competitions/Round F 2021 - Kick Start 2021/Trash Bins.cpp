/*
	group : Google Coding Competitions - Round F 2021 - Kick Start 2021
	name : Trash Bins.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Trash_Bins.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435bae/0000000000887c32
*/
/*
	author : aryan57
	created : 18-September-2021 22:31:32 IST
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
	int n;
	cin>>n;
	string s;
	cin>>s;

	vector <int> left(n);
	vector <int> right(n);

	int last=-1;

	F(i,0,n-1)
	{
		if(s[i]=='1')last=i;
		left[i]=last;
	}
	last=-1;
	RF(i,n-1,0)
	{
		if(s[i]=='1')last=i;
		right[i]=last;
	}

	int ans=0;
	F(i,0,n-1)
	{
		if(left[i]==-1)ans+=abs(i-right[i]);
		else if(right[i]==-1)ans+=abs(i-left[i]);
		else ans+=min(abs(i-right[i]),abs(i-left[i]));
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
//	parsed : 18-September-2021 22:30:16 IST