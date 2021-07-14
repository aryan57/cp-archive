//https://codeforces.com/contest/1099/problem/D

/*
    author : Aryan Agarwal, IIT KGP
    created : 05-January-2021 15:39:05 IST
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mxn = 1e5;
const long long INF = 2e18;
const int32_t M = 1000000007; /*more than 1e9 */ /*7 + 1e9*/
// const int32_t M = 998244353; /*less than 1e9 */   /*1 + 7*17*(1<<23) */
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
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

void solve_LOG()
{
    int n;
    cin>>n;

    int p[n+1];
    p[1]=-1;

    vector< vector<int> > adj(n+1);
    F(i,2,n)
    {
        cin>>p[i];
        adj[i].pb(p[i]);
        adj[p[i]].pb(i);
    }

    vector< vector<int> > h(n+1);

    queue<int> q;
    vector<bool> visited(n+1);
    vector<int> distance(n+1);
    
    q.push(1);
    visited[1] = true;
    distance[1]=1;
    
    while (!q.empty()) {
    
        int parent_node = q.front();
        q.pop();
    
        for (int child_node : adj[parent_node]) {
    
            if (!visited[child_node])
            {
                visited[child_node] = true;
                q.push(child_node);
                distance[child_node] = distance[parent_node] + 1;
            }
        }
    }

    F(i,1,n)
    {
        h[distance[i]].pb(i);
    }

    int s[n+1];
    int ans[n+1];
    F(i,1,n)
    {
        cin>>s[i];
        ans[i]=s[i];
    }

    vector<pair<int,int> > ran(n+1,{0,INF});

    // int su=1;


    F(i,3,n)
    {
        for(int u: h[i])
        {
            int r=s[u]-s[p[p[u]]];
            ran[p[u]].X=max(0ll,ran[p[u]].X);
            ran[p[u]].Y=min(r,ran[p[u]].Y);

            // dbg(r);

            if(ran[p[u]].X>ran[p[u]].Y)
            {
                cout<<"-1\n";
                return;
            }
        }

        for(int u: h[i-1])
        {
            if(ran[u].Y==INF)ans[u]=0;
            else ans[u]=ran[u].Y;
        }
        for(int u: h[i])
        {
            ans[u]=s[u]-s[p[p[u]]]-ans[p[u]];
        }

        i++;
    }

    int sum=0;

    F(i,1,n)
    {
        if(ans[i]==-1)
        {
            ans[i]=0;
        }

        sum+=ans[i];
    }

    cout<<sum;

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