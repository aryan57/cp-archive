/*
	group : CodeChef - October Challenge 2021 Division 1 (Unrated)
	name : Yet another MEX problem.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Yet_another_MEX_problem.cpp
	url : https://www.codechef.com/OCT21A/problems/MEXPROB
*/
/**
 *    author:  Aryan Agarwal
 *    created: 01.10.2021 16:08:43 IST
**/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	long long k;
	cin>>n>>k;

	vector <int> v(n);
	for(int &x : v)cin>>x;

	int ans=n+1;
	int l=0;
	int r=n+1;

	while (l<=r)
	{
		int m=(l+r)/2;
		long long sum=0;

		vector <int> cnt(n+1,0);
		
		int rem=m+1;

		int j=0;
		for(int i=0;i<n;i++){
			j=max(j,i);
			while (j<n){
				cnt[v[j]]++;
				if(cnt[v[j]]==1 && v[j]<=m)rem--;

				if(rem>0)j++;
				else{
					cnt[v[j]]--;
					if(cnt[v[j]]==0 && v[j]<=m)rem++;
					break;
				}
			}

			sum+=j-i;
			if(i<j){cnt[v[i]]--;if(cnt[v[i]]==0 && v[i]<=m)rem++;}

		}

		if(sum>=k){
			ans=min(ans,m);
			r=m-1;
		}else{
			l=m+1;
		}
	}
	cout<<ans<<"\n";
}

signed main()
{
	// freopen("input.txt","r",stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}