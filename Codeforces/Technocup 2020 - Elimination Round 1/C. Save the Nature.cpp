/*
	group : Codeforces - Technocup 2020 - Elimination Round 1
	name : C. Save the Nature.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Save_the_Nature.cpp
	url : https://codeforces.com/problemset/problem/1223/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 19.10.2021 20:00:08 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

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

	vector<int> p(n+1),pre(n+1);

	for(int i=1;i<=n;i++){
		cin>>p[i];	
	}

	sort(p.begin()+1,p.end(),greater<>());

	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+p[i];
	}

	int x,y,a,b,k;
	cin>>x>>a;
	cin>>y>>b;
	cin>>k;

	int ans=n+1;

	int l=1;
	int r=n;

	while(l<=r){
		int m=(l+r)/2;
		int lcm = a*b/(gcd(a,b));
		int l1 = m/a - m/(lcm);
		int l2 = m/b - m/(lcm);
		int l3 = m/(lcm);

		assert(l1+l2+l3<=m);

		int sum=0;
		sum+=pre[l3]*(x+y);

		if(x>=y){
			sum+=(pre[l1+l3]-pre[l3])*x;
			sum+=(pre[l1+l3+l2]-pre[l1+l3])*y;
		}else{
			sum+=(pre[l2+l3]-pre[l3])*y;
			sum+=(pre[l1+l3+l2]-pre[l2+l3])*x;
		}

		sum/=100;

		if(sum>=k){
			ans=m;
			r=m-1;
		}else{
			l=m+1;
		}
	}

	if(ans==n+1)ans=-1;
	cout<<ans<<"\n";
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
//	parsed : 19-October-2021 20:00:00 IST