//https://codeforces.com/contest/1322/problem/A

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
    int n;
    cin >> n;

    string s = "";
    char c;
    int a[n] = {};

    F(i, 0, n - 1)
    {
        cin >> c;
        if (i)
            a[i] = a[i - 1];

        s.push_back(c);
        if (c == '(')
        {
            a[i] += 1;
        }
        else
        {
            a[i] -= 1;
        }
    }

    // out(a,n);
    if (a[n-1]==0)
    {
        int i=0,len=0,str=0;
        while (i < n)
        {
            if(a[i]==0)
            {
                if(a[i-1]<0)len+=i-str+1;
                str=i+1;
            }

            i++;
        }

        cout << len;
        nl;
    }
    else
    {
        pfn1;
        nl;
    }

    return 0;
}