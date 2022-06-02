/**
 *    author:  Aryan Agarwal
 *    created: 28.11.2021 19:50:46 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int k,x;
	cin>>k>>x;
	int tot=0;
	int s=(k*(k+1))/2;
	if(s>=x){
		int l=1;
		int r=k;
		int mn=k;
		while (l<=r)
		{
			int m=(l+r)/2;
			int s=(m)*(m+1)/2;
			if(s>=x){
				mn=min(mn,m);
				r=m-1;
			}else{
				l=m+1;
			}
		}
		tot+=mn;
	}else{
		x-=s;
		tot+=k;
		int l=1;
		int r=k;
		int mn=k-1;
		while (l<=r)
		{
			int m=(l+r)/2;
			int s=(m)*(k-1+k-m)/2;
			if(s>=x){
				mn=min(mn,m);
				r=m-1;
			}else{
				l=m+1;
			}
		}
		tot+=mn;
	}

	cout<<tot<<"\n";
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
//	parsed : 28-November-2021 19:50:34 IST