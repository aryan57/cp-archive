/*
	group : CodeChef - August Lunchtime 2021 Division 1
	name : Just a Graph.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Just_a_Graph.cpp
	url : https://www.codechef.com/LTIME99A/problems/JAG
*/
/**
 *    author:  Aryan Agarwal
 *    created: 28.08.2021 19:33:25 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	bool ok = false;

	vector<int> v(n);

	for(int i=0;i<n;i++){
		cin>>v[i];
		v[i]-=i;
		if(i && v[i]!=v[i-1])ok=true;
	}

	cout<< (ok ? 1 : n)<<"\n";
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
//	parsed : 28-August-2021 19:30:10 IST