/*
	group : Facebook Coding Competitions - Facebook Hacker Cup 2021 Round 2
	name : C1: Valet Parking - Chapter 1.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C1_Valet_Parking_Chapter_1.cpp
	url : https://www.facebook.com/codingcompetitions/hacker-cup/2021/round-2/problems/C1
*/
/*
	author : aryan57
	created : 26-September-2021 00:40:35 IST
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

int f(vector <string> &v,int k,int r,int c)
{
	vector <vector <int> > pre(c,vector <int> (r+1));
	// dbg(v);
	F(j,0,c-1)
	{
		F(i,1,r)
		{
			pre[j][i]+=pre[j][i-1];
			if(v[i-1][j]=='X')pre[j][i]++;
		}
	}

	// dbg(pre);
	int ans=INF;
	F(z,0,r-1)
	{
		int t=0;
		bool ok = true;

		F(j,0,c-1)
		{
			int prev=pre[j][min(r,k+z)];

			if(prev>k-1){
				t+=1;
			}else{
				// dbg(k,z);
				if(k+z-1<r)
				if(v[(k+z-1)][j]=='X')t++;
			}
		}

		ans=min(ans,t+z);

		// if(ans==1){
		// 	dbg(z,t);
		// }
	}

	return ans;
}

void solve_LOL()
{
	int r,c,k;
	cin>>r>>c>>k;

	vector <string> v(r);

	F(i,0,r-1){
		cin>>v[i];
	}

	int ans=f(v,k,r,c);
	reverse(all(v));
	k=r+1-k;
	// dbg(k);
	ans=min(ans,f(v,k,r,c));

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
		solve_LOL();
	}
	return 0;
}
//	parsed : 26-September-2021 24:40:32 IST