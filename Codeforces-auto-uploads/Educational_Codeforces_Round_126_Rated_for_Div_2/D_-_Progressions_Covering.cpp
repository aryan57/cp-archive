#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> b(n);
	for(int &x : b){
		cin>>x;
	}
	
	int adder=0;
	int sum=0;
	int ans=0;
	
	int kk=k;
	deque<int> d;
	
	for(int i=n-1;i>=0;i--){
		if(i<k-1)k--;
		int z = (b[i]+sum+k-1)/k;
		if(b[i]+sum<=0)z=0;
		
		ans+=z;
		
		d.push_back(z);
		adder+=z;
		
		if(d.size()>kk){
			adder-=d.front();
			d.pop_front();
		}
		
		sum-=z*k;
		
		
		sum+=adder;
		
		
		//cout<<i<<",  "<<k<<", "<<", "<<sum<<", "<<adder<<", "<<z<<" | "<<ans<<"\n";
	}
	cout<<ans<<"\n";
}

signed main(){
	int _t=1;
	//cin>>_t;
	while(_t--){
		solve();
	}
	return 0;
}


