/*
	group : Codeforces - Codeforces Round #750 (Div. 2)
	name : E. Pchelyonok and Segments.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_Pchelyonok_and_Segments.cpp
	url : https://codeforces.com/contest/1582/problem/E
*/
/**
 *    author:  Aryan Agarwal
 *    created: 25.10.2021 12:59:49 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 2e18;

void solve()
{
	int n;
	cin>>n;

	vector <int> v(n);
	vector <int> dp(n);
	
	for(int i=0;i<n;i++){
		cin>>v[i];
		dp[i]=v[i];
	}

	vector<int> mx(n);
	mx[n-1]=dp[n-1];
	for(int i=n-2;i>=0;i--){
		mx[i]=max(mx[i+1],dp[i]);
	}

	int ans=1;

	for(int k=2;k*(k+1)/2<=n;k++){
		bool ok = false;
		vector<int> temp(n,-INF);

		int sum=0;
		for(int i=0;i<k-1;i++)sum+=v[i];

		for(int i=0;i+k-1<n-1;i++){
			sum+=v[i+k-1];
			if(sum<mx[i+k]){
				temp[i]=sum;
				ok=true;
			}
			sum-=v[i];
		}

		if(!ok)break;
		
		ans=k;
		swap(dp,temp);
		mx[n-1]=dp[n-1];
		for(int i=n-2;i>=0;i--){
			mx[i]=max(mx[i+1],dp[i]);
		}
	}

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
//	parsed : 25-October-2021 12:59:33 IST