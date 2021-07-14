//https://codeforces.com/contest/1506/problem/E

/*
    author : Aryan Agarwal, IIT Kharagpur
    created : 26-March-2021 03:59:58 IST
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
    int n;
    cin>>n;

    int q[n+1];

    int cnt[n+2]={};
    set <int> s;
    set<int> s2;
    vector <int> pos;

    F(i,1,n)
    {
        s.insert(i);
    }
    F(i,0,n-1)
    {
        cin>>q[i];
        cnt[q[i]]=1;
        if(s2.find(q[i])==s2.end())
        {
            s2.insert(q[i]);
            pos.push_back(i);
        }
        s.erase(q[i]);
    }
    q[n]=n+1;
    cnt[q[n]]=1;
    pos.push_back(n);

    vector <int> ansmn;

    // s2.clear();
    s2=s;

    F(ind,0,sz(pos)-2)
    {
        int i= pos[ind];
        int j=pos[ind+1];
        
        ansmn.push_back(q[i]);
        int len=j-i-1;
        while (len--)
        {
            auto it=s2.begin();

            ansmn.push_back(*it);

            s2.erase(it);
        }
        
    }

    vector <int> ansmx;

    
    F(ind,1,sz(pos)-1)
    {
        int i= pos[ind];
        int j=pos[ind-1];
        
        ansmx.push_back(q[j]);
        int len=i-j-1;
        while (len--)
        {
            auto it=s.lower_bound(q[j]);
            
            if(it!=s.begin())
            {
                it--;
            }

            ansmx.push_back(*it);

            s.erase(it);
        }
        
    }

    for(int x :ansmn)cout<<x<<" ";
    cout<<"\n";
    for(int x :ansmx)cout<<x<<" ";
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