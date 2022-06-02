/**
 *    author:  Aryan Agarwal
 *    created: 15.05.2022 23:15:35 IST
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
	int x,d;
	cin>>x>>d;

	int pw=0;
	while(x%d==0){
		x/=d;
		pw++;
	}
	if(pw<2){
		cout<<"NO\n";
		return;
	}

	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			cout<<"YES\n";
			return;
		}
	}

	if(pw==2){
		cout<<"NO\n";
		return;
	}

	for(int i=2;i*i<=d;i++){
		if(d%i==0){
			if(pw>3 || ((x*i)%d) || ((x*(d/i))%d)){
				cout<<"YES\n";
				return;
			}
		}
	}
	cout<<"NO\n";
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