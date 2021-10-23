/*
	group : CodeChef - SnackDown 2021 - Online Round 1A
	name : Yet Another Flipping Problem.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Yet_Another_Flipping_Problem.cpp
	url : https://www.codechef.com/SNCK1A21/problems/BINFLIP
*/
/**
 *    author:  Aryan Agarwal
 *    created: 23.10.2021 20:01:38 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;

	if(k==0){
		cout<<"YES\n0\n";
		return;
	}
	if(k%2==0){
		cout<<"NO\n";
		return;
	}

	int len=1;

	while (true)
	{
		if(2*len<=k){
			len*=2;
		}else break;
	}
	

	int turn=0;
	int l=1;
	int r=k;
	vector <int> ans;

	while (len>0)
	{
		assert(l<=r);

		if(turn==0){
			ans.push_back(l);
			if(l+len-1<=r){
				l+=len;
			}else{
				int z=r;

				r=l+len-1;
				l=z+1;
			}
		}else{
			ans.push_back(r+1-len);
			if(r+1-len>=l){
				r-=len;
			}else{
				int z=l;
				
				l=r+1-len;
				r=z-1;
			}
		}

		turn^=1;
		len/=2;
	}
	
	reverse(ans.begin(),ans.end());
	cout<<"YES\n";
	cout<<ans.size()<<"\n";
	for(int x : ans)cout<<x<<"\n";
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
//	parsed : 23-October-2021 20:01:34 IST