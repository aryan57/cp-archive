/*
	group : Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
	name : C. Compressed Bracket Sequence.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Compressed_Bracket_Sequence.cpp
	url : https://codeforces.com/contest/1556/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 29.08.2021 20:28:02 IST
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

	vector<int> v(n);

	for(int &x : v){
		cin>>x;
	}

	int ans=0;

	for(int i=0;i<n;i+=2){
		int s=0;
		int mxx=0;
		for(int j=i+1;j<n;j++){
			if(j%2==0){
				s+=v[j];
				continue;
			}
			// dbg(i,j);
			int  l =1-s;
			int  r =v[j]-s;
			l=max(l,mxx);
			int l2=1;
			int r2=v[i];

			int tot = min(r2,r)-max(l2,l)+1;

			// if(i==0){
			// 	dbg(l,r);
			// 	dbg(l2,r2);
			// 	dbg(tot,s);
			// }

			if(tot>=0){
				ans+=tot;
			}

			s-=v[j];
			mxx=max(mxx,-s);
			if(s+v[i]<0)break;
		}
	}

	cout<<ans;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 29-August-2021 20:27:01 IST