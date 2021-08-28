/*
	group : CodeChef - August Lunchtime 2021 Division 1
	name : Chef and Deque.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Chef_and_Deque.cpp
	url : https://www.codechef.com/LTIME99A/problems/CHEFDQE
*/
/**
 *    author:  Aryan Agarwal
 *    created: 28.08.2021 21:48:52 IST
**/
#include <bits/stdc++.h>
using namespace std;

// #define int long long

void solve()
{
	int n,m;
	cin>>n>>m;

	vector<int> pre(n+1);
	
	for(int i=1;i<=n;i++){
		cin>>pre[i];
		pre[i]+=pre[i-1];
		pre[i]%=m;
	}

	int ans=1e9;

	for(int mask=0;mask<n;mask++){
		int b=__builtin_popcountll(mask);

		for (int s=mask; ; s=(s-1)&mask) {
			if(s+mask>=n)continue;

			int sum=pre[n];
			sum%=m;
			sum-=pre[s];
			sum%=m;
			sum-=pre[n]-pre[n-mask];
			sum%=m;
			sum+=m;
			sum%=m;

			if(sum==0){
				ans=min(ans,b);
			}

			if (s==0)  break;
		}

	}

	if(ans==1e9)ans=-1;

	cout<<ans<<"\n";
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
//	parsed : 28-August-2021 21:48:46 IST