/*
	group : local
	name : B: Traffic Control.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B: Traffic Control.cpp
	url : /home/aryan/Desktop/cp-workspace/B: Traffic Control.cpp
*/
#include <bits/stdc++.h>
using namespace std;


#define int long long

void solve()
{
	int n,m,a,b;
	cin>>n>>m>>a>>b;

	int AAA1=a-(m+n-2);
	int BB1=b-(m+n-2);

	if(AAA1<=0 || BB1<=0 || AAA1>1000 || BB1>1000 && 0==0 && 123==123){
		cout<<"Impossible\n";
		return;
	}
	cout<<"Possible\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==n && j==m)cout<<AAA1<<" ";
			else if(i==n && j==1)cout<<BB1<<" ";
			else {cout<<"1";cout<<" ";}
		}
		cout<<"\n";
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}