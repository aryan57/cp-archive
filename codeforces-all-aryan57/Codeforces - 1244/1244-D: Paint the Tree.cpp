//https://codeforces.com/contest/1244/problem/D

/*
    author : aryan57
    created : 28-April-2021 19:11:55 IST
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

    int c[3][n];

    F(i,0,2)
    {
        F(j,0,n-1)
        {
            cin>>c[i][j];
        }
    }

    vector< int > adj[n];
    int deg[n]={};
    int head=-1;
    F(i,0,n-2)
    {
        int u,v;
        cin>>u>>v;
        --u;--v;
        deg[u]++;
        deg[v]++;

        if(deg[u]>2 || deg[v]>2)
        {
            cout<<"-1\n";
            return;
        }
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    F(i,0,n-1){
        if(deg[i]==1){head=i;break;}
    }

    vector <int> p(n);
    int ind=0;
    int par=-1;
    // dbg(head);
    while (true)
    {
        bool ok = false;
        p[ind++]=head;

        for(int to : adj[head]){
            if(to!=par){
                par=head;
                head=to;
                ok=true;
                break;
            }
        }

        if(!ok)break;
    }

    // dbg(p);

    vector <int> pp={0,1,2};
    vector <int> mnpp={0,1,2};
    int mn=INF;

    do{

        int cost=0;
        for(int i=0;i<n;i+=3)
        {
            if(i<n)cost+=c[pp[0]][p[i]];
            if(i+1<n)cost+=c[pp[1]][p[i+1]];
            if(i+2<n)cost+=c[pp[2]][p[i+2]];
        }

        // dbg(cost,pp);
        if(mn>cost){
            mn=cost;
            mnpp=pp;
        }

    }while(next_permutation(all(pp)));

    // dbg(mnpp);

    // dbg(lastcolor);

    vector <int> color(n,-1);

    for(int i=0;i<n;i+=3)
    {
        if(i<n)color[p[i]]=mnpp[0];
        if(i+1<n)color[p[i+1]]=mnpp[1];
        if(i+2<n)color[p[i+2]]=mnpp[2];
    }

    cout<<mn;
    cout<<"\n";
    for(int x : color)cout<<x+1<<" ";
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
    // cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOG();
    }
    return 0;
}