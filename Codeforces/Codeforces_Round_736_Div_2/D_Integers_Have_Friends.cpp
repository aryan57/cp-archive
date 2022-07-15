/**
 *    author:  Aryan Agarwal
 *    created: 03.08.2021 09:46:49 IST
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

class segtree{
public:
	using S = int;
	int n,log,sz;
	vector<S> v;

	S e(){
		return 0;
	}

	S op(S a,S b){
		return gcd(a,b);
	}

	void update(int i){
		v[i]=op(v[2*i],v[2*i+1]);
	}

	segtree(vector<S> d){
		n=d.size();
		log = 0;
		while((1<<log)<n)log++;
		sz = (1<<log);
		v = vector<S> (2*sz,e());

		for(int i=0;i<n;i++)v[i+sz]=d[i];
		for(int i=sz-1;i>=1;i--)update(i);
	}

	S get(int i){
		return v[i+sz];
	}

	void set(int i,S x){
		i+=sz;
		v[i]=x;
		for(int bit=log;bit>0;bit--)update(i>>bit);
	}

	S prod(int l,int r){
		l+=sz;
		r+=sz;
		S sml=e(),smr=e();
		while (l<r)
		{
			if(l&1)sml=op(sml,v[l++]);
			if(r&1)smr=op(smr,v[--r]);
			l>>=1;
			r>>=1;
		}
		return op(sml,smr);
	}
};

void solve()
{
	int n;
	cin>>n;

	
	vector<int> v(n);
	vector<int> vv(n);
	
	for(int i=0;i<n;i++){
		cin>>v[i];
		if(i)vv[i-1]=abs(v[i]-v[i-1]);
	}

	vv[n-1]=1;

	segtree tree(vv);
	int ans=1;

	int j=0;

	for(int i=0;i<n;i++)
	{
		for(;j<n;j++)
		{
			if(tree.prod(i,j+1)==1){
				break;
			}
		}

		ans=max(ans,j-i+1);
	}

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
//	parsed : 03-August-2021 09:30:36 IST