#include <bits/stdc++.h>
using namespace std;

int f(int m,int n){
	for(int c=1;c<n;c++){
		if((m+c)/n + 1 == (m+1+c)/n){
			return c;
		}
	}
	assert(false);
	return -1;
}

void solve(){
	int n;
	cin>>n;
	int l=1,r=n-1;
	while(l<r){
		int m=(l+r)/2;
		// two ranges [l,m] & [m+1,r]
		// we want to discard one
		assert(l<=m && m<r);
		
		// find any c (1,n) such that (m+c)/n + 1 = (m+1+c)/n
		int c = f(m,n);
		assert(c>0 && c<n);
		cout<<"+ "<<c<<endl;
		int val;
		cin>>val;
		
		if(val==(m+c)/n){
			// take left range
			r=m;
		}else{ // take right range
			l=m+1;
		}
		l+=c;
		r+=c;
	}
	
	assert(l==r);
	cout<<"! "<<l<<endl;
}

signed main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
