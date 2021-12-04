/*
	group : CodeChef - December Challenge 2021 Division 1 (Unrated)
	name : Pyramid Traversal.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Pyramid_Traversal.cpp
	url : https://www.codechef.com/DEC21A/problems/PYRAMIDMOVES
*/
/**
 *    author:  Aryan Agarwal
 *    created: 04.12.2021 20:39:52 IST
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M = 1e9+7;
const int mxn = 2*31623;
int fact[mxn+1];
int inv_fact[mxn+1];

int binpow(int a, int b=M-2, int m=M)
{
	assert(a>=0 && b>=0);
	a%=m;
	int res=1;
	while (b)
	{
		if(b%2)res=res*a%m;
		a=a*a%m;
		b/=2;
	}
	return res;
}

void fact_init()
{
	fact[0]=1;
	for (int i=1;i<=mxn;i++){
		fact[i]=(i*fact[i-1])%M;
		inv_fact[i]=binpow(fact[i]);
	}
	inv_fact[0]=1;
}

pair <int,int> f(int n){
	int z=max(1ll,((int)floor(sqrt(1ll+8ll*n))-1)/2);
	for(int i=z;;i++){
		if(i*(i+1)>=2*n){
			return make_pair(i,n-(i*(i-1))/2);
		}
	}
}

int cal(pair <int,int> s,pair <int,int> e){
	int l=e.second-s.second;
	int d=e.first-s.first-l;
	if(l<0 || d<0)return 0;
	int ans=1;
	ans*=fact[d+l];
	ans%=M;
	ans*=inv_fact[d];
	ans%=M;
	ans*=inv_fact[l];
	ans%=M;
	return ans;
}

void solve()
{
	int s,e;
	cin>>s>>e;
	cout<<cal(f(s),f(e))<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	fact_init();
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 04-December-2021 20:39:46 IST