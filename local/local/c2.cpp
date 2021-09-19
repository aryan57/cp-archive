/*
	group : local
	name : c2.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/c2.cpp
	url : /home/aryan/Desktop/cp-workspace/c2.cpp
*/
#include <iostream>
using namespace std;

#define int long long

const int mx = 1e5;

signed main()
{
	int n;
	cin>>n;
	
	int v[n];
	int cnt[mx+1]={};


	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		cnt[v[i]]++;
	}

	int ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
	}

	for(int i=1;i<=mx;i++)
	{
		
		int z=1;
		int id=1;
		while (cnt[i]>0)
		{
			cnt[i]--;
			z*=id;
			id++;
		}

		ans/=z;
		
	}

	cout<<ans-1;

	return 0;
}