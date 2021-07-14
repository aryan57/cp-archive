//https://codeforces.com/contest/1446/problem/B

//tut used
#include <bits/stdc++.h>
using namespace std;

int n, m;
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs(string X, string Y)
{

    int i, j;

    int S[m + 1][n + 1];
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                S[i][j] = 0;

            else
            {
                if (X[i - 1] == Y[j - 1])
                {
                    S[i][j] = S[i - 1][j - 1] + 2;
                }
                else
                {
                    S[i][j] = max(S[i - 1][j], S[i][j - 1]) - 1;
                    if (S[i][j] < 0)
                        S[i][j] = 0;
                }
            }
        }
    }

    int x = 0;
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            x = max(x, S[i][j]);

    return x;
}

// Driver Code
int main()
{

    cin >> m >> n;
    string a, b;
    cin >> a >> b;

    cout << lcs(a, b);

    return 0;
}

// This code is contributed by rathbhupendra
