//https://codeforces.com/contest/1514/problem/C

/*
    author : aryan57
    created : 19-April-2021 20:20:07 IST
*/
#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define F(i, a, b) for (int i = a; i <= b; i++)
#define RF(i, a, b) for (int i = a; i >= b; i--)

const int mxn = 1e5;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

#define ARYAN_SIEVE
const int mxn_sieve = 1e5;

int spf[mxn_sieve + 1]; // spf -> smallest prime factor
// if spf[x]==x ,then x is prime
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i <= mxn_sieve; i++)
        spf[i] = i;

    for (int i = 4; i <= mxn_sieve; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i <= mxn_sieve; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= mxn_sieve; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

void solve_LOG()
{

    // F(num, 3, 20)
    // {
    //     int n = num;

    //     vector<int> ans;

    //     F(i, 0, (int)pow(2, n - 1)-1)
    //     {
    //         vector<int> tt;

    //         int pro = 1;

    //         // dbg(i);

    //         F(bit, 0, n - 2)
    //         {
    //             if ((i >> bit) & 1)
    //             {
    //                 tt.push_back(bit + 1);
    //                 pro *= (bit+1);
    //                 pro %= n;
    //             }
    //         }

    //         if (pro == 1 && sz(tt) > sz(ans))
    //         {
    //             ans.clear();
    //             for (int t : tt)
    //                 ans.push_back(t);
    //         }
    //     }

    //     cout << n;
    //     cout << "\n";
    //     for (int x : ans)
    //         cout << x<<" ";
    //     cout<<"\n";
    // }

    int n;
    cin >> n;

    // F(n, 5, 5)
    // {
        vector<int> ans;

        
            vector<bool> vis(n);

            F(i, 2, n - 2)
            {
                if (vis[i])
                    continue;
                if (n % i == 0)
                {
                    for (int j = i; j < n; j += i)
                    {
                        vis[j] = true;
                    }
                }
            }

            int pro=1;
            F(i, 1, n - 2)
            if (!vis[i]) 
            {
                ans.push_back(i);
                pro*=i;
                pro%=n;
            }

            if((pro*(n-1))%n==1)
            {
                ans.push_back(n-1);
            }
        

        cout << sz(ans);
        cout << "\n";
        // cout<<n;cout<<"\n";
        for (int x : ans)
            cout << x << " ";
        cout<<"\n";
    // }
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
    sieve();
#endif
#ifdef ARYAN_SEG_SIEVE
    segmented_sieve();
#endif
#ifdef ARYAN_FACT
    fact_init();
#endif
    // cout<<fixed<<setprecision(10);
    int _t = 1;
    // cin>>_t;
    for (int i = 1; i <= _t; i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOG();
    }
    return 0;
}