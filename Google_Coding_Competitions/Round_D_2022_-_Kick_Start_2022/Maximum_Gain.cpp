/**
 *    author:  Aryan Agarwal
 *    created: 10.07.2022 10:49:14 IST
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
	int tot1=0;
	int tot2=0;
	vector <int> v(n);
	for(int &x : v){
		cin>>x;
		tot1+=x;
	}
	int m;
	cin>>m;
	vector <int> t(m);
	for(int &x : t){
		cin>>x;
		tot2+=x;
	}
	int k;
	cin>>k;

	int inf = 2e18;
	int bad = n+m-k;
	vector <int> mn1(bad+1,inf);
	mn1[0]=0;

	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			sum+=v[j];
			int len = j-i+1;
			if(len>bad)break;
			mn1[len]=min(mn1[len],sum);
		}
	}
	vector <int> mn2(bad+1,inf);
	mn2[0]=0;

	for(int i=0;i<m;i++){
		int sum=0;
		for(int j=i;j<m;j++){
			sum+=t[j];
			int len = j-i+1;
			if(len>bad)break;
			mn2[len]=min(mn2[len],sum);
		}
	}

	// dbg(mn);

	int ans=0;

	for(int l=0;l<=bad;l++){
		int sum=0;
		sum+=tot1-mn1[l];
		sum+=tot2-mn2[bad-l];
		ans=max(ans,sum);
	}


	cout<<ans;
	cout<<"\n";


}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}