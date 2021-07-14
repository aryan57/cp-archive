//https://codeforces.com/contest/1320/problem/B

/*
    // The only difference between this and my first MLE solution
    // is the way i did BFS
    // make vis[child]=true as soon as you see it false

    // If we use vis[parent]=true (which i used in my MLE solution),
    // we may visit same node multiple times, which
    // blows up the memory limit of queue used in the BFS

    author : Aryan Agarwal, IIT KGP
    created : 22-December-2020 10:27:08 IST
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mxn = 2e5;
const long long INF = 2e18;
const int32_t M = 1000000007; /*more than (10)^9*/ /*7 + 1e9*/
// const int32_t M = 998244353; /*less than (10)^9*/   /*1 + 7*17*(2)^23*/
const long double pie = acos(-1);

#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define F(i, a, b) for (int i = a; i <= b; i++)
#define RF(i, a, b) for (int i = a; i >= b; i--)

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> gr[n + 1];
    vector<int> ingr[n + 1]; //inverse graph

    F(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        gr[u].pb(v);
        ingr[v].pb(u);
    }

    int k;
    cin >> k;
    vector<int> p(k + 1);

    F(i, 1, k)
    {
        cin >> p[i];
    }

    int s = p[1], t = p[k];

    vector<int> d(n + 1, INF);
    d[t] = 0;

    queue<int> q;
    vector<bool> vis(n + 1, false);

    q.push(t);
    vis[t] = true;

    while (!q.empty())
    {
        int v = q.front();
        
        q.pop();

        for (int u : ingr[v])
        {
            if (!vis[u])
                {q.push(u);vis[u] = true;}
            d[u] = min(d[u], d[v] + 1);

            // dbg(u,v);
        }
    }

    // F(i, 1, n)
    // {
    //     cout << d[i] << " ";
    // }
    // cout << "\n";

    int mn = 0, mx = 0;

    // F(i, 1, k)
    // {
    //     cout << p[i] << " ";
    // }
    // cout << "\n";

    F(i,1,k-1)
    {
        int curmn=INF;

        for(int v : gr[p[i]])
        {
            curmn=min(curmn,d[v]);
        }

        int cntmn=0;
        for(int v : gr[p[i]])
        {
            if(d[v]==curmn)cntmn++;
            if(cntmn==2)break;
        }

        if(d[p[i+1]]==curmn)
        {
            if(cntmn==2)mx++;
        }
        else
        {
            mx++;
            mn++;
        }

        // dbg(mn,mx,curmn,cntmn,p[i]);

    }

    cout << mn << " " << mx;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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
    int _t = 1;
    // cin>>_t;
    for (int i = 1; i <= _t; i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}