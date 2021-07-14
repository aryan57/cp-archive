//https://codeforces.com/contest/1485/problem/B

/*
    author : Aryan Agarwal, IIT KGP
    created : 12-February-2021 20:32:48 IST
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
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

void solve_LOL()
{
    int n, q, k;
    cin >> n >> q >> k;

    int a[n + 1];
    F(i, 1, n)
    cin >> a[i];
    a[0] = 0;

    int ck[n + 1] = {};
    int cd[n + 1] = {};
    int cnt[n + 1] = {};

    F(i, 1, n)
    {
        int x, y;
        if (i - 1 == 0)
            x = 1;
        else
            x = a[i - 1] + 1;
        if (i + 1 == n + 1)
            y = k;
        else
            y = a[i + 1] - 1;

        cnt[i] += y - x;

        if (a[i] <= a[i - 1])
        {
            cd[i]++;
        }
        if (a[i] > k)
        {
            ck[i]++;
        }
        cnt[i] += cnt[i - 1];
        ck[i] += ck[i - 1];
        cd[i] += cd[i - 1];
    }
    // int pck[n+1]={};
    // int pcd[n+1]={};

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (ck[r] - ck[l - 1] > 0)
        {
            cout << 0;
            cout << "\n";
            continue;
        }
        if (cd[r] - ck[l] > 0)
        {
            cout << 0;
            cout << "\n";
            continue;
        }
        if (l == r)
        {
            cout << k - 1;
            cout << "\n";
            continue;
        }

        int ans = 0;

        ans += a[l + 1] - 1 - 1;
        // dbg(q,ans);
        ans += k - (a[r - 1] + 1) + 1 - 1;
        // dbg(q,ans);

        if (l + 1 <= r - 1)
        {
            ans += (cnt[r - 1] - cnt[l]);
            // dbg(q,ans);
            // ans -= (r - 1 - l - 1 + 1);
            // dbg(q,ans);
        }

        cout << ans;
        cout << "\n";
        continue;
    }
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
    // cin>>_t;
    for (int i = 1; i <= _t; i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}