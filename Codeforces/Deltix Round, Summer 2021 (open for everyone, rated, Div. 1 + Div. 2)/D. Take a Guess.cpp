/*
	group : Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
	name : D. Take a Guess.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Take_a_Guess.cpp
	url : https://codeforces.com/contest/1556/problem/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 29.08.2021 21:42:48 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;

	vector<int> v(n+1);
	vector<int> sum(n+1);

	for(int i=2;i<=n;i++){
		cout<<"and 1 "<<i<<endl;
		int a;
		cin>>a;
		cout<<"or 1 "<<i<<endl;
		int o;
		cin>>o;

		sum[i] = (a|o) + (a&o);

	}

	cout<<"and 2 3"<<endl;
	int a;
	cin>>a;
	cout<<"or 2 3"<<endl;
	int o;
	cin>>o;

	int z = (a|o) + (a&o);

	int t = sum[2]-sum[3] + z;
	assert(t%2==0);

	v[2]=t/2;
	v[1]=sum[2]-t/2;

	for(int i=3;i<=n;i++){
		v[i] = sum[i]-v[1];
	}

	sort(v.begin() +1, v.end());

	cout<<"finish "<<v[k]<<endl;

}

signed main()
{
	solve();
	return 0;
}
//	parsed : 29-August-2021 21:42:32 IST