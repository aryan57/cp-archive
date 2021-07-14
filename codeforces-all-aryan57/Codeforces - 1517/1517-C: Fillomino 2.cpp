//https://codeforces.com/contest/1517/problem/C

/*
    author : aryan57
    created : 23-April-2021 20:48:23 IST
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

void solve_LOG()
{
    int n;
    cin>>n;

    pair <int,int>  p[n+1]={};

    int cnt[n+1]={};

    pair <int,int>  g[3*n+1][n+1]={};
    int tot=0;
    F(i,1,n)
    {
        cin>>p[i].X;
        p[i].Y=p[i].X;
        g[i][i]=p[i];
        tot+=p[i].X;
    }

    
    int dist=0;
    // int l=1;
    // int r=n;
    while(tot>0)
    {
        int col=-1;
        // cout<<"col "<<col<<"\n";
        // cout<<"dist "<<dist<<"\n";

        F(j,1,n)
        {
            if(g[j+dist][j].Y==1)
            {
                col=j;
                break;
            }
        }

        // cout<<"col "<<col<<"\n";
        // cout<<"dist "<<dist<<"\n";
        // cout<<"tot "<<tot<<"\n";

        F(j,1,col-1)
        {
            if(j+dist+1>n)continue;
            g[j+dist+1][j]=g[j+dist][j];
            g[j+dist+1][j].Y--;
            tot--;
        }

        tot--;

        F(j,col+1,n)
        {
            if(j+dist>n)continue;
            g[j+dist][j-1]=g[j+dist][j];
            g[j+dist][j-1].Y--;
            tot--;
        }

        dist++;

        
        
        // cout<<"col "<<col<<"\n";
        // cout<<"dist "<<dist<<"\n";
        // cout<<"tot "<<tot<<"\n";

        
    }

    F(i,1,n)
    {
        F(j,1,i)
        {
            cout<<g[i][j].X<<" ";
        }
        cout<<"\n";
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