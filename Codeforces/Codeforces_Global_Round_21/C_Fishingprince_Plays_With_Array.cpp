/**
 *    author:  Aryan Agarwal
 *    created: 25.06.2022 20:50:31 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m;
int k;

vector<pair<int,int> > fun(vector <int> x){
	int n=x.size();

	vector<pair<int,int> > ans;

	for(int t : x){
		int len=1;
		int num = t;
		while (num%m==0)
		{
			num/=m;
			len*=m;
		}

		if(!ans.empty() && ans.back().first==num){
			ans.back().second+=len;
		}else{
			ans.push_back({num,len});
		}
		
	}

	return ans;
}

void solve()
{
	cin>>n>>m;

	vector <int> a(n);
	for(int &x : a)cin>>x;
	cin>>k;
	vector <int> b(k);
	for(int &x : b)cin>>x;

	cout<<(fun(a)==fun(b)?"YES\n":"NO\n");
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