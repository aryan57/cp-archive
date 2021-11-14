/*
	group : Codeforces - Codeforces Round #755 (Div. 2, based on Technocup 2022 Elimination Round 2)
	name : D. Guess the Permutation.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Guess_the_Permutation.cpp
	url : https://codeforces.com/contest/1589/problem/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 14.11.2021 12:19:44 IST
**/
#include <bits/stdc++.h>
using namespace std;

// #define int long long

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
	cout<<"? 1 "<<n<<endl;
	int tot;
	cin>>tot;

	int mn=n;

	int i=-1;
	int j=-1;
	int k=-1;

	int l=2;
	int r=n-2;

	while (l<=r)
	{
		int m = (l+r)/2;
		cout<<"? 1 "<<m<<endl;
		int x;
		cin>>x;
		assert(x!=-1);
		if(x==tot){
			mn=min(mn,m);
		}
		if(x==0){
			l=m+1;
		}else{
			i=m-1;
			r=m-1;
		}
	}

	assert(i>=1 && i<=n-3);

	int x1,x2;
	cout<<"? "<<i<<" "<<n<<endl;
	cin>>x1;
	cout<<"? "<<i+1<<" "<<n<<endl;
	cin>>x2;
	j=x1-x2+i+1;

	assert(j>=i+2 && j<=n-1);

	cout<<"? "<<j<<" "<<n<<endl;
	cin>>x1;
	cout<<"? "<<j+1<<" "<<n<<endl;
	cin>>x2;
	k=x1-x2+j;

	assert(k>j && k<=n);

	cout<<"! "<<i<<" "<<j<<" "<<k<<endl;
}

signed main()
{
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 14-November-2021 12:19:38 IST