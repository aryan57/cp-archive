//https://codeforces.com/contest/670/problem/F

/*
    author : Aryan Agarwal, IIT Kharagpur
    created : 12-April-2021 11:27:32 IST
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
    string s,sub;
    cin>>s>>sub;

    if(s=="01" || s=="10")
    {
        cout<<0;
        return;
    }

    int ocnt[10]={};

    for(char x : s)ocnt[x-'0']++;
    for(char x : sub)ocnt[x-'0']--;

    string ans(sz(s),'9');

    F(szk,1,1e6)
    {
        int k=szk;
        int cnt[10];
        F(i,0,9)cnt[i]=ocnt[i];


        bool ok = true;

        while(k)
        {
            cnt[k%10]--;
            if(cnt[k%10]<0)ok=false;
            k/=10;
        }

        int tot=0;
        F(i,0,9)tot+=cnt[i];

        if(!ok || tot+sz(sub)!=szk)continue;

        

        if(sub[0]!='0')
        {
            string t=sub;
            F(i,0,9)t+=string(cnt[i],'0'+i);

            ans=min(ans,t);
        }

        char t1='#';

        F(i,1,9)
        {
            if(cnt[i])
            {
                t1='0'+i;
                cnt[i]--;
                break;

            }
        }

        if(t1=='#')continue;

        F(i,0,9)
        {
            string t="";
            t+=t1;

            F(j,0,i-1)
            {
                t+=string(cnt[j],'0'+j);
            }

            t+=sub;

            F(j,i,9)
            {
                t+=string(cnt[j],'0'+j);
            }

            // if(t=="1003363")
            // {
            //     dbg(szk,ans);
            //     F(i,0,9)
            //     {
            //         dbg(cnt[i]);
            //     }
            // }
            ans=min(ans,t);



            t="";
            t+=t1;

            F(j,0,i)
            {
                t+=string(cnt[j],'0'+j);
            }

            t+=sub;

            F(j,i+1,9)
            {
                t+=string(cnt[j],'0'+j);
            }

            // if(t=="1003363")
            // {
            //     dbg(szk,ans);
            //     F(i,0,9)
            //     {
            //         dbg(cnt[i]);
            //     }
            // }

            ans=min(ans,t);


        }

    }

    cout<<ans;
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