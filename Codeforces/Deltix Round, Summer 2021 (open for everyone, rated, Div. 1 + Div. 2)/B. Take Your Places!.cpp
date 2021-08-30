/*
	group : Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
	name : B. Take Your Places!.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Take_Your_Places_.cpp
	url : https://codeforces.com/contest/1556/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 29.08.2021 20:10:56 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 2e18;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

int f(vector<int> v,int o,int e){

	priority_queue<int,vector<int>,greater<int>> s[2];
	int n = v.size();

	for(int i=0;i<n;i++){
		s[v[i]].push(i);
	}

	int ans=0;

	for(int i=0;i<n;i++){

		int a=o;
		if(i%2==0)a=e;

		if(v[i]==a)continue;

		while(!s[a].empty() && s[a].top()<=i){
			s[a].pop();
		}

		if(s[a].empty()){
			return INF;
		}

		int j = s[a].top();

		ans+= (j-i);

		s[a].pop();
		while(!s[1^a].empty() && s[1^a].top()<=i){
			s[1^a].pop();
		}
		s[1^a].push(j);

		v[j]^=1;
		v[i]^=1;
	}

	return ans;

}

void solve()
{
	int n;
	cin>>n;

	vector<int> v(n);

	for(int &x : v){
		cin>>x;
		x%=2;
	}

	int ans=INF;
	ans=min(ans,f(v,0,1));
	ans=min(ans,f(v,1,0));
	if(ans==INF)ans=-1;

	cout<<ans;
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 29-August-2021 20:08:50 IST