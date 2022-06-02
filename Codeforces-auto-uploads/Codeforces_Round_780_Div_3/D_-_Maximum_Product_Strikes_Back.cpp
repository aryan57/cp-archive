/**
 *    author:  Aryan Agarwal
 *    created: 09.05.2022 12:07:37 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;

pair<int,pii> fun(vector<int> &v)
{
	// for(int x : v){
	// 	cerr<<x<<", ";
	// }cerr<<"\n";
	if(v.empty())return {-1,{0,0}};


	int first[2]={};
	int last[2]={};

	int n=v.size();
	first[1]=n+1;
	last[1]=n+1;

	vector<int> cnt(n+1);

	int par=0;

	for(int i=0;i<n;i++){

		cnt[i+1]=cnt[i];
		if(abs(v[i])==2)cnt[i+1]++;
		assert(v[i]);
		if(v[i]<0)par^=1;

		if(first[par]==n+1)first[par]=i+1;
		last[par]=i+1;
	}
	for(int par : {0,1}){
		if(first[par]!=n+1)continue;
		return {cnt[last[par^1]]-cnt[first[par^1]],{first[par^1],n-last[par^1]}};
	}

	// cerr<<last[1]<<" "<<first[1]<<"^\n";

	if(cnt[last[0]]-cnt[first[0]] > cnt[last[1]]-cnt[first[1]]){
		return {cnt[last[0]]-cnt[first[0]],{first[0],n-last[0]}};
	}else{
		return {cnt[last[1]]-cnt[first[1]],{first[1],n-last[1]}};
	}
	
}
void solve()
{
	int n;
	cin>>n;
	vector<int> v;
	pii ans = {n,0};
	int cnt=0;
	int l=-1;
	for(int i=0;i<=n;i++){
		int x=0;
		if(i!=n)cin>>x;
		if(x==0){
			pair<int,pii> z = fun(v);
			// cerr<<i<<" , "<<z.first<<" "<<z.second.first<<" "<<z.second.second<<"^\n";
			if(cnt<z.first){
				cnt=z.first;
				ans={l+z.second.first,z.second.second+n-i};
			}
			v.clear();
			l=-1;
		}else{
			if(l==-1)l=i;
			v.push_back(x);
		}
	}
	cout<<ans.first<<" "<<ans.second<<"\n";
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