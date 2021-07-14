//https://codeforces.com/contest/1332/problem/B

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
bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

void solve(vector <int> v)
{
    int n;
    cin >> n;
    int a[n], c[n], m = 1, vsz = v.size(),che[n]={};
    int flag=0;

    in(a,n);
    F(i, 0, vsz - 1)
    {
        if(flag)m++;
        flag=0;
        F(j, 0, n - 1)
        {
            // if(a[j]>v[i])break;
            // watch(a[j]);
            // watch(v[i]);
            if (a[j] % v[i] == 0 && che[j]==0)
            {
                // watch(m);
                // if(fl[cm]==0)m++;
                c[j] = m;
                flag=1;
                che[j]=1;
            }
        }
    }
    cout<<m-1;nl;
    out(c,n);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("11.txt", "r", stdin);
#endif
    fast;

    int _t;
    cin >> _t;

    vector <int> v;
    F(i, 2, 500)
    {
        if (isPrime(i))
            v.push_back(i);
    }
    while (_t--)
    {
        solve(v);
    }

    return 0;
}