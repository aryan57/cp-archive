//https://codeforces.com/contest/1494/problem/C

/*
    author : Aryan Agarwal, IIT KGP
    created : 02-March-2021 20:36:46 IST
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

int fun(vector<int> &a, vector<int> &b)
{
    int ans = 0;

    int cnt = 0;

    int n = sz(a);
    int m = sz(b);

    int pre[n] = {};

    F(i, 0, n - 1)
    {
        int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        // pos--;
        // dbg(pos,a[i]);
        // if(pos>=0)dbg(b[pos]);
        if (pos >= 0 && pos<m && b[pos] == a[i])
        {
            pre[i]++;
            // dbg(pre[i]);
        }

        if (i)
            pre[i] += pre[i - 1];
    }

    // for(int x : pre)cout<<x<<" ";
    // cout<<"\n";

    RF(i, m - 1, 0)
    {
        int pos = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        pos--;

        // dbg(pos, b[i]);

        if (pos < 0)
            continue;

        int len = pos + 1;

        int last_p = b[i] - (len - 1);
        // dbg(last_p);

        int pos1 = lower_bound(b.begin(), b.end(), last_p) - b.begin();
        pos1--;

        // dbg(pos1);

        int k = pre[n - 1] - pre[pos];

        int k1 = i - pos1;

        // dbg(k,k1);

        ans = max(ans, k + k1);
    }

    return ans;
}

void solve_LOL()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);
    vector<int> a1;
    vector<int> b1;
    vector<int> a2;
    vector<int> b2;

    F(i, 0, n - 1)
    {
        cin >> a[i];
        if (a[i] >= 0)
        {
            a1.pb(a[i]);
        }
        else
        {
            // dbg(a[i]);
            a2.pb(a[i]);
        }
    }
    F(i, 0, m - 1)
    {
        cin >> b[i];
        if (b[i] >= 0)
            b1.pb(b[i]);
        else
            b2.pb(b[i]);
    }

    F(i, 0, sz(a2) - 1)
    {
        a2[i] =- a2[i];
    }
    F(i, 0, sz(b2) - 1)
    {
        b2[i] =- b2[i];
    }

    reverse(all(a2));
    reverse(all(b2));

    // for (int x : a1)
    //     cout << x << " ";
    // cout << "\n";
    // for (int x : a2)
    //     cout << x << " ";
    // cout << "\n";
    // for (int x : b1)
    //     cout << x << " ";
    // cout << "\n";
    // for (int x : b2)
    //     cout << x << " ";
    // cout << "\n";

    int x1 = fun(a1, b1);
    int x2 = fun(a2, b2);

    cout << x1 + x2;
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