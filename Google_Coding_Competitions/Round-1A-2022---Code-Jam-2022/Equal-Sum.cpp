/*
	group : Google Coding Competitions - Round 1A 2022 - Code Jam 2022
	name : Equal Sum.cpp
	srcPath : /home/aryan/cp-workspace/Equal_Sum.cpp
	url : https://codingcompetitions.withgoogle.com/codejam/round/0000000000877ba5/0000000000aa8fc1
*/
/**
 *    author:  Aryan Agarwal
 *    created: 09.04.2022 07:54:32 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mxn = (int)1e9;

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
	assert(n==100);
	vector <int> a;
	map<int,int> use;
	int c=0;
	for(int pw=1;pw<mxn;pw*=10){
		for(int i=1;i<=9;i++){
			a.push_back(i*pw);
			use[i*pw]=true;
			c+=i*pw;
		}
	}
	assert(a.size()<n);
	a.push_back(mxn);
	c+=mxn;
	for(int i=1;i<=200 && a.size()<n;i++){
		if(!use[i]){
			a.push_back(i);
			use[i]=true;
		}
	}

	// dbg(a);

	for(int x : a)cout<<x<<" ";
	cout<<"\n";
	fflush(stdout);
	


	
}

signed main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
//	parsed : 09-April-2022 07:33:49 IST