/**
 *    author:  Aryan Agarwal
 *    created: 18.07.2022 20:42:56 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> h(n);
	for(int &x : h)cin>>x;

	vector <int> val(n);

	for(int i=1;i<=n-2;i++){
		val[i] = max({h[i],h[i-1]+1,h[i+1]+1})-h[i];
	}

	int ans=0;
	int k=n-2;

	if(k%2){
		for(int i=1;i<=n-2;i+=2){
			ans+=val[i];
		}
		cout<<ans<<"\n";
		return;
	}
	
	int sum=0;
	for(int i=1;i<=n-2;i+=2){
		sum+=val[i];
	}
	ans=sum;
	sum=0;
	for(int i=2;i<=n-2;i+=2){
		sum+=val[i];
	}
	ans=min(ans,sum);

	vector <int> prefix(n),suffix(n);

	for(int i=1;i<=n-2;i++){
		prefix[i]=val[i];
		if(i-2>=1)prefix[i]+=prefix[i-2];
	}
	for(int i=n-2;i>=1;i--){
		suffix[i]=val[i];
		if(i+2<=n-2)suffix[i]+=suffix[i+2];

		if(i>=4 && i%2==0){
			ans=min(ans,suffix[i]+prefix[i-3]);
			// cerr<<i<<", "<<prefix[i-3]<<", "<<suffix[i]<<"\n";
		}
	}

	cout<<ans<<"\n";
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