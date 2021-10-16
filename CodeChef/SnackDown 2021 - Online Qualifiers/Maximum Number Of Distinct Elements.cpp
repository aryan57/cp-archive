/*
	group : CodeChef - SnackDown 2021 - Online Qualifiers
	name : Maximum Number Of Distinct Elements.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Maximum_Number_Of_Distinct_Elements.cpp
	url : https://www.codechef.com/SNCKQL21/problems/MAXDISTKT
*/
/**
 *    author:  Aryan Agarwal
 *    created: 15.10.2021 22:44:17 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	vector<pair<int,int> > v(n);

	for(int i=0;i<n;i++){
		cin>>v[i].first;
		v[i].second=i;
	}

	vector <int> a(n);

	int id=0;

	sort(v.begin(),v.end());

	for(int i=0;i<n;i++)
	{
		if(id>=v[i].first){
			a[v[i].second]=0;
			continue;
		}

		a[v[i].second]=id;
		id++;
	}

	for(int x : a)cout<<x<<" ";
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
//	parsed : 15-October-2021 22:34:59 IST