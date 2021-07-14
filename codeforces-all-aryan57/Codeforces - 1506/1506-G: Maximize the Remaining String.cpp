//https://codeforces.com/contest/1506/problem/G

/*
    author : Aryan Agarwal, IIT Kharagpur
    created : 01-April-2021 19:03:30 IST
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

void solve_LOL()
{
    string s;
    cin>>s;

    int n=sz(s);

    

    vector <bool> vis(26,false);

    // unordered_map<int,set <int> > has;
    vector <int> pos[26];

    F(i,0,n-1)
    {
        vis[s[i]-'a']=true;
        pos[s[i]-'a'].push_back(i);

        // F(j,0,25)
        // {
        //     if(vis[j])
        //     has[i].insert(j);
        // }
    }

    F(i,0,25)
    {
        sort(all(pos[i]));
    }

    vector <bool> vis2(26,false);
    
    F(i,0,25)
    {
        if(!vis[i])vis2[i]=true;
    }

    set <int,greater<int>> ss;

    for(char x : s)ss.insert(x-'a');

   int last=-1;


    string ans="";

    // int cnt=0;
    // int z='o'-'a';
    // dbg(pos['o'-'a'],z);

    while(!ss.empty())
    {
        for(int i : ss)
        {

            int newpos=upper_bound(all(pos[i]),last)-pos[i].begin();

            if(newpos==sz(pos[i]))continue;

            newpos=pos[i][newpos];

            bool ok = true;
            RF(j,i-1,0)
            {
                if(!vis2[j] && pos[j].back()<newpos)
                {
                    ok=false;
                    break;
                }
            }

            // dbg(i,newpos,ok);

            if(ok)
            {
                ans+=char('a'+i);
                ss.erase(i);
                last=newpos;
                vis2[i]=true;
                break;
            }
        }

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