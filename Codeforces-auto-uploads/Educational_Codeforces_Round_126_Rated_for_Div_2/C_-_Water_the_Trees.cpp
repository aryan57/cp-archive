#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mxn = 32768;
const int inf = 2e18;

int fun(vector<int> &a,int a1,int a2){
	int l=0;
	int r=inf;
	int ans=inf;
	auto mx = *max_element(a.begin(),a.end());
	while(l<=r){
		int k=(l+r)/2;
		int c[3]={};
		c[1]=(k+a1)/2;
		c[2]=(k+a2)/2;
		
		int req[3]={};
		
		for(int x : a){
			x=mx-x;
			
			int zz=min(x/2,c[2]);
			c[2]-=zz;
			x-=2*zz;
			
			if(x==1){
				x--;
				c[1]--;
			}else{
				req[1]+=x;
			}
		}
		
		if(c[1]<0 || req[1]>c[1]){
			l=k+1;
		}else{
			ans=min(ans,k);
			r=k-1;
		}
	}
	return ans;

}

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	int mx=0;
	for(int &x : a){
		cin>>x;
		mx=max(mx,x);
	}
	
	int ans=fun(a,1,0);
	auto it = max_element(a.begin(),a.end());
	(*it)++;
	ans=min(ans,1+fun(a,0,1));
	
	cout<<ans<<"\n";
}

signed main(){
	int _t=1;
	cin>>_t;
	while(_t--){
		solve();
	}
	return 0;
}


