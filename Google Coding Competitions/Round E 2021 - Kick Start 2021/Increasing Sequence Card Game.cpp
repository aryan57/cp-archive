/*
	group : Google Coding Competitions - Round E 2021 - Kick Start 2021
	name : Increasing Sequence Card Game.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Increasing_Sequence_Card_Game.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/000000000043585c/000000000085a709
*/
/*
	author : aryan57
	created : 22-August-2021 10:35:44 IST
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

	int n=10;
	// cin>>n;

	if(n>10){
		cout<<0;
		cout<<"\n";
		return;
	}

	vector <int> v(n);
	iota(all(v),1);
	int cnt[11]={};
	do{

		int z=1;
		int pre=v[0];

		F(i,1,n-1){
			if(v[i]>pre){
				pre=v[i];
				z++;
			}
		}

		cnt[z]++;

	}while(next_permutation(all(v)));
	int p=1;
	int s=0;
	F(i,1,n){
		dbg(i,cnt[i]);
		s+=i*cnt[i];
		p*=i;
	}

	long double ans=s;
	ans/=p;

	cout<<ans;cout<<"\n";
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
	cout<<fixed<<setprecision(10);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve_GOOGLE();
	}
	return 0;
}
//	parsed : 22-August-2021 10:07:33 IST