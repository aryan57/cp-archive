/**
 *    author:  Aryan Agarwal
 *    created: 07.06.2022 20:32:23 IST
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
	int n,k;
	cin>>n>>k;
	vector <int> cnt(k);
	int sum=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		sum+=(x/k);
		cnt[x%k]++;
	}
	int l=0,r=k-1;
	while (l<r){
		// dbg(l,r,sum);
		if(l+r<k){
			// if(cnt[l]<cnt[r])l++;
			// else r--;
			l++;
		}else{
			if(cnt[l]>cnt[r]){
				sum+=cnt[r];
				cnt[l]-=cnt[r];
				cnt[r]=0;
				r--;
			}else{
				sum+=cnt[l];
				cnt[r]-=cnt[l];
				cnt[l]=0;
				l++;
			}
		}
		// dbg(cnt);
	}
	// dbg(cnt,sum);
	for(int i=(k+1)/2;i<k;i++){
		sum+=cnt[i]/2;
	}
	cout<<sum<<"\n";
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