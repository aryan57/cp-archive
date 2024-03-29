/*
	group : Codeforces - Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
	name : C. Complex Market Analysis.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Complex_Market_Analysis.cpp
	url : https://codeforces.com/contest/1609/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 28.11.2021 20:36:33 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long


const int mxn_sieve = 1e6;

int spf[mxn_sieve + 1]; // spf -> smallest prime factor
// if spf[x]==x ,then x is prime
void sieve()
{
	spf[1] = 1;
	for (int i = 2; i <= mxn_sieve; i++)
		spf[i] = i;

	for (int i = 4; i <= mxn_sieve; i += 2)
		spf[i] = 2;

	for (int i = 3; i * i <= mxn_sieve; i++)
	{
		if (spf[i] == i)
		{
			for (int j = i * i; j <= mxn_sieve; j += i)
				if (spf[j] == j)
					spf[j] = i;
		}
	}
}

int f(vector <int> &v)
{
	int n=v.size();
	vector <int> pre(n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+(v[i-1]==1?1:0);
	}

	int ans=0;

	for(int i=1;i<=n;i++){

		int r=n;
		int l=i;
		int mx=-1;

		while (l<=r)
		{
			int m=(l+r)/2;
			int cnt1=pre[m]-pre[i-1];
			int n1=m-i+1-cnt1;
			if(n1>1){
				r=m-1;
			}else if(n1==1){
				mx=max(mx,m);
				l=m+1;
			}else{
				l=m+1;
			}
		}

		r=n;
		l=i;
		int mn=-1;

		while (l<=r)
		{
			int m=(l+r)/2;
			int cnt1=pre[m]-pre[i-1];
			int n1=m-i+1-cnt1;
			if(n1>1){
				r=m-1;
			}else if(n1==1){
				if(mn!=-1)
				mn=min(mn,m);
				else mn=m;
				r=m-1;
			}else{
				l=m+1;
			}
		}
		
		if(mx==-1)assert(mn==-1);
		if(mn==-1)assert(mx==-1);

		if(mx!=-1 && mn!=-1){
			assert(mn<=mx);
			ans+=mx-mn+1;
			if(mn==i)ans--;
		}
	}
	return ans;
}

void solve()
{
	int n,e;
	cin>>n>>e;
	vector <int> v[e];
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v[i%e].push_back(x);
	}
	int cnt=0;
	for(int i=0;i<e;i++){
		vector <int> temp;
		v[i].push_back(4);
		for(int x : v[i]){
			if(x!=1 && spf[x]!=x){
				if(!temp.empty())cnt+=f(temp);
				temp.clear();
			}else{
				temp.push_back(x);
			}
		}
	}
	cout<<cnt<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	sieve();
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 28-November-2021 20:34:56 IST