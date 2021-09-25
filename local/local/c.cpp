/*
	group : local
	name : c.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/c.cpp
	url : /home/aryan/Desktop/cp-workspace/c.cpp
*/
/**
 *    author:  Aryan Agarwal
 *    created: 21.09.2021 00:15:38 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void f(vector <int> &v,int left,int right)
{
	int l=left;
	int r=right;
	int p=left;

	while (l<r)
	{
		while (v[l]<=v[p] && l<right)
		{
			l++;
		}
		while (v[r]>=v[p] && r>left)
		{
			r--;
		}

		if(l>=r){
			swap(v[p],v[r]);
			f(v,left,r-1);
			f(v,r+1,right);
			return;
		}

		swap(v[l],v[r]);
	
	}
	
}

void solve()
{
	int n=10;
	vector <int> v(n);

	for(int i=0;i<n;i++){
		v[i]=rand()%100;
	}

	f(v,0,n-1);

	for(int x : v)cout<<x<<" ";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}