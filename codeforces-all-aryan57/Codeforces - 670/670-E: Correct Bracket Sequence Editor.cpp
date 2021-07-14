//https://codeforces.com/contest/670/problem/E

/*
    author : Aryan Agarwal, IIT Kharagpur
    created : 12-April-2021 10:56:31 IST
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

void solve_LOG()
{
    int n,m,p;
    cin>>n>>m>>p;

    p--;

    vector <int> pp(n);
    stack<int> s1;
    string s;
    cin>>s;

    F(i,0,n-1)
    {
        if(s[i]=='(')s1.push(i);
        else
        {
            int top=s1.top();
            s1.pop();

            pp[i]=top;
            pp[top]=i;
        }
    }

    string t;
    cin>>t;

    vector <bool> vis(n,false);

    set<int> ava;
    F(i,0,n-1)
    {
        ava.insert(i);
    }

    F(i,0,m-1)
    {
        // dbg(p,ava);
        if(t[i]=='L')
        {
            auto it=ava.lower_bound(p);
            it--;
            p=*it;
        }else if(t[i]=='R')
        {
            auto it=ava.upper_bound(p);
            p=*it;
        }else
        {
            auto lowit=ava.lower_bound(p);
            auto highit=ava.upper_bound(pp[p]);

            if(pp[p]<p)
            {
                swap(p,pp[p]);
                lowit=ava.lower_bound(p);
                highit=ava.upper_bound(pp[p]);
            }

            // dbg(p,pp[p],*lowit,*highit);
            vector <int> temp;

            for(auto it=lowit;it!=highit;it++)
            {
                temp.push_back(*it);
            }
            for(int num : temp)
            {
                ava.erase(num);
                vis[num]=true;
            }
            auto it=ava.upper_bound(p);
            if(it!=ava.end())
            {
                p=*it;
            }
            else
            {
                auto it=ava.lower_bound(p);
                it--;
                p=*it;
            }
        }
    }

    // dbg(p,ava);

    F(i,0,n-1)
    {
        if(!vis[i])cout<<s[i];
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
    int _t=1;
    // cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOG();
    }
    return 0;
}