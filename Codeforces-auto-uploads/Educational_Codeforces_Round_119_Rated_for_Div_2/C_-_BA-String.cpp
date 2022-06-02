#include<bits/stdc++.h>
using namespace std;

#define int long long

void fun(vector<int> &v,vector<int> &ans,int x,int t){
	assert(x>0);
	if(x==1)return;
	int p=1;
	for(int i=t-1;i>=0;i--){
		int k = (x+p-1)/p;
		if(v[i]<k){
			p*=v[i];
			continue;
		}
		assert(k>0);
		assert((k-1)*p<x);
		ans[i]=k-1;
		fun(v,ans,x-(k-1)*p,t);
		return;
	}
	assert(false);
}

void solve(){
	int n,k,x;
	cin>>n>>k>>x;
	string s;
	cin>>s;
	vector<int> v;
	s+='a';
	int cur=0;
	for(int i=0;i<=n;i++){
		if(s[i]!='*'){
			if(cur>0)v.push_back(k*cur+1);
			cur=0;
		}else cur++;
	}
	int t=v.size();
	vector<int> ans(t);
	fun(v,ans,x,t);
	
	string z="";
	int ind=0;
	for(int i=0;i<=n;i++){
		if(s[i]=='*')continue;
		if(i!=0 && s[i-1]=='*'){
			while(ans[ind]--)z+='b';
			ind++;
		}
		z+='a';
	}
	z.pop_back();
	cout<<z<<"\n";
}

signed main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}