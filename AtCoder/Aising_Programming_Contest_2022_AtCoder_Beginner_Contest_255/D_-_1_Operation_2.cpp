/**
 *    author:  Aryan Agarwal
 *    created: 11.06.2022 17:58:04 IST
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
	int n,q;
	cin>>n>>q;
	vector <int> a(n);
	for(int &x : a)cin>>x;

	sort(a.begin(),a.end());
	vector <int> pre(n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i-1];
	}
	while (q--)
	{
		int x;
		cin>>x;
		int i = lower_bound(a.begin(),a.end(),x)-a.begin();
		i--;
		
		int left = 0;
		if(i>=0){
			left=(i+1)*x - pre[i+1];
		}

		int j = upper_bound(a.begin(),a.end(),x)-a.begin();
		int right = 0;
		if(j!=n){
			right = pre[n]-pre[j] - (n-j)*x;
		}
		// dbg(left,right,i,j);
		cout<<left+right<<"\n";
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