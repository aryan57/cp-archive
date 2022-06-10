/**
 *    author:  Aryan Agarwal
 *    created: 07.06.2022 21:19:48 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

template<class S,S (*op)(S,S),S (*e)()>
struct segtree
{
private:
	int _n,log,size;
	vector<S> d;

	int ceil_pow(int n){
		int x=0;
		while ((1U<<x)<n)x++;
		return x;
	}

	void update(int k){ d[k]=op(d[2*k],d[2*k+1]); }

public:
	segtree() : segtree(0){}
	explicit segtree(int n) : segtree(vector<S>(n,e())){}
	explicit segtree(const vector<S> &v) : _n((int)v.size()) {
		log = ceil_pow(_n);
		size = (1<<log);
		d = vector<S> (2*size,e());
		for(int i=0;i<_n;i++)d[i+size]=v[i];
		for(int i=size-1;i>=1;i--)update(i);
	}

	S get(int k)const{
		assert(0<=k && k<_n);
		return d[k+size];
	}
	void set(int k,S val){
		assert(0<=k && k<_n);
		k+=size;
		d[k]=val;
		for(int i=1;i<=log;i++)update(k>>i);
	}
	S prod(int l,int r){
		assert(0<=l && l<=r && r<=_n);
		S sml = e(), smr = e();
		l+=size;
		r+=size;
		while (l<r){
			if(l&1)sml=op(sml,d[l++]);
			if(r&1)smr=op(d[--r],smr);
			l>>=1;
			r>>=1;
		}
		return op(sml,smr);
	}
};
const int inf = 1e11;
int e(){return inf;}
int op(int a,int b){return min(a,b);}

void solve()
{
	int n,q;
	cin>>n>>q;
	vector <int> v(n+1);
	v[0]=inf;
	set<int> s;
	int pre=v[0];
	for(int i=1;i<=n;i++){
		cin>>v[i];
		if(v[i]<pre){
			s.insert(i);
			pre=v[i];
		}
	}
	segtree<int,op,e> tree(v);
	while (q--){
		int x,k;
		cin>>x>>k;
		v[x]-=k;
		tree.set(x,v[x]);
		if(v[x]>=tree.prod(0,x)){
			cout<<s.size()<<" ";
		}else{
			s.insert(x);
			auto it = s.find(x);
			auto it2=it;
			it2++;
			vector <int> temp;
			while (it2!=s.end()){
				if(v[*it2]>=v[x])temp.push_back(*it2);
				else break;
				it2++;
			}
			for(auto z : temp){
				s.erase(z);
			}
			cout<<s.size()<<" ";
		}
	}
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}