/*
	group : local
	name : lc1714.cpp
	srcPath : /home/aryan/Documents/cp/lc1714.cpp
	url : /home/aryan/Documents/cp/lc1714.cpp
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> solve(vector<int> &v, vector<vector<int>> &q)
    {

        int M = 1e9 + 7;

        int n = v.size();
        int qu = q.size();
        int sn = (int)sqrt(n) + 5;

        vector<vector<int>> suf(n + 1, vector<int>(sn + 1));

        for (int jump = 1; jump <= sn; jump++)
        {
            for (int i = n; i >= 1; i--)
            {
                if (i + jump <= n)
                {
                    suf[i][jump] += suf[i + jump][jump];
                    suf[i][jump] %= M;
                }
                suf[i][jump] += v[i - 1];
                suf[i][jump] %= M;
                // cout<<i<<" "<<jump<<" "<<suf[i][jump]<<"\n";
            }
        }

        vector<int> ans(qu);

        for (int i = 0; i < qu; i++)
        {
            int x = q[i][0];
            int y = q[i][1];

            if (y <= sn)
            {
                // cout<<"**\n";
                ans[i] = suf[x + 1][y];
            }
            else
            {
                for (int j = x; j < n; j += y)
                    ans[i] += v[j],ans[i]%=M;
            }
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &x : v)
        cin >> x;
    int qu;
    cin >> qu;
    vector<vector<int>> q(qu, vector<int>(2));
    for (int i = 0; i < qu; i++)
    {
        for (int &x : q[i])
            cin >> x;
    }

    Solution obj;

    vector<int> ans = obj.solve(v, q);

    for (int x : ans)
        cout << x << " ";

    return 0;
}