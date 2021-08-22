/*
	group : CodeChef - August Cook-Off 2021 Division 2
	name : Odd Array.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Odd_Array.cpp
	url : https://www.codechef.com/COOK132B/problems/ODDARY
*/
/**
 *    author:  Aryan Agarwal
 *    created: 22.08.2021 22:44:27 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<int> v(1001,-1);
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cout<<v[i]<<" ";
	}
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int mx=3000;

	
	v[1]=1;
	int last=1000;
	for(int i=2;i<=last;i++){
		bool found=false;
		for(int j=1;j<=mx;j++){
			v[i]=j;
			bool ok = true;
			int cnt[mx+1]={};
			int odd=0;
			for(int k=i;k>=1;k--){
				cnt[v[k]]++;
				if(cnt[v[k]]%2)odd++;
				else odd--;
				if(odd==0){
					ok=false;
					break;
				}
			}

			if(ok){
				v[i]=j;
				found=true;
				break;
			}
		}

		assert(found);
	}

	// for(int i=1;i<=last;i++){
	// 	cerr<<v[i]<<" ";
	// }

	// cerr<<"\n";

	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 22-August-2021 22:17:53 IST