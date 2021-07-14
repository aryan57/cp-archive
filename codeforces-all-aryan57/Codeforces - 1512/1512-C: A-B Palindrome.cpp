//https://codeforces.com/contest/1512/problem/C

/*
    author : Aryan Agarwal, IIT Kharagpur
    created : 10-April-2021 20:17:45 IST
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

void solve_LOL()
{
    int a,b;
    cin>>a>>b;

    string s;
    cin>>s;

    int n=a+b;
    int p=0;
    int q=n-1;

    for(char x : s)
    {
        if(x=='0')a--;
        if(x=='1')b--;
    }

    if(a<0 || b<0)
    {
        cout<<"-1\n";
        return;
    }

    while(p<q)
    {
        // dbg(s,a,b,p,q);
        if(s[p]==s[q] && s[p]=='?')
        {
            p++;
            q--;
            continue;
        }
        if(s[p]=='?')
        {
            if(s[q]=='0' && a>0)
            {
                a--;
                s[p]='0';
            }else if(s[q]=='1' && b>0)
            {
                b--;
                s[p]='1';
            }
            else
            {
                cout<<"-1\n";
                return;
            }

            p++;
            q--;
            continue;
        }
        if(s[q]=='?')
        {
            if(s[p]=='0' && a>0)
            {
                a--;
                s[q]='0';
            }else if(s[p]=='1' && b>0)
            {
                b--;
                s[q]='1';
            }
            else
            {
                cout<<"-1\n";
                return;
            }
            p++;
            q--;
            continue;
        }

        if(s[p]!=s[q])
        {
            cout<<"-1\n";
            return;
        }

        p++;
        q--;
    }

    p=0;
    q=n-1;

    // dbg(a,b,s);

    while(p<q)
    {
        if(s[p]=='?' && s[q]=='?')
        {
            if(a>=2)
            {
                s[p]=s[q]='0';
                a-=2;
            }else if(b>=2)
            {
                s[p]=s[q]='1';
                b-=2;
            }else
            {
                cout<<"-1\n";
                return;
            }
        }

        p++;
        q--;
    }

    if(p==q && s[p]=='?')
    {
        if(a)
        {
            s[p]='0';
            a--;
        }
        else if(b)
        {
            s[p]='1';
            b--;
        }
        else
        {
            cout<<"-1\n";
            return;
        }
    }

    if(a || b)
    {
        cout<<"-1\n";
        return;
    }

    cout<<s;
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