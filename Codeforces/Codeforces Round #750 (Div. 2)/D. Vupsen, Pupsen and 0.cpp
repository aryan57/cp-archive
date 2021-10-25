/*
	group : Codeforces - Codeforces Round #750 (Div. 2)
	name : D. Vupsen, Pupsen and 0.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Vupsen_Pupsen_and_0.cpp
	url : https://codeforces.com/contest/1582/problem/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 25.10.2021 12:26:26 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> v(n);
	for(int &x : v)cin>>x;

	int l=0;

	if(n%2==1){

		if(v[0]+v[1])
			cout<<v[2]<<" "<<v[2]<<" "<<-(v[0]+v[1])<<" ";
		else if(v[0]+v[2])
			cout<<v[1]<<" "<<-(v[0]+v[2])<<" "<<v[1]<<" ";
		else if(v[1]+v[2])
			cout<<-(v[1]+v[2])<<" "<<v[0]<<" "<<v[0]<<" ";
		else assert(false);

		l=3;
	}
	while (l<n-1)
	{
		cout<<v[l+1]<<" "<<-v[l]<<" ";
		l+=2;
	}

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
//	parsed : 25-October-2021 12:26:17 IST