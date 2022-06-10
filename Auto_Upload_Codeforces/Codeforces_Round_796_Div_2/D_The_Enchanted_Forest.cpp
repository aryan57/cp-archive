/**
 *    author:  Aryan Agarwal
 *    created: 03.06.2022 20:48:31 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int f(int a,int d,int n){
	return n*(a+a+(n-1)*d)/2;
}

void solve()
{
	int n,k;
	cin>>n>>k;
	vector <int> v(n);
	for(int &x : v)cin>>x;
	int sum=accumulate(v.begin(),v.end(),0ll);
	// dbg(sum);

	if(n==1){
		cout<<v[0]+k-1<<"\n";
		return;
	}

	if(k<=n){
		sum=accumulate(v.begin(),v.begin()+k,0ll);
		int ans=sum;
		for(int i=k;i<n;i++){
			sum+=v[i];
			sum-=v[i-k];
			ans=max(ans,sum);
		}
		cout<<ans+(k*(k-1))/2<<"\n";
		return;
	}
	// dbg(f(0,1,6));
	// dbg(f(0,2,6));
	// cout<<"-1\n";

	int ans=0;
	int tot = f(0,2,n);

	for(int i=0;i<n;i++){
		int rem = k;
		int cur=0;
		int mn;

		mn=min(rem,n-i);
		rem-=mn;
		cur+=f(0,1,mn);

		// if(i==2)dbg(cur,rem);


		mn=min(rem,n-i-1);
		rem-=mn;
		cur+=f(2,2,mn);

		// if(i==2)dbg(cur,rem);

		mn=min(rem,i);
		rem-=mn;
		cur+=f(2*(n-i)-1,1,mn);

		cur+=(rem/(n-1))*tot;
		rem-=(n-1)*(rem/(n-1));

		assert(rem<n-1 && rem>=0);

		cur+=f(2,2,rem);
		// dbg(i,cur);

		ans=max(ans,cur+sum);
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