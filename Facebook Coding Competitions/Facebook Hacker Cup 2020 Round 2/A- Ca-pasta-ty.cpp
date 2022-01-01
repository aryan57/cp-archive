/*
	group : Facebook Coding Competitions - Facebook Hacker Cup 2020 Round 2
	name : A: Ca-pasta-ty.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Ca_pasta_ty.cpp
	url : https://www.facebook.com/codingcompetitions/hacker-cup/2020/round-2/problems/A
*/
/*
	author : aryan57
	created : 25-September-2021 14:19:15 IST
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
	int n,k;
	cin>>n>>k;

	vector <int> s(n),x(n),y(n);

	vector< vector<int> > q(3,vector <int> (4));

	F(i,0,k-1){
		cin>>s[i];
	}

	F(j,0,3){
		cin>>q[0][j];
	}
	F(i,0,k-1){
		cin>>x[i];
	}

	F(j,0,3){
		cin>>q[1][j];
	}
	F(i,0,k-1){
		cin>>y[i];
	}

	F(j,0,3){
		cin>>q[2][j];
	}

	F(i,k,n-1){
		s[i]=(q[0][0]*s[i-2]+q[0][1]*s[i-1]+q[0][2])%q[0][3];
		x[i]=(q[1][0]*x[i-2]+q[1][1]*x[i-1]+q[1][2])%q[1][3];
		y[i]=(q[2][0]*y[i-2]+q[2][1]*y[i-1]+q[2][2])%q[2][3];
	}

	int ans=0;
	int d=0;
	int u=0;

	F(i,0,n-1)
	{
		if(s[i]<x[i]){
			d+=x[i]-s[i];
			s[i]=x[i];
		}else if(s[i]>x[i]+y[i]){
			u+=s[i]-(x[i]+y[i]);
			s[i]=x[i]+y[i];
		}
	}

	if(d==u){
		cout<<d;
		cout<<"\n";
		return;
	}

	if(d>u)
	{
		int extra=0;
		F(i,0,n-1)
		{
			extra+=s[i]-x[i];
			if(extra+u>=d){
				cout<<d;
				cout<<"\n";
				return;
			}
		}

		cout<<"-1\n";
	}else{

		int extra=0;
		F(i,0,n-1)
		{
			extra+=-s[i]+x[i]+y[i];
			if(extra+d>=u){
				cout<<u;
				cout<<"\n";
				return;
			}
		}

		cout<<"-1\n";
	}


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
//	parsed : 25-September-2021 14:19:08 IST