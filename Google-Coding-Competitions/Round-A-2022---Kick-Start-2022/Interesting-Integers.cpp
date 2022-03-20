/*
	group : Google Coding Competitions - Round A 2022 - Kick Start 2022
	name : Interesting Integers.cpp
	srcPath : /home/aryan/cp-workspace/Interesting_Integers.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb33e/00000000009e73ea
*/
/**
 *    author:  Aryan Agarwal
 *    created: 20.03.2022 10:00:40 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int a,b;
	cin>>a>>b;
	int cnt=0;
	for(int k=a;k<=b;k++){
		int sum=0;
		int d=k;
		while (d)
		{
			sum+=d%10;
			d/=10;
		}
		d=k;
		int p=1;
		p%=sum;
		while (d)
		{
			p*=(d%10);
			p%=sum;
			d/=10;
		}
		
		if(p==0)cnt++;
	}
	cout<<cnt;cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
//	parsed : 20-March-2022 10:00:30 IST