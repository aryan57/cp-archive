/**
 *    author:  Aryan Agarwal
 *    created: 18.06.2022 15:47:01 IST
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

const int M  = 1e9 + 7;

void solve()
{
	int n;
	cin>>n;
	vector <int> a(n),b(n);

	int sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=(2*n*a[i])%M;
		sum%=M;
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
		b[i]-=a[i];
	}

	sort(b.begin(),b.end(),greater<>());



	for(int i=0;i<n;i++){
		int t=(2*(n-i)-1)*b[i];
		t%=M;
		t+=M;
		t%=M;
		sum+=t;
		sum%=M;
	}

	cout<<sum;
	cout<<"\n";
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