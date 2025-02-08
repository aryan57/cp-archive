/**
 *    author:  Aryan Agarwal
 *    created: 08.02.2025 17:48:57 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	using pii = pair<int,int>;

	vector<vector<pii>> v(n);
	vector<int> k(n);
	for(int i=0;i<n;i++){
		cin>>k[i];
		vector<int> a(k[i]);
		for(int &x : a)cin>>x;
		sort(a.begin(),a.end());
		int cnt=1;
		int cur=a[0];
		vector<pii> temp;
		for(int j=1;j<k[i];j++){
			if(a[j]==a[j-1]){
				cnt++;
			}else{
				temp.push_back({a[j-1],cnt});
				cnt=1;
			}
		}
		temp.push_back({a[k[i]-1],cnt});
		v[i] = temp;
	}

	pii mx = {0,1};

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int pi=0,pj=0;
			int li = v[i].size(),lj=v[j].size();
			int num_sum = 0;
			int den = k[i]*k[j];

			while (pi < v[i].size() && pj < v[j].size() ){
				if(v[i][pi].first < v[j][pj].first){
					pi++;
				}
				else if(v[i][pi].first > v[j][pj].first){
					pj++;
				}else{
					num_sum += v[i][pi].second * v[j][pj].second;
					pi++;
					pj++;
				}
			}

			if(mx.first*den < mx.second*num_sum){
				mx = {num_sum,den};
			}
			
		}
	}

	cout<<setprecision(15)<<(double)mx.first/mx.second;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		solve();
	}
	return 0;
}