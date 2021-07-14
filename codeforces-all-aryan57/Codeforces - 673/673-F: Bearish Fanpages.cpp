//https://codeforces.com/contest/673/problem/F

/*
    // tut used
    author : Aryan Agarwal, IIT Kharagpur
    created : 12-April-2021 18:50:08 IST
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
    int n,q;
    cin>>n>>q;

    int t[n+1]={};
    F(i,1,n)
    {
        cin>>t[i];
    }

    int par[n+1]={};

    vector <set<int> > child2(n+1); 

    F(i,1,n)
    {
        int x;
        cin>>x;
        par[i]=x;
        child2[x].insert(i);
    }
    int self[n+1]={};
    int other[n+1]={};
    int val[n+1]={};

    F(i,1,n)
    {
        int k=sz(child2[i]);
        other[i]=t[i]/(k+2);
        self[i]=t[i]-(k+1)*(t[i]/(k+2));
        val[i]=self[i];

        for(int to : child2[i])
        {
            other[to]=t[to]/(sz(child2[to])+2);
            val[i]+=other[to];
        }
    }

    vector <set<pair <int,int > > > child(n+1); 
    // {sum_due_to_self+sum_due_to_child,id}

    multiset<int> s;

    F(i,1,n)
    {
        for(auto p : child2[i])
        {
            child[i].insert({val[p],p});
        }

        set<int> childnodes;
        if(child[i].empty()==false)
        {
            childnodes.insert((*child[i].begin()).Y);
            childnodes.insert((*child[i].rbegin()).Y);
        }

        for(int childnode : childnodes)
        {
            s.insert(val[childnode]+other[par[childnode]]);
        }
    }

    while (q--)
    {
        int type;
        cin>>type;

        if(type==2)
        {
            int ind;
            cin>>ind;
            cout<<val[ind]+other[par[ind]];
            cout<<"\n";
            continue;
        }
        if(type==3)
        {
            cout<<*s.begin()<<" "<<*s.rbegin();
            cout<<"\n";
            continue;
        }

        int i,j;
        cin>>i>>j;

        int l=par[i];
        set<int> nodes={i,j,l,par[j],par[par[j]],par[l],par[par[l]]};

        for(int node : nodes)
        {
            set<int> childnodes;
            if(child[node].empty()==false)
            {
                childnodes.insert((*child[node].begin()).Y);
                childnodes.insert((*child[node].rbegin()).Y);
            }

            for(int childnode : childnodes)
            {
                auto it = s.find(val[childnode]+other[par[childnode]]);
                assert(it!=s.end());
                s.erase(it);
            }
        }
        child[l].erase({val[i],i});
        child[par[l]].erase({val[l],l});
        child[par[par[l]]].erase({val[par[l]],par[l]});

        child[par[j]].erase({val[j],j});
        child[par[par[j]]].erase({val[par[j]],par[j]});

        child2[l].erase(i);
        child2[j].insert(i);

        {
            int k=sz(child2[l]);
            int newother=t[l]/(k+2);
            int newself=t[l]-(k+1)*(t[l]/(k+2));
            val[par[l]]+=newother-other[l];

            val[l]-=other[i];
            val[l]+=newself-self[l];

            other[l]=newother;
            self[l]=newself;
        }

        {
            int k=sz(child2[j]);
            int newother=t[j]/(k+2);
            int newself=t[j]-(k+1)*(t[j]/(k+2));

            val[par[j]]+=newother-other[j];

            val[j]+=other[i];
            val[j]+=newself-self[j];

            other[j]=newother;
            self[j]=newself;
        }
        
        par[i]=j;

        child[par[l]].insert({val[l],l});
        child[par[par[l]]].insert({val[par[l]],par[l]});

        child[j].insert({val[i],i});
        child[par[j]].insert({val[j],j});
        child[par[par[j]]].insert({val[par[j]],par[j]});

        for(int node : nodes)
        {
            set<int> childnodes;
            if(child[node].empty()==false)
            {
                childnodes.insert((*child[node].begin()).Y);
                childnodes.insert((*child[node].rbegin()).Y);
            }

            for(int childnode : childnodes)
                s.insert(val[childnode]+other[par[childnode]]);
            
        }

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