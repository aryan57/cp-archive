/*
	group : Codeforces - Codeforces Round #764 (Div. 3)
	name : E. Masha-forgetful.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_Masha_forgetful.cpp
	url : https://codeforces.com/contest/1624/problem/E
*/
/**
 *    author:  Aryan Agarwal
 *    created: 10.01.2022 21:36:18 IST
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

struct pos{
	int l=-1,r=-1,i=-1;
};

void solve()
{
	int n,m;
	cin>>n>>m;

	vector<pos> v(100);
	vector<pos> v2(1000);
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=1;j<m;j++){
			v[10*(s[j-1]-'0')+s[j]-'0'] = {j,j+1,i+1};
			if(j!=1)v2[100*(s[j-2]-'0') + 10*(s[j-1]-'0')+s[j]-'0'] = {j-1,j+1,i+1};
		}
	}

	vector<pos> ans;
	cin>>s;

	// if(s.size()==2){

	// }

	if(m==1){
		cout<<"-1\n";
		return;
	}
	int tot=0;
	for(int j=0;j<m;j++){
		if(j+1<m){
			int num = 10*(s[j]-'0')+s[j+1]-'0';
			dbg(num);
			if(v[num].i!=-1){
				tot+=2;
				ans.push_back(v[num]);
				j+=1;
				continue;
			}

		}
		if(ans.empty() || j<2){
			cout<<"-1\n";
			return;
		}
		if(ans.back().r-ans.back().l+1!=2){
			cout<<"-1\n";
			return;
		}
		tot-=2;
		ans.pop_back();
		int num = 100*(s[j-2]-'0') + 10*(s[j-1]-'0')+s[j]-'0';
		dbg(j,num);
		if(v2[num].i!=-1){
			tot+=3;
			ans.push_back(v2[num]);
			continue;
		}
		cout<<"-1\n";
		return;
	}

	if(tot!=m){
		cout<<"-1\n";
		return;
	}
	cout<<ans.size()<<"\n";
	for(auto k : ans){
		cout<<k.l<<" "<<k.r<<" "<<k.i<<"\n";
	}

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
//	parsed : 10-January-2022 21:21:54 IST