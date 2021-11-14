/*
	group : Google Coding Competitions - Round G 2021 - Kick Start 2021
	name : Dogs and Cats.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Dogs_and_Cats.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/00000000004362d6/00000000008b3771
*/
/*
	author : aryan57
	created : 16-October-2021 17:31:34 IST
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
	int n,d,c,m;
	cin>>n>>d>>c>>m;

	string s;
	cin>>s;

	for(int i=0;i<n;i++)
	{
		if(s[i]=='D'){
			if(d==0){
				cout<<"NO\n";
				return;
			}
			d--;
			c+=m;
		}else{
			if(c==0){
				for(int j=i+1;j<n;j++){
					if(s[j]=='D'){
						cout<<"NO\n";
						return;
					}
				}
				break;
			}else{
				c--;
			}
		}
	}

	cout<<"YES\n";
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
//	parsed : 16-October-2021 17:30:10 IST