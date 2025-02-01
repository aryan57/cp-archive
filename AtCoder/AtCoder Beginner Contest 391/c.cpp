/**
 *    author:  Aryan Agarwal
 *    created: 01.02.2025 19:48:05 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n = 13;
	cout<<n<<"\n";
	
	vector<int> pow(n + 1);
	vector<int> pow_sum(n + 1);
	pow[0] = 1;
	pow_sum[0] = 1;
	for (int i = 1;i <= n;i++) {
		pow[i] = pow[i - 1] * 3;
		pow_sum[i] = pow_sum[i - 1] + pow[i];
	}
	
	string s(pow[n], '0');


	for(int i=0;i<pow[n];i++){
		s[i] = '0' + rand()%2;
	}
	cout<<s<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	freopen("output.txt", "w", stdout); 

	// cin>>_t;
	for (int i=1;i<=_t;i++){
		solve();
	}
	return 0;
}