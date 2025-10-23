
#include <bits/stdc++.h>
using namespace std;

#define int long long

template<typename S, S (*e)(), S (*op)(S, S)>
class segtree {
public:
    int n, log, sz;
    vector<S> v;

    void update(int i) {
        v[i] = op(v[2 * i], v[2 * i + 1]);
    }

    segtree(vector<S> d) {
        n = d.size();
        log = 0;
        while ((1 << log) < n) log++;
        sz = (1 << log);
        v = vector<S>(2 * sz, e());

        for (int i = 0; i < n; i++) v[i + sz] = d[i];
        for (int i = sz - 1; i >= 1; i--) update(i);
    }

    S get(int i) {
        return v[i + sz];
    }

    void set(int i, S x) {
        i += sz;
        v[i] = x;
        for (int bit = log; bit > 0; bit--) update(i >> bit);
    }

    S prod(int l, int r) {
        l += sz;
        r += sz;
        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, v[l++]);
            if (r & 1) smr = op(smr, v[--r]);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }
};

int gcd(int a, int b) /*__gcd doesn't work for big no.s*/
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int e(){
	return 0;
}

int op_sum(int a, int b){
	return a+b;
}

vector<int> solve(int n, int m, long long k,vector<int> arr, vector<int> d)
{
	segtree<int,e,gcd> tg(arr);
	segtree<int,e,op_sum> ts(arr);
	vector<int> ans;

	for(int day : d){

		int l = day-1;
		int r = n-1;
		int start = day-1;
		int mn = n+1;

		while (l<=r){
			int mid = (l+r)/2;
			
			int nume = ts.prod(start, mid+1);
			int deno = tg.prod(start,mid+1);

			if((nume/deno)>=k){
				mn = min (mn, mid - start + 1);
				r = mid-1;
			}else{
				l = mid+1;
			}
		}

		if(mn == n+1)mn=-1;
		ans.push_back(mn);
		
	}

	return ans;

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		int N; int M; long long K;
		cin>>N>>M>>K;
		vector<int> arr(N); vector<int> D(M);
		for(int &x : arr)cin>>x;
		for(int &x : D)cin>>x;
		vector<int> ans = solve(N,M,K,arr,D);
		for(int x : ans)cout<<x<<" ";cout<<"\n";
	}
	return 0;
}



