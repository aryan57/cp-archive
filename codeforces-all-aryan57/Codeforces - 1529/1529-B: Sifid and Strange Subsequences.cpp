//https://codeforces.com/contest/1529/problem/B

/*
    author : aryan57
    created : 24-May-2021 20:23:41 IST
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

    vector <int> plus,minus;
    int zero=0;
    int mn=INF;
    F(i,1,n)
    {
        int x;
        cin>>x;
        if(x>0)
        {
            plus.push_back(x);
            mn=min(mn,x);
        }
        if(x<0)
        {
            minus.push_back(-x);
        }

        if(x==0)zero++;
    }

    if(zero>1 || plus.empty())
    {
        cout<<sz(minus)+zero;
        cout<<"\n";
        return;
    }

    if(minus.empty())
    {
        cout<<1+zero;
        cout<<"\n";
        return;
    }

    int ans=sz(minus)+zero;
    
    sort(all(minus));

    if(zero && *minus.begin()<mn)
    {
        cout<<ans;
        cout<<"\n";
        return;
    }

    bool ok = true;

    F(i,1,sz(minus)-1)
    {
        if(minus[i]-minus[i-1]<mn)
        {
            ok=false;
            break;
        }
    }

    if(!ok)
    {
        cout<<ans;
        cout<<"\n";
        return;
    }

    cout<<1+zero+sz(minus);
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
//	parsed : 24-May-2021 20:22:34 IST