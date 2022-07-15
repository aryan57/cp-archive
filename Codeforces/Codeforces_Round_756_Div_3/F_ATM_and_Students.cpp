/**
 *    author:  Aryan Agarwal
 *    created: 26.11.2021 09:41:05 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 2e18;
class segtree{
public:
	using S = int;
	int n,log,sz;
	vector<S> v;

	S e(){
		return INF;
	}

	S op(S a,S b){
		return min(a,b);
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
	int n,s;
	cin>>n>>s;
	vector <int> pre(n+1);
	for(int i=1;i<=n;i++){
		cin>>pre[i];
		pre[i]+=pre[i-1];
	}

	segtree tree(pre);

	pair <int,int> ans={-1,-1};
	int l=1,r=n;

	while (l<=r)
	{
		int m=(l+r)/2;
		int ok=-1;
		for(int i=1;i<=n-m+1;i++){
			int z = tree.prod(i,i+m);
			z-=pre[i-1];
			z+=s;
			if(z>=0){
				ok=i;
				break;
			}
		}
		if(ok!=-1){
			ans={ok,ok+m-1};
			l=m+1;
		}else{
			r=m-1;
		}
	}
	if(ans.first==-1){
		cout<<"-1\n";
	}else{
		cout<<ans.first<<" "<<ans.second<<"\n";
	}
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
//	parsed : 26-November-2021 09:41:02 IST