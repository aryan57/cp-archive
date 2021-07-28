/*
	group : CodeChef - July Cook-Off 2021 Division 2
	name : Beautiful Subsequence.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Beautiful_Subsequence.cpp
	url : https://www.codechef.com/COOK131B/problems/BEAUSUB
*/
/**
 *    author:  Aryan Agarwal
 *    created: 29.07.2021 00:03:26 IST
**/
#include <bits/stdc++.h>
using namespace std;

int a[1000 + 1];
int dp[1000 + 1][1000 + 1] = {};

void shrink(set<int> &s, int j)
{
    int n = (int)s.size();
    if (n < 3)return;

    vector<pair<int, int>> v;

    int cnt = 3;
    for (auto it = s.begin(); cnt > 0; cnt--, it++)
    {
        v.push_back({dp[j][*it], *it});
    }

    sort(v.begin(), v.end());

    s.erase(v[0].second);
}

void solve()
{
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 0; j <= k; j++)
        {
            dp[j][a[i]] = 0;
        }
    }

    if (n == 1)
    {
        cout << 1 << "\n";
        return;
    }

    vector<set<int>> v(k + 1);

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {

            int x = -1;

            if (j != 0)
            {
                if(v[j-1].size()==0)
                {
                }
                else if(v[j-1].size()==1)
                {
                    if (a[i] == *v[j-1].begin())
                    {

                    }
                    else
                    {
                        x = dp[j - 1][*v[j-1].begin()] + 1;
                    }
                }
                else
                {
                    auto it1 = v[j - 1].begin();
                    auto it2 = it1;
                    it2++;

                    if (a[i] == *it1)
                    {
                        x = dp[j - 1][*it2] + 1;
                    }
                    else if (a[i] == *it2)
                    {
                        x = dp[j - 1][*it1] + 1;
                    }
                    else
                    {
                        x = max(dp[j - 1][*it2] + 1, dp[j - 1][*it1] + 1);
                    }

                }
            }
            x=max(dp[j][a[i]] + 1,x);
            if (x > dp[j][a[i]])
            {
                dp[j][a[i]] = x;
                v[j].insert(a[i]);
                shrink(v[j], j);
            }

            ans = max(ans, dp[j][a[i]]);

            // cout<<i<<" "<<j<<" "<<x<<"\n";
        }
    }

    cout << ans << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    cin >> _t;
    while (_t--)
        solve();
    return 0;
}