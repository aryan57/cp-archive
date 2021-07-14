//https://codeforces.com/contest/1323/problem/B

/*
    author : Aryan Agarwal, 19CS30005, IIT KGP
*/

#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;                        /*more than (10)^9*/
int PEG = 998244353; /*less than (10)^9*/ /*1 + 7*17*(2)^23*/
const double pie = 2 * acos(0.0);

typedef long long int ll;
typedef unsigned long long ull;

#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define int ll
#define F(i, a, b) for (ll i = a; i <= b; i++)
#define RF(i, a, b) for (ll i = a; i >= b; i--)
#define in(a, n)   \
    F(i, 0, n - 1) \
    cin >> a[i]
#define in1(a, n) \
    F(i, 1, n)    \
    cin >> a[i]
#define out(a, n)        \
    F(i, 0, n - 1)       \
    cout << a[i] << " "; \
    cout << "\n"
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pfy cout << "YES"
#define pfn cout << "NO"
#define pfn1 cout << "-1" // printf negative 1
#define pf1 cout << "1"
#define nl cout << "\n"
#define gcd(a, b) __gcd((a), (b))

int binpow(int x, int y, int p) /* (x^y)%p in O(log y) */
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
int mod_inverse(int n, int p) /* Returns n^(-1) mod p */ { return binpow(n, p - 2, p); }

signed main()
{
    fast;

    int n, m, k;
    cin >> n >> m >> k;
    int a[n], b[m], count = 0, temp;
    in(a, n);
    in(b, m);

    vector<pair<int, int>> v;

    for (ll i = 1; i * i <= k; i++)
    {
        if (k % i == 0)
        {
            v.push_back({i, k / i});
        }
    }
    int vsz = v.size();
    // F(i,0,vsz-1){watch(v[i].first);watch(v[i].second);}
    int a1, b1, a2, b2, a3, b3,a4,b4;
    F(i, 0, vsz - 1)
    {
        a3 = 0; b3 = 0,a4=0,b4=0;
        a1 = v[i].first;
        b1 = v[i].second;
        if (a1 != b1)
        {
            a2 = b1;
            b2 = a1;
        }
        else
        {
            a2 = 0;
            b2 = 0;
        }
        // watch(a1);
        // watch(b1);
        // watch(a2);
        // watch(b2);

        temp = 0;
        F(j, 0, n - 1)
        {
            if (a[j])
                temp++;
            else
            {
                if (temp >= a1)
                    a3 += temp - a1 + 1;
                if (temp >= a2 && a2)
                    a4 += temp - a2 + 1;
                temp = 0;
            }
        }
        if (a[n - 1])
        {
            if (temp >= a1)
                a3 += temp - a1 + 1;
            if (temp >= a2 && a2)
                a4 += temp - a2 + 1;
            temp = 0;
        }
        // watch(a3);
        temp = 0;
        F(j, 0, m - 1)
        {
            if (b[j])
                temp++;
            else
            {
                if (temp >= b1)
                    b3 += temp - b1 + 1;
                if (temp >= b2 && b2)
                    b4 += temp - b2 + 1;
                temp = 0;
            }
        }

        if (b[m - 1])
        {
            if (temp >= b1)
                b3 += temp - b1 + 1;
            if (temp >= b2 && b2)
                b4 += temp - b2 + 1;
            temp = 0;
        }
        // watch(b3);

        count += (a3 * b3)+(a4 * b4);
    }

    cout << count;
    return 0;
}