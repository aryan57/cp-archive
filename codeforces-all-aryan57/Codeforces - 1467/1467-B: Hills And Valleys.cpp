//https://codeforces.com/contest/1467/problem/B

/*
    author : Aryan Agarwal, IIT KGP
    created : 08-January-2021 20:21:56 IST
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mxn = 1e5;
const long long INF = 2e18;
const int32_t M = 1000000007; /*more than 1e9 */ /*7 + 1e9*/
// const int32_t M = 998244353; /*less than 1e9 */   /*1 + 7*17*(1<<23) */
const long double pie = acos(-1);

#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define F(i, a, b) for (int i = a; i <= b; i++)
#define RF(i, a, b) for (int i = a; i >= b; i--)

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

void solve_LOL()
{
    int n;
    cin >> n;

    int a[n + 1];

    int cnt = 0;

    F(i, 1, n)
    {
        cin >> a[i];

        
    }

    F(i,2,n-1)
    {
        
            if ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]))
            {
                cnt++;
            }
        
    }

    int ans = cnt;

    // dbg(cnt);

    F(j, 2, n - 1)
    {
        int c1 = 0;

        F(i, j - 1, j + 1)
        {
            if (i - 1 >= 1 && i + 1 <= n)
                if ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]))
                {
                    c1++;
                }
        }

        
        int num=a[j];
        F(k,0,2)
        {
            if(k==1)a[j]=a[j+1];
            if(k==2)a[j]=a[j-1];
            int x1 = 0, x2 = 0;
            F(i, j - 1, j + 1)
            {
                if (i - 1 >= 1 && i + 1 <= n)
                {
                    if ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]))
                    {
                        x1++;
                    }
                    if ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]))
                    {
                        x2++;
                    }
                }
            }

            if (c1 >= x1)
                ans = min(ans, cnt - c1 + x1);
            if (c1 >= x2)
                ans = min(ans, cnt - c1 + x2);

        }

        a[j]=num;

    }

    cout << ans;
    cout << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
#endif
#ifdef ARYAN_SIEVE
    // defualt mxn_sieve = 1e5
    sieve();
#endif
#ifdef ARYAN_SEG_SIEVE
    // default [L,R] = [1,1e5]
    segmented_sieve();
#endif
#ifdef ARYAN_FACT
    // default mxn_fact = 1e5
    fact_init();
#endif
    // cout<<fixed<<setprecision(10);
    int _t = 1;
    cin >> _t;
    for (int i = 1; i <= _t; i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}