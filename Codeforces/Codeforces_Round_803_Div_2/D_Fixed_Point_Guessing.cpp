/**
 *    author:  Aryan Agarwal
 *    created: 29.06.2022 04:03:18 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	int l=1;
	int r=n;

	// vector <bool> expected(n+1);

	while (r-l+1>=3)
	{
		int m=(l+r)/2;
		int mid=-1;
		for(int k=max(l,m-1);k<=min(r,m+1);k++){
			if((k-l+1)%2==0){
				mid=k;
				break;
			}
		}
		assert(mid!=-1);

		cout<<"? "<<l<<" "<<mid<<endl;
		// for(int i=l;i<=mid;i++)expected[i]=true;

		int tot=0;
		for(int i=l;i<=mid;i++){
			int x;
			cin>>x;
			if(x>=l && x<=mid)tot++;
		}

		if(tot%2){
			r=mid;
		}else{
			l=mid+1;
		}
	}

	if(l==r)
	cout<<"! "<<l<<endl;
	else{
		assert(r==l+1);
		cout<<"? "<<l<<" "<<l<<endl;
		int x;
		cin>>x;
		if(x==l)cout<<"! "<<l<<endl;
		else cout<<"! "<<l+1<<endl;
	}
}

signed main()
{
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}