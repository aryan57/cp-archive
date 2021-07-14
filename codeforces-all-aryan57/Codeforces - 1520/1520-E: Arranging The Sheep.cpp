//https://codeforces.com/contest/1520/problem/E

/*
    author : aryan57
    created : 05-May-2021 20:27:20 IST
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

void solve_LOL()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    int tot=0;

    int left[n]={};
    int right[n]={};

    int pre=0;
    int cnt=0;
    int vv[n]={};
    F(i,0,n-1)
    {
        if(i)vv[i]=vv[i-1];
        left[i]+=i*cnt-pre;
        if(s[i]=='*')
        {
            cnt++;
            tot++;
            pre+=i;
            vv[i]++;
        }

    }
    pre=0;
    cnt=0;

    RF(i,n-1,0)
    {
        right[i]+=-(i*cnt-pre);
        if(s[i]=='*')
        {
            cnt++;
            pre+=i;
        }
    }

    // for(int x : left)cout<<x<<" ";
    // cout<<"\n";
    // for(int x : right)cout<<x<<" ";
    // cout<<"\n";
    int ans=INF;
    F(i,0,n-1)
    {
        // cout<<i<<" = "<<left[i]<<", "<<right[i]<<"\n";
        // cout<<i<<" = "<<left[i]+right[i]<<"\n";
        int k=vv[i]-1;
        int k2=tot-vv[i];
        int s=k*(k+1)/2+(k2*(k2+1))/2;
        // cout<<i<<" = "<<s<<"\n";
        // cout<<i<<" = "<<left[i]+right[i]-s<<"\n";
        ans=min(ans,left[i]+right[i]-s);

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