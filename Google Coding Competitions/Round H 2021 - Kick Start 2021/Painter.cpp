/*
	group : Google Coding Competitions - Round H 2021 - Kick Start 2021
	name : Painter.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Painter.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435914/00000000008d9a88
*/
/*
	author : aryan57
	created : 14-November-2021 08:40:27 IST
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

int f(string s)
{
	int n= sz(s);

	vector <bool> r(n+1);
	vector <bool> b(n+1);
	vector <bool> y(n+1);

	F(i,0,n-1)
	{
		if(s[i]=='R' || s[i]=='O' || s[i]=='P' || s[i]=='A')r[i]=true;
		if(s[i]=='B' || s[i]=='G' || s[i]=='P' || s[i]=='A')b[i]=true;
		if(s[i]=='Y' || s[i]=='O' || s[i]=='G' || s[i]=='A')y[i]=true;
	}

	int cnt=0;

	F(i,1,n)
	{
		if(!r[i] && r[i-1])cnt++;
		if(!b[i] && b[i-1])cnt++;
		if(!y[i] && y[i-1])cnt++;
	}

	return cnt;
}

void solve_GOOGLE()
{
	int n;
	cin>>n;

	string s;
	cin>>s;
	s+='U';
	string cur="";
	int cnt=0;
	for(char x : s){
		if(x=='U'){
			if(!cur.empty())cnt+=f(cur);
			cur="";
		}else{
			cur+=x;
		}
	}

	cout<<cnt;
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
//	parsed : 14-November-2021 08:40:23 IST