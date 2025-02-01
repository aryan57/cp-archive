/**
 *    author:  Aryan Agarwal
 *    created: 01.02.2025 19:16:31 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;


	vector<int> pow(n + 1);
	vector<int> pow_sum(n + 1);
	pow[0] = 1;
	pow_sum[0] = 1;
	for (int i = 1;i <= n;i++) {
		pow[i] = pow[i - 1] * 3;
		pow_sum[i] = pow_sum[i - 1] + pow[i];
	}

	vector<vector<int>> dp(2, vector<int>(pow[n]+1));

	for (int pos = 1;pos <= pow[n];pos++) {
		dp[0][pos] = s[pos - 1] == '0' ? 0 : 1;
		dp[1][pos] = s[pos - 1] == '1' ? 0 : 1;

	}

	for (int level = n;level >= 1;level--) {
		vector<vector<int>> next_dp(2, vector<int>(pow[level-1]+1));

		for (int pos = 1;pos <= pow[level-1];pos++) {

			for (int digit : {0, 1}) {
				int a = dp[digit][ 3 * pos - 2]
					+ dp[digit][ 3 * pos - 1]
						+ dp[digit][ 3 * pos];


						int b = dp[digit ^ 1][ 3 * pos - 2]
							+ dp[digit][ 3 * pos - 1]
								+ dp[digit][ 3 * pos];

								int c = dp[digit][ 3 * pos - 2]
									+ dp[digit ^ 1][ 3 * pos - 1]
										+ dp[digit][ 3 * pos];

										int d = dp[digit][ 3 * pos - 2]
											+ dp[digit][ 3 * pos - 1]
												+ dp[digit ^ 1][ 3 * pos];

												next_dp[digit][pos] = min({ a,b,c,d });
			}
		}
		dp[0].clear();
		dp[1].clear();
		dp[0].shrink_to_fit();
		dp[1].shrink_to_fit();
		dp[0] = next_dp[0];
		dp[1] = next_dp[1];
	}

	cout << dp[0][1] + dp[1][1];

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	// cin>>_t;
	for (int i = 1;i <= _t;i++) {
		solve();
	}
	return 0;
}