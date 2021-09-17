/*
	group : Google Coding Competitions - Round D 2019 - Kick Start 2019
	name : X or What?.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/X_or_What_.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/0000000000051061/0000000000161426
*/
/*
	author : aryan57
	created : 17-September-2021 19:25:59 IST
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
	vector <bool> xo(1024);
	for(int i=0;i<1024;i++)
	{
		if(__builtin_popcount(i)%2)xo[i]=true;
	}


	int n,q;
	cin>>n>>q;

	vector <int> v(n);
	set<int> z;
	int s=0;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		s^=v[i];
		if(xo[v[i]])z.insert(i);
	}

	while (q--)
	{
		int i,p;
		cin>>i>>p;
		if(xo[v[i]])z.erase(i);
		s^=v[i];
		v[i]=p;
		s^=v[i];
		if(xo[v[i]])z.insert(i);

		if(!xo[s]){
			cout<<n<<" ";
		}else{
			assert(!z.empty());
			int mn=*z.begin();
			int mx=*z.rbegin();

			cout<<max({mn,n-mn-1,mx,n-mx-1})<<" ";
		}
	}

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