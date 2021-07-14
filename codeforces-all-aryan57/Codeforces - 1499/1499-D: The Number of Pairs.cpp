//https://codeforces.com/contest/1499/problem/D

/*
    author : Aryan Agarwal, IIT Kharagpur
    created : 18-March-2021 21:34:22 IST
*/

#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

// #define int long long
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
const int mxn_sieve = 2e7+100;

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

int gcd(int a, int b) /*__gcd doesn't work for big no.s*/
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve_LOL()
{
    int c,d,x;
    cin>>c>>d>>x;

    unordered_set <int> s;

    for(int i=1;i*i<=x;i++)
    {
        if(x%i==0)
        {
            int p=x/i;
            int q=i;

            if((p+d)%c==0)
            {
                int k=(p+d)/c;
                s.insert(k);
            }
            if((q+d)%c==0)
            {
                int k=(q+d)/c;
                s.insert(k);
            }
        }
    }

    int ans=0;

    // dbg(s);

    for(int num : s)
    {
       int s1=1;

        while (num!=1)
        {
            int z1=spf[num];


            while(num%z1==0)
            {
                num/=z1;
            }

            // s1.insert(z1);
            s1*=2;
        }

        // ans+=(int)pow(2,sz(s1));
        ans+=s1;
        
    }
    cout<<ans;
    cout<<"\n";
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
    int _t=1;
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}