/*
	group : CodeDrills - ICPC Amritapuri 2020 Preliminary Round
	name : Express the Number.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Express_the_Number.cpp
	url : https://codedrills.io/contests/icpc-amritapuri-2020-preliminary-round/problems/express-the-number
*/
/*
	author : aryan57
	created : 07-August-2021 18:51:15 IST
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

void solve_LOL()
{
	int n,x;
	cin>>n>>x;

	if(n%2 && x==0){
		cout<<"-1\n";
		return;
	}

	int use=0;

	if(n%2){
		n--;
		x--;
		use=1;
	}
	multiset<int> v;
	
	for(int bit=31;bit>=1;bit--){
		if((n>>bit)&1){
			if(bit%2==1){
				v.insert((int)pow(2,bit));
			}else{
				v.insert((int)pow(2,bit-1));
				v.insert((int)pow(2,bit-1));
			}
		}
	}

	while (sz(v)>=1)
	{
		int k=*v.begin();
		v.erase(v.begin());
		// int k2=*v.begin();
		// v.erase(v.begin());

		if(k<=x){
			x-=k;
			use=1;
		}else{
			v.insert(k);
			// v.insert(k2);
			break;
		}
	}
	

	cout<<v.size()+use<<"\n";
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
//	parsed : 07-August-2021 18:49:28 IST