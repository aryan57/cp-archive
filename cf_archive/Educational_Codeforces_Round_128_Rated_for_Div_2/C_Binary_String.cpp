/**
 *    author:  Aryan Agarwal
 *    created: 13.05.2022 20:18:47 IST
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

const int inf = 2e18;

void solve()
{
	string s;
	cin>>s;

	int n=s.size();
	vector<vector<int>> pre(2,vector<int>(n+2));
	int tot=0;
	int ans = inf;
	for(int i=1;i<=n+1;i++){
		pre[0][i]+=pre[0][i-1];
		pre[1][i]+=pre[1][i-1];

		if(i<=n){

			pre[s[i-1]-'0'][i]++;
			if(s[i-1]=='1')tot++;
		}
	}

	int l=0,r=n+1;
	while(l<=r){
		int t = (l+r)/2;

		bool ok = false;
		for(int j=0;j<=n;j++){
			int ind1 = lower_bound(pre[0].begin(),pre[0].end(),pre[0][j]-t)-pre[0].begin();
			int ind2 = upper_bound(pre[1].begin(),pre[1].end(),t+pre[1][j]-tot)-pre[1].begin();
			ind2--;
			

			if(ind1<j && ind1<=ind2){
				ok=true;
				break;
			}
			// if(t==0 && j==0){
			// 	dbg(ind1,ind2);
			// 	dbg(t+pre[1][j]-tot);
			// }
		}

		if(ok){
			ans=min(ans,t);
			r=t-1;
		}else{
			l=t+1;
		}
	}

	ans=min(ans,n-tot);
	ans=min(ans,tot);

	// if(ans==inf)ans=0;

	cout<<ans<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}