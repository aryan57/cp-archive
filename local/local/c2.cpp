/*
	group : local
	name : c2.cpp
	srcPath : /home/aryan/Dropbox/Documents from PC/free/marwah/ass/c2.cpp
	url : /home/aryan/Dropbox/Documents from PC/free/marwah/ass/c2.cpp
*/
/**
 *    author:  Aryan Agarwal
 *    created: 22.03.2022 12:47:20 IST
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

int fun(int a,int b){
	if(a<b){
		int c=b;
		b=a;
		a=c;
	}
	while (b!=0)
	{
		int c=a%b;
		dbg(a,b,c);
		a=b;
		b=c;
	}
	return a;
	
}

void solve()
{
	cout<<fun(17,17)<<"\n";
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