/*
	group : Google Coding Competitions - Round A 2022 - Kick Start 2022
	name : Interesting Integers.cpp
	srcPath : /home/aryan/cp-workspace/Interesting_Integers.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb33e/00000000009e73ea
*/
/**
 *    author:  Aryan Agarwal
 *    created: 20.03.2022 10:00:40 IST
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
	int a,b;
	cin>>a>>b;
	int cnt=0;
	for(int k=a;k<=b;k++){
		int sum=0;
		int d=k;
		while (d)
		{
			sum+=d%10;
			d/=10;
		}
		d=k;
		int p=1;
		p%=sum;
		bool ok =true;
		vector <int> v(10);
		while (d)
		{
			p*=(d%10);
			if(d%10==0)ok=false;
			v[d%10]++;
			p%=sum;
			d/=10;
		}
		
		if(p==0){
			cnt++;
			// dbg(v[9],v[8]);
			// dbg(k);
		}
		cout<<cnt<<", ";
	}
	cout<<cnt;cout<<"\n";
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
//	parsed : 20-March-2022 10:00:30 IST