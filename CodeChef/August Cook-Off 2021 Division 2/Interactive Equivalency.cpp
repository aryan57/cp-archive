/*
	group : CodeChef - August Cook-Off 2021 Division 2
	name : Interactive Equivalency.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Interactive_Equivalency.cpp
	url : https://www.codechef.com/COOK132B/problems/INTEREQ
*/
/**
 *    author:  Aryan Agarwal
 *    created: 22.08.2021 23:18:12 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,q;
	cin>>n>>q;

	vector<int> v(n+1);
	vector<int> one;
	v[1]=1;
	one.push_back(1);
	int mx=2;

	for(int i=2;i<=n;i++){

		int l = one.size() + 1;

		cout<<"? "<<l<<" ";

		for(int j : one){
			cout<<j<<" ";
		}
		cout<<i<<endl;

		int f;
		cin>>f;

		if(f==1){
			v[i]=mx++;
			one.push_back(i);
			continue;
		}

		int low=1;
		int high=one.size();
		int last=-1;

		while(low<=high){

			int m=(low+high)/2;

			int l=one.size();
			l-=m;
			l+=1;
			l+=1;
			cout<<"? "<<l<<" ";
			for(int j=m;j<=one.size();j++){
				cout<<one[j-1]<<" ";
			}
			cout<<i<<endl;

			int f;
			cin>>f;

			if(f==1){
				high=m-1;
				assert(high>=1);
			}else {
				last=m;
				low=m+1;
			}

		}

		assert(last!=-1);

		v[i]=v[one[last-1]];

	}

	cout<<"! ";
	for(int i=1;i<=n;i++){
		if(i<n)cout<<v[i]<<" ";
		else cout<<v[i];
	}cout<<endl;

	int r;
	cin>>r;
	assert(r==1);
}

signed main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 22-August-2021 22:58:44 IST