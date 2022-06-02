/**
 *    author:  Aryan Agarwal
 *    created: 10.05.2022 12:27:43 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M = 1e9 + 7;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ARYAN_SIEVE  
const int mxn_sieve = 5e6;

int spf[mxn_sieve + 1]; // spf -> smallest prime factor
// if spf[x]==x ,then x is prime
void sieve()
{
	spf[1] = 1;
	for (int i = 2; i <= mxn_sieve; i++)
		spf[i] = i;

	for (int i = 4; i <= mxn_sieve; i += 2)
		spf[i] = 2;

	for (int i = 3; i * i <= mxn_sieve; i++)
	{
		if (spf[i] == i)
		{
			for (int j = i * i; j <= mxn_sieve; j += i)
				if (spf[j] == j)
					spf[j] = i;
		}
	}
}

void solve()
{
	sieve();

	int t,l,r;
	cin>>t>>l>>r;

	vector<int> dp(r+1);

	for(int i=2;i<=r;i++)dp[i]=(i*(i-1))/2;

	for(int j=2;j<=r;j++){
		int i = j/spf[j];
		dp[j] = min(dp[j],dp[i] + (j*(j-i))/(2*i));
	}

	int ans=0;
	int pw=1;
	for(int i=l;i<=r;i++){
		dp[i]%=M;
		ans+=(dp[i]*pw)%M;
		ans%=M;
		pw*=t;
		pw%=M;
	}
	cout<<ans;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}