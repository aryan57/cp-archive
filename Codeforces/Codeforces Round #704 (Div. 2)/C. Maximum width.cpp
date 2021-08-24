/*
	group : Codeforces - Codeforces Round #704 (Div. 2)
	name : C. Maximum width.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Maximum_width.cpp
	url : https://codeforces.com/contest/1492/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 24.08.2021 19:43:00 IST
**/
#include <bits/stdc++.h>
using namespace std;

// #define int long long

int n,m;
vector<int> fun(string s,string t){

	vector<int> ans(m);
	int ind=0;

	int i=0;
	int j=0;

	while(i<m && j<n && ind<m){
		if(t[i]==s[j]){
			ans[ind++]=j;
			i++;
			j++;
			continue;
		}
		j++;
	}
	return ans;
}

void solve()
{
	cin>>n>>m;

	string s,t;
	cin>>s>>t;

	vector<int> p1=fun(s,t);
	reverse(t.begin(),t.end());
	reverse(s.begin(),s.end());
	vector<int> p2=fun(s,t);
	reverse(p2.begin(),p2.end());

	for(int &x : p2){
		x=n-x;
	}
	
	int ans=0;
	for(int i=1;i<m;i++){
		ans=max(ans,p2[i]-p1[i-1]-1);
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
//	parsed : 24-August-2021 19:38:37 IST