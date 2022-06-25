/**
 *    author:  Aryan Agarwal
 *    created: 25.06.2022 20:08:58 IST
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
	int n,z;
	cin>>n>>z;
	vector <int> a(n);
	for(int &x : a)cin>>x;
	int cnt=0;
	while (true)
	{
		int i=0;
		int mx=(a[0]|z);

		for(int j=0;j<n;j++){
			if(mx < (a[j]|z)){
				mx = (a[j]|z);
				i=j;
			}
		}

		int x=a[i];
		int y=z;

		if(a[i]==(x|y))break;

		a[i]=(x|y);
		z=(x&y);

		// dbg(a,x,y);
		// if(cnt++==5)break;
	}

	cout<<*max_element(a.begin(),a.end())<<"\n";
	
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