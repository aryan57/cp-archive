//https://codeforces.com/contest/1539/problem/D

/*
    author : aryan57
    created : 20-June-2021 16:34:43 IST
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


bool comp(pair <int,int>  a, pair <int,int>  b)
{
    return a.Y < b.Y;
}

void solve_LOG()
{
    int n;
    cin>>n;

    vector<pair<int,int> > v(n);
    int sa=0;
    F(i,0,n-1)
    {
        cin>>v[i].X>>v[i].Y;
        sa+=v[i].X;
    }

    sort(all(v),comp);
    
    int p=0;
    int q=n-1;

    int ans=sa;
    int cnt=0;
    while (p<=q)
    {
        dbg(p,q,cnt,ans);

        if(v[p].Y<=cnt)
        {
            cnt+=v[p].X;
            v[p].X=0;
            p++;
            continue;
        }

        int req=v[p].Y-cnt;

        int j=q;
        while (j>=p && req>0)
        {
            int mn=min(v[j].X,req);
            ans+=mn;
            cnt+=mn;
            v[j].X-=mn;
            req-=mn;
            q=j;
            j--;
        }

        // dbg(p,q,cnt,ans);
        if(v[p].Y<=cnt)
        {
            cnt+=v[p].X;
            v[p].X=0;
            p++;
            continue;
        }

        cnt+=v[p].X;
        ans+=v[p].X;
        v[p].X=0;

        p++;

        
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
    // cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOG();
    }
    return 0;
}
//	parsed : 20-June-2021 16:21:36 IST