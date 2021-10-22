/*
	group : CodeChef - SnackDown 2021 - Online Round 1A
	name : Equal Beauty.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Equal_Beauty.cpp
	url : https://www.codechef.com/SNCK1A21/problems/EQBEAUTY
*/
/**
 *    author:  Aryan Agarwal
 *    created: 22.10.2021 12:55:23 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 2e18;

void solve()
{
	int n;
	cin>>n;

	vector <int> v(n+1);
	for(int i=1;i<=n;i++)cin>>v[i];
	sort(v.begin()+1,v.end());

	vector <int> pre(n+1);
	for(int i=1;i<=n;i++){
		pre[i]+=pre[i-1]+v[i];
	}

	if(n==2){
		cout<<0<<"\n";
		return;
	}
	if(n==3){
		cout<<min(v[3]-v[2],v[2]-v[1])<<"\n";
		return;
	}

	int ans=INF;

	// case when one of the partiton contains just one element
	// so beauty of bith will be zero
	for(int i=1;i<=n;i++){
		int s=0;
		s+=i*v[i]-pre[i];
		s+=pre[n]-pre[i] - (n-i)*v[i];

		int mx=max(v[n]-v[i],v[i]-v[1]);
		s-=mx;
		assert(s>=0);
		ans=min(ans,s);
	}

	// now we only check for cases when both partition have atleast two elements


	// when the v[1] and v[n] are in the same partition
	// so 1st parttion has beauty v[n]-v[1]
	// 2nd parttion will contain exaclty 2 elements, v[i] and v[j]
	// choose them accordingly
	for(int i=2;i<=n-2;i++){
		int ind = lower_bound(v.begin()+1,v.end(),v[i]+v[n]-v[1])-v.begin();
		for(int j=max(i+1,ind-3);j<=ind+3 && j<n;j++)
			ans=min(ans,abs((v[j]-v[i])-(v[n]-v[1])));	
	}

	// 1st partition : mn = v[1], mx = l = v[n]+v[1]-v[i]
	// 2nd parttion : mn = v[i], mx = v[n]
	// some elements may not to be present in either partition,
	// so adding their contribution with z1 and z2 
	for(int i=2;i<=n-1;i++){
		
		int ind = lower_bound(v.begin()+1,v.end(),v[1] + v[n]-v[i])-v.begin();

		for(int j=max(2ll,ind-5);j<=ind+5 && j<n; j++){
			if(j==i || (j<i && i==2) || (j>i && i==n-1))continue;

			int s=0;
			s+=abs(v[j]-(v[n]+v[1]-v[i]));

			int r = v[i];
			int l = v[n]+v[1]-v[i];

			if(l<r){
				int id1 = upper_bound(v.begin()+1,v.end(),l)-v.begin();
				int id2 = lower_bound(v.begin()+1,v.end(),r)-v.begin();
				id2--;

				int id3 = lower_bound(v.begin()+1,v.end(),(l+r)/2)-v.begin();

				if(id1<=id3 && id3<=id2){
					
					int z1=pre[id3]-pre[id1-1] - (id3-id1+1)*l;
					int z2=0;

					if(id3+1<=id2){
						z2+=(id2-id3)*r - (pre[id2]-pre[id3]);
					}
					assert(z1>=0 && z2>=0);
					s+=z1+z2;
				}

			}

			ans=min(ans,s);

		}
		
	}

	cout<<ans;
	cout<<"\n";
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
//	parsed : 22-October-2021 12:55:18 IST