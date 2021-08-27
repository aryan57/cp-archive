/*
	group : Facebook Coding Competitions - Facebook Hacker Cup 2021 Qualification Round
	name : A1: Consistency - Chapter 1.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A1_Consistency_Chapter_1.cpp
	url : https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/A1
*/
/*
	author : aryan57
	created : 28-August-2021 00:40:11 IST
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

bool vow(int i){
	return (i==0 || i==4 || i==8 || i=='o'-'a' || i=='u'-'a');
}

void solve_GOOGLE()
{
	string s;
	cin>>s;

	int ans=INF;

	int n=sz(s);

	F(i,0,25){

		int z=0;

		F(j,0,n-1){
			if(i==s[j]-'A')continue;
			if(vow(i)^vow(s[j]-'A'))z+=1;
			else z+=2;
		}

		ans=min(ans,z);
	}

	cout<<ans<<"\n";
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
//	parsed : 28-August-2021 24:29:29 IST