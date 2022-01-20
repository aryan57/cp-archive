/*
	group : Codeforces - Codeforces Round #764 (Div. 3)
	name : D. Palindromes Coloring.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Palindromes_Coloring.cpp
	url : https://codeforces.com/contest/1624/problem/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 10.01.2022 20:32:30 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,k;
bool check2(int m,vector <int> &cnt){
	if(m==0)return true;
	// dbg(m);
	deque<int> d;
	for(int i=1;i<=m;i++)d.push_back(k);
	while(!d.empty()){
		if(d.size()==1)return false;
		int l=d.front();
		int r=d.back();

		assert(l==r);

		d.pop_back();
		d.pop_front();
		for(int i=0;i<26;i++){
			if(cnt[i]>=l+r){
				cnt[i]-=(l+r);
				l=0;
				r=0;
				break;
			}
			l-=cnt[i]/2;
			r-=cnt[i]/2;
			cnt[i]=0;
		}

		if(l)return false;
	}
	return true;
	
}
bool check(int m,vector <int> cnt){
	if(m%2){
		m--;
		if(n-m*k>=k && check2(m,cnt))return true;
		return false;
	}
	return check2(m,cnt);	
}

void solve()
{
	cin>>n>>k;
	vector <int> cnt(26);
	string s;
	cin>>s;
	for(char x : s){
		cnt[x-'a']++;
	}

	int ans=1;
	int l=1,r=n;
	while(l<=r){

		int m=(l+r)/2;
		// dbg(l,r,m);
		if(check(m,cnt)){
			ans=max(ans,m);
			l=m+1;
		}else{
			r=m-1;
		}
	}
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
//	parsed : 10-January-2022 20:32:23 IST