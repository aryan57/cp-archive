/**
 *    author:  Aryan Agarwal
 *    created: 28.11.2021 20:07:20 IST
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
	vector <int> v(n);
	for(int &x : v){
		cin>>x;
	}

	int ans=0;

	for(int i=0;i<n;i++){
		vector <int> t(v);
		int s=0;
		for(int j=0;j<n;j++){
			if(i==j)continue;
			while (t[j]%2==0)
			{
				t[j]/=2;
				t[i]*=2;
			}
		}
		ans=max(ans,accumulate(t.begin(),t.end(),0ll));
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 28-November-2021 20:05:40 IST