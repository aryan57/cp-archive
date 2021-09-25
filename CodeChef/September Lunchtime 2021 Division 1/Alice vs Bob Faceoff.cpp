/*
	group : CodeChef - September Lunchtime 2021 Division 1
	name : Alice vs Bob Faceoff.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Alice_vs_Bob_Faceoff.cpp
	url : https://www.codechef.com/LTIME100A/problems/ALBOFACE
*/
/*
	author : aryan57
	created : 25-September-2021 18:49:10 IST
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

bool f(int n)
{
	if(n==1)return true;
	if(n==2)return false;
	if(n==3)return true;
	if(n==4)return true;

	if(n%2)return true^f(n-1);

	if(n%4==0)return true;
	return true^f(n/2);
}

void solve_LOL()
{
	int n;
	cin>>n;

	bool w=f(n);

	if(w)cout<<"Alice\n";
	else cout<<"Bob\n";
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
		// cout<<"Case #"<<i<<": ";
		solve_LOL();
	}
	return 0;
}