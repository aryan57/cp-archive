/**
 *    author:  Aryan Agarwal
 *    created: 25.06.2022 22:17:47 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void solve()
{
	int n;
	cin>>n;
	vector <int> a(n+1);
	for(int &x : a)cin>>x;

	int z=12;

	vector <int> temp(z);
	temp[0]=1;

	int k=11;
	int ind=0;
	int sum=0;
	while (ind<=n)
	{
		for(int i=0;i<a[ind];i++){
			sum+=temp[i];
		}
		dbg(temp,sum);

		for(int i=z-1;i>=0;i--){
			for(int j=i-1;j>=0;j--)temp[i]+=temp[j];
		}
		ind++;
	}
	

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