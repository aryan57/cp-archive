//https://codeforces.com/contest/1538/problem/E

/*
    author : aryan57
    created : 11-June-2021 00:28:13 IST
*/
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
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

int count (string z)
{
    int cnt=0;
    F(i,0,sz(z)-4)
    {
        if(z.substr(i,4)=="haha")cnt++;
    }

    return cnt;
}

class str{
    public:
    string s;
    int cnt=0;


    string pre()
    {
        if(sz(s)<3)return s;
        return s.substr(0,3);
    }
    string suf()
    {
        if(sz(s)<3)return s;
        return s.substr(sz(s)-3,3);
    }
};

str merge(str a,str b)
{
    str c;
    c.s=a.s+b.s;
    c.cnt=a.cnt+b.cnt+count(a.suf()+b.pre());

    if(sz(c.s)>6)
    {
        c.s=c.pre()+"$"+c.suf();
    }

    return c;
}

void solve_LOL()
{
    int n;
    cin>>n;


    unordered_map<string,str> mp;
    int ans=0;
    F(j,0,n-1)
    {
        string v1,op;
        cin>>v1>>op;
        str a;
        if(op==":=")
        {
            string val;
            cin>>val;
            a.s=val;
            a.cnt=count(val);
            
        }else
        {
            string v2,plus,v3;
            cin>>v2>>plus>>v3;
            a=merge(mp[v2],mp[v3]);
        }
        // dbg(j,v1,a.s,a.cnt);
        mp[v1]=a;
        ans=a.cnt;
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
    sieve();
#endif
#ifdef ARYAN_SEG_SIEVE
    segmented_sieve();
#endif
#ifdef ARYAN_FACT
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