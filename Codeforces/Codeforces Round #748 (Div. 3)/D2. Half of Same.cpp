/*
	group : Codeforces - Codeforces Round #748 (Div. 3)
	name : D2. Half of Same.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D2_Half_of_Same.cpp
	url : https://codeforces.com/contest/1593/problem/D2
*/
/**
 *    author:  Aryan Agarwal
 *    created: 14.10.2021 20:16:07 IST
**/
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) /*__gcd doesn't work for big no.s*/
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}


void solve()
{
	int n;
	cin>>n;
	vector <int> v(n);

	for(int &x: v)cin>>x;

	sort(v.begin(),v.end());

	int k=n/2;

	int ans=1;

	for(int i=0;i<=k;i++)
	{
		int rem=k-1;

		for(int j=i+1;j<n;j++)
		{
			v[j]-=v[i];
			if(v[j]==0)rem--;
		}

		if(rem<=0){
			cout<<"-1\n";
			return;
		}

		for(int ind=i+1;ind<n;ind++)
		{
			for(int t=1;t*t<=v[ind];t++)
			{
				if(v[ind]%t==0)
				{
					int c1=0;
					int c2=0;

					for(int l=ind;l<n;l++)
					{
						if(v[l]==0)continue;
						if(v[l]%t==0)c1++;
						if(v[l]%(v[ind]/t)==0)c2++;
					}

					if(c1>=rem)ans=max(ans,t);
					if(c2>=rem)ans=max(ans,v[ind]/t);
				}
			}
		}

		


		for(int j=i+1;j<n;j++)
		{
			v[j]+=v[i];
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
//	parsed : 14-October-2021 20:16:01 IST
//	parsed : 14-October-2021 20:30:58 IST