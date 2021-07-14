//https://codeforces.com/contest/1476/problem/E

/*
    credits : @CoderAnshu
    author : Aryan Agarwal, IIT KGP
    created : 21-February-2021 12:17:46 IST
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

vector <int> adj[mxn];
int vis_topo[mxn];
vector<int> topo;

bool dfs_topo(int node) {

    if(vis_topo[node] == 1)
        return false;
    
    if(vis_topo[node] == 2)
        return true;

    vis_topo[node] = 1;
    for(auto to : adj[node])
        if(!dfs_topo(to))return false;
    
    vis_topo[node] = 2;
    topo.push_back(node);
    return true;
}

// returns true if the directed graph has a topological sorting in O(N+M)
// nodes are 0 indexed from 0 to no_of_nodes_topo-1
bool topological_sort(int no_of_nodes_topo) {

    
    for(int i=0;i<no_of_nodes_topo;i++)
        if(!dfs_topo(i)) return false;
    reverse(topo.begin(),topo.end());
    return true;
}




void solve_LOG()
{
    int n,m,k;
    cin>>n>>m>>k;

    map<string,int> mp;
    vector <string> pa(n);
    F(i,0,n-1)
    {
        cin>>pa[i];
        mp[pa[i]]=i;
    }

    vector <string> s(m);

    F(i,0,m-1)
    {
        cin>>s[i];
        int mt;
        cin>>mt;

        mt--;

        bool ok = false;
        int par=mt;

        F(num,0,(int)pow(2,k)-1)
        {
            string zz(k,'0');
            F(bit,0,k-1)
            {
                if((num>>bit)&1)zz[bit]='_';
                else zz[bit]=s[i][bit];
            }

            if(mp.find(zz)!=mp.end())
            {
                if(mp[zz]==mt)ok=true;
                else
                {
                    adj[mt].pb(mp[zz]);
                }
            }
        }

        if(!ok)
        {
            cout<<"NO\n";
            return;
        }
    }

    if(!topological_sort(n))
    {
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";
    for(int x : topo)cout<<x+1<<" ";


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