/*
    author : Aryan Agarwal, IIT KGP
    created : 19-January-2021 21:02:21 IST
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
    int n;
    cin >> n;

    int a[2 * n];
    // multiset<int,greater<int> > s;

    F(i, 0, 2 * n - 1)
    {
        cin >> a[i];
        // s.insert(a[i]);
    }

    sort(a, a + 2 * n, greater<int>());

    bool ok = false;

    F(i, 1, 2 * n - 1)
    {

        vector<pair<int, int>> ans;
        multiset<int, greater<int>> s2;
        for (auto x : a)
            s2.insert(x);

        int mx = max(a[i], a[0]);
        ans.pb({a[i], a[0]});
        // dbg(a[i],a[0],mx);
        s2.erase(s2.find(a[i]));
        s2.erase(s2.find(a[0]));
        bool ok = true;

        int cnt = 0;
        while (!s2.empty() && cnt == 0)
        {

            int p = (mx - *s2.begin());
            int q = (*s2.begin());

            if (s2.find(p) == s2.end())
            {
                ok = false;
                break;
            }
            s2.erase(s2.find(p));

            if (s2.find(q) == s2.end())
            {
                ok = false;
                break;
            }
            s2.erase(s2.find(q));

            ans.pb({q, p});
            mx = max(p, q);
        }

        if (ok)
        {
            cout << "YES\n";
            cout << ans[0].X + ans[0].Y;
            cout << "\n";
            for (auto p : ans)
            {
                cout << p.X << " " << p.Y;
                cout << "\n";
            }
            return;
        }
    }

    cout << "NO\n";
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