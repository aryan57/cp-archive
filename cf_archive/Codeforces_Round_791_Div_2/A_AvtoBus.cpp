/**
 *    author:  Aryan Agarwal
 *    created: 14.05.2022 15:08:04 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	if(n%2){
		cout<<"-1\n";
		return;
	}
	n/=2;
	int mn=-1;
	int mx=-1;

	if(n%2==0){
		mn=n/2;
		mx=n/2;
	}
	if(n%3==0){
		if(mn==-1){
			mn=n/3;
			mx=n/3;
		}else{
			mn=min(mn,n/3);
			mx=max(mx,n/3);
		}
	}
	
	for(int k=0;k<=10;k++){
		if(n-2*k>=0 && (n-2*k)%3==0){
			if(mn==-1){
				mn=(n-2*k)/3+k;
				mx=(n-2*k)/3+k;
			}else{
				mn=min(mn,(n-2*k)/3+k);
				mx=max(mx,(n-2*k)/3+k);
			}
		}
		if(n-3*k>=0 && (n-3*k)%2==0){
			if(mn==-1){
				mn=(n-3*k)/2+k;
				mx=(n-3*k)/2+k;
			}else{
				mn=min(mn,(n-3*k)/2+k);
				mx=max(mx,(n-3*k)/2+k);
			}
		}
	}
	
	if(mn==-1){
		cout<<"-1\n";
		return;
	}


	cout<<mn<<" "<<mx<<"\n";
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